#ifndef GRAPHVIEW_H
#define GRAPHVIEW_H

#include "QGraphicsView"
#include "QGraphicsScene"
#include "QGraphicsEllipseItem"

#include "Towers.h"
#include "graphicsactor.h"
#include "aboutactor.h"
#include "panelitem.h"
#include "enemyactor.h"

class Line;

class GraphView : public QGraphicsView, public PanelItem
{
     Q_OBJECT
public:
    explicit GraphView(int h, int w, QWidget *parent = 0);
public slots:
    void resizeEvent(QResizeEvent *);
protected slots:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
protected:
    QGraphicsScene m_scene;
    GraphicsActor m_actor;
    EnemyActor *enemy_actor;
    towers m_tower;
    towers *m_newTower;
    AboutActor m_about;
    Line *m_line;
    PanelItem panel;
    bool m_isKeyPressed;
};

#endif // GRAPHVIEW_H
