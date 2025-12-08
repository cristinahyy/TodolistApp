#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <string>

class Activity {
public:
    Activity(const std::string& description, const std::string& date = "", bool completed = false);

    Activity(const std::string& desc, bool comp);
    std::string getDescription() const;
    std::string getDueDate() const;

    bool isCompleted() const;
    void setCompleted(bool completed);

private:
    std::string description;
    std::string dueDate;
    bool completed;
};

#endif //ACTIVITY_H
