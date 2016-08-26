#-------------------------------------------------
#
# Project created by QtCreator 2016-07-26T17:04:45
#
#-------------------------------------------------

QT       += core gui
QT += sql

TARGET = A66-app
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    step.cpp \
    moulds.cpp \
    manual.cpp \
    easybend.cpp \
    systemsetting.cpp \
    runstate.cpp \
    global.cpp \
    programdb.cpp \
    qsoftkeyboard.cpp \
    qsoftkeyvalue.cpp \
    programname.cpp \
    thread.cpp \
    chooseupmolddialog.cpp \
    chooselowermolddialog.cpp \
    TestSlave.c \
    TestMaster.c \
    sync.c \
    timer.c \
    states.c \
    sdo.c \
    pdo.c \
    ObjDict.c \
    objacces.c \
    nmtSlave.c \
    nmtMaster.c \
    lss.c \
    lifegrd.c \
    emcy.c \
    def.c \
    dcf.c \
    CanopenDictConfig.c \
    canfestival.c \
    canfestivalAPI.c \
    manualadjustdate.cpp \
    wrokedtotal.cpp \
    systeminfo.cpp \
    systemwarn.cpp \
    mathcalculation.cpp \
    yreferencepoint.cpp

HEADERS  += mainwindow.h \
    step.h \
    moulds.h \
    manual.h \
    easybend.h \
    systemsetting.h \
    runstate.h \
    global.h \
    programdb.h \
    qsoftkeyboard.h \
    qsoftkeyvalue.h \
    programname.h \
    thread.h \
    chooseupmolddialog.h \
    chooselowermolddialog.h \
    TestSlave.h \
    TestMaster.h \
    sysdep.h \
    sync.h \
    timerscfg.h \
    timer.h \
    timers_driver.h \
    states.h \
    sdo.h \
    pdo.h \
    objdictdef.h \
    ObjDict.h \
    objacces.h \
    nmtSlave.h \
    nmtMaster.h \
    lss.h \
    lifegrd.h \
    emcy.h \
    def.h \
    dcf.h \
    data.h \
    config.h \
    CanopenDictConfig.h \
    canfestival.h \
    can.h \
    can_driver.h \
    applicfg.h \
    canfestivalAPI.h \
    manualadjustdate.h \
    wrokedtotal.h \
    systeminfo.h \
    systemwarn.h \
    mathcalculation.h \
    yreferencepoint.h

FORMS    += mainwindow.ui \
    step.ui \
    moulds.ui \
    manual.ui \
    easybend.ui \
    systemsetting.ui \
    runstate.ui \
    programdb.ui \
    qsoftkeyboardForm.ui \
    programname.ui \
    chooseupmolddialog.ui \
    chooselowermolddialog.ui \
    manualadjustdate.ui \
    wrokedtotal.ui \
    systeminfo.ui \
    systemwarn.ui \
    yreferencepoint.ui

RESOURCES += \
    A66-appsrc.qrc

OTHER_FILES +=
