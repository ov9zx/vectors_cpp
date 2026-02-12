#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

using namespace std;

void deleteEvens(vector<int>& a) {
    vector<int>::iterator it;
    for (it = a.begin(); it != a.end(); ) {
        if (*it % 2 == 0) {
            it = a.erase(it);
        }
        else {
            ++it;
        }
    }
}

void addElementsOnEnd(vector<int>& a) {
    int m;
    cin >> m;
    a.push_back(m);
}

void reorder(vector<int>& a) {
    vector<int> negatives;
    vector<int> positives;

    for (int i = 0; i < a.size(); i++) {
        int x = a[i];
        if (x > 0) {
            positives.push_back(x);
        }
        else {
            negatives.push_back(x);
        }
    }
    a.clear();
    for (int i = 0; i < negatives.size(); i++) {
        a.push_back(negatives[i]);
    }

    for (int i = 0; i < positives.size(); i++) {
        a.push_back(positives[i]);
    }
}

int findLastNegativeIndex(const vector<int>& a) {
    for (int i = a.size() - 1; i >= 0; i--) {
        if (a[i] <= 0) {
            return i;
        }
    }
    return -1; 
}

int main() {
    SetConsoleOutputCP(65001);
    srand(time(0));

    vector<int> a(10);
    cout << "Исходный вектор: ";
    for (int i = 0; i < 10; i++) {
        a[i] = rand() % 131 - 30;
        cout << a[i] << " ";
    }
    cout << endl;

    deleteEvens(a);
    cout << "После удаления четных: ";
    for (int x : a) cout << x << " ";
    cout << endl;

    int m;
    cout << "Сколько элементов добавить? ";
    cin >> m;
    for (int i = 0; i < m; i++) {
        cout << "Введите число: ";
        addElementsOnEnd(a);
    }

    reorder(a);
    cout << "После перестановки: ";
    for (int x : a) cout << x << " ";
    cout << endl;

    int lastIdx = findLastNegativeIndex(a);
    if (lastIdx != -1) {
        cout << "Индекс последнего отрицательного: " << lastIdx << endl;
        cout << "Значение: " << a[lastIdx] << endl;
    }
    else {
        cout << "Отрицательные элементы не найдены." << endl;
    }

    return 0;
}
