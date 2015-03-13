#include "point_test.h"

#include "point.h"

using namespace core;

void PointTest::testConstructors()
{
    Point<bool, 1> vb1;
    Point<bool, 2> vb2;
    Point<bool, 3> vb3;
    Point<bool, 4> vb4;
    Point<bool, 5> vb5;

    QVERIFY(!vb1.at(0));
    QVERIFY(!vb2.at(1));
    QVERIFY(!vb3.at(2));
    QVERIFY(!vb4.at(3));
    QVERIFY(!vb5.at(4));

    Point<int, 1> vi1(5);
    Point<int, 2> vi2(1, 6);
    Point<int, 3> vi3(1, 3, 7);
    Point<int, 4> vi32;

    QCOMPARE(vi1.x(), 5);
    QCOMPARE(vi2.y(), 6);
    QCOMPARE(vi3.z(), 7);
    QCOMPARE(vi32.x(), 0);
    QCOMPARE(vi32.y(), 0);
    QCOMPARE(vi32.z(), 0);

    Point<float, 3> vf31(4.23, 34.43, 43.234);
    Point<float, 3> vf32(vf31);

    QVERIFY(qFuzzyCompare(vf31.y(), vf32.y()));
}

void PointTest::testGetterFunctions()
{
    Point<int, 2> vi2(423, 712);

    QCOMPARE(vi2.at(0), vi2.x());
    QCOMPARE(vi2[1], vi2.y());

    Point<double, 3> vd3(5.46, 34.34, 67.765);

    QVERIFY(qFuzzyCompare(vd3.at(0), 5.46));
    QVERIFY(qFuzzyCompare(vd3[1], 34.34));
    QVERIFY(qFuzzyCompare(vd3.z(), 67.765));
}

void PointTest::testSetterFunctions()
{
    Point<int, 2> vi2;

    vi2[0] = 5;
    vi2.setY(7);

    QCOMPARE(vi2.x(), 5);
    QCOMPARE(vi2.y(), 7);

    Point<double, 3> vd3;

    vd3[0] = 5.46;
    vd3.setY(34.34);

    QVERIFY(qFuzzyCompare(vd3.at(0), 5.46));
    QVERIFY(qFuzzyCompare(vd3[1], 34.34));
    QVERIFY(qFuzzyCompare(vd3.z(), 0));
}

void PointTest::testComparation()
{
    QVERIFY((Point<int, 2>(4, 5) != Point<int, 2>(5, 5)));
    QVERIFY((Point<double, 3>(434.34, 56.435, 23.88) ==
              Point<double, 3>(434.34, 56.435, 23.88)));
    QVERIFY((Point<char, 2>('a', 'c') == Point<char, 2>('a', 'c')));
    QVERIFY((Point<char, 2>('a', 'c') != Point<char, 2>('a', 'd')));
}

void PointTest::testOffsets()
{
    Point<int, 2> vi(4, 4);

    QCOMPARE(vi.offset(1, 1), (Point<int, 2>(5, 5)));
    QCOMPARE(vi.offset(0, -1), (Point<int, 2>(4, 3)));
    QCOMPARE(vi.offset(-1, 2), (Point<int, 2>(3, 6)));
    QCOMPARE(vi.offset(-3, -4), (Point<int, 2>(1, 0)));

    Point<float, 3> vf(3.5, -0.5, 1.5);

    QCOMPARE(vf.up(), (Point<float, 3>(3.5, -0.5, 2.5)));
    QCOMPARE(vf.down(), (Point<float, 3>(3.5, -0.5, 0.5)));
    QCOMPARE(vf.right(), (Point<float, 3>(3.5, 0.5, 1.5)));
    QCOMPARE(vf.left(), (Point<float, 3>(3.5, -1.5, 1.5)));
    QCOMPARE(vf.forward(), (Point<float, 3>(4.5, -0.5, 1.5)));
    QCOMPARE(vf.backward(), (Point<float, 3>(2.5, -0.5, 1.5)));

    QCOMPARE(vf.up(0), (Point<float, 3>(3.5, -0.5, 1.5)));
    QCOMPARE(vf.down(1), (Point<float, 3>(3.5, -0.5, 0.5)));
    QCOMPARE(vf.right(5), (Point<float, 3>(3.5, 4.5, 1.5)));
    QCOMPARE(vf.left(10), (Point<float, 3>(3.5, -10.5, 1.5)));

    QCOMPARE(vf.up().left().down().right(), vf);
    QCOMPARE(vf.up().right(), vf.right().up());
}

void PointTest::testMoveAndGo()
{
    Point<int, 2> vi(5, 3);

    QCOMPARE(vi.move(1, 0), (Point<int, 2>(6, 3)));
    QCOMPARE(vi.move(1, 2), (Point<int, 2>(7, 5)));
    QCOMPARE(vi.move(-6, 0).move(0, -4), (Point<int, 2>(1, 1)));

    Point<float, 3> vf(3.5, -0.5, 1.5);

    QCOMPARE(vf.goForward(), (Point<float, 3> (4.5, -0.5, 1.5)));
    QCOMPARE(vf.goForward().goRight(2), (Point<float, 3> (5.5, 1.5, 1.5)));
}

void PointTest::testProduct()
{
    QCOMPARE((Point<int, 2>(1, 0).product()), 0);
    QCOMPARE((Point<int, 2>(6, 4).product()), 24);

    QVERIFY(qFuzzyCompare(Point<double, 3>(3.34, 6.35, 3.88).product(), 82.29092));
}
