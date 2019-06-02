#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cmdhelper.h"
#include "confighelper.h"

#include <QRadioButton>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    auto vLayout = new QVBoxLayout;    
    auto names = CMDs::getCMDsNames();
    auto params = CONFIGS::getParamsNames();

    for(auto name : names){
        auto radioButton = new QRadioButton(name);
        vLayout->addWidget(radioButton);
    }

    ui->cmdGroupBox->setLayout( vLayout );

    vLayout = new QVBoxLayout;
    for(auto param : params){
        auto radioButton = new QRadioButton(param);
        vLayout->addWidget(radioButton);
    }
    ui->paramGroupBox->setLayout( vLayout );


}

MainWindow::~MainWindow()
{
    delete ui;
}
