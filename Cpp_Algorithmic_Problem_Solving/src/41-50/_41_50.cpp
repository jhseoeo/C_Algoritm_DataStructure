#include "_41_50.h"

using namespace std;

void p041p050() {
    int n;

    cout << "Enter the number of chapter that you want to test" << endl;
    cout << "1. 041 : RATIO" << endl;
    cout << "2. 042 : FOSSIL" << endl;
    cout << "3. 043 : PASS486" << endl;
    cout << "4. 044 : POTION" << endl;
    cout << "5. 045 : PINBALL" << endl;
    cout << "6. 046 : TRESURE" << endl;
    cout << "7. 047 : NERDS" << endl;

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
    case 3:
        p043();
        break;
    case 4:
        p044();
        break;
    case 5:
        p045();
        break;
    case 6:
        p046();
        break;
    case 7:
        p047();
        break;
    default:
        break;
    }
}