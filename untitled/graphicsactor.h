#ifndef GRAPHICSACTOR_H
#define GRAPHICSACTOR_H
#include "hpitem.h"
#include "Towers.h"
#include "animatedgraphicsitem.h"
#include <QTimeLine>

class QGraphicsItemAnimation;

class GraphicsActor : public AnimatedGraphicsItem, public HpItem
{
   Q_OBJECT
public:
    explicit GraphicsActor(QObject *parent = 0);
public slots:
    void processKey(AnimationID key);
    void setSprites(AnimationID sprites, bool force = false);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    bool processCollidings(QList<QGraphicsItem *> collidins);
    void onAnimationFinished();

public:
    QTimeLine *m_moveAnimationTimer;
    AnimationID m_currentAction;
    QPointF m_posBeforeCollision;
    QGraphicsRectItem *hp_rect;
    QGraphicsRectItem *Redhp_rect;
    QGraphicsScene *GraphScene;
    HpItem *currentFocusEnemy;
protected:
    const int AnimationPeriodMS = 1000;
    const int SpeedPx = 30;
};

#endif // GRAPHICSACTOR_H
