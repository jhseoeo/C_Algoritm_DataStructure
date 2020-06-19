#include <iostream>
#include "Problems.h"
// Supposed to be added

using namespace std;

int main() {
    int n;

    cout << "Enter the number of chapter that you want to test" << endl;
    cout << "001 : FESTIVAL" << endl;
    cout << "002 : BOGGLE" << endl;
    cout << "003 : PICNIC" << endl;
    cout << "004 : BOARDCOVER" << endl;
    cout << "005 : CLOCKSYNK" << endl;
    cout << "006 : QUADTREE" << endl;
    cout << "007 : FENCE" << endl;
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

    // Supposed to added
        default:
            break;
    }

    return 0;
}