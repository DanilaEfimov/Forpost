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

public:
    explicit EulerAnglesVisualizer(QWidget *parent = nullptr);
    ~EulerAnglesVisualizer();

    void write(EulerAngles& out) const override;

private:
    Ui::EulerAnglesVisualizer *ui;
};

#endif // EULERANGLESVISUALIZER_H
