#ifndef CHATVIEW_H
#define CHATVIEW_H

#include <QWidget>
#include <QStringList>
#include <QColor>

#include "styledtext.h"
#include "textcolorschemeeffect.h"

namespace Ui {
class ChatView;
}

class ChatView : public QWidget
{
    Q_OBJECT

    using effect_p = std::unique_ptr<TextColorSchemeEffect>;

    QVector<StyledText> messages;
    effect_p effect = nullptr;

    StyledText applyEffect(QString text);

public:
    explicit ChatView(QWidget *parent = nullptr);
    ~ChatView();

    void setInputEffect(effect_p&& effect);

    void addLine(const StyledText& line);

private slots:
    void onInputLineReturnPressed();

private:
    Ui::ChatView *ui;
};

#endif // CHATVIEW_H
