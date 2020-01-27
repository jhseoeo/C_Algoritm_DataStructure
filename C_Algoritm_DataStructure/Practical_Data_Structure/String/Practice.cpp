#include "Practice.h"

int bf_match(const char* txt, const char* pat) {
    int txtp = 0, patp = 0;
    
    while(txt[txtp] != '\0' && pat[patp] != '\0') {
        if(txt[txtp + patp] == pat[patp]) {
            patp++;
        } else {
            printf("txtp : %d\n", txtp);
            txtp += patp + 1;
            patp = 0; 
        }
        if(pat[patp] == '\0')
            return txtp;
    }
    return -1;
}

int Practice() {
    const char* A = "INJIJasdINJIKasd";
    const char* B = "INJIK";

    printf("%d\n", bf_match(A, B));
    
    return 0;
}