#ifndef CACHED_SPACE_TEST_H
#define CACHED_SPACE_TEST_H

#include <QtTest/QtTest>

class CacheSpaceTest : public QObject
{
    Q_OBJECT

private slots:
    void testConstructors();
    void testAbstractInterface();
    void testLoading();
};

#endif // CACHED_SPACE_TEST_H
