#include "systeminfotip.h"
#include "global.h"
#include <QDebug>


extern "C"{
    #include "canfestival.h"
    #include "canfestivalAPI.h"
    #include "ObjDict.h"
    #include "CanopenDictConfig.h"

SystemInfoTip::SystemInfoTip(QObject *parent) :
    QObject(parent)
{

    list << trUtf8(" X轴") << trUtf8(" Y轴") << trUtf8(" R轴")<<trUtf8(" MT1")<< trUtf8(" 电机离线") << trUtf8(" 电机异常") << trUtf8(" 油泵未启动");
    for(int i =0; i < list.size(); i++)
    {
        errorResult[i].errorId= i;
        errorResult[i].errorName= list.at(i);
        qDebug()<<errorResult[i].errorId<<errorResult[i].errorName;
    }
    //qDebug()<<list.at(4);
}
QString SystemInfoTip::getCurrentErrorStatus(int errorId)
{


//    setMotorOffline(0x01);
//    setMotorOffline(0x02);
//    error = list.last();
////    list.
//    printf("error:%d",error.errorId);
//    return error.errorName;

}
void SystemInfoTip::setMotorOffline(unsigned char nodeId)
{
//    _MOTORERROR error ;
//    if(Get_HeartbetError(nodeId) == 0x01 || motor[nodeId-1].initStatus == 0)
//    {
//       for(int i =0;i<list.length();i++)
//        {
//            errorResult[20]= list.at(i);
//            if(error.errorId == nodeId)
//            return ;
//        }
//       if(nodeId == 0x01)
//        error.errorName = "X轴电机离线";
//       if(nodeId == 0x02)
//        error.errorName = "Y轴电机离线";
//        error.errorId   = nodeId;
//        error.CurError  = true;
//        list.append(error);
//    }
//    else
//    {
//        for(int i =0;i<list.length();i++)
//         {
//             error= list.at(i);
//             if(error.CurError == true)
//             {
//                 list.removeAt(i);
//             }
//         }
//    }

}
//void SystemInfoTip::setMotorError()
//{

//    CurrentReg.Current_MotorTipResult.clear();

//    if(Get_HeartbetError(0x01) == 0x01 || motor[X1_ID-1].initStatus == 0 || XFaultFlag ==true)
//    {

//        MotorTipFlag = true;
//        CurrentReg.Current_MotorTips = Motor1Tip;
//        CurrentReg.Current_MotorTipResult.append(SystemTipsInformation(CurrentReg.Current_MotorTips));
////         QMessageBox::critical(0,QObject::trUtf8("异常"),
////                               trUtf8("1号电机离线"));

//       // qDebug("Motor1");
//    }
//    if(Get_HeartbetError(0x02) == 0x01 || motor[Y1_ID-1].initStatus == 0 || YFaultFlag ==true)
//    {
//        MotorTipFlag = true;
//        CurrentReg.Current_MotorTips = Motor2Tip;
//        CurrentReg.Current_MotorTipResult.append("/").append(SystemTipsInformation(CurrentReg.Current_MotorTips));
////         QMessageBox::critical(0,QObject::trUtf8("异常"),
////                               trUtf8("2号电机离线"));
//          // qDebug("Motor2");
//    }
//    if(Get_HeartbetError(0x04) == 0x01)
//    {
//        MotorTipFlag = true;
//        CurrentReg.Current_MotorTips = MTTip;
//        CurrentReg.Current_MotorTipResult.append("/").append(SystemTipsInformation(CurrentReg.Current_MotorTips));
////         QMessageBox::critical(0,QObject::trUtf8("异常"),
////                               trUtf8("MT离线"));
//       //qDebug("Motor4");
//    }
//    if(RaxisParameter.ENABLE_AXIS == 1)
//    {
//        if(Get_HeartbetError(0x03) == 1 || motor[R1_ID-1].initStatus == 0 || RFaultFlag ==true)
//        {
//            MotorTipFlag = true;
//            CurrentReg.Current_MotorTips = Motor3Tip;
//            CurrentReg.Current_MotorTipResult.append("/").append(SystemTipsInformation(CurrentReg.Current_MotorTips));
//   //         QMessageBox::critical(0,QObject::trUtf8("异常"),
//   //                               trUtf8("3号电机离线"));
//           //qDebug("Motor3");
//        }

//        if( (XFaultFlag ==true) ||  (YFaultFlag ==true) || (RFaultFlag ==true))
//        {
//            MotorTipFlag = true;
//            CurrentReg.Current_MotorTips = MotorErrorTip;
//            CurrentReg.Current_MotorTipResult.append(SystemTipsInformation(CurrentReg.Current_MotorTips));
//            XFaultFlag =false;
//            YFaultFlag =false;
//            RFaultFlag =false;
//        }
//        if((Get_HeartbetError(0x01) == 0x01) ||( Get_HeartbetError(0x02) == 0x01) || (Get_HeartbetError(0x03) == 0x01)  ||  (Get_HeartbetError(0x04) == 0x01) )//||  (Get_HeartbetError(0x03) == 0x01)
//        {
//            MotorTipFlag = true;
//            CurrentReg.Current_MotorTips = OfflineTip;
//            CurrentReg.Current_MotorTipResult.append(SystemTipsInformation(CurrentReg.Current_MotorTips));
//        }


//    }
//    else
//    {
//        if( (XFaultFlag ==true) ||  (YFaultFlag ==true) )
//        {
//            MotorTipFlag = true;
//            CurrentReg.Current_MotorTips = MotorErrorTip;
//            CurrentReg.Current_MotorTipResult.append(SystemTipsInformation(CurrentReg.Current_MotorTips));
//            XFaultFlag =false;
//            YFaultFlag =false;
//        }
//        if((Get_HeartbetError(0x01) == 0x01) ||( Get_HeartbetError(0x02) == 0x01) ||  (Get_HeartbetError(0x04) == 0x01) )//
//        {
//            MotorTipFlag = true;
//            CurrentReg.Current_MotorTips = OfflineTip;
//            CurrentReg.Current_MotorTipResult.append(SystemTipsInformation(CurrentReg.Current_MotorTips));
//        }
//    }




//}
}
