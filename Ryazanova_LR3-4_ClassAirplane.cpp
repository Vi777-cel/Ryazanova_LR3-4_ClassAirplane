#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "M:\\Program\\Ryazanova_LR3-4_ClassAirplane\\Ryazanova_LR3-4_Methods.h"

using namespace std;


Airplane::Airplane() : model("Unknown"), capacity(0), speeds({}) {}

Airplane::Airplane(const std::string& model, int capacity, const std::vector<double>& speeds)
    : model(model), capacity(capacity), speeds(speeds) {}

Airplane::Airplane(const Airplane& other) : model(other.model), capacity(other.capacity), speeds(other.speeds) {}

Airplane::Airplane(Airplane&& other) noexcept : model(std::move(other.model)), capacity(other.capacity), speeds(std::move(other.speeds)) {
    other.capacity = 0;
}

Airplane& Airplane::operator=(const Airplane& other) {
    if (this != &other) {
        model = other.model;
        capacity = other.capacity;
        speeds = other.speeds;
    }
    return *this;
}

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

// Getters and Setters
string Airplane::getModel() const { return model; }
void Airplane::setModel(const string& model) { this->model = model; }
int Airplane::getCapacity() const { return capacity; }
void Airplane::setCapacity(int capacity) { this->capacity = capacity; }
vector<double> Airplane::getSpeeds() const { return speeds; }
void Airplane::setSpeeds(const vector<double>& speeds) { this->speeds = speeds; }

// Method to display airplane information
void Airplane::display() const {
    cout << "Model: " << model << ", Capacity: " << capacity << ", Speeds: ";
    for (const auto& speed : speeds) {
        cout << speed << " ";
    }
    cout << endl;
}

// Average speed calculation
double Airplane::averageSpeed() const {
    double sum = 0;
    for (const auto& speed : speeds) {
        sum += speed;
    }
    return speeds.empty() ? 0 : sum / speeds.size();
}

// Overloaded operators
bool Airplane::operator<(const Airplane& other) const {
    return averageSpeed() < other.averageSpeed();
}

Airplane Airplane::operator+(const Airplane& other) const {
    return Airplane(model + " & " + other.model, capacity + other.capacity, speeds);
}

Airplane& Airplane::operator++() {
    capacity++;
    return *this;
}

Airplane Airplane::operator++(int) {
    Airplane temp = *this;
    ++(*this);
    return temp;
}