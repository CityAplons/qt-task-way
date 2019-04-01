#include "parser2.h"

parser2::parser2():parser(){
    hashedCSG.clear();
}

parser2::parser2(const QString &filename):parser(filename){
    genHash();
}

void parser2::genHash()
{
    //Re-initialize hash, just in case
    hashedCSG.clear();

    QStringList csg = this->get_data("#CSG");
    int lines = this->get_quantity_data();

    if(csg[0] != static_cast<QString>("")){
        for (int i=0; i<lines; i++) {
            //So I increment indexes of lines for data check (if data not found, .value method will return 0)
            int g = i+1;
            hashedCSG.insert(csg[i],g);
        }
    }
}
