#ifndef OPTIONDATA_H
#define OPTIONDATA_H

#include "data.h"

#include <QString>
#include <QList>

class OptionData : public Data {
    QString name;
    bool value;

public:
    OptionData(const QString& name, bool value = false);
    virtual ~OptionData() = default;

    QString getName() const;
    void setName(const QString &newName);

    bool getValue() const;
    void setValue(bool newValue);

    bool operator==(const OptionData& right) const;
};

#endif // OPTIONDATA_H
