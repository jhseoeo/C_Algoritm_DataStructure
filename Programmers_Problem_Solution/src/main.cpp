#include <iostream>
#include "./01_HASH/Problems.h"

using namespace std;

int main() {
    int n;

    cout << "Enter the number of chapter that you want to test" << endl;
    cout << "1. Problem 1 - Hash" << endl;
    // Supposed to added
    cout << ">>> ";
    cin >> n;
    system("cls");
    fflush(stdin);

    switch (n) {
    case 1:
        Problem_1();
        break;
        // Supposed to added
    default:
        break;
    }

    return 0;
}