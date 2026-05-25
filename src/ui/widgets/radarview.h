#ifndef RADARVIEW_H
#define RADARVIEW_H

#include <QWidget>

namespace Ui {
class RadarView;
}

class RadarView : public QWidget
{
    Q_OBJECT

    QColor accentColor;
    quint8 sectors;
    quint8 circles;

    void applyFlags();

public:
    explicit RadarView(quint8 circles, quint8 sectors, QColor accentColor, QWidget *parent = nullptr);
    ~RadarView();

private:
    Ui::RadarView* ui;

protected:
    void paintEvent(QPaintEvent* event) override;
};

#endif // RADARVIEW_H
