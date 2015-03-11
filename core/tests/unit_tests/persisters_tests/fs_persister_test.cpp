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
         QStringList({ "", "vol", "tar.gz", "very.many.dots", ".wrong_ext"}))
    {
        persister.setExtension(extention);

        persister.save("test_path_" + extention, QByteArray("test"));
        QCOMPARE(persister.load("test_path_" + extention), QByteArray("test"));

        persister.clear();

        qDebug() << persister.avalibleEntries();

        QVERIFY(persister.avalibleEntries().empty());
    }
}
