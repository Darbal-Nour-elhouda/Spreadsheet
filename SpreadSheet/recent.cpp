#include "recent.h"
#include "ui_recent.h"
#include<QTextEdit>

recent::recent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::recent)
{
    ui->setupUi(this);
}

recent::~recent()
{
    delete ui;
}
//QTextEdit* recent::recenttext() const
//{
//    return ui->textEdit;
//}
