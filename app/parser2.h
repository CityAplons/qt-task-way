#ifndef PARSER2_H
#define PARSER2_H

#include "parser.h"
#include <QTextStream>
#include <QStringList>
#include <QHash>

class parser2 : public parser
{
public:
    QHash<QString, int> hashedCSG;

    parser2();
    parser2(const QString &filename);
    void genHash();

};

#endif // PARSER2_H
