#include "gtest/gtest.h"
#include "../Todolist.h"

TEST(TodolistTest, AddAndRemove) {
    Todolist manager;
    manager.addActivity("Test 1");
    manager.addActivity("Test 2");

    auto list = manager.getActivities();
    EXPECT_EQ(list.size(), 2);
    EXPECT_EQ(list[0].getDescription(), "Test 1");

    manager.removeActivity(0);
    EXPECT_EQ(manager.getActivities().size(), 1);
    EXPECT_EQ(manager.getActivities()[0].getDescription(), "Test 2");
}

TEST(TodolistTest, Persistence) {
    Todolist manager;
    manager.addActivity("Save Me");
    manager.getActivities()[0].setCompleted(true);

    std::string testFile = "test_data.txt";
    manager.saveToFile(testFile);

    Todolist newManager;
    newManager.loadFromFile(testFile);

    auto list = newManager.getActivities();
    EXPECT_EQ(list.size(), 1);
    EXPECT_EQ(list[0].getDescription(), "Save Me");
}
