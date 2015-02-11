#ifndef AREA_TEST_H
#define AREA_TEST_H

#include <QtTest/QtTest>

#include "area.h"

class AreaTest: public QObject
{
    Q_OBJECT

private slots:
    void creationAndLinking();
};

#endif // AREA_TEST_H
