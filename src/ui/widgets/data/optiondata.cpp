#include "optiondata.h"

#include <QSet>

OptionData::OptionData(const QString& name, bool value)
    : Data(), name(name), value(value)
{}

QString OptionData::getName() const
{
    return this->name;
}

void OptionData::setName(const QString &newName)
{
    this->name = newName;
}

bool OptionData::getValue() const
{
    return this->value;
}

void OptionData::setValue(bool newValue)
{
    this->value = newValue;
}

bool OptionData::operator==(const OptionData &right) const
{
    return this->name == right.getName();
}
