#ifndef RADIOOPTIONGROUP_H
#define RADIOOPTIONGROUP_H

#include "data/optiongroup.h"

class RadioOptionGroup : public OptionGroup
{
    bool selected = false;

public:
    RadioOptionGroup(const QList<QString>& names);
    virtual ~RadioOptionGroup() = default;

    void selectOption(const QString &name) override;
    void unselectOption(const QString &name) override;

    void selectOption(qsizetype idx) override;
    void unselectOption(qsizetype idx) override;

    void removeOption(qsizetype idx) override;
    void unselectAll();

    bool isSelected() const;
};

#endif // RADIOOPTIONGROUP_H
