#include "form.h"
#include "ui_form.h"
#include "graphview.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
   // connect(ui->pushButton, SIGNAL(clicked(bool)), SIGNAL(exit()));
}

Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_clicked()
{
}
