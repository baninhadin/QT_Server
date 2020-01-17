#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = new QUdpSocket(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_button_send_clicked()
{

    auto data = ui->lineEdit->text().toLatin1();
    socket->writeDatagram(data, QHostAddress("224.16.80.80"), ui->spinBox->value());
}
