#include <QApplication>
#include <QMainWindow>

#include "euleranglesvisualizer.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    EulerAnglesVisualizer* av = new EulerAnglesVisualizer;

    auto window = new QMainWindow;
    window->setCentralWidget(av);

    window->resize(600, 600);
    window->show();

    return app.exec();
}
