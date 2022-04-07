#include <stdio.h>

void rec_dec(char* s) {
    for(; *s != 0; *s++) {
        if(*s != 0) {
            printf("%c,", *s);
        }
    }
}

void hanoi_tower(int n, char A, char B, char C) { 
    FILE* hanoi;
    if(n == 1) {     
        hanoi = fopen("hanoi.txt", "a+");
        fprintf(hanoi,"Move disk 1 from %c to %c\n", A, C);
        fclose(hanoi);
    } else {         
        hanoi_tower(n-1, A, C, B);       
        hanoi = fopen("hanoi.txt", "a+");
        fprintf(hanoi,"Move disk %d from %c to %c\n", n, A, C);        
        fclose(hanoi);
        hanoi_tower(n-1, B, A, C);
    } 
} 

int multiplication(int x, int y) {
    if (x<=9) {
        if (y<=9) {
            printf("%d*%d=%2d\t",x,y,x*y);
            multiplication(x,y+1);
        } else {
            printf("\n");
            x++;
            multiplication(x,1);
        }
    }
}    

int main() {
    char s[] = "1234567890";
    printf("func1\n");
    rec_dec(s);
    printf("\n");
    hanoi_tower(16, 'A', 'B', 'C');
    printf("func3\n");
    multiplication(1,1);

    return 0;
}
