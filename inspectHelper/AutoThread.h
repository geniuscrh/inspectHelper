#ifndef AUTOTHREAD_H
#define AUTOTHREAD_H

#include <QThread>
#include <QAxObject>
#include <QtGui>
#include <ThreadMsg.h>
#include <windows.h>

class AutoThread  : public QThread
{
    Q_OBJECT
public:
    AutoThread();
    AutoThread(int inspect_site_num);

    static const int Thread_SIGNAL_LOAD_SITE=1001;
    static const int Thread_SIGNAL_SIGNIN=1002;
    static const int Thread_SIGNAL_SIGNOUT_1=1003;
    static const int Thread_SIGNAL_SIGNOUT_2=1004;
private :
    void my_sleep(int s);
    int m_inspect_site_num;

protected:
    void run();

signals:
    void returnMsg(ThreadMsg msg);
};

#endif // AUTOTHREAD_H
