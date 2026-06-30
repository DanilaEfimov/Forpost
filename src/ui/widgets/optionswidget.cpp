#include "optionswidget.h"

#include <QStandardItemModel>
#include <QStandardItem>
#include <QItemDelegate>

OptionsWidget::OptionsWidget(QWidget *parent)
    : QListView(parent)
    , options()
{}

OptionsWidget::OptionsWidget(OptionGroup&& options, QWidget *parent)
    : QListView(parent)
    , options(std::move(options))
{
}

OptionsWidget::OptionsWidget(const OptionGroup& options, QWidget *parent)
    : QListView(parent)
    , options(options)
{
}

OptionsWidget::~OptionsWidget()
{
}


void OptionsWidget::write(OptionGroup& out) const
{
    out.clear();

    size_t size = this->options.size();
    for(size_t i = 0; i < size; i++) {
        out.addOption(this->options.getOption(i));

        if(this->options.checkOption(i))
            out.selectOption(i);
    }
}

void OptionsWidget::visualize(const OptionGroup& in)
{

}

OptionGroup OptionsWidget::get() const
{
    return this->options;
}

void OptionsWidget::paintEvent(QPaintEvent *ev)
{

}

void OptionsWidget::initModel()
{
    auto* model = new QStandardItemModel(this);

    for(size_t i; i < this->options.size(); i++) {
        const auto& opt = this->options.getOption(i);

        auto* item = new QStandardItem(opt.getName());
        item->setCheckable(true);
        item->setCheckState(opt.getValue() ? Qt::Checked : Qt::Unchecked);

        model->appendRow(item);
    }

    this->setModel(model);
    //this->setItemDelegate(new CheckBoxItemDelegate(this));
}
