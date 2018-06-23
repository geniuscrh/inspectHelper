#include "AutoThread.h"

AutoThread::AutoThread()
{

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
    for(;time_rec<=10*60;time_rec++)
    {
        Sleep(1000);
        msg.setMsgType(1);
        msg.setMsgString("开发");
        emit returnMsg(msg);
    }





    OleUninitialize();
}
