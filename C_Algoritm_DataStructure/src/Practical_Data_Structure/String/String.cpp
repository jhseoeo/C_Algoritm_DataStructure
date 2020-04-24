#include "String.h"

static int bf_match(const char* txt, const char* pat) {
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

static int bm_match(const char* txt, const char* pat) {
    int txtl = strlen(txt); int patl = strlen(pat);
    int txtp = 0, patp = patl-1;
    int skip[UCHAR_MAX + 1];
    
    for (txtp = 0; txtp < UCHAR_MAX; txtp++)
        skip[txtp] = patl;
    for (txtp = 0; txtp < patl; txtp++)
        skip[pat[txtp]] = patl - txtp - 1;

    while (txtp < txtl) {
        patp = patl - 1;
        while (txt[txtp] == pat[patp]) {
            if (patp == 0)
                return txtp;
            patp--;
            txtp--;
        }
        txtp += (skip[txt[txtp]] > patl - patp) ? skip[txt[txtp]] : patl - patp;
    }
    return -1;
}

int String_Main() {
    const char* A = "INJIJasdINQIKbdsINJIKasd";
    const char* B = "INJIK";

	system(CLEAR);
    printf("A : %s\n", A);
    printf("B : %s\n", B);
    printf("1. BF\n");
    printf("2. BM\n");
    printf(">> ");  int n; scanf("%d", &n); getchar(); printf("\n");
    
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