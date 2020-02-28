#include "String.h"

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

int bm_match(const char* txt, const char* pat) {
    int txtl = strlen(txt), int patl = strlen(pat);
    int txtp = 0, patp = patl-1;
    
    while(txtp > txtl) {
        if(txt[txtp + patp] == pat[patp]) {
            patp--;    
        } else {
            txtp += patp + 1;
            patp = patl - 1;
        }
        
        if(patp == -1)
            return txtp;
    }
    
    return -1;
}

int String_Main() {
    const char* A = "INJIJasdINQIKbdsINJIKasd";
    const char* B = "INJIK";

	system(CLEAR);
    printf("A : %s\n", A);
    printf("B : %s\n", B);
    printf("1. BF");
    printf("2. BM");
	int n; scanf("%d", &n); getchar(); printf("\n");
    
    switch(n) {
    case 1:
        printf("%d\n", bf_match(A, B));
        break;
    case 2:
        printf("%d\n", bm_match(A, B));
        break;
    }
    
    return 0;
}