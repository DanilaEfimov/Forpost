#include <QApplication>
#include <QMainWindow>

#include "chatview.h"
#include "noisetexteffect.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    ChatView* chView = new ChatView();

    std::unique_ptr<NoiseTextEffect> effect(new NoiseTextEffect());
    effect->addNoiseFlag(NoiseMode::Color);
    effect->addNoiseFlag(NoiseMode::Size);
    effect->addNoiseFlag(NoiseMode::Formats);
    chView->setInputEffect(std::move(effect));

    auto window = new QMainWindow;
    window->setCentralWidget(chView);

    window->resize(600, 600);
    window->show();

    return app.exec();
}
