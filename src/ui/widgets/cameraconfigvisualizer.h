#ifndef CAMERACONFIGVISUALIZER_H
#define CAMERACONFIGVISUALIZER_H

#include "idatavisualizer.h"
#include "data/cameraconfig.h"

#include <QWidget>

namespace Ui {
class CameraConfigVisualizer;
}

class CameraConfigVisualizer : public QWidget, public IDataVisualizer<CameraConfig>
{
    Q_OBJECT

public:
    explicit CameraConfigVisualizer(QWidget *parent = nullptr);
    virtual ~CameraConfigVisualizer();

    void write(CameraConfig& out) const override;
    void visualize(const CameraConfig& in) override;

    CameraConfig get() const override;

private:
    Ui::CameraConfigVisualizer *ui;
};

#endif // CAMERACONFIGVISUALIZER_H
