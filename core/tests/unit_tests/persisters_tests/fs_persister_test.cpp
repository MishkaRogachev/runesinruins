#include "fs_persister_test.h"

#include "fs_persister.h"

using namespace core;

PersisterPtr FsPersisterTest::persister()
{
    return PersisterPtr(new FsPersister());
}

#include <QDebug>

void FsPersisterTest::testPath()
{
    FsPersister persister;

    for (const QString& extention:
         QStringList({ "vol", "abc", "", "tar.gz", "very.many.dots", ".wrong"}))
    {
        persister.setExtension(extention);

        persister.save("test_path", QByteArray("test"));
        QCOMPARE(persister.load("test_path"), QByteArray("test"));

        persister.clear();

        QVERIFY(persister.avalibleEntries().empty());
    }
}
