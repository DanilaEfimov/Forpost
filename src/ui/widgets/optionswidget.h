#ifndef OPTIONSWIDGET_H
#define OPTIONSWIDGET_H

#include <QListView>

namespace Ui {
class OptionsWidget;
}

class OptionsWidget : public QListView
{
    Q_OBJECT

public:
    explicit OptionsWidget(QWidget *parent = nullptr);
    ~OptionsWidget();

private:
    Ui::OptionsWidget *ui;
};

#endif // OPTIONSWIDGET_H
