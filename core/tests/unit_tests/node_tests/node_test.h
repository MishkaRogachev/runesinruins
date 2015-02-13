#ifndef NODE_TEST_H
#define NODE_TEST_H

#include <QtTest/QtTest>

class NodeTest: public QObject
{
    Q_OBJECT
    
private slots:
    void directions();
    void linkAndBreak();
    void autoCleaningLinks();
};
#endif // NODE_TEST_H
