
import com.aliyuncs.DefaultAcsClient;
import com.aliyuncs.IAcsClient;
import com.aliyuncs.dysmsapi.model.v20170525.QuerySendDetailsRequest;
import com.aliyuncs.dysmsapi.model.v20170525.QuerySendDetailsResponse;
import com.aliyuncs.dysmsapi.model.v20170525.SendSmsRequest;
import com.aliyuncs.dysmsapi.model.v20170525.SendSmsResponse;
import com.aliyuncs.exceptions.ClientException;
import com.aliyuncs.profile.DefaultProfile;
import com.aliyuncs.profile.IClientProfile;
import com.sun.net.httpserver.HttpExchange;
import com.sun.net.httpserver.HttpHandler;
import com.sun.net.httpserver.HttpServer;

import java.io.*;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.net.InetSocketAddress;
import java.net.HttpURLConnection;
import java.net.URL;

import org.json.JSONArray;
import org.json.JSONObject;
import org.json.JSONTokener;


public class AliSms {
    //产品名称:云通信短信API产品,开发者无需替换
    static final String product = "Dysmsapi";
    //产品域名,开发者无需替换
    static final String domain = "dysmsapi.aliyuncs.com";

    // TODO 此处需要替换成开发者自己的AK(在阿里云访问控制台寻找)
    static final String accessKeyId = "xxxxx";
    static final String accessKeySecret = "xxxxx";

    public static SendSmsResponse sendSms(String phoneNumbers, String code,String signName, String templateCode) throws ClientException {

        //可自助调整超时时间
        System.setProperty("sun.net.client.defaultConnectTimeout", "10000");
        System.setProperty("sun.net.client.defaultReadTimeout", "10000");

        //初始化acsClient,暂不支持region化
        IClientProfile profile = DefaultProfile.getProfile("cn-hangzhou", accessKeyId, accessKeySecret);
        DefaultProfile.addEndpoint("cn-hangzhou", "cn-hangzhou", product, domain);
        IAcsClient acsClient = new DefaultAcsClient(profile);

        //组装请求对象-具体描述见控制台-文档部分内容
        SendSmsRequest request = new SendSmsRequest();
        //必填:待发送手机号
        request.setPhoneNumbers(phoneNumbers);
        //必填:短信签名-可在短信控制台中找到
        request.setSignName(signName);
        //必填:短信模板-可在短信控制台中找到
        request.setTemplateCode(templateCode);
        //可选:模板中的变量替换JSON串,如模板内容为"亲爱的${name},您的验证码为${code}"时,此处的值为
        request.setTemplateParam("{\"code\":\""+ code +"\"}");

        //选填-上行短信扩展码(无特殊需求用户请忽略此字段)
        //request.setSmsUpExtendCode("90997");

        //可选:outId为提供给业务方扩展字段,最终在短信回执消息中将此值带回给调用者
        request.setOutId("205");

        //hint 此处可能会抛出异常，注意catch
        SendSmsResponse sendSmsResponse = acsClient.getAcsResponse(request);

        return sendSmsResponse;
    }

    public static boolean sendSmsMC(String phoneNumbers, String code, String signName, String templateCode)
    {
        try{
            // 建立URL连接
            URL url = new URL("http://112.74.139.4:8002/sms3_api/jsonapi/jsonrpc2.jsp");
            HttpURLConnection connection = (HttpURLConnection)url.openConnection();
            connection.setDoInput(true);
            connection.setDoOutput(true);
            connection.setRequestMethod("POST");
            connection.setRequestProperty("Content-Type", "application/json;charset=UTF-8");
            // 组建提交内容
            JSONObject jsonSubmit = new JSONObject();
            jsonSubmit.put("content", templateCode+code+"【"+signName+"】");
            jsonSubmit.put("phone", phoneNumbers);
            // 组建提交内容数组
            JSONArray jsonArray = new JSONArray();
            jsonArray.put(jsonSubmit);
            // 组建参数内容
            JSONObject jsonParams = new JSONObject();
            jsonParams.put("userid", "200216");
            jsonParams.put("password", "ab123456");
            jsonParams.put("submit", jsonArray);
            // 组建完整消息对象
            JSONObject jsonObj = new JSONObject();
            jsonObj.put("id",1);
            jsonObj.put("method", "send");
            jsonObj.put("params", jsonParams);
            // 发送JSON数据
            OutputStream os = connection.getOutputStream();
            os.write(jsonObj.toString().getBytes());
            os.close();
            // 获取返回的JSON
            InputStream is = connection.getInputStream();
            JSONTokener jsonTokener = new JSONTokener(is);
            JSONObject jsonResult = new JSONObject(jsonTokener);
            JSONArray resultArray;
            try {
                resultArray = jsonResult.getJSONArray("result");
            } catch (Exception e)
            {
                e.printStackTrace();
                System.out.println(jsonResult.toString());
                return false;
            }
            JSONObject resultMsg = (JSONObject) resultArray.get(0);
            return resultMsg.getString("info").equals("成功");

        } catch(Exception e) {
            e.printStackTrace();
            return false;
        }
    }

