#include <iostream>
#include <limits>
#include "Todolist.h"

void clearInputBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void printMenu() {
    std::cout << "\n--- TODO LIST APP ---\n";
    std::cout << "1. Visualizza Attivita'\n";
    std::cout << "2. Aggiungi Attivita'\n";
    std::cout << "3. Segna come Completata/Da fare\n";
    std::cout << "4. Rimuovi Attivita'\n";
    std::cout << "5. Salva su disco\n";
    std::cout << "6. Carica da disco\n";
    std::cout << "0. Esci\n";
    std::cout << "Scegli un'opzione: ";
}

int main() {
    Todolist manager;
    int choice = -1;
    std::string filename = "database.txt";
    manager.loadFromFile(filename);

    while (choice != 0) {
        printMenu();
        if (!(std::cin >> choice)) {
            std::cout << "Input non valido. Inserisci un numero.\n";
            std::cin.clear();
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();

        switch (choice) {
            case 1: {
                auto activities = manager.getActivities();
                std::cout << "\nELENCO ATTIVITA':\n";
                if (activities.empty()) {
                    std::cout << " - Nessuna attivita' presente.\n";
                } else {
                    for (size_t i = 0; i < activities.size(); ++i) {
                        std::string status = activities[i].isCompleted() ? "[X]" : "[ ]";
                        std::cout << i + 1 << ". " << status << " " << activities[i].getDescription() << "\n";
                    }
                }
                break;
            }
            case 2: {
                std::cout << "Inserisci descrizione: ";
                std::string desc;
                std::getline(std::cin, desc);
                if (!desc.empty()) {
                    manager.addActivity(desc);
                    std::cout << "Attivita' aggiunta.\n";
                }
                break;
            }
            case 3: {
                std::cout << "Inserisci il numero dell'attivita' da modificare: ";
                int index;
                std::cin >> index;
                manager.markCompleted(index - 1);
                std::cout << "Stato aggiornato.\n";
                break;
            }
            case 4: {
                std::cout << "Inserisci il numero dell'attivita' da rimuovere: ";
                int index;
                std::cin >> index;
                manager.removeActivity(index - 1);
                std::cout << "Attivita' rimossa.\n";
                break;
            }
            case 5: {
                manager.saveToFile(filename);
                std::cout << "Dati salvati in " << filename << "\n";
                break;
            }
            case 6: {
                manager.loadFromFile(filename);
                std::cout << "Dati caricati da " << filename << "\n";
                break;
            }
            case 0:
                std::cout << "Uscita...\n";
                break;
            default:
                std::cout << "Opzione non valida.\n";
        }
    }

    return 0;
}
