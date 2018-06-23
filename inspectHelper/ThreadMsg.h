#ifndef THREADMSG_H
#define THREADMSG_H

#include <QtGui>

class ThreadMsg
{
public:
    ThreadMsg();
    QString getMsgString() const;
    void setMsgString(const QString &value);



    QStringList getMsgStringList() const;
    void setMsgStringList(const QStringList &value);

    int getMsgType() const;
    void setMsgType(int value);



    int getMsgInt() const;
    void setMsgInt(int value);

private :
    int msgType;
    QStringList msgStringList;
    QString msgString;
    int msgInt;
};

#endif // THREADMSG_H
