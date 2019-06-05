#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "client.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    public slots:
    void onSendCmdClicked();

private:
    Ui::MainWindow *ui;

    std::unique_ptr<Client> mClient = nullptr;
};

#endif // MAINWINDOW_H
