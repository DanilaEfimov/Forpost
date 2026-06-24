#ifndef THEMEMANAGER_H
#define THEMEMANAGER_H

#include <QMap>
#include <QObject>

enum class Theme {
    BasicDark,
    BasicLight,
};

class ThemeManager : public QObject
{
    Q_OBJECT

    static const QMap<Theme, const char*> paths;
    static Theme current;

public:
    void switchTheme(Theme newTheme);
    void setTheme(Theme newTheme);

signals:
    void themeSwitched();
};

#endif // THEMEMANAGER_H
