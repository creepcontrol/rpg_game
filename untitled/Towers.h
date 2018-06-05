#ifndef TOWERS_H
#define TOWERS_H

#include "animatedgraphicsitem.h"
#include <QTimeLine>
#include "graphicsactor.h"

class QGraphicsItemAnimation;

class towers : public AnimatedGraphicsItem, public HpItem
{
    Q_OBJECT
public:
    explicit towers(QObject *parent = 0);
public slots:
    void setSprites(AnimationID sprites, bool force = false);
    bool processCollidings(QList<QGraphicsItem *> collidins);
    void OnAnimationFinished();
    void Build(QPointF pos, QGraphicsScene *scene);
protected:

    QTimeLine *m_moveAnimationTimer;
    AnimationID m_currentAction;
private:
    QPointF m_posBeforeCollision;
};

#endif // TOWERS_H
