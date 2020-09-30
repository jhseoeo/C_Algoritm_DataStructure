#include "_11_20.h"

using namespace std;

void p011p020() {
    int n;

    cout << "Enter the number of chapter that you want to test" << endl;
    cout << "1. 011 : TRIANGLEPATH" << endl;
    cout << "2. 012 : LIS" << endl;
    cout << "3. 013 : JLIS" << endl;

    // Supposed to added
    cout << ">>> ";
    cin >> n;
    system("cls");
    fflush(stdin);

    switch (n) {
    case 1:
        p011();
        break;
    case 2:
        p012();
        break;
    case 3:
        p013();
        break;
    default:
        break;
    }
}