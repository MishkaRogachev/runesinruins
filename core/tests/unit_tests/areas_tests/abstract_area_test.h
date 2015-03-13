#ifndef ABSTRACT_AREA_TEST_H
#define ABSTRACT_AREA_TEST_H

#include <QtTest/QTest>

#include "core_traits.h"

class AbstractAreaTest: public QObject
{
    Q_OBJECT

protected:
    virtual core::AreaPtr area() = 0;
};

#endif // ABSTRACT_AREA_TEST_H
