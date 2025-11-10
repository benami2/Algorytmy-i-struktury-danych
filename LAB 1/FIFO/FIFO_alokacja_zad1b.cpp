#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class Queue {
private:

    T* data;    // wskaźnik do dynamicznej tablicy
    int max_size;
    int pierwszy;
    int ostatni;
    int count;

public:
    // Konstruktor
    Queue(int rozmiar) : pierwszy(0), ostatni(0), count(0), max_size(rozmiar) {
        data = new T[max_size];    // dynamiczna alokacja pamięci
    }

    void enqueue(const T& element) {
        if (count >= max_size) {
            throw overflow_error("Kolejka jest pelna!");
        }

        data[ostatni] = element;
        ostatni = (ostatni + 1) % max_size;
        count++;
    }

    T dequeue() {
        if (is_empty()) {
            throw underflow_error("Kolejka jest pusta!");
        }

        T element = data[pierwszy];
        pierwszy = (pierwszy + 1) % max_size;
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
    ~Queue() {
        delete[] data;
    }


    void display() const {
        cout << "Kolejka: [";
        int current = pierwszy;
        for (int i = 0; i < count; i++) {
            cout << data[current];
            if (i < count - 1) cout << ", ";
            current = (current + 1) % max_size;
        }
        cout << "]" << endl;
        cout << "Front: " << pierwszy << ", Rear: " << ostatni << ", Count: " << count << endl;
    }
};


int main() {
    int rozmiar;
    cout << "Podaj rozmiar kolejki: ";
    cin >> rozmiar;
    Queue<int> queue(rozmiar);

    int wybor;
    bool running = true;

    cout << "===== KOLEJKA CYKLICZNA =====" << endl;

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
                    queue.enqueue(value);
                    cout << "Dodano " << value << " do kolejki." << endl;
                    break;
                }
                case 2: {
                    int removed = queue.dequeue();
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