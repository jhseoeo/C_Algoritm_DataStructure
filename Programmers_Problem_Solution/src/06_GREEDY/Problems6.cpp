#include "Problems6.h"

void Problem_6() {
    int n;

    cout << "Enter the number of chapter that you want to run" << endl;
    cout << "1. 6-1" << endl;
    cout << "2. 6-2" << endl;
    cout << "3. 6-3" << endl;
    cout << "4. 6-4" << endl;
    cout << "5. 6-5" << endl;
    cout << "6. 6-6" << endl;

    // Supposed to added
    cout << ">>> ";
    cin >> n;
    system("cls");
    fflush(stdin);

    switch (n) {
    case 1:
        solution_6_1();
        break;
    case 2:
        solution_6_2();
        break;
    case 3:
        solution_6_3();
        break;
     case 4:
        solution_6_4();
        break;
    //case 5:
    //    solution_6_5();
    //    break;
    //case 6:
    //    solution_6_6();
    //    break;
    default:
        break;
    }
}