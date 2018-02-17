#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createButtons();
    this->buffer = new Buffer(ui->mainLabel, ui->historyTextBrowser, ui->resultLabel);
}

void MainWindow::createButtons(){
    std::vector<QPushButton*>
            pushButtonsPtrs = {ui->zeroButton,ui->oneButton, ui->twoButton,
                               ui->threeButton, ui->fourButton, ui->fiveButton,
                               ui->sixButton, ui->sevenButton, ui->eightButton,
                               ui->nineButton, ui->plusButton, ui->minusButton,
                               ui->multiplyButton, ui->divisionButton, ui->dotButton,
                               ui->deleteButton, ui->percentButton, ui->plusOrMinusButton,
                               ui->equalsButton};



  QSignalMapper* signalMapper = new QSignalMapper(this);
  for(QPushButton* pushButtonPtr : pushButtonsPtrs){
      Button* buttonPtr =  ButtonFactory::Instance()->createButton(pushButtonPtr);
      connectButton(pushButtonPtr, buttonPtr, signalMapper);
      this->buttonsPtrs.push_back(buttonPtr);
  }


  connect(signalMapper, SIGNAL(mapped(QObject*)), this, SLOT(handleButton(QObject*)));

}

void MainWindow::keyPressEvent(QKeyEvent* keyEvent){

    for(Button* button : buttonsPtrs){
        if(button->hasKey(keyEvent->key())){
            button->click();
        }
    }
}

void MainWindow::connectButton(QPushButton* pushButton, Button* button, QSignalMapper* signalMapper){
    connect(pushButton, SIGNAL(clicked()),signalMapper,SLOT(map()));
    signalMapper->setMapping(pushButton, button);
}

void MainWindow::handleButton(QObject* btn){
    Button* button = static_cast<Button*>(btn);
    button->sendInfoToBuffer(this->buffer);
}

MainWindow::~MainWindow()
{
    delete this->buffer;
    delete ui;
}
