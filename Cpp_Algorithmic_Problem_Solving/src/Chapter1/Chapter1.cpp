#include "Chapter1.h"

void Chapter1() {
    int n;
    
    cout << "Enter the number of problem that you want to test" << endl;
    cout << "1. 001 : FESTIVAL" << endl;
    cout << ">>> ";
    cin >> n;
    system("cls");

    switch(n) {
        case 1:
            p001();
            break;

        default:
            break;
    }

}