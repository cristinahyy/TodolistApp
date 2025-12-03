#include "gtest/gtest.h"
#include "../Activity.h"

TEST(ActivityTest, Initialization) {
    Activity task("Fare la spesa");
    EXPECT_EQ(task.getDescription(), "Fare la spesa");
    EXPECT_FALSE(task.isCompleted());
}

TEST(ActivityTest, ToggleStatus) {
    Activity task("Studiare C++");
    task.setCompleted(true);
    EXPECT_TRUE(task.isCompleted());
}
