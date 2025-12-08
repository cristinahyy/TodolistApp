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

TEST(ActivityTest, DateHandling) {
    Activity task("Esame C++", "15/02/2025");
    EXPECT_EQ(task.getDescription(), "Esame C++");
    EXPECT_EQ(task.getDueDate(), "15/02/2025");
}