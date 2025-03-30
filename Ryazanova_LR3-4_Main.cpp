#include <iostream>
#include <ctime>
#include <map>
#include <functional>
#include "M:\\Program\\Ryazanova_LR3-4_ClassAirplane\\Ryazanova_LR3-4_ClassAirplane.cpp"
using namespace std;   

// Структура для меню
class MenuItem {
public:
    string title; // Название пункта
    function<void()> action; // Действие
};
int main() {
    //Генерация случайного значения
srand(time(NULL));
    map<int, MenuItem> menu = {
        {1, {"Добавить самолет",addAirPlane }},
        {2, {"Показать все самолеты", displayAllAirplanes}},
        {3, {"Отсортировать самолеты",displaySortedAirplanes}},
    };
    int choice = 0;
    cout << "Меню:" << endl;

    // Вывод
    for (const auto& item : menu) {
        cout << "Task " << item.first << ". " << item.second.title << endl;
    }
    cout << "0. Выход" << endl;

    while (true) {
        EnterMenu(choice, "Введите номер пункта: ");
        cout << "Пользователь выбрал пункт: " << choice << endl;

        // Выход из программы, если выбран 0
        if (choice == 0) {
            cout << "2025 Viktoria Ryazanova" << endl; 
            break;
        }

        // Проверка, существует ли выбранный пункт меню
        if (menu.find(choice) != menu.end()) {
            menu[choice].action(); // Вызов действия
        } else {
            cout << "Некорректный ввод "; 
        }
        cout << endl;
    }
    return 0;
}
