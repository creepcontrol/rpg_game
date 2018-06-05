#ifndef PANELITEM_H
#define PANELITEM_H
#include <QGraphicsItem>

class PanelItem
{
public:
    PanelItem();
    QGraphicsRectItem* AddCell(QGraphicsRectItem *rectangle, QGraphicsScene *scene,int width);
    void AddPanel(QGraphicsScene *scene);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QGraphicsRectItem *MainPanel;
    QGraphicsRectItem *firstCell;
    QGraphicsRectItem *secondCell;
    QGraphicsRectItem *thirdCell;
    QGraphicsRectItem *fourthCell;
    QGraphicsRectItem *fifthCell;
    QGraphicsRectItem *sixthCell;
    QGraphicsRectItem *seventhCell;
    QGraphicsRectItem *eighthCell;
    QGraphicsRectItem *ninthCell;
    QGraphicsRectItem *tenthCell;
    QGraphicsRectItem *ChildPanel;
};

#endif // PANELITEM_H
