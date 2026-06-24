#ifndef KNOB_H
#define KNOB_H

#include <QWidget>

namespace Ui {
class Knob;
}

class Knob : public QWidget
{
    Q_OBJECT

    QPoint lastPos;
    QColor borderColor = QColor("#F97316");
    QColor directionPointerColor = QColor("#FB923C");
    QColor effectColor = QColor("#FDBA74");
    QColor backgroundColor = QColor("#1C1917");
    int borderWidth = 3;
    int arcWidth = 3;

    float angle;

    static float normalize(float angle);

    void drawDirectionPointer(QPainter& p);
    void drawRotatingEffect(QPainter& p);
    void drawBorders(QPainter& p);
    void drawBackground(QPainter& p);

    float mouseAngle(const QPoint& pos) const;
    int radius() const;
    QPoint normvec() const;
    QPoint directionPointerCenter() const;
    int directionPointerRadius() const;

public:
    explicit Knob(QWidget *parent = nullptr);
    virtual ~Knob();

    float getAngle() const;
    void setAngle(float newAngle);

    QColor getBorderColor() const;
    void setBorderColor(const QColor &newBorderColor);

    QColor getDirectionPointerColor() const;
    void setDirectionPointerColor(const QColor &newDirectionPointerColor);

    QColor getEffectColor() const;
    void setEffectColor(const QColor &newEffectColor);

    QColor getBackgroundColor() const;
    void setBackgroundColor(const QColor &newBackgroundColor);

    int getBorderWidth() const;
    void setBorderWidth(int newBorderWidth);

    int getArcWidth() const;
    void setArcWidth(int newArcWidth);

protected:
    void paintEvent(QPaintEvent* ev) override;
    void mousePressEvent(QMouseEvent* ev) override;
    void mouseMoveEvent(QMouseEvent* ev) override;

private:
    Ui::Knob *ui;
};

#endif // KNOB_H
