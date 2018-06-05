#ifndef ENEMYACTOR_H
#define ENEMYACTOR_H
#include "animatedgraphicsitem.h"
#include "hpitem.h"
#include <QTimeLine>

class QGraphicsItemAnimation;

class EnemyActor : public AnimatedGraphicsItem, public HpItem
{
  Q_OBJECT
public:
    explicit EnemyActor(QObject *parent = 0);
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
protected:
    const int AnimationPeriodMS = 1000;
    const int SpeedPx = 30;
};

#endif // ENEMYACTOR_H
