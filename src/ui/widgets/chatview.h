#ifndef CHATVIEW_H
#define CHATVIEW_H

#include <QWidget>
#include <QStringList>
#include <QColor>

#include "styledtext.h"

namespace Ui {
class ChatView;
}

class ChatView : public QWidget
{
    Q_OBJECT

    QVector<StyledText> messages;

public:
    explicit ChatView(QWidget *parent = nullptr);
    ~ChatView();

    void addLine(const StyledText& line);

private:
    Ui::ChatView *ui;
};

#endif // CHATVIEW_H
