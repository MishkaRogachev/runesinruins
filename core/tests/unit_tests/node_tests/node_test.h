#ifndef NODE_TEST_H
#define NODE_TEST_H

#include <QtTest/QTest>

class NodeTest: public QObject
{
    Q_OBJECT
    
private slots:
    void testChaining();
    void testCleaningChains();
};

#endif // NODE_TEST_H
