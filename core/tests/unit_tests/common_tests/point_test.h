#ifndef VEC_TEST_H
#define VEC_TEST_H

#include <QtTest/QTest>

class PointTest: public QObject
{
    Q_OBJECT

private slots:
    void testConstructors();
    void testGetterFunctions();
    void testSetterFunctions();
    void testComparation();
    void testOffsets();
    void testMoveAndGo();
    void testProduct();
};

#endif // VEC_TEST_H
