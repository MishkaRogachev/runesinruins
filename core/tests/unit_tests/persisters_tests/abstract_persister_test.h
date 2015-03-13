#ifndef ABSTRACT_PERSISTER_TEST_H
#define ABSTRACT_PERSISTER_TEST_H

#include <QtTest/QTest>

#include "core_traits.h"

class AbstractPersisterTest: public QObject
{
    Q_OBJECT

protected:
    virtual core::PersisterPtr persister() = 0;

private slots:
    void testSaveAndLoad();
    void testRemoveAndHasEntry();
    void testClearAndAvalibleEntries();
    void testEncodeDecode();
};

#endif // ABSTRACT_PERSISTER_TEST_H
