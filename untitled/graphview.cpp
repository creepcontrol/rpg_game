#include "graphview.h"
#include <QMouseEvent>
#include <QKeyEvent>
#include <QGraphicsScene>
#include "line.h"
#include "graphicsactor.h"
#include "panelitem.h"
#include <QMessageBox>

GraphView::GraphView(int h, int w, QWidget *parent)
    :QGraphicsView(parent), PanelItem(),
      m_scene(0, 0, w, h, this),
      m_isKeyPressed(false)
{
    setScene(&m_scene);
    enemy_actor = new EnemyActor();
    m_scene.addItem(&m_actor);
    m_scene.addItem(enemy_actor);
    m_scene.setSceneRect(0, 0, 900, 900);

    fitInView(m_scene.sceneRect(), Qt::KeepAspectRatio);

    enemy_actor->setPos(m_scene.sceneRect().center().x()-((enemy_actor->pixmap().rect().width())/2),
                   m_scene.sceneRect().center().y()-(enemy_actor->pixmap().rect().height()));
    m_actor.setPos(m_scene.sceneRect().center().x()-((m_actor.pixmap().rect().width())/2),
                   m_scene.sceneRect().center().y());

    // меняем расположение актера если на его месте уже стоит товер
    QPointF currentPos = pos();
    QList<QGraphicsItem *> colliding = m_scene.collidingItems(&m_actor);

    //передаем функции лист, если возвращает false то нельзя двигаться в этот объект
    if (m_actor.processCollidings(colliding) == false) {
        if (m_actor.m_moveAnimationTimer) {
            m_actor.m_moveAnimationTimer->deleteLater();
            m_actor.m_moveAnimationTimer = nullptr;
        }
        m_actor.setSprites(AnimationID::Stay); // остановить
        m_actor.m_currentAction = AnimationID::Stay;

        //m_actor.setPos(m_actor.m_posBeforeCollision);
        m_actor.setPos(100,100);
    }
    else {
        m_actor.m_posBeforeCollision = currentPos;
    }
    panel.AddPanel(&m_scene);
    m_actor.setHpRect(&m_scene,&m_actor,30);
    enemy_actor->setHpRect(&m_scene,enemy_actor,30);
}

/*
Подписываемся на событие нажатия кнопки мыши
 */
void GraphView::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        m_isKeyPressed = true;
    }
}

/*
 Подписываемся на событие передвижение курсора
 */
void GraphView::mouseMoveEvent(QMouseEvent *event) {
    if (m_isKeyPressed) {

    }
}

/*
Подписываемся на событие Отпускание кнопки мыши
 */
void GraphView::mouseReleaseEvent(QMouseEvent *event) {
    QPointF pos = mapToScene(event->pos());
    if (event->button() == Qt::LeftButton) {
        m_isKeyPressed = false;
    }

    QList<QGraphicsItem *> selItems = m_scene.items(pos);
            //m_scene.selectedItems();

    // выбор объекта
    for (QGraphicsItem* itemSel: selItems) {
        // если встречается объект towers
         if (dynamic_cast<towers*> (itemSel)) {
             //открываем менюшку
             m_scene.addItem(&m_about);
             QPointF position;
             m_about.setPos(0,0);
             int he =(m_about.pixmap().height()/100)*30;
             int bot = m_scene.sceneRect().bottom();
             position.setX(m_scene.sceneRect().left());
             position.setY(bot-he);
             m_about.setPos(position);
             // static_cast<towers*>(itemSel)->deleteLater();
            }
         else {m_about.hide();}

        if ((dynamic_cast<QGraphicsRectItem*> (itemSel)) == panel.firstCell) {
            if (enemy_actor->CurHealth > 0)
            {
                m_actor.currentFocusEnemy = enemy_actor;
                m_actor.processKey(AnimationID::Fight);
            }
        }
    }
}

void GraphView::resizeEvent(QResizeEvent *) {
    fitInView(m_scene.sceneRect(), Qt::KeepAspectRatio);
}

/*
 Событие нажатия кнопки клавиатуры
 */
void GraphView::keyPressEvent(QKeyEvent *event) {
    switch(event->key()) {
    case Qt::Key_Down:
       m_actor.processKey(AnimationID::Down);
        break;
    case Qt::Key_Up:
        m_actor.processKey(AnimationID::Up);
        break;
    case Qt::Key_Left:
        m_actor.processKey(AnimationID::Left);
        break;
    case Qt::Key_Right:
        m_actor.processKey(AnimationID::Right);
        break;
    }
}
