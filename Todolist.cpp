#include "Todolist.h"
#include <fstream>
#include <iostream>

void Todolist::addActivity(const std::string& desc) {
    activities.emplace_back(desc);
}

void Todolist::removeActivity(int index) {
    if (index >= 0 && index < activities.size()) {
        activities.erase(activities.begin() + index);
    }
}

void Todolist::markCompleted(int index) {
    if (index >= 0 && index < activities.size()) {
        bool current = activities[index].isCompleted();
        activities[index].setCompleted(!current);
    }
}

std::vector<Activity> Todolist::getActivities() const {
    return activities;
}

void Todolist::saveToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& activity : activities) {
            file << activity.isCompleted() << "|" << activity.getDescription() << "\n";
        }
        file.close();
    }
}

void Todolist::loadFromFile(const std::string& filename) {
    activities.clear();
    std::ifstream file(filename);
    std::string line;

    if (file.is_open()) {
        while (std::getline(file, line)) {
            size_t delimiterPos = line.find('|');
            if (delimiterPos != std::string::npos) {
                std::string statusStr = line.substr(0, delimiterPos);
                std::string desc = line.substr(delimiterPos + 1);

                Activity newActivity(desc);
                if (statusStr == "1") {
                    newActivity.setCompleted(true);
                }
                activities.push_back(newActivity);
            }
        }
        file.close();
    }
}