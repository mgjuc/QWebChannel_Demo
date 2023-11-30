#include "widget.h"
#include "ui_widget.h"
#include "web.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    Web* web = new Web(this);
    ui->setupUi(this);
    ui->gridLayout->addWidget(web);
    web->setUrl(QUrl("qrc:/webchanel.html"));
}

Widget::~Widget()
{
    delete ui;
}

