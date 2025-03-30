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
    while (true) {
        cout << "Введите емкость: ";
        cin >> capacity;
        if (cin.fail() || !isValidCapacity(capacity)) {
            cin.clear(); // Сбросить состояние потока
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Игнорировать неверный ввод
            cout << "Ошибка ввода. Пожалуйста, введите положительное число." << std::endl;
        } else {
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Игнорировать оставшийся ввод
            break; // Ввод корректен, выходим из цикла
        }
    }
    return capacity;
}

double inputSpeed() {
    double speed;
    while (true) {
        cout << "Введите скорость: ";
        cin >> speed;
        if (cin.fail() || !isValidSpeed(speed)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Ошибка ввода. Пожалуйста, введите неотрицательное число." << endl;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            break; 
        }
    }
    return speed;
}

// Отображение всех объектов класса
void displayAllAirplanes() {
    for (const auto& airplane : airplanes) {
        airplane.display();
    }
}

// Получение отсортированного списка самолетов
void displaySortedAirplanes() {
    vector<Airplane> sortedAirplanes = airplanes; 
    sort(sortedAirplanes.begin(), sortedAirplanes.end());
    
    cout << "Отсортированные самолеты по средней скорости:" << endl;
    for (const auto& airplane : sortedAirplanes) {
        airplane.display();
    }
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
        cout << "Введите модель: ";
        cin >> model;
        int capacity = inputCapacity();
        vector<double> speeds;
        for (int i = 0; i < 3; ++i) { // Пример: ввод 3 скоростей
            speeds.push_back(inputSpeed());
        }
        airplanes.emplace_back(model, capacity, speeds);
    };
#endif 