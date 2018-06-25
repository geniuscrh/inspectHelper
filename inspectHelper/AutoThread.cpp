#include "AutoThread.h"

AutoThread::AutoThread()
{

}

void AutoThread::my_sleep(int s)
{
    ThreadMsg msg;

    for(int i=0;i<s;i++){
        if(i%10==0){
            msg.setMsgString("等待:"+QString::number(s)+"s,已过"+QString::number(i)+"s");
            emit returnMsg(msg);
        }

        Sleep(1000);
    }

}

void AutoThread::run()
{
    HRESULT r = OleInitialize(0);
    if (r != S_OK && r != S_FALSE)
    {
        qDebug()<<"Qt:初始化Ole失败（error）:"+QString::number((unsigned int)r);
        return;
    }
    ThreadMsg msg;
    int time_rec=0;
    for(;time_rec<1;time_rec++)
    {
        Sleep(1000);
        msg.setMsgType(Thread_SIGNAL_LOAD_SITE);
        msg.setMsgString("加载站点");
        emit returnMsg(msg);

        Sleep(2000);
        msg.setMsgType(Thread_SIGNAL_SIGNIN);
        msg.setMsgString("签到");
        emit returnMsg(msg);

        my_sleep(11*60);
        msg.setMsgType(Thread_SIGNAL_SIGNOUT_1);
        msg.setMsgString("签退");
        emit returnMsg(msg);

        Sleep(10*1000);
        msg.setMsgType(Thread_SIGNAL_SIGNOUT_2);
        msg.setMsgString("签退2");
        emit returnMsg(msg);


        //等待几分钟后在执行
        Sleep(5*60*1000);
    }


    OleUninitialize();
}
