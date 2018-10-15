#include "AutoThread.h"

AutoThread::AutoThread()
{

}

AutoThread::AutoThread(int inspect_site_num)
{
    this->m_inspect_site_num=inspect_site_num;
}

void AutoThread::my_sleep(int s)
{
    ThreadMsg msg;

    for(int i=0;i<s;i++){
        if(i%30==0){
            msg.setMsgString("等待:"+QString::number(s/60)+"m,已过"+QString::number(i/60)+"m");
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

    for(int i=0;i<m_inspect_site_num;i++)
    {
        Sleep(1000);
        msg.setMsgType(Thread_SIGNAL_LOAD_SITE);
        msg.setMsgString("加载站点");
        emit returnMsg(msg);

        Sleep(2000);
        msg.setMsgType(Thread_SIGNAL_SIGNIN);
        msg.setMsgString("签到");
        emit returnMsg(msg);


        int random_min=(qrand()%5+11)*60;
        my_sleep(random_min);
        msg.setMsgType(Thread_SIGNAL_SIGNOUT_1);
        msg.setMsgString("签退");
        emit returnMsg(msg);

        Sleep(10*1000);
        msg.setMsgType(Thread_SIGNAL_SIGNOUT_2);
        msg.setMsgString("签退2");
        emit returnMsg(msg);

        //等待几分钟后在执行
        random_min=(qrand()%10)*60;
        my_sleep(random_min);
    }


    OleUninitialize();
}
