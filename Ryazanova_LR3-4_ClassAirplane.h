#ifndef RYAZANOVA_LR3_4_CLASSAIRPLANE_H
#define RYAZANOVA_LR3_4_CLASSAIRPLANE_H

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Airplane {
private:
    string model;
    int capacity;
    vector<double> speeds; // Скорости в разных режимах полета

public:
    // Конструкторы
    Airplane();
    Airplane(const string& model, int capacity, const vector<double>& speeds);
    Airplane(const Airplane& other); // Конструктор копирования
    Airplane(Airplane&& other) noexcept; // Конструктор перемещения
    Airplane& operator=(const Airplane& other); // Оператор присваивания
    Airplane& operator=(Airplane&& other) noexcept; // Оператор перемещения
    ~Airplane(); // Деструктор

    // Методы get и set
    string getModel() const;
    void setModel(const string& model);
    int getCapacity() const;
    void setCapacity(int capacity);
    vector<double> getSpeeds() const;
    void setSpeeds(const vector<double>& speeds);

    // Методы
    void display() const; // Вывод информации о самолете
    double averageSpeed() const; // Средняя скорость

    // Перегруженные операции
    bool operator<(const Airplane& other) const; // Сравнение по средней скорости
    Airplane operator+(const Airplane& other) const; // Сложение
    Airplane& operator++(); // Префиксный инкремент
    Airplane operator++(int); // Постфиксный инкремент
};

#endif 