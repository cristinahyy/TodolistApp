#include "Activity.h"

Activity::Activity(const std::string& desc, const std::string& date, bool comp)
    : description(desc), dueDate(date),completed(comp) {}

std::string Activity::getDescription() const {
    return description;
}

std::string Activity::getDueDate() const {
    return dueDate;
}

bool Activity::isCompleted() const {
    return completed;
}

void Activity::setCompleted(bool status) {
    completed = status;
}

