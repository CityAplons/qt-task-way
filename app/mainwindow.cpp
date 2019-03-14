#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "about.h"
#include "parser.h"
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusBar->showMessage("Ready");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_about_clicked()
{
    //about
    about window;
    window.setModal(true);
    window.exec();
}

void MainWindow::check_files(bool a, bool b)
{
    if(a && b)
    {
        ui->submit->setEnabled(true);
    } else {
        ui->submit->setEnabled(false);
    }
}

void MainWindow::on_file1_clicked()
{
    //QString -> char array
    QString file1Name = QFileDialog::getOpenFileName(this,tr("Open a CSV"), QDir::homePath(), tr("CSV files (*.csv)"));

    if(file1Name != "")
    {
        file1->setFile(file1Name);

        //get rows and columns
        int cols = file1->get_quantity_headers();
        int rows = file1->get_quantity_data();

        //get headers
        QStringList headers = file1->get_headers();

        //check for attributes
        bool all = 0, x = 0, y = 0, z = 0, csg = 0;
        for(int i = 0; i < cols; i++)
        {
            if(headers[i] == "#CSG")
                csg = 1;
            if(headers[i] == "#X")
                x = 1;
            if(headers[i] == "#Y")
                y = 1;
            if(headers[i] == "#Z")
                z = 1;
        }
        all = x && y && z && csg;

        //print in mainwindow
        ui->strings1->setText(QString::number(rows));
        ui->column1->setText(QString::number(cols));
        if(all) ui->status1->setText("All attributes in file was found!");
        else ui->status1->setText("Check data, there is no needed attributes inside CSV!");

        is_first_ready = all;
        check_files(is_second_ready, is_first_ready);
    } else {
        ui->status1->setText("No file selected");
        check_files(is_second_ready, 0);
    }

}

void MainWindow::on_file2_clicked()
{
    //QString -> char array
    QString file1Name = QFileDialog::getOpenFileName(this,tr("Open a CSV"), QDir::homePath(), tr("CSV files (*.csv)"));

    if(file1Name != "")
    {
        file2->setFile(file1Name);

        //get rows and columns
        int cols = file2->get_quantity_headers();
        int rows = file2->get_quantity_data();

        //get headers
        QStringList headers = file2->get_headers();

        //check for attributes
        bool all = 0, from = 0, to = 0, srv = 0, csg = 0;
        for(int i = 0; i < cols; i++)
        {
            if(headers[i] == "#CSG")
                csg = 1;
            if(headers[i] == "#FROM")
                from = 1;
            if(headers[i] == "#TO")
                to = 1;
            if(headers[i] == "#SRV")
                srv = 1;
        }
        all = from && to && srv && csg;

        //print in mainwindow
        ui->strings2->setText(QString::number(rows));
        ui->column2->setText(QString::number(cols));
        if(all) ui->status2->setText("All attributes in file was found!");
        else ui->status2->setText("Check data, there is no needed attributes inside CSV!");

        is_second_ready = all;
        check_files(is_second_ready, is_first_ready);
    } else {
       ui->status2->setText("No file selected");
       check_files(0, is_first_ready);
    }
}

void MainWindow::on_submit_clicked()
{
    //get headers
    QStringList h1 = file1->get_headers();
    QStringList h2 = file2->get_headers();

    ui->statusBar->showMessage("Generating file...");
    ui->progressBar->setValue(0);

    //make new header line
    QStringList new_header;
    new_header  << h1[0] << h1[1] << h1[2] << h1[3]
                << h2[1] << h2[2] << h2[3];


    QString fileName = QFileDialog::getSaveFileName(this,
            tr("Save CSV file"), "output.csv",
            tr("Comma-separated values file (*.csv);;All Files (*)"));

    QFile file(fileName);
    if ( file.open(QIODevice::WriteOnly | QIODevice::Truncate) )
    {
        QTextStream out( &file );

        //write header
        for(int g = 0; g<6; g++)
        {
            out << new_header[g] << ",";
        }
        out << new_header[6] << endl;

        //make new data (by string)
        QStringList data1 = file1->get_data("#CSG");
        QStringList data2 = file2->get_data("#CSG");
        QStringList xS = file1->get_data("#X");
        QStringList yS = file1->get_data("#Y");
        QStringList zS = file1->get_data("#Z");
        QStringList fromS = file2->get_data("#FROM");
        QStringList toS = file2->get_data("#TO");
        QStringList srvS = file2->get_data("#SRV");

        for(int i = 0; i < file1->get_quantity_data(); i++)
        {
            for(int j = 0; j < file2->get_quantity_data(); j++)
            {
                if(data1[i] == data2[j] && data1[i] != "" && data2[i] != ""){
                    out << data1[i] << "," << xS[i] << "," << yS[i] << "," << zS[i] << "," << fromS[j] << "," << toS[j] << "," << srvS[j] << endl;
                }
            }
            float calc = i*100/(file1->get_quantity_data());
            ui->progressBar->setValue(static_cast<int>(calc));
        }

    }
    file.close();
    ui->statusBar->showMessage("Complete!");
    ui->progressBar->setValue(100);
}
