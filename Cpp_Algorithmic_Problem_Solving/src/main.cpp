#include <iostream>
#include "001.h"
#include "002.h"
#include "003.h"
// Supposed to be added

using namespace std;

int main() {
    int n;

    cout << "Enter the number of chapter that you want to test" << endl;
    cout << "1. 001 : FESTIVAL" << endl;
    cout << "2. 002 : BOGGLE" << endl;
    cout << "3. 003 : PICNIC" << endl;
    // Supposed to added
    cout << ">>> ";
    cin >> n;
    system("cls");
    fflush(stdin);

    switch(n) {
        case 1:
            p001();
            break;
        case 2:
            p002();
            break;
        case 3:
            p003();
            break;
    // Supposed to added
        default:
            break;
    }

    return 0;
}