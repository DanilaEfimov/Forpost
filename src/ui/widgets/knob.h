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
    float angle;

    static float normalize(float angle);

    void update();

public:
    explicit Knob(QWidget *parent = nullptr);
    ~Knob();

    float getAngle() const;
    void setAngle(float newAngle);

protected:
    void paintEvent(QPaintEvent* ev) override;
    void mousePressEvent(QMouseEvent* ev) override;
    void mouseMoveEvent(QMouseEvent* ev) override;

private:
    Ui::Knob *ui;
};

#endif // KNOB_H
