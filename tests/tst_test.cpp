#include <QtTest>
#include "../app/parser.h"
#include "../app/parser.cpp"

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
    QCOMPARE(value, 2);
}

void test::test_headers()
{
    parser t(file);
    QStringList value = t.get_headers();
    QCOMPARE(value.at(1), "bar");
    QCOMPARE(value.at(0), "foo");
}

void test::test_data_by_header()
{
    parser t(file);
    QStringList foo = t.get_data("foo");
    QStringList bar = t.get_data("bar");
    QCOMPARE(foo.at(0), "11");
    QCOMPARE(foo.at(1), "12");
    QCOMPARE(bar.at(0), "21");
    QCOMPARE(bar.at(1), "22");
}

QTEST_APPLESS_MAIN(test)

#include "tst_test.moc"
