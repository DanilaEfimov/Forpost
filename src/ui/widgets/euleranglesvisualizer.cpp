#include "euleranglesvisualizer.h"
#include "ui_euleranglesvisualizer.h"
#include "data/eulerangles.h"

QColor EulerAnglesVisualizer::getSubPageColor() const
{
    return this->subPageColor;
}

void EulerAnglesVisualizer::setSubPageColor(const QColor &newSubPageColor)
{
    this->subPageColor = newSubPageColor;
}

QColor EulerAnglesVisualizer::getAddPageColor() const
{
    return this->addPageColor;
}

void EulerAnglesVisualizer::setAddPageColor(const QColor &newAddPageColor)
{
    this->addPageColor = newAddPageColor;
}

bool EulerAnglesVisualizer::getClickable() const
{
    return this->clickable;
}

void EulerAnglesVisualizer::setClickable(bool newClickable)
{
    this->clickable = newClickable;
}

void EulerAnglesVisualizer::mousePressEvent(QMouseEvent *ev)
{
    if(this->clickable)
        QWidget::mousePressEvent(ev);
}

void EulerAnglesVisualizer::init()
{
    this->initConstraits();
    this->initGui();
}

void EulerAnglesVisualizer::initConstraits()
{
    constexpr int maxPitch = 180;
    constexpr int minPitch = -180;

    constexpr int maxYaw = 180;
    constexpr int minYaw = -180;

    // sliders
    this->ui->pitchSlider->setMaximum(maxPitch);
    this->ui->pitchSlider->setMinimum(minPitch);

    this->ui->yawSlider->setMaximum(maxYaw);
    this->ui->yawSlider->setMinimum(minYaw);
}

void EulerAnglesVisualizer::initGui()
{
    QPalette palette;
    palette.setColor(QPalette::Accent, this->subPageColor);
    palette.setColor(QPalette::Dark, this->addPageColor);

    this->ui->pitchSlider->setPalette(palette);
    this->ui->yawSlider->setPalette(palette);
}

EulerAnglesVisualizer::EulerAnglesVisualizer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::EulerAnglesVisualizer)
{
    ui->setupUi(this);

    this->init();
}

EulerAnglesVisualizer::~EulerAnglesVisualizer()
{
    delete ui;
}

void EulerAnglesVisualizer::write(EulerAngles& out) const
{
    out.setPitch(this->ui->pitchSlider->value());
    out.setRoll(this->ui->rollKnob->getAngle());
    out.setYaw(this->ui->yawSlider->value());
}

void EulerAnglesVisualizer::visualize(const EulerAngles &in)
{
    this->ui->rollKnob->setAngle(in.getRoll());
    this->ui->pitchSlider->setValue(in.getPitch());
    this->ui->yawSlider->setValue(in.getYaw());

    QWidget::update();
}

EulerAngles EulerAnglesVisualizer::get() const
{
    float roll = this->ui->rollKnob->getAngle();
    float pitch = this->ui->pitchSlider->value();
    float yaw = this->ui->yawSlider->value();

    return EulerAngles(pitch, roll, yaw);
}
