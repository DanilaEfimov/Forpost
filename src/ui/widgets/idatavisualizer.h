#ifndef IDATAVISUALIZER_H
#define IDATAVISUALIZER_H

#include "data/data.h"

#include <QWidget>
#include <concepts>

template<typename T>
concept dataclass = std::derived_from<T, Data>;

template<dataclass T>
class IDataVisualizer
{
public:
    IDataVisualizer() = default;
    virtual ~IDataVisualizer() = default;

    virtual void write(T& out) const = 0;
};

#endif // IDATAVISUALIZER_H
