#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "M:\\Program\\Ryazanova_LR3-4_ClassAirplane\\Ryazanova_LR3-4_Methods.h"

using namespace std;

//Конструкторы
Airplane::Airplane() : model("Unknown"), capacity(0), speeds({}) {}//по умолчанию

Airplane::Airplane(const std::string& model, int capacity, const std::vector<double>& speeds)
    : model(model), capacity(capacity), speeds(speeds) {}//С параметрами

Airplane::Airplane(const Airplane& other) : model(other.model), capacity(other.capacity), speeds(other.speeds) {}//Копирования

Airplane::Airplane(Airplane&& other) noexcept : model(std::move(other.model)), capacity(other.capacity), speeds(std::move(other.speeds)) {
    other.capacity = 0;//Перемещения
}
//Операторы присваивания(копирования)
Airplane& Airplane::operator=(const Airplane& other) {
    if (this != &other) {
        model = other.model;
        capacity = other.capacity;
        speeds = other.speeds;
    }
    return *this;
}
//Операторы присваивания(перемещения)
Airplane& Airplane::operator=(Airplane&& other) noexcept {
    if (this != &other) {
        model = move(other.model);
        capacity = other.capacity;
        speeds = move(other.speeds);
        other.capacity = 0;
    }
    return *this;
}

Airplane::~Airplane() {}

// Сеттеры и геттеры
string Airplane::getModel() const { return model; }
void Airplane::setModel(const string& model) { this->model = model; }
int Airplane::getCapacity() const { return capacity; }
void Airplane::setCapacity(int capacity) { this->capacity = capacity; }
vector<double> Airplane::getSpeeds() const { return speeds; }
void Airplane::setSpeeds(const vector<double>& speeds) { this->speeds = speeds; }


void Airplane::display() const {
    cout << "Model: " << model << ", Capacity: " << capacity << ", Speeds: ";
    for (const auto& speed : speeds) {
        cout << speed << " ";
    }
    cout << endl;
}

// Средняя скорость(расчет)
double Airplane::averageSpeed() const {
    double sum = 0;
    for (const auto& speed : speeds) {
        sum += speed;
    }
    return speeds.empty() ? 0 : sum / speeds.size();
}

//Перегруженные оператооры
bool Airplane::operator<(const Airplane& other) const {
    return averageSpeed() < other.averageSpeed();
}

Airplane Airplane::operator+(const Airplane& other) const {
    return Airplane(model + " & " + other.model, capacity + other.capacity, speeds);
}

Airplane& Airplane::operator++() {// Префиксный
    capacity++;
    return *this;
}

Airplane Airplane::operator++(int) {// Постфиксный 
    Airplane temp = *this;
    ++(*this);
    return temp;
}