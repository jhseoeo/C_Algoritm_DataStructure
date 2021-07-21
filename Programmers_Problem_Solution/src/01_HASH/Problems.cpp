#include "Problems.h"

void Problem_1() {
    int n;

    cout << "Enter the number of chapter that you want to run" << endl;
    cout << "1. 1-1" << endl;
    cout << "2. 1-2" << endl;
    cout << "3. 1-3" << endl;
    cout << "4. 1-4" << endl;

    // Supposed to added
    cout << ">>> ";
    cin >> n;
    system("cls");
    fflush(stdin);

    switch (n) {
    case 1:
        solution_1_1();
        break;
    case 2:
        solution_1_2();
        break;
    case 3:
        solution_1_3();
        break;
    case 4:
        solution_1_4();
        break;
    default:
        break;
    }
}