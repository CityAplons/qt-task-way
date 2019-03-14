#include "parser.h"

parser::parser()
{
    count = 0;
    col_count = 0;
}

parser::parser(QString filename)
{
    setFile(filename);
}

int parser::get_quantity_data()
{
    return count;
}

int parser::get_quantity_headers()
{
    return col_count;
}

QStringList parser::get_headers()
{
    return headers;
}

QStringList parser::get_data(QString header)
{
    int index = headers.indexOf(header);
    QStringList arr;
    for (int i = 0; i < data.size(); ++i){
        arr << data[i][index];
    }
    return arr;
}

void parser::setFile(QString filename)
{
    count = get_rows(filename);
    col_count = get_cols(filename);

    //reading file
    QFile inputFile(filename);
    if (inputFile.open(QIODevice::ReadOnly))    //if file opened
    {
        int i= 0;                               //line counter
        QTextStream in(&inputFile);
        while(!in.atEnd())                      //while is not end of file
        {
            QString ss = in.readLine();
            if(i == 0)                          //first line(headers)
            {
                headers = ss.split(QRegExp("[,\\s]+"));

            } else {
                QStringList line = ss.split(QRegExp("[,\\s]+"));
                    data << line;
            }
            i++;
        }
        inputFile.close();
    } else {
        return;
    }
}

int parser::get_rows(const QString filename)
{
    int i = 0;

    QFile inputFile(filename);
    if (inputFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&inputFile);
        while(!in.atEnd())
        {
            in.readLine();
            i++;
        }
        return --i;     //exclude last blank row
    } else {
        return i;
    }
}

int parser::get_cols(const QString filename)
{
    QFile inputFile(filename);
    if (inputFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&inputFile);
        QString line = in.readLine();
        QStringList h = line.split(',');

        inputFile.close();

        return h.size();
    } else {
        return 0;
    }
}

