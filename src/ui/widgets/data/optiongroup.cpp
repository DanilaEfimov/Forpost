#include "optiongroup.h"

#include <QSet>

size_t qHash(const OptionData& option, size_t seed = 0)
{
    return qHash(option.getName(), seed);
}

const OptionData &OptionGroup::findByName(const QString &name) const
{
    for(auto& o : this->options)
        if(o.getName() == name)
            return o;

    throw std::invalid_argument(QString(
                                    "OptionGroup::findByName: no such option named %1"
                                    ).arg(name).toStdString());
}

OptionData &OptionGroup::findByName(const QString &name)
{
    for(auto& o : this->options)
        if(o.getName() == name)
            return o;

    throw std::invalid_argument(QString(
                                    "OptionGroup::findByName: no such option named %1"
                                    ).arg(name).toStdString());
}

OptionGroup::OptionGroup(const QList<OptionData> &options)
    : Data(), options(options)
{}

OptionGroup::OptionGroup(const QList<QString>& names)
    : Data()
{
    for(const auto& name : names){
        this->options.push_back(OptionData(name));
    }
}

bool OptionGroup::checkOption(const QString& name) const
{
    for(const auto& option : this->options){
        if(option.getName() == name)
            return option.getValue();
    }

    throw std::invalid_argument(QString(
                                    "OptionGroup::checkOption: no such option named %1"
                                    ).arg(name).toStdString());
}

void OptionGroup::selectOption(const QString &name)
{
    try {
        auto& option = this->findByName(name);
        option.setValue(true);
    }
    catch(const std::exception& e) {
        return;
    };
}

void OptionGroup::unselectOption(const QString &name)
{
    try {
        auto& option = this->findByName(name);
        option.setValue(false);
    }
    catch(const std::exception& e) {
        return;
    };
}

bool OptionGroup::checkOption(qsizetype idx) const
{
    if(this->size() <= idx)
        throw std::out_of_range("OptionGroup::unselectOption: index out of range");

    return this->options.at(idx).getValue();
}

void OptionGroup::selectOption(qsizetype idx)
{
    if(this->size() <= idx)
        throw std::out_of_range("OptionGroup::selectOption: index out of range");

    this->options[idx].setValue(true);
}

void OptionGroup::unselectOption(qsizetype idx)
{
    if(this->size() <= idx)
        throw std::out_of_range("OptionGroup::unselectOption: index out of range");

    this->options[idx].setValue(false);
}

void OptionGroup::removeDuplicates()
{
    QSet<OptionData> uniques(this->options.begin(), this->options.end());
    this->options = QList<OptionData>(uniques.begin(), uniques.end());
}

void OptionGroup::addOption(const OptionData &option)
{
    this->options.push_back(option);
}

void OptionGroup::removeOption(qsizetype idx)
{
    if(this->size() <= idx)
        throw std::out_of_range("OptionGroup::removeOption: index out of range");
}

const OptionData& OptionGroup::getOption(qsizetype idx) const
{
    if(this->size() <= idx)
        throw std::out_of_range("OptionGroup::getOption: index out of range");

    return this->options.at(idx);
}

qsizetype OptionGroup::size() const
{
    return this->options.size();
}

void OptionGroup::clear()
{
    this->options.clear();
}
