#ifndef PLAINEDITOR_H
#define PLAINEDITOR_H

#include <QPlainTextEdit>
#include <QWidget>

class PlainTextEditor: public QPlainTextEdit
{
public:
    PlainTextEditor(QWidget *parent = nullptr);
    ~PlainTextEditor();
    quint32 lineNumberAreaWidth();
};

#endif // PLAINEDITOR_H
