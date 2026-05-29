#include <QApplication>
#include <QMainWindow>

#include "radarview.h"
#include "radiansweepeffect.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    auto effect = std::make_unique<RadianSweepEffect>(QColor(0, 255, 0, 120), 0.008);
    effect->setWidth(4);

    auto radar = new RadarView(
        6,
        12,
        Qt::white
        );
    radar->setRenderEffect(std::move(effect));

    RadarTarget t1;
    t1.id = 1;
    t1.angle = 45.0;
    t1.distance = 0.4;
    t1.velocityAngle = 90.0;
    t1.rotateSpeed = 0.002;
    t1.movingSpeed = 0.000002;
    t1.type = TargetType::Enimy;
    t1.label = "Bogey-1";

    RadarTarget t2;
    t2.id = 2;
    t2.angle = 190.0;
    t2.distance = 0.65;
    t2.velocityAngle = 340.0;
    t2.rotateSpeed = -0.005;
    t2.movingSpeed = 0.000001;
    t2.type = TargetType::Friend;
    t2.label = "Alpha-2";

    RadarTarget t3;
    t3.id = 3;
    t3.angle = 300.0;
    t3.distance = 0.3;
    t3.velocityAngle = 0.0;
    t3.rotateSpeed = 0.0;
    t3.movingSpeed = 0.0;
    t3.type = TargetType::Neutral;
    t3.label = "UNK-3";

    radar->addTarget(t1);
    radar->addTarget(t2);
    radar->addTarget(t3);

    auto window = new QMainWindow;
    window->setCentralWidget(radar);

    window->resize(600, 600);
    window->show();

    return app.exec();
}
