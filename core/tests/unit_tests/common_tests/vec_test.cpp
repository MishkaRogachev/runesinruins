#include "vec_test.h"

#include "vec.h"

using namespace core;

void VecTest::testConstructors()
{
    Vec<bool, 1> vb1;
    Vec<bool, 2> vb2;
    Vec<bool, 3> vb3;
    Vec<bool, 4> vb4;
    Vec<bool, 5> vb5;

    Q_ASSERT(!vb1.at(0));
    Q_ASSERT(!vb2.at(1));
    Q_ASSERT(!vb3.at(2));
    Q_ASSERT(!vb4.at(3));
    Q_ASSERT(!vb5.at(4));

    Vec<int, 1> vi1(5);
    Vec<int, 2> vi2(1, 6);
    Vec<int, 3> vi3(1, 3, 7);
    Vec<int, 4> vi32;

    QCOMPARE(vi1.x(), 5);
    QCOMPARE(vi2.y(), 6);
    QCOMPARE(vi3.z(), 7);
    QCOMPARE(vi32.x(), 0);
    QCOMPARE(vi32.y(), 0);
    QCOMPARE(vi32.z(), 0);

    Vec<float, 3> vf31(4.23, 34.43, 43.234);
    Vec<float, 3> vf32(vf31);

    Q_ASSERT(qFuzzyCompare(vf31.y(), vf32.y()));
}

void VecTest::testGetterFunctions()
{
    Vec<int, 2> vi2(423, 712);

    QCOMPARE(vi2.at(0), vi2.x());
    QCOMPARE(vi2[1], vi2.y());

    Vec<double, 3> vd3(5.46, 34.34, 67.765);

    Q_ASSERT(qFuzzyCompare(vd3.at(0), 5.46));
    Q_ASSERT(qFuzzyCompare(vd3[1], 34.34));
    Q_ASSERT(qFuzzyCompare(vd3.z(), 67.765));
}

void VecTest::testSetterFunctions()
{
    Vec<int, 2> vi2;

    vi2[0] = 5;
    vi2.setY(7);

    QCOMPARE(vi2.x(), 5);
    QCOMPARE(vi2.y(), 7);

    Vec<double, 3> vd3;

    vd3[0] = 5.46;
    vd3.setY(34.34);

    Q_ASSERT(qFuzzyCompare(vd3.at(0), 5.46));
    Q_ASSERT(qFuzzyCompare(vd3[1], 34.34));
    Q_ASSERT(qFuzzyCompare(vd3.z(), 0));
}

void VecTest::testComparation()
{
    Q_ASSERT((Vec<int, 2>(4, 5) != Vec<int, 2>(5, 5)));
    Q_ASSERT((Vec<double, 3>(434.34, 56.435, 23.88) ==
              Vec<double, 3>(434.34, 56.435, 23.88)));
    Q_ASSERT((Vec<char, 2>('a', 'c') == Vec<char, 2>('a', 'c')));
    Q_ASSERT((Vec<char, 2>('a', 'c') != Vec<char, 2>('a', 'd')));
}

void VecTest::testOffsets()
{
    Vec<int, 2> vi(4, 4);

    QCOMPARE(vi.offset(1, 1), (Vec<int, 2>(5, 5)));
    QCOMPARE(vi.offset(0, -1), (Vec<int, 2>(4, 3)));
    QCOMPARE(vi.offset(-1, 2), (Vec<int, 2>(3, 6)));
    QCOMPARE(vi.offset(-3, -4), (Vec<int, 2>(1, 0)));

    Vec<float, 3> vf(3.5, -0.5, 1.5);

    QCOMPARE(vf.up(), (Vec<float, 3>(3.5, -0.5, 2.5)));
    QCOMPARE(vf.down(), (Vec<float, 3>(3.5, -0.5, 0.5)));
    QCOMPARE(vf.right(), (Vec<float, 3>(3.5, 0.5, 1.5)));
    QCOMPARE(vf.left(), (Vec<float, 3>(3.5, -1.5, 1.5)));
    QCOMPARE(vf.forward(), (Vec<float, 3>(4.5, -0.5, 1.5)));
    QCOMPARE(vf.backward(), (Vec<float, 3>(2.5, -0.5, 1.5)));

    QCOMPARE(vf.up(0), (Vec<float, 3>(3.5, -0.5, 1.5)));
    QCOMPARE(vf.down(1), (Vec<float, 3>(3.5, -0.5, 0.5)));
    QCOMPARE(vf.right(5), (Vec<float, 3>(3.5, 4.5, 1.5)));
    QCOMPARE(vf.left(10), (Vec<float, 3>(3.5, -10.5, 1.5)));

    QCOMPARE(vf.up().left().down().right(), vf);
    QCOMPARE(vf.up().right(), vf.right().up());
}

void VecTest::testProduct()
{
    QCOMPARE((Vec<int, 2>(1, 0).product()), 0);
    QCOMPARE((Vec<int, 2>(6, 4).product()), 24);

    Q_ASSERT(qFuzzyCompare(Vec<double, 3>(3.34, 6.35, 3.88).product(), 82.29092));
}
