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
    qreal mana; // мана
    qreal PAttk; // физическая атака
    qreal MAttk; // магическая атака
    qreal CurHealth; // текущее здоровье
    qreal Pdef; // физ защита
    qreal Mdef; // маг защита
    int strength; // сила
    int agility; // ловкость
    int intelligence; // интеллект
    AnimatedGraphicsItem *MainItem = 0;
    QColor *color;
    QGraphicsTextItem *textCurHealth;

};

#endif // HPITEM_H
