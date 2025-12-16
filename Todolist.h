#ifndef TODOLIST_H
#define TODOLIST_H

#include <vector>
#include <string>
#include "Activity.h"

class Todolist {
public:
    void addActivity(const std::string& description);
    void removeActivity(int index);
    void markCompleted(int index);
    std::vector<Activity> getActivities() const;

    void saveToFile(const std::string& filename);
    void loadFromFile(const std::string& filename);
    void addActivity(const std::string& desc, const std::string& date);

private:
    std::vector<Activity> activities;
};

#endif //TODOLIST_H
