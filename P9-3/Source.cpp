#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void hasRun(int values[], int size) {
    bool inRun = false;
    for (int i = 0; i < size; ++i) {
        if (i == 0 || values[i] != values[i - 1]) {
            if (inRun) {
                cout << ")";
                inRun = false;
            }
            if (i != 0)
                cout << " ";
            cout << values[i];
        }
        else {
            if (!inRun) {
                cout << " (";
                inRun = true;
            }
            cout << values[i];
        }
    }
    if (inRun)
        cout << ")";
}

int main() {
    const int DIE_TOSSES = 20;
    int dieValues[DIE_TOSSES];

    srand(time(nullptr));

    for (int i = 0; i < DIE_TOSSES; ++i) {
        dieValues[i] = rand() % 6 + 1;
    }

    cout << "No run: ";
    for (int i = 0; i < DIE_TOSSES; ++i) {
        cout << dieValues[i] << " ";
    }

    cout << "\nHas run: ";
    hasRun(dieValues, DIE_TOSSES);
}
