#include "Problems7.h"

void Problem_7() {
    int n;

    cout << "Enter the number of chapter that you want to run" << endl;
    cout << "1. 7-1" << endl;
    cout << "2. 7-2" << endl;
    cout << "3. 7-3" << endl;
    cout << "4. 7-4" << endl;

    // Supposed to added
    cout << ">>> ";
    cin >> n;
    system("cls");
    fflush(stdin);

    switch (n) {
    case 1:
        solution_7_1();
        break;
    case 2:
        solution_7_2();
        break;
    case 3:
        solution_7_3();
        break;
    case 4:
        solution_7_4();
        break;
    default:
        break;
    }
}