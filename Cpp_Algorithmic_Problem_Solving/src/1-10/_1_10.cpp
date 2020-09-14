#include "_1_10.h"

using namespace std;

void p001p010() {
    int n;

    cout << "Enter the number of chapter that you want to test" << endl;
    cout << "1. 001 : FESTIVAL" << endl;
    cout << "2. 002 : BOGGLE" << endl;
    cout << "3. 003 : PICNIC" << endl;
    cout << "4. 004 : BOARDCOVER" << endl;
    cout << "5. 005 : CLOCKSYNK" << endl;
    cout << "6. 006 : QUADTREE" << endl;
    cout << "7. 007 : FENCE" << endl;
    cout << "8. 008 : FANMEETING" << endl;
    cout << "9. 009 : JUMPGAME" << endl;
    cout << "10. 010 : WILDCARD" << endl;

    // Supposed to added
    cout << ">>> ";
    cin >> n;
    system("cls");
    fflush(stdin);

    switch (n) {
    case 1:
        p001();
        break;
    case 2:
        p002();
        break;
    case 3:
        p003();
        break;
    case 4:
        p004();
        break;
    case 5:
        p005();
        break;
    case 6:
        p006();
        break;
    case 7:
        p007();
        break;
    case 8:
        p008();
        break;
    case 9:
        p009();
        break;
    case 10:
        p010();
        break;
    default:
        break;
    }
}