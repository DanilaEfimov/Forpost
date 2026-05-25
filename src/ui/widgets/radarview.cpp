#include "radarview.h"
#include "ui_radarview.h"

#include <QPainter>

void RadarView::applyFlags()
{
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setWindowFlags(Qt::FramelessWindowHint);
}

RadarView::RadarView(quint8 circles, quint8 sectors, QColor accentColor, QWidget *parent)
    : QWidget(parent),
    accentColor(accentColor),
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

void RadarView::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    quint16 height = this->height();
    quint16 width = this->width();
    quint16 radius = std::min(width, height) / 2;
    QPoint center = QPoint(width / 2, height / 2);

}
