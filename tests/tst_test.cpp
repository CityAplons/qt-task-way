#include <QtTest>
#include "../app/parser.h"
#include "../app/parser.cpp"
#include "../app/parser2.h"
#include "../app/parser2.cpp"

// add necessary includes here

static QString file = ":/csv/test.csv";

class test : public QObject
{
    Q_OBJECT

private slots:
    void test_row_count();
    void test_col_count();
    void test_headers();
    void test_data_by_header();
    void test_hash();
};

void test::test_row_count()
{
    parser t(file);
    int value = t.get_quantity_data();
    QCOMPARE(value, 2);
}

void test::test_col_count()
{
    parser t(file);
    int value = t.get_quantity_headers();
    QCOMPARE(value, 3);
}

void test::test_headers()
{
    parser t(file);
    QStringList value = t.get_headers();
    QCOMPARE(value.at(2), "bar");
    QCOMPARE(value.at(1), "foo");
    QCOMPARE(value.at(0), "#CSG");
}

void test::test_data_by_header()
{
    parser t(file);
    QStringList foo = t.get_data("foo");
    QStringList bar = t.get_data("bar");
    QStringList null = t.get_data("NO");
    QCOMPARE(foo.at(0), "11");
    QCOMPARE(foo.at(1), "12");
    QCOMPARE(bar.at(0), "21");
    QCOMPARE(bar.at(1), "22");
    QCOMPARE(null.at(0), "");
}

void test::test_hash()
{
    parser2 t(file);
    QStringList arr = t.get_data("foo");
    int key = t.hashedCSG.value("A1");
    QCOMPARE(key, 1);
    key = t.hashedCSG.value("B1");
    QCOMPARE(key, 2);
    key = t.hashedCSG.value("C3");
    QCOMPARE(key, 0);
}

QTEST_APPLESS_MAIN(test)

#include "tst_test.moc"
