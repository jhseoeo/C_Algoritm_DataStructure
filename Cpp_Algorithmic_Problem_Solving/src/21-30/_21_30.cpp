#include "_21_30.h"

using namespace std;

void p021p030() {
    int n;

    cout << "Enter the number of chapter that you want to test" << endl;
    cout << "1. 021 : PACKING" << endl;
    cout << "2. 022 : OCR" << endl;


    // Supposed to added
    cout << ">>> ";
    cin >> n;
    system("cls");
    fflush(stdin);

    switch (n) {
    case 1:
        p021();
        break;
    case 2:
        p022();
        break;
    default:
        break;
    }
}