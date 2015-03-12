#ifndef FSPERSISTERTEST_H
#define FSPERSISTERTEST_H

#include "abstract_persister_test.h"

class FsPersisterTest: public AbstractPersisterTest
{
    Q_OBJECT

protected:
    virtual core::PersisterPtr persister() override;

private slots:
    void testPath();
    void testFolders();
};

#endif // FSPERSISTERTEST_H
