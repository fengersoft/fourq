#include "fourqwidget.h"
#include "ui_fourqwidget.h"

FourQWidget::FourQWidget(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::FourQWidget)
{
    ui->setupUi(this);
    m_areas[0].color = QColor(178, 34, 34);
    m_areas[1].color = QColor(210, 105, 30);
    m_areas[2].color = QColor(0, 129, 255);
    m_areas[3].color = QColor(57, 181, 74);

    m_areas[0].caption = "紧急且重要";
    m_areas[0].isEmergency = 1;
    m_areas[0].isImportant = 1;
    m_areas[1].caption = "紧急但不重要";
    m_areas[1].isEmergency = 1;
    m_areas[1].isImportant = 0;
    m_areas[2].caption = "不紧急但重要";
    m_areas[2].isEmergency = 0;
    m_areas[2].isImportant = 1;
    m_areas[3].caption = "不紧急且不重要";
    m_areas[3].isEmergency = 0;
    m_areas[3].isImportant = 0;
    m_mouseDownFlag = false;
    resetCenter();
    setMouseTracking(true);
}

FourQWidget::~FourQWidget()
{
    delete ui;
}

QPoint FourQWidget::centerPoint() const
{
    return m_centerPoint;
}

void FourQWidget::setCenterPoint(const QPoint& centerPoint)
{
    m_centerPoint = centerPoint;
}

void FourQWidget::resetCenter()
{
    m_centerPoint = QPoint(width() / 2, height() / 2);
    update();
}

void FourQWidget::reCalArea()
{
    m_areas[0].areaRect = QRect(m_centerPoint.x(), 0, width(), m_centerPoint.y());
    m_areas[1].areaRect = QRect(m_centerPoint.x(), m_centerPoint.y(), width(), height());
    m_areas[2].areaRect = QRect(0, 0, m_centerPoint.x(), m_centerPoint.y());
    m_areas[3].areaRect = QRect(0, m_centerPoint.y(), m_centerPoint.x(), height());

    m_areas[0].captionArea = QRect(m_centerPoint.x() + 6, 0, 120, 24);
    m_areas[1].captionArea = QRect(m_centerPoint.x() + 6, m_centerPoint.y(), 120, 24);
    m_areas[2].captionArea = QRect(6, 0, 120, 24);
    m_areas[3].captionArea = QRect(6, m_centerPoint.y(), 120, 24);

}

void FourQWidget::clear()
{
    qDeleteAll(items.begin(), items.end());
    items.clear();

}

void FourQWidget::paintEvent(QPaintEvent* event)
{
    reCalArea();
    QPainter painter;
    painter.begin(this);

    for (int i = 0; i < 4; i++)
    {
        painter.save();
        painter.setClipRect(m_areas[i].areaRect);
        painter.setPen(Qt::NoPen);
        painter.setBrush(m_areas[i].color);
        painter.drawRect(m_areas[i].areaRect);
        painter.setPen(Qt::white);
        painter.drawText(m_areas[i].captionArea, Qt::AlignLeft | Qt::AlignVCenter, m_areas[i].caption);
        painter.restore();
    }


    painter.setPen(Qt::white);
    painter.drawLine(0, m_centerPoint.y(), width(), m_centerPoint.y());
    painter.drawLine(m_centerPoint.x(), 0, m_centerPoint.x(), height());
    for (int i = 0; i < 4; i++)
    {
        painter.save();

        int x = m_areas[i].areaRect.left() + 6;
        int y = m_areas[i].areaRect.top() + 30;
        m_areas[i].maxY = y;
        QRect clipRect = QRect(x, y, m_areas[i].areaRect.width() - 6, m_areas[i].areaRect.height() - 30);
        painter.setClipRect(clipRect);
        y -= m_areas[i].top;
        if (y > m_areas[i].maxY)
        {
            y = m_areas[i].maxY;
        }
        qDebug() << y;

        for (int j = 0; j < items.count(); j++)
        {
            FourQWidgetItem* item = items.at(j);
            if ((item->important() == m_areas[i].isImportant) && (item->emergency() == m_areas[i].isEmergency))
            {
                QRect textRc = QRect(x, y, m_areas[i].areaRect.width() - 10, 24);

                painter.drawText(textRc, Qt::AlignLeft | Qt::AlignVCenter,
                                 item->createTime().toString("yyyy-MM-dd hh:mm:ss") + "        " + item->info());
                y += 30;
            }

        }
        painter.restore();


    }
    painter.end();


}

void FourQWidget::mousePressEvent(QMouseEvent* event)
{
    m_mouseDownFlag = true;
    m_mouseDownPoint = mapFromGlobal(this->cursor().pos());

}

void FourQWidget::mouseReleaseEvent(QMouseEvent* event)
{
    m_mouseDownFlag = false;

}

void FourQWidget::mouseDoubleClickEvent(QMouseEvent* event)
{

}

void FourQWidget::mouseMoveEvent(QMouseEvent* event)
{
    if (m_mouseDownFlag)
    {
        QPoint pt = mapFromGlobal(this->cursor().pos());
        int x = pt.x() - m_mouseDownPoint.x();
        int y = pt.y() - m_mouseDownPoint.y();
        m_centerPoint.setX(m_centerPoint.x() + x);
        m_centerPoint.setY(m_centerPoint.y() + y);
        update();
        m_mouseDownPoint = pt;
    }

}

void FourQWidget::wheelEvent(QWheelEvent* event)
{
    int y = event->angleDelta().y();
    QPoint pt = mapFromGlobal(this->cursor().pos());
    for (int i = 0; i < 4; i++)
    {
        if (m_areas[i].areaRect.contains(pt))
        {
            m_areas[i].top -= y;
        }

    }
    update();

}
