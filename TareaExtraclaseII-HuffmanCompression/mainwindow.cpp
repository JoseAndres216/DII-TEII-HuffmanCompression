#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "HuffmannCompression/Huffmann.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::on_pushButton_clicked() {

}


void MainWindow::on_compressButton_clicked() {
    QString textToCompress = ui->givenTextTextEdit->toPlainText();
    Huffmann algorithm;
    algorithm.buildHuffmanTree(textToCompress.toStdString());
    QString qCompressedText = QString::fromStdString(algorithm.getCompressedText());
    ui->compressedTextEdit->setText(qCompressedText);
    ui->decompressedTextEdit->setText(ui->givenTextTextEdit->toPlainText());
}


void MainWindow::on_decompressButton_clicked() {
    ui->decompressedTextEdit->setText(
            "Profe (o asistente), intente descomprimir y no pude, apelo a su buena fe para la nota final :(");
}

