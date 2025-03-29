#ifndef RYAZANOV_LR3_4_METHODS_H
#define RYAZANOV_LR3_4_METHODS_H

#include "M:\\Program\\Ryazanova_LR3-4_ClassAirplane\\Ryazanova_LR3-4_ClassAirplane.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <limits>

// Глобальный вектор объектов класса
vector<Airplane> airplanes;

// Функции проверки корректности входных данных
bool isValidCapacity(int capacity);
bool isValidSpeed(double speed);

// Функции ввода данных
int inputCapacity();
double inputSpeed();
void displayAllAirplanes();
vector<Airplane> getSortedAirplanes();

// Проверка корректности входных данных
bool isValidCapacity(int capacity) {
    return capacity > 0;
}

bool isValidSpeed(double speed) {
    return speed >= 0;
}

// Ввод данных
int inputCapacity() {
    int capacity;
    do {
        cout << "Enter capacity: ";
        cin >> capacity;
    } while (!isValidCapacity(capacity));
    return capacity;
}

double inputSpeed() {
    double speed;
    do {
        cout << "Enter speed: ";
        cin >> speed;
    } while (!isValidSpeed(speed));
    return speed;
}

// Отображение всех объектов класса
void displayAllAirplanes() {
    for (const auto& airplane : airplanes) {
        airplane.display();
    }
}

// Получение отсортированного списка самолетов
vector<Airplane> getSortedAirplanes() {
    vector<Airplane> sortedAirplanes = airplanes;
    sort(sortedAirplanes.begin(), sortedAirplanes.end());
    return sortedAirplanes;
}
void EnterMenu(int& choice, const string& prompt) {
    cout << prompt;
    while (!(cin >> choice)) {
        cout << "Ошибка ввода. Пожалуйста, введите число." << endl;
        cin.clear(); // Сбросить состояние потока
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Игнорировать неверный ввод
        cout << prompt; // Повторный запрос
    }
}

void addAirPlane(){
      string model;
        cout << "Enter model: ";
        cin >> model;
        int capacity = inputCapacity();
        vector<double> speeds;
        for (int i = 0; i < 3; ++i) { // Пример: ввод 3 скоростей
            speeds.push_back(inputSpeed());
        }
        airplanes.emplace_back(model, capacity, speeds);
    };
#endif // RYAZANOV_LR3_4_METHODS_H