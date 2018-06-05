#ifndef ABOUTACTOR_H
#define ABOUTACTOR_H

#include "animatedgraphicsitem.h"
#include <QTimeLine>
#include "graphicsactor.h"

class QGraphicsItemAnimation;

class AboutActor : public AnimatedGraphicsItem
{
    Q_OBJECT
public:
    explicit AboutActor(QObject *parent = 0);
public slots:
    void setSprites(AnimationID sprites, bool force = false);
  //  bool processCollidings(QList<QGraphicsItem *> collidins);
    void OnAnimationFinished();
protected:
    QTimeLine *m_moveAnimationTimer;
    AnimationID m_currentAction;
};

#endif // ABOUTACTOR_H
