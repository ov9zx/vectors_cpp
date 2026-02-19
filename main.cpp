#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

void deleteEvens(vector<int>& a) {
    for (int i = 0; i < a.size(); ) {
        if (a[i] % 2 == 0) {
            a.erase(a.begin() + i);
        } else {
            i++;
        }
    }
}

void addMultipleElements(vector<int>& a) {
    int count, val;
    cout << "How many elements to add? ";
    cin >> count;
    for (int i = 0; i < count; i++) {
        cout << "Enter number: ";
        cin >> val;
        a.push_back(val);
    }
}

void reorder(vector<int>& a) {
    int n = a.size();
    int moved = 0;
    for (int i = 0; moved < n; ) {
        if (a[i] >= 0) {
            a.push_back(a[i]);
            a.erase(a.begin() + i);
            moved++;
        } else {
            i++;
            moved++;
        }
    }
}

int findLastNegativeIndex(vector<int>& a) {
    for (int i = a.size() - 1; i >= 0; i--) {
        if (a[i] < 0) {
            return i;
        }
    }
    return -1;
}

void printVector(string label, vector<int>& a) {
    cout << label << ": ";
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    srand(time(0));

    vector<int> a(10);
    for (int i = 0; i < 10; i++) {
        a[i] = rand() % 131 - 30;
    }

    printVector("vector:", a);

    deleteEvens(a);
    printVector("After deleting evens", a);

    addMultipleElements(a);

    reorder(a);
    printVector("After reordering (Negatives first)", a);

    int lastIdx = findLastNegativeIndex(a);
    if (lastIdx != -1) {
        cout << "Index of last negative: " << lastIdx << " (Value: " << a[lastIdx] << ")" << endl;
    } else {
        cout << "No negative elements found." << endl;
    }

    return 0;
}
