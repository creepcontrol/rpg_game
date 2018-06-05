#include "panelitem.h"
#include <QGraphicsScene>
#include <QPainter>
#include "resize_image.h"

PanelItem::PanelItem()
{
}

/*
 Добавляем панель скиллов на сцену
 */
void PanelItem::AddPanel(QGraphicsScene *scene) {
    int height = 70;
    QGraphicsRectItem *rect = new QGraphicsRectItem(0,0,600,height);
    QGraphicsRectItem *SecRect = new QGraphicsRectItem(0,0,300,height);

    // панель меню
    ChildPanel = scene->addRect(SecRect->rect());
    int x = scene->sceneRect().center().x()-(ChildPanel->rect().width()/2);
    int y = scene->sceneRect().topRight().y();
    ChildPanel->setPos(x,y);
    menuFirstCell  = MenuAddCell(menuFirstCell,  scene,  0);
    menuSecondCell = MenuAddCell(menuSecondCell, scene, 75);
    menuThirdCell  = MenuAddCell(menuThirdCell,  scene, 150);
    menuFourthCell = MenuAddCell(menuFourthCell, scene, 225);

    // панель умений
    MainPanel = scene->addRect(rect->rect());
    MainPanel->setRect(rect->rect());
    x = scene->sceneRect().left()+100;
    y = scene->sceneRect().bottomLeft().y()-height;
    MainPanel->setPos(x,y);

    firstCell = AddCell(firstCell,  scene,  0);
    secondCell = AddCell(secondCell, scene, 60);
    AddCell(thirdCell,  scene, 120);
    AddCell(fourthCell, scene, 180);
    AddCell(fifthCell,  scene, 240);
    AddCell(sixthCell,  scene, 300);
    AddCell(seventhCell,scene, 360);
    AddCell(eighthCell, scene, 420);
    AddCell(ninthCell,  scene, 480);
    AddCell(tenthCell,  scene, 540);

   AddPixmap(":/game/sword.png", firstCell);
   AddPixmap(":/game/actorMenu.png", menuFirstCell);

}

void PanelItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {

}

void PanelItem::AddPixmap(const QString &filename, QGraphicsRectItem *Cell) {
    // добавляем иконку на первую ячейку
    QPixmap *pixmap = new QPixmap(Cell->rect().width(),Cell->rect().height());
    pixmap->load(filename);

    QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem();
    pixmapItem->setPixmap(QPixmap (*pixmap));
    pixmapItem->setParentItem(Cell);
    pixmapItem->setPos(0,+10);
}

/*
Добавляем ячейку в панель меню где Параметры:
1) Rectangle - само свойство ячейки, с которой делаем манипуляции
2) Width - отступ для расположения ячеек
*/
QGraphicsRectItem* PanelItem::MenuAddCell(QGraphicsRectItem *rectangle, QGraphicsScene *scene, int width) {
    int height = 70;
    QGraphicsRectItem *ChildRect = new QGraphicsRectItem(0,0,75,height);
    rectangle = scene->addRect(ChildRect->rect());
    rectangle->setParentItem(ChildPanel);
    rectangle->setRect(ChildRect->rect());
    rectangle->setPos(ChildPanel->rect().left()+width,ChildPanel->rect().top());
    return rectangle;
}

/*
Добавляем ячейку в панель где Параметры:
1) Rectangle - само свойство ячейки, с которой делаем манипуляции
2) Width - отступ для расположения ячеек
*/
QGraphicsRectItem* PanelItem::AddCell(QGraphicsRectItem *rectangle, QGraphicsScene *scene, int width) {
    int height = 70;
    QGraphicsRectItem *ChildRect = new QGraphicsRectItem(0,0,60,height);
    rectangle = scene->addRect(ChildRect->rect());
    rectangle->setParentItem(MainPanel);
    rectangle->setRect(ChildRect->rect());
    rectangle->setPos(MainPanel->rect().left()+width,MainPanel->rect().top());
    return rectangle;
}
