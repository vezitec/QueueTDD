#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "queue.hpp"

class QueueTests : public ::testing::Test
{
public:
    Queue queueTested;
};

TEST_F(QueueTests, When_CreatedNewQueue_Expected_TwoPointersToStartAndEndOfTheQueueAreNullPtr)
{
    EXPECT_EQ(queueTested.isEmpty(), true);
}

TEST_F(QueueTests, When_AddenNewElement_Expect_QueueIsNotEmpty)
{
    queueTested.push(5);
    EXPECT_EQ(queueTested.isEmpty(), false);
}

TEST_F(QueueTests, When_AddenNewElementAndRemoved_Expect_QueueIsEmpty)
{
    queueTested.push(5);
    queueTested.pop();
    queueTested.pop(); // message "Queue is already empty."
    EXPECT_EQ(queueTested.isEmpty(), true);
}

TEST_F(QueueTests, When_FrontMethodIsUsed_Expect_Five)
{
    queueTested.push(5);
    EXPECT_EQ(queueTested.front(), 5);
}
TEST_F(QueueTests, When_BackMethodIsUsed_Expect_Five)
{
    queueTested.push(5);
    EXPECT_EQ(queueTested.back(), 5);
}
TEST_F(QueueTests, When_TwicePushedNumber_Expect_FrontIsNotEqualBack)
{
    queueTested.push(5);
    queueTested.push(7);
    EXPECT_NE(queueTested.front(), queueTested.back());
}
TEST_F(QueueTests, When_TwicePushedNumberAndOnePop_Expect_FrontIsEqualBack)
{
    queueTested.push(5);
    queueTested.push(7);
    queueTested.pop();
    EXPECT_EQ(queueTested.front(), queueTested.back());
}
TEST_F(QueueTests, When_FiveTimesPushedNumberAndTwicePop_Expect_FrontIsEqual7AndBackIsEqual9)
{
    queueTested.push(3);
    queueTested.push(5);
    queueTested.push(7);
    queueTested.push(9);
    queueTested.pop();
    queueTested.pop();
    EXPECT_EQ(queueTested.front(), 7);
    EXPECT_EQ(queueTested.back(), 9);
}