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
