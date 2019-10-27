Read fields from both .csv files (file01.csv, file02.csv) and export in defined format to output.csv file. 
Output format is: #CSG,#X,#Y,#Z,#FROM,#TO,#SRV (see output.smpl)
#CSG is identifier


\+ 1) Parse text files file01.csv and file02.csv.

\+ 2) Store fields in data structure (eg. class, struct...).

\+ 3) Match fields on the #CSG identifier, format and export fields to output.csv.

\+ 4) Can you write unit tests?

\- *) Try to use qmake file for building.

\- *) Try to use cmake file for building.

You can use libraries and build environments of your choice. 
Use of Qt library and QtCreator is recommended.
