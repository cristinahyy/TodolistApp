#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <string>

class Activity {
public:
    Activity(const std::string& description, bool completed = false);

    std::string getDescription() const;
    bool isCompleted() const;
    void setCompleted(bool completed);

private:
    std::string description;
    bool completed;
};

#endif //ACTIVITY_H
