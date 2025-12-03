#include "Activity.h"

Activity::Activity(const std::string& desc, bool comp)
    : description(desc), completed(comp) {}

std::string Activity::getDescription() const {
    return description;
}

bool Activity::isCompleted() const {
    return completed;
}

void Activity::setCompleted(bool status) {
    completed = status;
}

