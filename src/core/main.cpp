#include <QApplication>
#include <QMainWindow>

#include "chatview.h"
#include "solidtextcoloreffect.h"
#include "thememanager.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    ThemeManager themeManager;
    themeManager.setTheme(Theme::BasicDark);

    ChatView* chView = new ChatView();

    std::unique_ptr<SolidTextColorEffect> effect(new SolidTextColorEffect(MessageType::Error));
    chView->setInputEffect(std::move(effect));

    auto window = new QMainWindow;
    window->setCentralWidget(chView);

    window->resize(600, 600);
    window->show();

    return app.exec();
}
