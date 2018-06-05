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

    MainPanel = scene->addRect(rect->rect());
    MainPanel->setRect(rect->rect());
    int x = scene->sceneRect().left()+100;
    int y = scene->sceneRect().bottomLeft().y()-height;
    MainPanel->setPos(x,y);
    ChildPanel = scene->addRect(SecRect->rect());
    x = scene->sceneRect().center().x()-(ChildPanel->rect().width()/2);
    y = scene->sceneRect().topRight().y();
    ChildPanel->setPos(x,y);
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

    // добавляем иконку на первую ячейку
    QPixmap *pixmap = new QPixmap(firstCell->rect().width(),firstCell->rect().height());
    pixmap->load(":/game/sword.png");

    QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem();
    pixmapItem->setPixmap(QPixmap (*pixmap));
    pixmapItem->setParentItem(firstCell);  
  //  pixmapItem->setScale(0.05);
    pixmapItem->setPos(0,+10);



 //   pixmapItem->setPos(0,0);
   // rectangle->scene()->addPixmap(pixmapItem->pixmap());

}

void PanelItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
   // QPixmap *pixmap = new QPixmap(":/game/sword.png");
   // painter->drawPixmap(firstCell->rect().toRect(),QPixmap (*pixmap));
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
