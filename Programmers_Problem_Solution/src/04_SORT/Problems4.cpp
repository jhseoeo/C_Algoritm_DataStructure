#include "Problems4.h"

void Problem_4() {
    int n;

    cout << "Enter the number of chapter that you want to run" << endl;
    cout << "1. 4-1" << endl;
    cout << "2. 4-2" << endl;
    cout << "3. 4-3" << endl;

    // Supposed to added
    cout << ">>> ";
    cin >> n;
    system("cls");
    fflush(stdin);

    switch (n) {
    case 1:
        solution_4_1();
        break;
    case 2:
        solution_4_2();
        break;
    case 3:
        solution_4_3();
        break;
    default:
        break;
    }
}