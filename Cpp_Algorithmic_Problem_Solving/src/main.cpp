#include "Base.h"
#include "./Chapter1/Chapter1.h"
// Supposed to be added

int main() {
    int n;

    cout << "Enter the number of chapter that you want to test" << endl;
    cout << "1. Chapter 1" << endl;
    // Supposed to added
    cout << ">>> ";
    cin >> n;
    system("cls");

    switch(n) {
        case 1:
            Chapter1();     
            break;
    // Supposed to added
        default:
            break;
    }

    return 0;
}