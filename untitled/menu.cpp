#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Menu)
{

    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked(bool)), SIGNAL(exit()));
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_pushButton_clicked()
{

}
