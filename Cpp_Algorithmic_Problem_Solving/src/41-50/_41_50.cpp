#include "_41_50.h"

using namespace std;

void p041p050() {
    int n;

    cout << "Enter the number of chapter that you want to test" << endl;
    cout << "1. 041 : RATIO" << endl;
    cout << "2. 042 : FOSSIL" << endl;

    // Supposed to added
    cout << ">>> ";
    cin >> n;
    system("cls");
    fflush(stdin);

    switch (n) {
    case 1:
        p041();
        break;

    case 2:
        p042();
        break;

    default:
        break;
    }
}