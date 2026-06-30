#ifndef OPTIONSWIDGET_H
#define OPTIONSWIDGET_H

#include "data/optiongroup.h"
#include "idatavisualizer.h"

#include <QListView>

class OptionsWidget : public QListView, public IDataVisualizer<OptionGroup>
{
    Q_OBJECT

    OptionGroup options;

public:
    explicit OptionsWidget(QWidget* parent = nullptr);
    explicit OptionsWidget(OptionGroup&& options, QWidget *parent = nullptr);
    explicit OptionsWidget(const OptionGroup& option, QWidget* parent = nullptr);
    virtual ~OptionsWidget();

    void write(OptionGroup &out) const override;
    void visualize(const OptionGroup &in) override;

    OptionGroup get() const override;

protected:
    void paintEvent(QPaintEvent* ev) override;

private:
    void initModel();
};

#endif // OPTIONSWIDGET_H
