#ifndef PLAYOBJECT_H
#define PLAYOBJECT_H

#include <QObject>


class PlayObject : public QObject
{
    Q_OBJECT
public:
    PlayObject(QObject *parent);
    // 使用 Q_INVOKABLE 来修饰成员函数，目的在于被修饰的成员函数能够被元对象系统所唤起
    // 注：在 JS 中可以使用 JSSendMessage 向 Qt 发送数据 ...
    Q_INVOKABLE void JSSendMessage(QString strParameter, QString str) {
        // 当接收到 JS 发来的数据时，向外部发送消息 ...
        emit SigReceivedMessFromJS(strParameter,str);
    }
    Q_INVOKABLE void JSSendMessage1(QString str) {
        // 当接收到 JS 发来的数据时，向外部发送消息 ...
        SigSendMessageToJS(str);
    }
signals:
    // 当接收到 JS 发来的数据时，向 Qt 其它类发送消息 ...
    void SigReceivedMessFromJS(QString strParameter,QString str);
    // 通过该信号向 JS 发送数据 ...
    void SigSendMessageToJS(QString strParameter);
};

#endif // PLAYOBJECT_H
