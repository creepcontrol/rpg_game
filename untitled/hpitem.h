#ifndef HPITEM_H
#define HPITEM_H
#include <QGraphicsItem>
#include <QGraphicsScene>
#include "animatedgraphicsitem.h"

class HpItem
{

public:
    HpItem();    
    void setHpRect(QGraphicsScene *scene, AnimatedGraphicsItem *item, int height);
    int lessHpRect(qreal value);
    QGraphicsRectItem *hp_rect;
    QGraphicsRectItem *Redhp_rect;
    qreal health; // количество здоровья
    qreal PAttk; // физическая атака
    qreal CurHealth; // текущее здоровье
    AnimatedGraphicsItem *MainItem = 0;
    QColor *color;
    QGraphicsTextItem *textCurHealth;

};

#endif // HPITEM_H
