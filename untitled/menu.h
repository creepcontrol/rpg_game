#ifndef MENU_H
#define MENU_H

#include "QWidget"

namespace Ui {
class Menu;
}
class Menu : public QWidget
{
    Q_OBJECT
public:
    explicit Menu(QWidget *parent = 0);
    ~Menu();
signals:
    void exit();
private slots:
    void on_pushButton_clicked();

private:
    Ui::Menu *ui;
};

#endif // MENU_H
