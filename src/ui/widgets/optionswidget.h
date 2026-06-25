#ifndef OPTIONSWIDGET_H
#define OPTIONSWIDGET_H

#include "data/optiongroup.h"
#include "idatavisualizer.h"

#include <QListView>

namespace Ui {
class OptionsWidget;
}

class OptionsWidget : public QListView, public IDataVisualizer<OptionGroup>
{
    Q_OBJECT

    OptionGroup options;

public:
    explicit OptionsWidget(OptionGroup&& options, QWidget *parent = nullptr);
    virtual ~OptionsWidget();

private:
    Ui::OptionsWidget *ui;
};

#endif // OPTIONSWIDGET_H
