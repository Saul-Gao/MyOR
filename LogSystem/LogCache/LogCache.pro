HEADERS += \
    myhttpserver.h \
    myamqpclient.h

SOURCES += \
    myhttpserver.cpp \
    main.cpp \
    myamqpclient.cpp

CONFIG += TUFAO1 c++11

LIBS += \
    -lSimpleAmqpClient
