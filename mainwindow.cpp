#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->CanvasWidget->setTool(ToolType::None);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Save_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Сохранить файл", "", "Canvas Files (*.bin)");
    if (!fileName.isEmpty()) {
        if (!ui->CanvasWidget->saveToFile(fileName)) {
            QMessageBox::warning(this, "Ошибка", "Не удалось сохранить файл");
        }
    }
}


void MainWindow::on_Load_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Открыть файл", "", "Canvas Files (*.bin)");
    if (!fileName.isEmpty()) {
        if (!ui->CanvasWidget->loadFromFile(fileName)) {
            QMessageBox::warning(this, "Ошибка", "Не удалось загрузить файл");
        }
    }
}


void MainWindow::on_Select_triggered()
{
    ui->CanvasWidget->setTool(ToolType::Select);
}


void MainWindow::on_Rectangle_triggered()
{
    ui->CanvasWidget->setTool(ToolType::Rectangle);
}


void MainWindow::on_Ellipse_triggered()
{
    ui->CanvasWidget->setTool(ToolType::Ellipse);
}


void MainWindow::on_Line_triggered()
{
    ui->CanvasWidget->setTool(ToolType::Line);
}


void MainWindow::on_Clear_triggered()
{
    ui->CanvasWidget->clearAll();
}


void MainWindow::on_Info_triggered()
{
    QString info =
        "   Информация\n"
        "   Автор: Сорокин Александр, 6 группа";

    QMessageBox::information(this, "О программе", info);
}


void MainWindow::on_Exit_triggered()
{
    QApplication::quit();
}

