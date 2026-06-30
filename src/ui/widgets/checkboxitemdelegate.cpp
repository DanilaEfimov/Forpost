#include "checkboxitemdelegate.h"


QPalette CheckBoxItemDelegate::getPalette() const
{
    return this->palette;
}

void CheckBoxItemDelegate::setPalette(const QPalette &newPalette)
{
    this->palette = newPalette;
}

OptionData CheckBoxItemDelegate::getOption() const
{
    return this->option;
}

void CheckBoxItemDelegate::setOption(const OptionData &newOption)
{
    this->option = newOption;
}

void CheckBoxItemDelegate::setEffect(std::unique_ptr<CircleRenderEffect>&& newEffect)
{
    this->effect = std::move(newEffect);
}

void CheckBoxItemDelegate::checkPatternRender(QPainter &p, const ellipse_wp& ellipse) const
{
}

ellipse_wp CheckBoxItemDelegate::getCheckMarkEllipseWithPos(const QRect &rect) const
{

}

CheckBoxItemDelegate::CheckBoxItemDelegate(const QString& name, QWidget* parent)
    : QStyledItemDelegate(parent), option(name)
{}

void CheckBoxItemDelegate::setName(const QString &name)
{
    this->option.setName(name);
}

QString CheckBoxItemDelegate::getName() const
{
    return this->option.getName();
}

void CheckBoxItemDelegate::setChecked(bool value)
{
    this->option.setValue(value);
}

bool CheckBoxItemDelegate::getChecked() const
{
    return this->option.getValue();
}

void CheckBoxItemDelegate::paint(QPainter* p,
                                 const QStyleOptionViewItem &option,
                                 const QModelIndex &index) const
{
    p->setRenderHint(QPainter::Antialiasing);

    QString text = index.data(Qt::DisplayRole).toString();
    bool checked = index.data(Qt::CheckStateRole).toInt() == Qt::Checked;

    QRect rect = option.rect.adjusted(padding, padding, padding, padding);

    this->checkPatternRender(*p, this->getCheckMarkEllipseWithPos(rect));
}

QSize CheckBoxItemDelegate::sizeHint(const QStyleOptionViewItem &option,
                                     const QModelIndex &index) const
{

}
