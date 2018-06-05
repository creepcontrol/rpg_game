#include "graphicsactor.h"
#include "animatedgraphicsitem.h"
#include "QGraphicsItemAnimation"
#include "Towers.h"
#include "QGraphicsScene"
#include <QMessageBox>

/*класс основного персонажа
 Наследование:
 1) AnimatedGraphicsItem(parent) стандартный класс Qt анимационного объекта
 2) HpItem() созданный класс для работы с индикатором здоровья у объекта
 Тело конструктора:
 1) setScale() - назначает объекту коэффициент масштаба на сцене
 2) setSprites() - устанавливает объект в положение Stay
*/
GraphicsActor::GraphicsActor(QObject *parent)
    : AnimatedGraphicsItem(parent),HpItem(),
      m_moveAnimationTimer(nullptr), m_currentAction(AnimationID::Up)
{
  //  setScale(0.3);
    setSprites(m_currentAction,true);
    health = 500;
    PAttk = 100;
}

void GraphicsActor::setSprites(AnimationID sprites, bool force) {
    if (force || sprites != m_currentAction) {
        animation(sprites, Mode::Loop, true);
    }
}
/*
 Функция завершения анимации, привязана к завершению таймера
 Если текущее состояние объекта - БОЙ, то наносим урон врагу
 */
void GraphicsActor::onAnimationFinished() {
    if (m_currentAction == AnimationID::Fight) {
           int curHP = currentFocusEnemy->lessHpRect(PAttk);
    }
    processKey(AnimationID::Stay);
    //processKey(m_currentAction);
}
/*
 Функция возвращает признак столкновения актёра с другими объектами
 */

bool GraphicsActor::processCollidings(QList<QGraphicsItem *> collidins) {
   bool can_move = true;
   for (QGraphicsItem* item: collidins) {
       // если встречается объект towers
       if (dynamic_cast<towers*> (item)) {
           can_move = false;
           currentFocusEnemy = dynamic_cast<towers*>(item);
       }
   }
   return can_move;
}

/*
 Подписываемся на стандартное событие отрисовки объекта, при обнаружении
 коллизий начинаем сражаться
 */
void GraphicsActor::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
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
void GraphicsActor::processKey(AnimationID action) {

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

