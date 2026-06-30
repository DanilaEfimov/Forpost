#include <QApplication>
#include <QMainWindow>

#include "optionswidget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QList<QString> variants = {
        "Right top", "Left top",
        "Right bottom", "Left bottom",
    };
    OptionGroup options(variants);
    OptionsWidget* optWidget = new OptionsWidget(options);

    auto window = new QMainWindow;
    window->setCentralWidget(optWidget);

    window->resize(600, 600);
    window->show();

    return app.exec();
}
