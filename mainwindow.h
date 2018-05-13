#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void digit_pressed();
    void on_pushButton_point_pressed();
    void unary_opretion_pressed();
    void on_pushButton_clear_pressed();
    void on_pushButton_equal_released();
    void binary_opretion_pressed();
};

#endif // MAINWINDOW_H
