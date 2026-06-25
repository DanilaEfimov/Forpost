#include "optionswidget.h"
#include "ui_optionswidget.h"

OptionsWidget::OptionsWidget(OptionGroup&& options, QWidget *parent)
    : QListView(parent)
    , options(std::move(options))
    , ui(new Ui::OptionsWidget)
{
    ui->setupUi(this);
}

OptionsWidget::~OptionsWidget()
{
    delete ui;
}
