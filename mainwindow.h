#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_Load_triggered();

    void on_Save_triggered();

    void on_Select_triggered();

    void on_Rectangle_triggered();

    void on_Ellipse_triggered();

    void on_Line_triggered();

    void on_Clear_triggered();

    void on_Info_triggered();

    void on_Exit_triggered();

    void on_Background_triggered();

    void on_Brush_triggered();

    void on_Delete_triggered();

    void on_Copy_triggered();

    void on_Paste_triggered();

    void on_Undo_triggered();

    void on_Redo_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
