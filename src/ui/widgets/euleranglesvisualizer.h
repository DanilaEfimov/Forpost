#ifndef EULERANGLESVISUALIZER_H
#define EULERANGLESVISUALIZER_H

#include "idatavisualizer.h"
#include "data/eulerangles.h"

#include <QWidget>

namespace Ui {
class EulerAnglesVisualizer;
}

class EulerAnglesVisualizer : public QWidget, public IDataVisualizer<EulerAngles>
{
    Q_OBJECT

    QColor subPageColor = QColor("#F97316");
    QColor addPageColor = QColor("#1C1917");

    bool clickable = true;

    void init();    // initialize gui
    void initConstraits();
    void initGui();

public:
    explicit EulerAnglesVisualizer(QWidget *parent = nullptr);
    virtual ~EulerAnglesVisualizer();

    void write(EulerAngles& out) const override;
    void visualize(const EulerAngles& in) override;

    EulerAngles get() const override;

    QColor getSubPageColor() const;
    void setSubPageColor(const QColor &newSubPageColor);

    QColor getAddPageColor() const;
    void setAddPageColor(const QColor &newAddPageColor);

    bool getClickable() const;
    void setClickable(bool newClickable);

protected:
    void mousePressEvent(QMouseEvent* ev) override;

private:
    Ui::EulerAnglesVisualizer *ui;
};

#endif // EULERANGLESVISUALIZER_H
