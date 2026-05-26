#include "radarview.h"
#include "ui_radarview.h"

#include <QPainter>

QColor RadarView::getAccentColor() const
{
    return this->accentColor;
}

void RadarView::setAccentColor(const QColor &newAccentColor)
{
    this->accentColor = newAccentColor;
}

quint8 RadarView::getSectors() const
{
    return this->sectors;
}

void RadarView::setSectors(quint8 newSectors)
{
    this->sectors = newSectors;
}

quint8 RadarView::getCircles() const
{
    return this->circles;
}

void RadarView::setCircles(quint8 newCircles)
{
    this->circles = newCircles;
}

QPointF RadarView::intersectEllipse(quint16 ax, quint16 by, double angle)
{
    double rad = qDegreesToRadians(angle);
    double cosA = std::cos(rad);
    double sinA = std::sin(rad);

    double r = 1.0 / std::sqrt(
                   (cosA * cosA) / (ax * ax) +
                   (sinA * sinA) / (by * by)
                   );

    return QPointF(r * cosA, r * sinA);
}

void RadarView::printSectors(QPainter& painter)
{
    if(this->sectors == 0)
        return;

    double angle = 360.0 / this->sectors;
    auto ax = this->width() / 2;
    auto by = this->height() / 2;
    QPointF center = QPointF(ax, by);
    painter.setPen(QPen(this->accentColor));
    for (qsizetype i = 0; i < this->sectors; i++) {
        double rayAngle = angle * i - 90.0;
        QPointF edge = center + this->intersectEllipse(ax, by, rayAngle);
        painter.drawLine(center, edge);
    }
}

void RadarView::printCircles(QPainter &painter)
{
    if(this->circles == 0)
        return;

    auto ax = this->width() / 2;
    auto by = this->height() / 2;
    QPointF center = QPointF(ax, by);
    painter.setPen(QPen(this->accentColor));
    for (qsizetype i = 0; i < this->circles; i++) {
        float aspect = (1.0+i)/this->circles;
        painter.drawEllipse(center, ax * aspect, by * aspect);
    }
}

void RadarView::applyFlags()
{
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setWindowFlags(Qt::FramelessWindowHint);
}

RadarView::RadarView(std::unique_ptr<CircleRenderEffect> effect,
                     quint8 circles,
                     quint8 sectors,
                     QColor accentColor,
                     QWidget *parent)
    : QWidget(parent),
    accentColor(accentColor),
    effect(std::move(effect)),
    sectors(sectors),
    circles(circles),
    ui(new Ui::RadarView)
{
    ui->setupUi(this);
    this->applyFlags();
}

RadarView::~RadarView()
{
    delete ui;
}

void RadarView::setRenderEffect(std::unique_ptr<CircleRenderEffect>&& effect)
{
    this->effect = std::move(effect);
    this->update();
}

void RadarView::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);

    quint16 height = this->height();
    quint16 width = this->width();
    QPoint center = QPoint(width / 2, height / 2);
    Ellipse ellipse(center, height, width);

    this->QWidget::paintEvent(event);

    if(this->effect)
        this->effect->render(painter, ellipse);

    this->printSectors(painter);
    this->printCircles(painter);

    this->update();
}
