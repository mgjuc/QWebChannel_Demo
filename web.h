#ifndef WEB_H
#define WEB_H

#include <QWebEngineView>
#include <QWebChannel>
#include "playobject.h"

class Web : public QWebEngineView
{
    Q_OBJECT
public:
    Web(QWidget *parent = 0);
    // 注册
    void regObject();
public slots:
    // 接收
    void OnReceiveMessageFromJS(QString usr,QString passwd);
signals:
    // 发送
    void SigSendMessageToJS(QString strParameter);
};

#endif // WEB_H
