#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QTextStream>
#include "parser.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void check_files(bool a, bool b);

    void on_about_clicked();

    void on_file1_clicked();

    void on_file2_clicked();

    void on_submit_clicked();

private:
    Ui::MainWindow *ui;
    parser *file1 = new (parser);
    parser *file2 = new (parser);
    bool is_first_ready = false;
    bool is_second_ready = false;
};

#endif // MAINWINDOW_H
