#include "styledtextadapter.h"

void StyledTextAdapter::print(const StyledText& styled, QTextEdit* edit)
{
    const QString& text = styled.getText();
    const auto& style = styled.getSpans();

    QTextCursor cursor = edit->textCursor();
    qsizetype written = 0;
    for(const auto& span : style) {
        qsizetype len = span.getLength();

        QString substr = text.mid(written, len);
        QTextCharFormat format = span.toFormat();
        cursor.insertText(substr, format);

        written += len;
    }
}
