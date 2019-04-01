#ifndef PARSER_H
#define PARSER_H
#pragma once
#include <QTextStream>
#include <QStringList>
#include <QFile>
using namespace std;

class parser
{
private:
    QStringList headers;    //contains list header names (#CSG, #X, #Y etc)
    QList<QStringList> data; //[rows][columns(attributes)]
    int count;          //count of lines
    int col_count;      //count of columns

    int get_rows(const QString &filename);
    int get_cols(const QString &filename);

public:
    parser();                               //constructor
    parser(const QString &filename);         //constructor with file init
    void setFile(const QString &filename);   //setter
    QStringList get_data(QString header);        //getter, returns array of data by header
    QStringList get_headers();                  //getter, returns array of header names
    int get_quantity_data();                 //getter, returns 'int count' value
    int get_quantity_headers();             //getter, returns 'int col_count' value
};

#endif // PARSER_H

