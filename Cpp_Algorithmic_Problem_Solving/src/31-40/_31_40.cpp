#include "_31_40.h"

using namespace std;

void p031p040() {
    int n;

    cout << "Enter the number of chapter that you want to test" << endl;
    cout << "1. 031 : GENIUS" << endl;
    cout << "2. 032 : LUNCHBOX" << endl;
    cout << "3. 033 : STRJOIN" << endl;


    // Supposed to added
    cout << ">>> ";
    cin >> n;
    system("cls");
    fflush(stdin);

    switch (n) {
    case 1:
        p031();
        break;
    case 2:
        p032();
        break;
    case 3:
        p033();
        break;

    default:
        break;
    }
}