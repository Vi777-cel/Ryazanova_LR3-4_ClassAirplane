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
    vector<double> speeds;

public:
    // Конструкторы
    Airplane();
    Airplane(const string& model, int capacity, const vector<double>& speeds);
    Airplane(const Airplane& other); 
    Airplane(Airplane&& other) noexcept;
    Airplane& operator=(const Airplane& other); 
    Airplane& operator=(Airplane&& other) noexcept; 
    ~Airplane(); // Деструктор

    // Методы get и set
    string getModel() const;
    void setModel(const string& model);
    int getCapacity() const;
    void setCapacity(int capacity);
    vector<double> getSpeeds() const;
    void setSpeeds(const vector<double>& speeds);

    // Методы
    void display() const; 
    double averageSpeed() const; 

    // Перегруженные операции
    bool operator<(const Airplane& other) const; 
    Airplane operator+(const Airplane& other) const;
    Airplane& operator++(); 
    Airplane operator++(int); 
};

#endif 