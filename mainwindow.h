#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <QPushButton>
#include <QSignalMapper>
#include <QKeyEvent>
#include "button.h"
#include "buttonfactory.h"
#include "buffer.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void handleButton(QObject*);

private:
    void createButtons();
    QString replaceIfNecessary(QString);
    void keyPressEvent(QKeyEvent*) override;
    void connectButton(QPushButton*, Button*, QSignalMapper*);
    Ui::MainWindow *ui;
    std::vector<Button*> buttonsPtrs;
    Buffer* buffer;
};

#endif // MAINWINDOW_H
