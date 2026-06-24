#include "thememanager.h"

#include <QApplication>
#include <QFile>

const QMap<Theme, const char*> ThemeManager::paths = {
    {Theme::BasicDark, ":/basic_dark.qss"},
    {Theme::BasicLight, ":/basic_light.qss"}
};
Theme ThemeManager::current = Theme::BasicDark;

void ThemeManager::switchTheme(Theme newTheme)
{
    if(ThemeManager::current == newTheme)
        return;

    QFile theme(ThemeManager::paths[newTheme]);
    theme.open(QIODevice::ReadOnly);

    qApp->setStyleSheet(theme.readAll());

    ThemeManager::current = newTheme;

    theme.close();

    emit this->themeSwitched();
}

void ThemeManager::setTheme(Theme newTheme)
{
    QFile theme(ThemeManager::paths[newTheme]);
    theme.open(QIODevice::ReadOnly);

    qApp->setStyleSheet(theme.readAll());

    ThemeManager::current = newTheme;

    theme.close();

    emit this->themeSwitched();
}
