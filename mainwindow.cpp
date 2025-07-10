#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QColorDialog>

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
        "   Векторный графический редактор\n\n"
        "   Возможности:\n"
        " • Рисование прямоугольников, эллипсов и линий\n"
        " • Выделение и перемещение фигур\n"
        " • Установка цвета кисти и фона\n"
        " • Копирование и вставка фигур\n"
        " • Сохранение и загрузка в бинарные файлы\n"
        " • Undo / Redo (отмена и повтор действий)\n"
        " • Горячие клавиши\n\n"
        "   Автор: Сорокин Александр\n"
        "   Группа: 6 группа\n";

    QMessageBox::information(this, "О программе", info);
}


void MainWindow::on_Exit_triggered()
{
    QApplication::quit();
}


void MainWindow::on_Background_triggered()
{
    QColor color = QColorDialog::getColor(Qt::white, this, "Выберите цвет фона");
    if (color.isValid())
        ui->CanvasWidget->setBackgroundColor(color);
}


void MainWindow::on_Brush_triggered()
{
    QColor color = QColorDialog::getColor(Qt::black, this, "Выберите цвет кисти");
    if (color.isValid())
        ui->CanvasWidget->setBrushColor(color);
}


void MainWindow::on_Delete_triggered()
{
    ui->CanvasWidget->deleteSelected();
}


void MainWindow::on_Copy_triggered()
{
    ui->CanvasWidget->copySelectedFigure();
}


void MainWindow::on_Paste_triggered()
{
    ui->CanvasWidget->pasteFigure();
}


void MainWindow::on_Undo_triggered()
{
    ui->CanvasWidget->undo();
}


void MainWindow::on_Redo_triggered()
{
    ui->CanvasWidget->redo();
}
