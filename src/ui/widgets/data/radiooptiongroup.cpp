#include "data/radiooptiongroup.h"

RadioOptionGroup::RadioOptionGroup(const QList<QString>& names)
    : OptionGroup(names), selected(false)
{}

void RadioOptionGroup::selectOption(const QString &name)
{
    this->unselectAll();

    OptionGroup::selectOption(name);

    this->selected = true;
}

void RadioOptionGroup::unselectOption(const QString &name)
{
    if(this->checkOption(name))
        this->selected = false;

    OptionGroup::unselectOption(name);
}

void RadioOptionGroup::selectOption(qsizetype idx)
{
    this->unselectAll();

    OptionGroup::selectOption(idx);

    this->selected = true;
}

void RadioOptionGroup::unselectOption(qsizetype idx)
{
    if(this->checkOption(idx))
        this->selected = false;

    OptionGroup::unselectOption(idx);
}

void RadioOptionGroup::removeOption(qsizetype idx)
{
    if(this->checkOption(idx))
        this->selected = false;

    OptionGroup::removeOption(idx);
}

void RadioOptionGroup::unselectAll()
{
    for(auto& o : this->options)
        o.setValue(false);

    this->selected = false;
}

bool RadioOptionGroup::isSelected() const
{
    return this->selected;
}
