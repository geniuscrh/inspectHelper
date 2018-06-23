#include "ThreadMsg.h"



ThreadMsg::ThreadMsg()
{

}

QString ThreadMsg::getMsgString() const
{
    return msgString;
}

void ThreadMsg::setMsgString(const QString &value)
{
    msgString = value;
}



QStringList ThreadMsg::getMsgStringList() const
{
    return msgStringList;
}

void ThreadMsg::setMsgStringList(const QStringList &value)
{
    msgStringList = value;
}

int ThreadMsg::getMsgType() const
{
    return msgType;
}

void ThreadMsg::setMsgType(int value)
{
    msgType = value;
}

int ThreadMsg::getMsgInt() const
{
    return msgInt;
}

void ThreadMsg::setMsgInt(int value)
{
    msgInt = value;
}

