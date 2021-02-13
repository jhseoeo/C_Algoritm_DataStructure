#include "_11_20.h"

using namespace std;

void p011p020() {
    int n;

    cout << "Enter the number of chapter that you want to test" << endl;
    cout << "1. 011 : TRIANGLEPATH" << endl;
    cout << "2. 012 : LIS" << endl;
    cout << "3. 013 : JLIS" << endl;
    cout << "4. 014 : PI" << endl;
    cout << "5. 015 : QUANTIZATION" << endl;
    cout << "6. 016 : TILING2" << endl;
    cout << "7. 017 : TRIPATHCNT" << endl;
    cout << "8. 018 : ASYMTILING" << endl;
    cout << "9. 019 : POLY" << endl;
    cout << "10. 020 : NUMB3RS" << endl;

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
    case 4:
        p014();
        break;
    case 5:
        p015();
        break;
    case 6:
        p016();
        break;
    case 7:
        p017();
        break;
    case 8:
        p018();
        break;
    case 9:
        p019();
        break;
    case 10:
        p020();
        break;
    default:
        break;
    }
}