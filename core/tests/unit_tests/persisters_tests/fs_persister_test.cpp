#include "fs_persister_test.h"

#include <QDir>

#include "fs_persister.h"

using namespace core;

PersisterPtr FsPersisterTest::persister()
{
    return PersisterPtr(new FsPersister());
}

void FsPersisterTest::testExtention()
{
    FsPersister persister;

    for (const QString& extention:
         QStringList({ "vol", "abc", "tar.gz", "very.many.dots", ".wrong"}))
    {
        persister.setExtension(extention);

        persister.save("test_path", QByteArray("test"));
        QCOMPARE(persister.load("test_path"), QByteArray("test"));

        persister.clear();

        QVERIFY(persister.avalibleEntries().empty());
    }
}

void FsPersisterTest::testFolders()
{
    FsPersister persister;

    for (const QString& subdir:
         QStringList({ "1", "abc", "1/2", "foo/bar", "folder.dot", ".hidden"}))
    {
        QDir dir(QDir::currentPath() + "/test/" + subdir);
        persister.setPath(dir.path());

        persister.save("test_path", QByteArray("test"));
        QCOMPARE(persister.load("test_path"), QByteArray("test"));

        persister.clear();

        QVERIFY(persister.avalibleEntries().empty());
    }

    QDir dir(QDir::currentPath() + "/test/");
    dir.removeRecursively();
}
