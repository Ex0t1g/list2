#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "Ru");
    list<string> toDoList; 
    list<string> archive; 

    int choice;
    string task;

    while (true) {
        cout << "Меню:\n";
        cout << "1. Добавить дело\n";
        cout << "2. Дело выполнено\n";
        cout << "3. Отобразить список дел\n";
        cout << "4. Отобразить отчёт (список выполненных дел)\n";
        cout << "Выберите действие (1-4): ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введите дело: ";
            cin.ignore();
            getline(cin, task);
            toDoList.push_back(task);
            break;

        case 2:
            if (toDoList.empty()) {
                cout << "Список дел пуст.\n";
            }
            else {
                cout << "Введите номер дела, которое выполнено (1-" << toDoList.size() << "): ";
                int index;
                cin >> index;

                if (index >= 1 && index <= toDoList.size()) {
                    auto itr = toDoList.begin();
                    advance(itr, index - 1);
                    archive.push_back(*itr);
                    toDoList.erase(itr);
                }
                else {
                    cout << "Некорректный номер дела.\n";
                }
            }
            break;

        case 3:
            cout << "Список дел:\n";
            if (toDoList.empty()) {
                cout << "Пусто\n";
            }
            else {
                int i = 1;
                for (const auto& task : toDoList) {
                    cout << i++ << ". " << task << endl;
                }
            }
            break;

        case 4:
            cout << "Отчёт:\n";
            if (archive.empty()) {
                cout << "Архив пуст\n";
            }
            else {
                int i = 1;
                for (const auto& task : archive) {
                    cout << i++ << ". " << task << endl;
                }
            }
            break;

        default:
            cout << "Некорректный выбор.\n";
            break;
        }

        cout << endl;
    }

    return 0;
}
