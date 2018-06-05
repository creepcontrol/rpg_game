#include "line.h"

Line::Line(const QColor &color, QObject* parent)
    : QGraphicsItemGroup(), QObject(parent),
      m_pen(color), m_brush(color), m_lastPoint(nullptr)
{
    m_pen.setWidth(LineWidth);
}

void Line::addPoint(QPointF point) {
    QPointF radius(EllipseRadius, EllipseRadius);
    if (m_lastPoint) {
        QGraphicsLineItem *line = new QGraphicsLineItem(
                    QLineF(m_lastPoint->pos(), point), this);
        line->setPen(m_pen);
        delete m_lastPoint;
    }
    m_lastPoint = new QGraphicsEllipseItem(QRectF(-radius, radius), this);
    m_lastPoint->setBrush(m_brush);
    m_lastPoint->setPos(point);
}

void Line::removePoint() {
    if (m_lastPoint)
        delete m_lastPoint;
    m_lastPoint = nullptr;
}
