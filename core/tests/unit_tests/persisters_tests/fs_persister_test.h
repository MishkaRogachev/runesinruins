#ifndef FS_PERSISTER_TEST_H
#define FS_PERSISTER_TEST_H

#include "abstract_persister_test.h"

class FsPersisterTest: public AbstractPersisterTest
{
    Q_OBJECT

protected:
    virtual core::PersisterPtr persister() override;

private slots:
    void testExtention();
    void testFolders();
};

#endif // FS_PERSISTER_TEST_H
