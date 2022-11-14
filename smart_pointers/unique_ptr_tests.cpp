#include "unique_ptr.hpp"

#include <gtest/gtest.h>

// for tests google test.
TEST(HelloTest, BasicAssertions)
{
    // Expect two strings not to be equal.
    EXPECT_STRNE("hello", "world");
    // Expect equality.
    EXPECT_EQ(7 * 6, 42);
}

TEST(SmartPointerStateTest1, BasicState1)
{
    int *raw_ptr = new int;
    *raw_ptr = 5;
    smart_ptr::unique_ptr<int> smt_ptr(raw_ptr);

    EXPECT_EQ(*raw_ptr, *smt_ptr);
    EXPECT_EQ(raw_ptr, smt_ptr.get());
    EXPECT_EQ(*raw_ptr, *smt_ptr.get());
}

struct point_t
{
    double x = 0.0;
    double y = 0.0;
};

TEST(SmartPointerStateTest2, BasicState2)
{
    point_t *point = new point_t();
    point->x = 5.0;
    point->y = 10.0;

    smart_ptr::unique_ptr<point_t> smt_ptr(point);

    EXPECT_EQ(point->x, smt_ptr->x);
    EXPECT_EQ(point->y, smt_ptr->y);
    EXPECT_EQ(point, smt_ptr.get());
}

TEST(BoolTest1, BoolOperator)
{
    smart_ptr::unique_ptr<int> smt_ptr1(new int);
    *smt_ptr1 = 5;

    smart_ptr::unique_ptr<int> smt_ptr2(new int);
    *smt_ptr2 = 10;

    EXPECT_TRUE(smt_ptr1);
    EXPECT_TRUE(smt_ptr2);
}

TEST(BoolTest2, BoolOperator)
{
    smart_ptr::unique_ptr<int> smt_ptr1(nullptr);

    EXPECT_FALSE(smt_ptr1);
}

TEST(MoveTests1, Move)
{
    smart_ptr::unique_ptr<int> smt_ptr1(new int);
    *smt_ptr1 = 5;

    smart_ptr::unique_ptr<int> smt_ptr2 = std::move(smt_ptr1);

    EXPECT_EQ(*smt_ptr2, 5);
    EXPECT_EQ(*smt_ptr2.get(), 5);
}

TEST(MoveTests2, Move)
{
    smart_ptr::unique_ptr<int> smt_ptr1(new int);
    *smt_ptr1 = 5;

    smart_ptr::unique_ptr<int> smt_ptr2(new int);
    *smt_ptr2 = 10;

    smt_ptr2 = std::move(smt_ptr1);

    EXPECT_EQ(*smt_ptr2, 5);
    EXPECT_EQ(*smt_ptr2.get(), 5);
}