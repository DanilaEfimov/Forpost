#ifndef OPTIONGROUP_H
#define OPTIONGROUP_H

#include "data/optiondata.h"

#include <QString>

class OptionGroup : public Data {
    const OptionData& findByName(const QString& name) const;
    OptionData& findByName(const QString& name);

protected:
    QList<OptionData> options;

public:
    OptionGroup() = default;
    OptionGroup(const QList<OptionData>& options);
    OptionGroup(const QList<QString>& names);
    virtual ~OptionGroup() = default;

    bool checkOption(const QString& name) const;
    virtual void selectOption(const QString& name);
    virtual void unselectOption(const QString& name);

    bool checkOption(qsizetype idx) const;
    virtual void selectOption(qsizetype idx);
    virtual void unselectOption(qsizetype idx);

    void removeDuplicates();
    void addOption(const OptionData& option);
    virtual void removeOption(qsizetype idx);

    const OptionData& getOption(qsizetype idx) const;

    qsizetype size() const;
    void clear();
};

#endif // OPTIONGROUP_H
