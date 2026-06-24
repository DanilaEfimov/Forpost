#include "knob.h"
#include "ui_knob.h"

#include <QPainter>
#include <QPaintEvent>

float Knob::getAngle() const
{
    return this->angle;
}

void Knob::setAngle(float newAngle)
{
    this->angle = newAngle;
}

void Knob::paintEvent(QPaintEvent* ev)
{
    QWidget::paintEvent(ev);

    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);

    this->drawBackground(p);
    this->drawBorders(p);
    this->drawRotatingEffect(p);
    this->drawDirectionPointer(p);
}

void Knob::mousePressEvent(QMouseEvent *ev)
{
    if(ev->button() == Qt::LeftButton)
        this->lastPos = ev->pos();
}

void Knob::mouseMoveEvent(QMouseEvent *ev)
{
    if(!(ev->buttons() & Qt::LeftButton))
        return;

    float prev = this->mouseAngle(this->lastPos);
    float curr = this->mouseAngle(ev->pos());

    float delta = curr - prev;

    if(delta > 180.f)
        delta -= 360.f;

    if(delta < -180.f)
        delta += 360.f;

    this->angle = this->normalize(this->angle + delta);
    this->lastPos = ev->pos();

    this->update();
}

QColor Knob::getBorderColor() const
{
    return this->borderColor;
}

void Knob::setBorderColor(const QColor &newBorderColor)
{
    this->borderColor = newBorderColor;
}

QColor Knob::getDirectionPointerColor() const
{
    return this->directionPointerColor;
}

void Knob::setDirectionPointerColor(const QColor &newDirectionPointerColor)
{
    this->directionPointerColor = newDirectionPointerColor;
}

QColor Knob::getEffectColor() const
{
    return this->effectColor;
}

void Knob::setEffectColor(const QColor &newEffectColor)
{
    this->effectColor = newEffectColor;
}

QColor Knob::getBackgroundColor() const
{
    return this->backgroundColor;
}

void Knob::setBackgroundColor(const QColor &newBackgroundColor)
{
    this->backgroundColor = newBackgroundColor;
}

int Knob::getBorderWidth() const
{
    return this->borderWidth;
}

void Knob::setBorderWidth(int newBorderWidth)
{
    this->borderWidth = newBorderWidth;
}

int Knob::getArcWidth() const
{
    return this->arcWidth;
}

void Knob::setArcWidth(int newArcWidth)
{
    this->arcWidth = newArcWidth;
}

float Knob::normalize(float angle)
{
    return std::fmod(angle, 360.f);
}

void Knob::drawDirectionPointer(QPainter &p)
{
    QPoint center = this->directionPointerCenter();

    int r = this->radius();
    constexpr float pointerPart = 0.15f;
    int radius = r * pointerPart;

    p.setBrush(this->directionPointerColor);
    p.drawEllipse(center, radius, radius);

    p.setBrush(Qt::NoBrush);
    p.setPen(this->borderColor);
    p.drawEllipse(center, radius, radius);
}

void Knob::drawRotatingEffect(QPainter &p)
{
    QPen pen(this->effectColor);
    pen.setWidth(this->arcWidth);

    p.setPen(pen);
    p.setBrush(Qt::NoBrush);

    int r = this->directionPointerRadius();
    QPoint center = this->rect().center();
    QRect area = QRect(
        center.x() - r,
        center.y() - r,
        2 * r,
        2 * r
    );

    p.drawArc(area, 0, this->angle * 16);
}

void Knob::drawBorders(QPainter &p)
{
    QPoint center = this->rect().center();

    int r = this->radius();

    QPen pen(this->borderColor);
    pen.setWidth(this->borderWidth);
    p.setBrush(Qt::NoBrush);

    p.drawEllipse(center, r, r);
}

void Knob::drawBackground(QPainter &p)
{
    QPoint center = this->rect().center();

    int r = this->radius();

    p.setBrush(this->backgroundColor);
    p.setPen(Qt::NoPen);

    p.drawEllipse(center, r, r);
}

float Knob::mouseAngle(const QPoint& pos) const
{
    QPoint center = this->rect().center();

    float dx = pos.x() - center.x();
    float dy = -(pos.y() - center.y());

    return qRadiansToDegrees(std::atan2(dy, dx));
}

int Knob::radius() const
{
    int r = std::min(this->height(), this->width()) * 0.45f;

    return r;
}

QPoint Knob::normvec() const
{
    QPoint center = this->rect().center();

    float dx = this->lastPos.x() - center.x();
    float dy = -(this->lastPos.y() - center.y());
    float norm = std::hypot(dx, dy);

    return QPoint(dx / norm, dy / norm);
}

QPoint Knob::directionPointerCenter() const
{
    int r = this->directionPointerRadius();

    QPoint center = this->rect().center();
    float angle = this->angle;

    float rad = qDegreesToRadians(angle);
    float dx = r * std::cos(rad);
    float dy = -r * std::sin(rad);

    return QPoint(center.x() + dx, center.y() + dy);
}

int Knob::directionPointerRadius() const
{
    int r = this->radius();

    constexpr float part = 0.6;   // 0..1 |pointer center| / |widget center|

    return r * part;
}

Knob::Knob(QWidget *parent)
    : QWidget(parent)
    , lastPos(0, 0)
    , ui(new Ui::Knob)
{
    ui->setupUi(this);
}

Knob::~Knob()
{
    delete ui;
}
