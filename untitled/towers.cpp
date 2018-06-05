#include "Towers.h"
#include "animatedgraphicsitem.h"
#include "QGraphicsItemAnimation"
#include "QGraphicsScene"
#include "graphicsactor.h"
#include "QMessageBox"

towers::towers(QObject *parent)
    : AnimatedGraphicsItem(parent), HpItem(),
      m_moveAnimationTimer(nullptr),m_currentAction(AnimationID::Tower_Build)
{
    setScale(0.3);
    setSprites(m_currentAction,true);
}

void towers::setSprites(AnimationID sprites, bool force) {
    if (force || sprites != m_currentAction) {
        animation(sprites,Mode::Loop, true);
    }
}

void towers::Build(QPointF pos, QGraphicsScene *scene) {
    // если объектов на этом месте нет, то добавляем здание
    scene->addItem(this);
    this->setPos(pos);
    QList<QGraphicsItem *> colliding = scene->collidingItems(this);
    if (processCollidings(colliding) == false) {
        if (m_moveAnimationTimer) {
            m_moveAnimationTimer->deleteLater();
            m_moveAnimationTimer = nullptr;
        }
        this->deleteLater();
    }
}

void towers::OnAnimationFinished() {
    // здесь конец анимации
}

// функция возвращает признак существования элемента
bool towers::processCollidings(QList<QGraphicsItem *> collidins) {
   bool can_move = true;
   for (QGraphicsItem* item: collidins) {
       // если встречается объект towers
       if (dynamic_cast<towers*> (item)) {
           can_move = false;
       }
   }
   return can_move;
}


