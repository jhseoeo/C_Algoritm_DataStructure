#include "_21_30.h"

using namespace std;

void p021p030() {
    int n;

    cout << "Enter the number of chapter that you want to test" << endl;
    cout << "1. 021 : PACKING" << endl;
    cout << "2. 022 : OCR" << endl;
    cout << "3. 023 : MORSE" << endl;
    cout << "4. 024 : KLIS" << endl;
    cout << "5. 025 : DRAGON" << endl;
    cout << "6. 026 : ZIMBABWE" << endl;

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
    case 3:
        p023();
        break;
    case 4:
        p024();
        break;
    case 5:
        p025();
        break;
    case 6:
        p026();
        break;
    default:
        break;
    }
}