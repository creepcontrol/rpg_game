#include "enemyactor.h"
#include "animatedgraphicsitem.h"
#include "QGraphicsItemAnimation"
#include "QGraphicsScene"

EnemyActor::EnemyActor(QObject *parent)
    : AnimatedGraphicsItem(parent),HpItem(),
      m_moveAnimationTimer(nullptr), m_currentAction(AnimationID::Stay)
{
    setSprites(m_currentAction, true);
    health = 500;
}

void EnemyActor::setSprites(AnimationID sprites, bool force) {
    if (force || sprites != m_currentAction) {
        animation(sprites, Mode::Loop, true);
    }
}

void EnemyActor::onAnimationFinished() {
    processKey(m_currentAction);
}

bool EnemyActor::processCollidings(QList<QGraphicsItem *> collidins) {
    bool can_move = true;
    for (QGraphicsItem* item: collidins) {

       }
       return can_move;
}

/*
 Подписываемся на стандартное событие отрисовки объекта, при обнаружении
 коллизий начинаем сражаться
 */
void EnemyActor::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QPointF currentPos = pos();
    QList<QGraphicsItem *> colliding = scene()->collidingItems(this);
    //передаем функции лист, если возвращает false то нельзя двигаться в этот объект
    if (processCollidings(colliding) == false) {
        setSprites(AnimationID::Fight);
        m_currentAction = AnimationID::Fight;
        setPos(m_posBeforeCollision);
    }
    else {
        m_posBeforeCollision = currentPos;
    }

    AnimatedGraphicsItem::paint(painter, option, widget);
}

/*
Подписывается на кнопки клавиатуры и двигаем актёра
 */
void EnemyActor::processKey(AnimationID action) {

    if ((m_currentAction == AnimationID::Down && action == AnimationID::Up)
            ) {
        action = AnimationID::Stay;
    }

    setSprites(action);

    // moving
    if (m_moveAnimationTimer) {
        m_moveAnimationTimer->stop();
        delete m_moveAnimationTimer;
        m_moveAnimationTimer =  nullptr;
    }

    if (action != AnimationID::Stay) {
        m_moveAnimationTimer = new QTimeLine(AnimationPeriodMS, this);

        auto moveAnimation = new QGraphicsItemAnimation(m_moveAnimationTimer);
        connect(m_moveAnimationTimer, SIGNAL(finished()),
                this, SLOT(onAnimationFinished()));
        connect(m_moveAnimationTimer, SIGNAL(valueChanged(qreal)),
                this, SIGNAL(moved()));

        moveAnimation->setItem(this);
        moveAnimation->setTimeLine(m_moveAnimationTimer);

        switch(action) {
          default:
            break;
          case AnimationID::Right:
              moveAnimation->setPosAt(1.0, pos() + QPointF(SpeedPx, 0));
              break;
          case AnimationID::Left:
              moveAnimation->setPosAt(1.0, pos() + QPointF(-SpeedPx, 0));
              break;
          case AnimationID::Up:
              moveAnimation->setPosAt(1.0, pos() + QPointF(0, -SpeedPx));
              break;
          case AnimationID::Down:
              moveAnimation->setPosAt(1.0,pos() + QPointF(0, SpeedPx));
              break;
          case AnimationID::Stay:
              break;
        }

        m_moveAnimationTimer->start();
    }
    m_currentAction = action;
}