    public static QuerySendDetailsResponse querySendDetails(String bizId) throws ClientException {

        //可自助调整超时时间
        System.setProperty("sun.net.client.defaultConnectTimeout", "10000");
        System.setProperty("sun.net.client.defaultReadTimeout", "10000");

        //初始化acsClient,暂不支持region化
        IClientProfile profile = DefaultProfile.getProfile("cn-hangzhou", accessKeyId, accessKeySecret);
        DefaultProfile.addEndpoint("cn-hangzhou", "cn-hangzhou", product, domain);
        IAcsClient acsClient = new DefaultAcsClient(profile);

        //组装请求对象
        QuerySendDetailsRequest request = new QuerySendDetailsRequest();
        //必填-号码
        request.setPhoneNumber("xxxxxx");
        //可选-流水号
        request.setBizId(bizId);
        //必填-发送日期 支持30天内记录查询，格式yyyyMMdd
        SimpleDateFormat ft = new SimpleDateFormat("yyyyMMdd");
        request.setSendDate(ft.format(new Date()));
        //必填-页大小
        request.setPageSize(10L);
        //必填-当前页码从1开始计数
        request.setCurrentPage(1L);

        //hint 此处可能会抛出异常，注意catch
        QuerySendDetailsResponse querySendDetailsResponse = acsClient.getAcsResponse(request);

        return querySendDetailsResponse;
    }

    static void handleSms(HttpExchange t, String aliSignName, String aliTemplateCode, String mcSignName,
                          String mcTemplateCode) throws IOException {
        // 获取输入流，此时获取的是位流
        InputStream is = t.getRequestBody();
        // JSONTokener 用于读取json格式的文件，可以用InputStream,Reader,String构造
        JSONTokener jsonTokener = new JSONTokener(is);
        // 可以直接用JSONTokener对象构造JSON对象
        JSONObject jsonObj = new JSONObject(jsonTokener);
        // 获取phoneNumbers和code
        String phoneNumbers = jsonObj.getString("phoneNumbers");
        String code = jsonObj.getString("code");

        // 响应消息
        String responseMsg = null;
        // 发短信
        SendSmsResponse response = null;

        try {
            response = sendSms(phoneNumbers, code, aliSignName, aliTemplateCode);
        } catch (ClientException e) {
            e.printStackTrace();
            boolean mcStatus = sendSmsMC(phoneNumbers, code, mcSignName, mcTemplateCode);
            if (mcStatus)
                responseMsg = "success";
            else
                responseMsg = "failed";
            t.sendResponseHeaders(200, responseMsg.length());
            OutputStream os = t.getResponseBody();
            os.write(responseMsg.getBytes());
            os.close();
            return;
        }
        System.out.println("短信接口返回的数据----------------");
        System.out.println("Code=" + response.getCode());
        System.out.println("Message=" + response.getMessage());
        System.out.println("RequestId=" + response.getRequestId());
        System.out.println("BizId=" + response.getBizId());

        if (response.getMessage().equals("OK"))
            responseMsg = "success";
        else
        {
            boolean mcStatus = sendSmsMC(phoneNumbers, code, mcSignName, mcTemplateCode);
            if (mcStatus)
                responseMsg = "success";
            else
                responseMsg = "failed";
        }

        t.sendResponseHeaders(200, responseMsg.length());
        OutputStream os = t.getResponseBody();
        os.write(responseMsg.getBytes());
        os.close();
    }

    static class  HandleRegistSms implements HttpHandler{
        public void handle(HttpExchange t) throws IOException{
            handleSms(t, "Saul", "SMS_134970001", "淘金者平台",
                    "您的注册验证码为：");

        }
    }

    static class HandleLoginSms implements HttpHandler{
        public void handle(HttpExchange t) throws IOException{
            handleSms(t, "Saul", "SMS_135028150", "淘金者平台",
                    "您的登录验证码为：");
        }
    }

    public static void main(String[] args) throws ClientException, InterruptedException, IOException {
        HttpServer server = HttpServer.create(new InetSocketAddress(5001), 0);
        server.createContext("/regist", new HandleRegistSms());
        server.createContext("/login", new HandleLoginSms());
        server.setExecutor(null);
        server.start();
    }

}
