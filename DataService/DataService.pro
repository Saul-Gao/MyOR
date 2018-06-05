SOURCES += \
    main.cpp \
    myhttpserver.cpp \
    Connection.cpp \
    ConnectionPool.cpp \
    DatabaseOperation.cpp \
    ToolHelper.cpp

HEADERS += \
    myhttpserver.h \
    Connection.h \
    ConnectionPool.h \
    DatabaseOperation.h \
    ToolHelper.h


CONFIG += TUFAO1 c++11

INCLUDEPATH += \
    /usr/include/mysql

LIBS += \
    -lmysqlclient \
    -lpthread

