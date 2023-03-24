#ifndef CLIPRECT_H
#define CLIPRECT_H

#include <QGraphicsRectItem>

class ClipRect : public QGraphicsRectItem
{
public:
    explicit ClipRect();

    // QGraphicsItem interface
private:
    bool m_mousePressed;
    QPointF m_startPos;
    QPointF m_startClipPos;
    qreal m_clipPos;
    QPointF m_mouseDelta;

    double trackWidth = 60;
    qreal clipWidth;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    // QGraphicsItem interface
public:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // CLIPRECT_H
