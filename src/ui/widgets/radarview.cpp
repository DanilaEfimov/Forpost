#include "radarview.h"
#include "ui_radarview.h"

#include <QPainter>

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

    this->update();
}
