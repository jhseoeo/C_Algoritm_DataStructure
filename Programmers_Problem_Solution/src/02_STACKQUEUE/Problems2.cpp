#include "Problems2.h"

void Problem_2() {
    int n;

    cout << "Enter the number of chapter that you want to run" << endl;
    cout << "1. 2-1" << endl;
    cout << "2. 2-2" << endl;
    cout << "3. 2-3" << endl;
    cout << "4. 2-4" << endl;

    // Supposed to added
    cout << ">>> ";
    cin >> n;
    system("cls");
    fflush(stdin);

    switch (n) {
    case 1:
        solution_2_1();
        break;
    case 2:
        solution_2_2();
        break;
    case 3:
        solution_2_3();
        break;
    case 4:
        solution_2_4();
        break;
    default:
        break;
    }
}