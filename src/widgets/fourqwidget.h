#ifndef FOURQWIDGET_H
#define FOURQWIDGET_H

#include <QWidget>
#include <QPainter>
#include "fourqwidgetitem.h"
#include <QList>
#include <QWheelEvent>

namespace Ui
{
class FourQWidget;
}
struct FourQWidgetArea
{
    QRect areaRect;
    QRect captionArea;
    QString caption;
    QColor color;
    int isImportant = 0;
    int isEmergency = 0;
    int top = 0;
    int minY;
    int maxY;

};

class FourQWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FourQWidget(QWidget* parent = nullptr);
    ~FourQWidget();

    QPoint centerPoint() const;
    void setCenterPoint(const QPoint& centerPoint);
    void resetCenter();
    void reCalArea();
    QList<FourQWidgetItem*> items;
    void clear();
protected:
    void paintEvent(QPaintEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void mouseDoubleClickEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void wheelEvent(QWheelEvent* event);
private:
    Ui::FourQWidget* ui;
    QPoint m_centerPoint;
    FourQWidgetArea m_areas[4];
    QPoint m_mouseDownPoint;
    bool m_mouseDownFlag;


};

#endif // FOURQWIDGET_H
