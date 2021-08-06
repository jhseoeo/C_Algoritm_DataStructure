#include <iostream>
#include "./01_HASH/Problems1.h"
#include "./02_STACKQUEUE/Problems2.h"
#include "./03_HEAP/Problems3.h"

using namespace std;

int main() {
    int n;

    cout << "Enter the number of chapter that you want to test" << endl;
    cout << "1. Problem 1 - Hash" << endl;
    cout << "2. Problem 2 - Stack / Queue" << endl;
    cout << "3. Problem 3 - Heap" << endl;
    // Supposed to added
    cout << ">>> ";
    cin >> n;
    system("cls");
    fflush(stdin);

    switch (n) {
    case 1:
        Problem_1();
        break;
    case 2:
        Problem_2();
        break;
    case 3:
        Problem_3();
        break;
        // Supposed to added
    default:
        break;
    }

    return 0;
}