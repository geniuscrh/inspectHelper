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
protected:
    void run();
signals:
    void returnMsg(ThreadMsg msg);
};

#endif // AUTOTHREAD_H
