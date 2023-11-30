#include "web.h"
#include <QDebug>

Web::Web(QWidget *parent) : QWebEngineView(parent)
{
    regObject();
}

// 注册通道对象类 ...
void Web::regObject() {
    // 创建 QWebChannel
    QWebChannel *m_wc = new QWebChannel(this->page());
    // 创建 PlayObject
    PlayObject *m_po = new PlayObject(this);
    // 注册 PlayObject 到 QWebChannel 指定 ID 为 context
    m_wc->registerObject(QStringLiteral("context"), m_po);
    // 设置 QWebChannel 到 QWebEngineView
    this->page()->setWebChannel(m_wc);

    // 当 JS 调用 JSSendMessage 时，PlayObject 发送 SigReceivedMessFromJS 信号到 Web
    connect(m_po, &PlayObject::SigReceivedMessFromJS, this, &Web::OnReceiveMessageFromJS);

    // 当 Web 调用 SigSendMessageToJS 时 PlayObject 发送 SigSendMessageToJS 信号到 JS
    connect(this, &Web::SigSendMessageToJS, m_po, &PlayObject::SigSendMessageToJS);
}

// 接收 JS 发来的数据 ... 通过 PlayObject 中 JSSendMessage 中转 ...
void Web::OnReceiveMessageFromJS(QString usr,QString passwd)
{
    qDebug(">>> %s", QString("%1 %2").arg(usr).arg(passwd).toStdString().c_str());
    // 发送数据到 JS ... 通过 PlayObject 中 SigSendMessageToJS 中转 ...
    emit SigSendMessageToJS("ok");
}
