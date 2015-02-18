#ifndef DIRECTION_TEST_H
#define DIRECTION_TEST_H

#include <QtTest/QtTest>

class DirectionTest: public QObject
{
    Q_OBJECT

private slots:
    void testInversion();
    void testStatic();
};

#endif // DIRECTIONTEST_H
