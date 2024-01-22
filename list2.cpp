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
        cout << "����:\n";
        cout << "1. �������� ����\n";
        cout << "2. ���� ���������\n";
        cout << "3. ���������� ������ ���\n";
        cout << "4. ���������� ����� (������ ����������� ���)\n";
        cout << "�������� �������� (1-4): ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "������� ����: ";
            cin.ignore();
            getline(cin, task);
            toDoList.push_back(task);
            break;

        case 2:
            if (toDoList.empty()) {
                cout << "������ ��� ����.\n";
            }
            else {
                cout << "������� ����� ����, ������� ��������� (1-" << toDoList.size() << "): ";
                int index;
                cin >> index;

                if (index >= 1 && index <= toDoList.size()) {
                    auto itr = toDoList.begin();
                    advance(itr, index - 1);
                    archive.push_back(*itr);
                    toDoList.erase(itr);
                }
                else {
                    cout << "������������ ����� ����.\n";
                }
            }
            break;

        case 3:
            cout << "������ ���:\n";
            if (toDoList.empty()) {
                cout << "�����\n";
            }
            else {
                int i = 1;
                for (const auto& task : toDoList) {
                    cout << i++ << ". " << task << endl;
                }
            }
            break;

        case 4:
            cout << "�����:\n";
            if (archive.empty()) {
                cout << "����� ����\n";
            }
            else {
                int i = 1;
                for (const auto& task : archive) {
                    cout << i++ << ". " << task << endl;
                }
            }
            break;

        default:
            cout << "������������ �����.\n";
            break;
        }

        cout << endl;
    }

    return 0;
}
