#ifndef ABSTRACTSPACETEST_H
#define ABSTRACTSPACETEST_H

#include <QtTest/QtTest>


class AbstractSpaceTest : public QObject
{
    Q_OBJECT

private slots:
    void testIntegrity();
    void testChaning2D();
};

#endif // ABSTRACTSPACETEST_H
