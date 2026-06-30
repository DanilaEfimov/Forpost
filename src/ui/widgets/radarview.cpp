#include "radarview.h"
#include "ui_radarview.h"

#include <QPainter>
#include <QMouseEvent>
#include <cmath>

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

void RadarView::printTargets(QPainter& painter)
{
    auto ax = this->width() / 2;
    auto by = this->height() / 2;
    QPointF center = QPointF(ax, by);

    for(auto& t : this->targets){
        this->printTarget(painter, t, center);
    }
}

void RadarView::printTarget(QPainter &painter, const RadarTarget &t, QPointF center)
{
    constexpr double TARGET_RADIUS = 5;

    QBrush brush(t.markColorByType());
    painter.setBrush(brush);

    QPointF pos = t.getPos(center);
    painter.drawEllipse(pos, TARGET_RADIUS, TARGET_RADIUS);

    QPen pen(Qt::white);
    painter.setPen(pen);
    painter.drawEllipse(pos, TARGET_RADIUS + 2, TARGET_RADIUS + 2);
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
    painter.setBrush(Qt::NoBrush);
    painter.setFont(this->font);

    for (qsizetype i = 0; i < this->sectors; i++) {
        double rayAngle = angle * i - 90.0;
        QPointF edge = center + this->intersectEllipse(ax, by, rayAngle);
        painter.drawLine(center, edge);
        painter.drawText(edge, QString("%1").arg(i+1));
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
    painter.setFont(this->font);

    for (qsizetype i = 0; i < this->circles; i++) {
        float aspect = (1.0+i)/this->circles;
        painter.drawEllipse(center, ax * aspect, by * aspect);
        painter.drawText(
            QPoint(center.x() + ax * aspect, center.y()),
            QString("%1").arg(i+1)
        );
    }
}

void RadarView::mousePressEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
        this->sectors = std::max((quint8)1, --this->sectors);

    if(event->button() == Qt::RightButton)
        this->sectors++;
}

QFont RadarView::getFont() const
{
    return this->font;
}

void RadarView::setFont(const QFont &newFont)
{
    this->font = newFont;
}

void RadarView::applyFlags()
{
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setWindowFlags(Qt::FramelessWindowHint);
}

RadarView::RadarView(quint8 circles,
                     quint8 sectors,
                     QColor accentColor,
                     QWidget *parent)
    : QWidget(parent),
    accentColor(accentColor),
    effect(nullptr),
    sectors(sectors),
    circles(circles),
    ui(new Ui::RadarView)
{
    ui->setupUi(this);
    this->applyFlags();

    QFont font;
    font.setPointSize(14);
    font.setBold(true);
    this->setFont(font);
}

RadarView::~RadarView()
{
    delete ui;
}

void RadarView::addTarget(const RadarTarget& target)
{
    if(!this->contains(target.id))
        this->targets.append(target);
}

bool RadarView::contains(int id) const
{
    for(const RadarTarget& t : this->targets)
        if(t.id == id)
            return true;

    return false;
}

std::optional<RadarTarget> RadarView::getTarget(int id) const
{
    for(const RadarTarget& t : this->targets)
        if(id == t.id)
            return t;

    return std::nullopt;
}

void RadarView::removeTarget(int id)
{
    this->targets.removeIf([id](const RadarTarget& t){
        return t.id == id;
    });
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
        this->effect->render(painter, {ellipse, {0,0}});

    this->printSectors(painter);
    this->printCircles(painter);
    this->printTargets(painter);

    this->update();
}

QPointF RadarTarget::getPos(const QPointF& center) const
{
    auto dx = center.x()*this->distance * std::cos(this->angle);
    auto dy = center.y()*this->distance * std::sin(this->angle);

    return QPointF(center.x() + dx, center.y() + dy);
}

QColor RadarTarget::markColorByType() const noexcept
{
    switch(this->type)
    {
        case TargetType::Friend: return QColor(Qt::green);
        case TargetType::Enimy: return QColor(Qt::red);
        case TargetType::Neutral: return QColor(Qt::blue);
    default:
        return QColor(Qt::white);
    }
}

void RadarTarget::move()
{
    this->angle += this->rotateSpeed;
    this->distance += this->movingSpeed;
}
