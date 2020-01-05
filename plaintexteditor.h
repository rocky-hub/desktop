#ifndef PLAINEDITOR_H
#define PLAINEDITOR_H

#include <QPlainTextEdit>
#include <QPaintEvent>
#include <QResizeEvent>
#include <QSize>
#include <QWidget>

class PlainTextEditor: public QPlainTextEdit
{
public:
    PlainTextEditor(QWidget *parent = nullptr);

    int lineNumberAreaWidth() const;
    void lineNumberAreaPaintEvent(QPaintEvent *event);

    QSize sizeHint() const override
    {
        return QSize(lineNumberAreaWidth(), 0);
    }

protected:
    void resizeEvent(QResizeEvent *event) override;

    void paintEvent(QPaintEvent *event) override {
        lineNumberAreaPaintEvent(event);
    }

private slots:
    void updateLineNumberAreaWidth(int newBlockCount);
    void updateLineNumberArea(const QRect&, int);
    void highlightCurrentLine();
};

#endif // PLAINEDITOR_H
