#ifndef ABSTRACT_AREA_TEST_H
#define ABSTRACT_AREA_TEST_H

#include <QtTest/QTest>

#include "core_traits.h"

class AbstractAreaTest: public QObject
{
    Q_OBJECT

protected:
    virtual core::AreaPtr area(int size) = 0;

private slots:
    void testSizes();
    void testPositions();
};

#endif // ABSTRACT_AREA_TEST_H
