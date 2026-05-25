#include <QApplication>
#include <QMainWindow>

#include "radarview.h"
#include "solidrendereffect.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    auto effect = std::make_unique<SolidRenderEffect>(QColor(0, 255, 0, 30));

    auto radar = new RadarView(
        std::move(effect),
        8,
        16,
        Qt::green
        );

    auto window = new QMainWindow;
    window->setCentralWidget(radar);

    window->resize(600, 600);
    window->show();

    return app.exec();
}
