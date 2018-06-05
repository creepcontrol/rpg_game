#ifndef LINE_H
#define LINE_H

#include <QObject>
#include <QGraphicsItemGroup>
#include <QPen>
#include <QBrush>

class Line : public QGraphicsItemGroup, public QObject
{
    const int EllipseRadius = 3;
    const int LineWidth = 1;

    QPen m_pen;
    QBrush m_brush;
public:
    Line(const QColor &color, QObject *parent = 0);
    void removePoint();
public slots:
    void addPoint(QPointF point);
protected:
    QGraphicsEllipseItem *m_lastPoint;
};

#endif // LINE_H
