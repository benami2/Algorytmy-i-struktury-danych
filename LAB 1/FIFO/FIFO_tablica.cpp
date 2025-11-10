#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class Queue {
private:
    static const int MAX_SIZE = 10;
    T data[MAX_SIZE];
    int pierwszy;
    int ostatni;
    int count;

public:
    // Konstruktor
    Queue() : pierwszy(0), ostatni(0), count(0) {}

    void AddingToTheEndOfQueue(const T& element) {
        if (count >= MAX_SIZE) {
            throw overflow_error("Kolejka jest pelna!");
        }

        data[ostatni] = element;
        ostatni = (ostatni + 1) % MAX_SIZE;
        count++;
    }

    T DeletingFirstInQueue() {
        if (is_empty()) {
            throw underflow_error("Kolejka jest pusta!");
        }

        T element = data[pierwszy];
        pierwszy = (pierwszy + 1) % MAX_SIZE;
        count--;
        return element;
    }

    // Sprawdza czy kolejka jest pusta
    bool is_empty() const {
        return count == 0;
    }

    // Zwraca liczbę elementów w kolejce
    int size() const {
        return count;
    }


    void display() const {
        cout << "Kolejka: [";
        int current = pierwszy;
        for (int i = 0; i < count; i++) {
            cout << data[current];
            if (i < count - 1) cout << ", ";
            current = (current + 1) % MAX_SIZE;
        }
        cout << "]" << endl;
        cout << "Front: " << pierwszy << ", Rear: " << ostatni << ", Count: " << count << endl;
    }
};


int main() {
    Queue<int> queue;
    int wybor;
    bool running = true;

    cout << "===== KOLEJKA CYKLICZNA =====" << endl;

    while (running) {
        cout << "\n--- MENU ---" << endl;
        cout << "1. Dodaj element do kolejki" << endl;
        cout << "2. Usun element z kolejki" << endl;

        cout << "4. Wyswietl cala kolejke" << endl;
        cout << "5. Pokaz liczbe elementow" << endl;
        cout << "0. Zakoncz program" << endl;
        cout << "Twoj wybor: ";
        cin >> wybor;

        try {
            switch (wybor) {
                case 1: {
                    int value;
                    cout << "Podaj wartosc: ";
                    cin >> value;
                    queue.AddingToTheEndOfQueue(value);
                    cout << "Dodano " << value << " do kolejki." << endl;
                    break;
                }
                case 2: {
                    int removed = queue.DeletingFirstInQueue();
                    cout << "Usunieto: " << removed << endl;
                    break;
                }

                case 3: {
                    queue.display();
                    break;
                }
                case 4: {
                    cout << "Liczba elementow w kolejce: " << queue.size() << endl;
                    break;
                }
                case 0: {
                    cout << "Koniec programu." << endl;
                    running = false;
                    break;
                }
                default:
                    cout << "Nieprawidlowy wybor!" << endl;
                    break;
            }
        } catch (const exception& e) {
            cout << "Blad: " << e.what() << endl;
        }
    }
    return 0;
}