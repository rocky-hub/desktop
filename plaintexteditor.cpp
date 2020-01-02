#include "plaintexteditor.h"

PlainTextEditor::PlainTextEditor(QWidget* parent): QPlainTextEdit(parent)
{

}

PlainTextEditor::~PlainTextEditor()
{

}

quint32 PlainTextEditor::lineNumberAreaWidth()
{
    return 0;
}
