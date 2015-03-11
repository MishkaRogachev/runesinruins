#include "abstract_persister_test.h"

#include "abstract_persister.h"

using namespace core;

void AbstractPersisterTest::testSaveAndLoad()
{
    PersisterPtr persister = this->persister();
    QByteArray data1("Test Data 1");
    QByteArray data2("Test Data 2");

    persister->save("test_1", data1);
    persister->save("test_2", data2);

    QCOMPARE(persister->load("test_1"), data1);
    QCOMPARE(persister->load("test_2"), data2);
}

void AbstractPersisterTest::testRemoveAndHasEntry()
{
    PersisterPtr persister = this->persister();

    QVERIFY(!persister->hasEntry("remove_test_1"));
    QVERIFY(!persister->hasEntry("remove_test_2"));

    persister->save("remove_test_1", QByteArray());

    QVERIFY(persister->hasEntry("remove_test_1"));
    QVERIFY(!persister->hasEntry("remove_test_2"));

    persister->save("remove_test_2", QByteArray());

    QVERIFY(persister->hasEntry("remove_test_1"));
    QVERIFY(persister->hasEntry("remove_test_2"));

    persister->remove("remove_test_1");

    QVERIFY(!persister->hasEntry("remove_test_1"));
    QVERIFY(persister->hasEntry("remove_test_2"));

    persister->remove("remove_test_2");

    QVERIFY(!persister->hasEntry("remove_test_1"));
    QVERIFY(!persister->hasEntry("remove_test_2"));
}

void AbstractPersisterTest::testClearAndAvalibleEntries()
{
    PersisterPtr persister = this->persister();

    persister->save("test_clear_1", QByteArray());

    QVERIFY(persister->avalibleEntries().contains("test_clear_1"));

    persister->clear();

    QVERIFY(persister->avalibleEntries().empty());
}

void AbstractPersisterTest::testEncodeDecode()
{
    PersisterPtr persister = this->persister();
    QByteArray someData("Some long data with numbers 1234578");

    QCOMPARE(persister->decode(persister->encode(someData)), someData);
}
