#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cmdhelper.h"
#include "confighelper.h"
#include "cmdhelper.h"

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

    connect( ui->pushButton, &QPushButton::clicked, this, &MainWindow::onSendCmdClicked );

    mClient = std::make_unique<Client>();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onSendCmdClicked(){

    CMDs::CMDs_NAMES cmdType;

    for(auto child : ui->cmdGroupBox->children().mid(1) ){
        auto radioButton = reinterpret_cast<QRadioButton*>(child);

        if(radioButton->isChecked()){
            auto cmdName  = radioButton->text();
            cmdType = CMDs::cmdMap().value(cmdName);
        }
    }

    CMDs::CMD_t tmp = {
                    cmdType,
                    {
                        CONFIGS::configsNames::mmInRotation,
                        10
                    }
               };


    mClient->sendCmd( tmp );

}
