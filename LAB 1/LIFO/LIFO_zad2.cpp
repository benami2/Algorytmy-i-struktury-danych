
#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class Queue {
private:
    static const int MAX_SIZE = 10;
    T data[MAX_SIZE];
    int top;
    int count;

public:
    // Konstruktor
    Queue() : top(0), count(0) {}

    void push(const T& element) {
        if (count >= MAX_SIZE) {
            throw overflow_error("Kolejka jest pelna!");
        }

        data[top++] = element; // dodaj element i zwiększ top
        count++;
    }

    T pop() {
        if (is_empty()) {
            throw underflow_error("Kolejka jest pusta!");
        }
        count--;
        return data[--top]; // najpierw zmniejsz top, potem zwróć element



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
        int current = top;
        for (int i = 0; i < count ; i++) {
            cout << data[i];
            if (i != count - 1) {
                cout << "," ;
            }

        }

        cout << "]" << endl;
        cout << " Rear: " << top << ", Count: " << count << endl;
    }
};


int main() {
    Queue<int> queue;
    int wybor;
    bool running = true;


    while (running) {
        cout << "\n--- MENU ---" << endl;
        cout << "1. Dodaj element do kolejki" << endl;
        cout << "2. Usun element z kolejki" << endl;

        cout << "3. Wyswietl cala kolejke" << endl;
        cout << "4. Pokaz liczbe elementow" << endl;
        cout << "0. Zakoncz program" << endl;
        cout << "Twoj wybor: ";
        cin >> wybor;

        try {
            switch (wybor) {
                case 1: {
                    int value;
                    cout << "Podaj wartosc: ";
                    cin >> value;
                    queue.push(value);
                    cout << "Dodano " << value << " do kolejki." << endl;
                    break;
                }
                case 2: {
                    int removed = queue.pop();
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