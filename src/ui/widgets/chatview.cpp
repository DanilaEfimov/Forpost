#include "chatview.h"
#include "ui_chatview.h"
#include "styledtextadapter.h"

#define NEWLINE "<hr>"

StyledText ChatView::applyEffect(QString text)
{
    if(this->effect)
        return this->effect->apply(text);

    return StyledText(text);
}

ChatView::ChatView(QWidget *parent)
    : QWidget(parent)
    , messages()
    , ui(new Ui::ChatView)
{
    ui->setupUi(this);

    this->ui->chatText->setReadOnly(true);

    connect(this->ui->inputLine, &QLineEdit::returnPressed, this, &ChatView::onInputLineReturnPressed);
}

ChatView::~ChatView()
{
    delete ui;
}

void ChatView::setInputEffect(effect_p&&effect)
{
    this->effect = std::move(effect);
}

void ChatView::addLine(const StyledText &line)
{
    this->ui->chatText->append(NEWLINE);
    StyledTextAdapter::print(line, this->ui->chatText);
    this->messages.push_back(line);
}

void ChatView::onInputLineReturnPressed()
{
    QString content = this->ui->inputLine->text().trimmed();
    this->ui->inputLine->clear();
    if(content.isEmpty())
        return;

    StyledText line = this->applyEffect(content);

    this->addLine(line);
    this->ui->chatText->moveCursor(QTextCursor::End);
}

