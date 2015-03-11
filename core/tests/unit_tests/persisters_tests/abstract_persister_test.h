#ifndef ABSTRACTPERSISTERTEST_H
#define ABSTRACTPERSISTERTEST_H

#include <QTest>

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

#endif // ABSTRACTPERSISTERTEST_H
