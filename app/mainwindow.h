#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QElapsedTimer>
#include "parser.h"
#include "parser2.h"

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
    parser2 *file2 = new (parser2);
    bool is_first_ready = false;
    bool is_second_ready = false;
};

#endif // MAINWINDOW_H
