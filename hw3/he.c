#include <stdio.h>

int m=0;

void he(int i, char A, char B, char C) {
    if(i == 1) {
        m++;
    }
    else {
        he(i-1, A, C, B);
        he(1, A, B, C);
        he(i-1, B, A, C);
    }
}

int main() {
    int n;
    n = 16;
    he(n, 'A', 'B', 'C');
    printf("%d\n",m);
    
    return 0;
}