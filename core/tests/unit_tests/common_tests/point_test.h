#ifndef VECTEST_H
#define VECTEST_H

#include <QtTest>

class PointTest: public QObject
{
    Q_OBJECT

private slots:
    void testConstructors();
    void testGetterFunctions();
    void testSetterFunctions();
    void testComparation();
    void testOffsets();
    void testProduct();
};

#endif // VECTEST_H
