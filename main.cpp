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
                        std::string date = activities[i].getDueDate();

                        std::cout << i + 1 << ". " << status << " " << activities[i].getDescription() << "\n";

                        if (!date.empty()) {
                            std::cout << " (Scadenza: " << date << ")";
                        }
                        std::cout << "\n";
                    }
                }
                break;
            }
            case 2: {
                std::cout << "Inserisci descrizione: ";
                std::string desc;
                std::getline(std::cin, desc);
                    std::cout << "Inserisci data scadenza (es. 31/12/2024) o premi Invio per vuota: ";
                    std::string date;
                    std::getline(std::cin, date);

                if (!desc.empty()) {
                    manager.addActivity(desc, date);
                    std::cout << "Attivita' aggiunta. \n";
                }
                break;
            }
            case 3: {
                std::cout << "Inserisci il numero dell'attivita' da modificare: ";
                int index;
                std::cin >> index;

                int listSize = manager.getActivities().size();
                if (index > 0 && index <= listSize) {
                    manager.markCompleted(index - 1);
                    std::cout << "Stato aggiornato con successo.\n";
                } else {
                    std::cout << "ERRORE: Indice non trovato. Inserisci un numero tra 1 e " << listSize << ".\n";
                }
                break;
            }
            case 4: {
                std::cout << "Inserisci il numero dell'attivita' da rimuovere: ";
                int index;
                std::cin >> index;

                int listSize = manager.getActivities().size();
                if (index > 0 && index <= listSize) {
                        manager.removeActivity(index - 1);
                        std::cout << "Attivita' rimossa.\n";
                    } else {
                        std::cout << "ERRORE: Impossibile rimuovere. Indice non valido.\n";
                    }
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
