#include <iostream>
#include "Problems.h"
// Supposed to be added

using namespace std;

int main() {
    int n;

    cout << "Enter the number of chapter that you want to test" << endl;
    cout << "1. 1 - 10" << endl;
    cout << "2. 11 - 20" << endl;
    // Supposed to added
    cout << ">>> ";
    cin >> n;
    system("cls");
    fflush(stdin);

    switch(n) {
        case 1:
            p001p010();
            break;
        case 2:
            p011p020();
            break;
    // Supposed to added
        default:
            break;
    }

    return 0;
}