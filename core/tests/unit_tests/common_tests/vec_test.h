#ifndef VECTEST_H
#define VECTEST_H

#include <QtTest/QtTest>

class VecTest: public QObject
{
    Q_OBJECT

private slots:
    void testConstructors();
    void testGetterFunctions();
    void testSetterFunctions();
    void compareTest();
};

#endif // VECTEST_H
