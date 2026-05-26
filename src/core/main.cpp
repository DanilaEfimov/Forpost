#include <QApplication>
#include <QMainWindow>

#include "radarview.h"
#include "pingeffect.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    auto effect = std::make_unique<PingEffect>(QColor(0, 255, 0, 120), 2000, 500);

    auto radar = new RadarView(
        std::move(effect),
        6,
        12,
        Qt::white
        );

    auto window = new QMainWindow;
    window->setCentralWidget(radar);

    window->resize(600, 600);
    window->show();

    return app.exec();
}
