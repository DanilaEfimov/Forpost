#ifndef CHECKBOXITEMDELEGATE_H
#define CHECKBOXITEMDELEGATE_H

#include "data/optiondata.h"
#include "circlerendereffect.h"

#include <QStyledItemDelegate>
#include <QPalette>

class CheckBoxItemDelegate : public QStyledItemDelegate
{
    Q_OBJECT

    static constexpr size_t padding = 4;

    QPalette palette;
    OptionData option;
    std::unique_ptr<CircleRenderEffect> effect = nullptr;

    void checkPatternRender(QPainter& p, const ellipse_wp& ellipse) const;
    ellipse_wp getCheckMarkEllipseWithPos(const QRect& rect) const;

public:
    CheckBoxItemDelegate(const QString& name, QWidget* parent = nullptr);
    virtual ~CheckBoxItemDelegate() = default;

    void setName(const QString& name);
    QString getName() const;

    void setChecked(bool value);
    bool getChecked() const;

    QPalette getPalette() const;
    void setPalette(const QPalette &newPalette);

    OptionData getOption() const;
    void setOption(const OptionData &newOption);

    void setEffect(std::unique_ptr<CircleRenderEffect>&& newEffect);

protected:
    void paint(QPainter* p,
               const QStyleOptionViewItem& option,
               const QModelIndex& index) const override;

    QSize sizeHint(const QStyleOptionViewItem& option,
                   const QModelIndex& index) const override;
};

#endif // CHECKBOXITEMDELEGATE_H
