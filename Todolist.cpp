#include "Todolist.h"
#include <fstream>
#include <iostream>

void Todolist::addActivity(const std::string& desc, const std::string& date) {
    activities.emplace_back(desc, date);
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
            file << activity.isCompleted() << "|"
                 << activity.getDueDate() << "|"
                 << activity.getDescription() << "\n";
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
            size_t firstPipe= line.find('|');
            size_t secondPipe = line.find('|', firstPipe + 1);

            if (firstPipe != std::string::npos && secondPipe != std::string::npos) {
                std::string statusStr = line.substr(0, firstPipe);
                std::string dateStr = line.substr(firstPipe + 1, secondPipe - firstPipe - 1);
                std::string descStr = line.substr(secondPipe + 1);

                Activity newActivity(descStr, dateStr);
                if (statusStr == "1") {
                    newActivity.setCompleted(true);
                }
                activities.push_back(newActivity);
            }
        }
        file.close();
    }
}