#include <QCoreApplication>
#include <curl/curl.h>
#include <QtGlobal>
#include <QTime>
#include <QDebug>
#include <map>
#include <openssl/hmac.h>

using std::map;

#include <boost/archive/iterators/base64_from_binary.hpp>
#include <boost/archive/iterators/binary_from_base64.hpp>
#include <boost/archive/iterators/transform_width.hpp>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
bool Base64Encode(const string& input, string* output) {
  typedef boost::archive::iterators::base64_from_binary<boost::archive::iterators::transform_width<string::const_iterator, 6, 8> > Base64EncodeIterator;
  stringstream result;
  copy(Base64EncodeIterator(input.begin()) , Base64EncodeIterator(input.end()), ostream_iterator<char>(result));
  size_t equal_count = (3 - input.length() % 3) % 3;
  for (size_t i = 0; i < equal_count; i++) {
    result.put('=');
  }
  *output = result.str();
  return output->empty() == false;
}

bool Base64Decode(const string& input, string* output) {
  typedef boost::archive::iterators::transform_width<boost::archive::iterators::binary_from_base64<string::const_iterator>, 8, 6> Base64DecodeIterator;
  stringstream result;
  try {
    copy(Base64DecodeIterator(input.begin()) , Base64DecodeIterator(input.end()), ostream_iterator<char>(result));
  } catch(...) {
    return false;
  }
  *output = result.str();
  return output->empty() == false;
}

size_t write_func(void *buffer,size_t size, size_t nmemb, void *stream)
{
    qDebug() << (char *)buffer;
}

QString specialUrlEncode(CURL *curl, const char *string)
{
    char *c = curl_easy_escape(curl, string, 0);
    QString temp = c;
    temp.replace("+","%20").replace("*","%2A").replace("%7E","~");
    curl_free(c);
    return temp;
}

int main(int argc, char *argv[])
{
    QCoreApplication core(argc, argv);
    curl_global_init(CURL_GLOBAL_DEFAULT);
    CURL *curl = curl_easy_init();

    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    QString datetime = QDateTime::currentDateTimeUtc().toString("yyyy-MM-dd'T'HH:mm:ss'Z'");

    map<QString, QString> msgMap;
#if 0

    msgMap["AccessKeyId"] = "xxxxx"; //
    msgMap["Action"] = "SendSms";
    msgMap["PhoneNumbers"] = "xxxxx"; //
    msgMap["RegionId"] = "cn-hangzhou";
    msgMap["SignName"] = "Saul"; //
    msgMap["SignatureMethod"] = "HMAC-SHA1";
    msgMap["SignatureNonce"] = QString("%1").arg(qrand());
    msgMap["SignatureVersion"] = "1.0";
    msgMap["TemplateCode"] = "SMS_134970001"; //
    msgMap["TemplateParam"] = "{\"code\":\"1234\"}"; //
    msgMap["Timestamp"] = datetime;
    msgMap["Version"] = "2017-05-25";
    msgMap["Format"] = "XML";
#else
    msgMap["AccessKeyId"] = "testId";
    msgMap["Action"] = "SendSms";
    msgMap["Format"] = "XML";
    msgMap["OutId"] = "123";
    msgMap["PhoneNumbers"] = "15300000001";
    msgMap["RegionId"] = "cn-hangzhou";
    msgMap["SignName"] = "阿里云短信测试专用";
    msgMap["SignatureMethod"] = "HMAC-SHA1";
    msgMap["SignatureNonce"] = "45e25e9b-0a6f-4070-8c85-2956eda1b466";
    msgMap["SignatureVersion"] = "1.0";
    msgMap["TemplateCode"] = "SMS_71390007";
    msgMap["TemplateParam"] = "{\"customer\":\"test\"}";
    msgMap["Timestamp"] = "2017-07-12T02:42:19Z";
    msgMap["Version"] = "2017-05-25";
#endif

    // 拼接编码前的字符串,此处仅为了前后对比，可以直接删掉
    QString msgStr;
    for (map<QString, QString>::iterator it = msgMap.begin(); it != msgMap.end(); ++it)
    {
        msgStr.append(it->first);
        msgStr.append("=");
        msgStr.append(it->second);
        msgStr.append("&");
    }

    msgStr.remove(msgStr.length()-1,1);

    qDebug() << msgStr;
    qDebug() << "---------------------------------------";

    // 拼接编码后的字符串
    QString msgEncodeStr;
    for (map<QString, QString>::iterator it = msgMap.begin(); it != msgMap.end(); ++it)
    {
        msgEncodeStr.append(specialUrlEncode(curl, it->first.toUtf8().data()));
        msgEncodeStr.append("=");
        msgEncodeStr.append(specialUrlEncode(curl, it->second.toUtf8().data()));
        msgEncodeStr.append("&");
    }

    msgEncodeStr.remove(msgEncodeStr.length()-1,1);

    qDebug() << msgEncodeStr;
    qDebug() << "-------------------------------------------------";
    // 把编码后的字符串拼接成待签名串
    QString stringToSign;
    stringToSign.append("GET&").append(specialUrlEncode(curl, "/"));
    stringToSign.append("&").append(msgEncodeStr.toUtf8().toPercentEncoding("&",""));
    qDebug() << stringToSign;
    qDebug() << "------------------------------------------------------------";

    // 使用 HmacSHA1+Base64 进行签名，编码采用 UTF-8

    //QString AccessKeySecret = "xxxxxx";
    QString AccessKeySecret = "testSecret";
    AccessKeySecret.append("&");

     std::string accessKeySecretStd = AccessKeySecret.toStdString();
     std::string stringToSignStd = stringToSign.toStdString();

     unsigned char digest[EVP_MAX_MD_SIZE] = {'\0'};
     unsigned int digest_len = 0;

//     HMAC(EVP_sha1(),
//          accessKeySecretStd.c_str(),
//          accessKeySecretStd.length(),
//          (const unsigned char *)stringToSignStd.c_str(),
//          stringToSignStd.length(), digest, &digest_len);

     HMAC(EVP_sha1(),
          (const unsigned char *)accessKeySecretStd.c_str(),
          accessKeySecretStd.length(),
           (const unsigned char *)stringToSign.toStdWString().data(),
          stringToSign.length()*2, digest, &digest_len);
     char mdString[41] = {'\0'};
     for (int i = 0; i < 20; i++)
     {
         sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);
     }

    qDebug () << mdString;
      //base64算法调用，前面签名算法结果作为输入参数，得到最终签名

     //  std::string hmac;
    //   Base64Encode(digest, &hmac);
    //   qDebug() << hmac.c_str();
    //   qDebug() << "-------------------------------------------------------";

    QByteArray bufDigest((char*)digest, 20);
    QByteArray base64Data = bufDigest.toBase64();
    qDebug() <<base64Data;

       // 把生成的签名做特殊编码转换
       QString Signature = specialUrlEncode(curl, base64Data);

       qDebug() << Signature;
       qDebug() << "-------------------------------------------------------";
      //将特殊编码后的签名加入到编码后的字符串中
      msgEncodeStr.insert(0, QString("http://dysmsapi.aliyuncs.com/?Signature=%1&").arg(Signature));
      qDebug() << msgEncodeStr;

      qDebug() << "-------------------------------------------------------------------";
    curl_easy_setopt(curl, CURLOPT_URL, msgEncodeStr.toUtf8().data());
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, NULL);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_func);
    curl_easy_perform(curl);

    curl_easy_cleanup(curl);
    curl_global_cleanup();
    return 0;
}
