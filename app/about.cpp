#include "about.h"
#include "ui_about.h"
#include <QPixmap>

about::about(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::about)
{
    ui->setupUi(this);
    QPixmap pix(":/imgs/logo");

    ui->label_2->setPixmap(pix.scaled(200,200,Qt::KeepAspectRatio));
}

about::~about()
{
    delete ui;
}
