#include <stdio.h>
#include <stdlib.h>
typedef struct my_mm{
    char hs[10];
    char* tt[10];
    int id;
}my_mm_t;

int g_mem[10];
my_mm_t mms;

char* my_calloc(int n, int size){
    int i, sp = 0;
    mms.id++;
    for(i = 0;i < 10; i++){
        if(g_mem[i] == 0) sp+=1;
        else sp = 0;
        //printf("%d\n", sp);
        if(sp == size*n) { 
            for(int k = i + 1 - size*n; k <= i; k++){
                
                g_mem[k] = mms.id;
                mms.hs[k] = '1';
            }
            printf("%s\n", mms.hs);
            char* u = calloc(size, sizeof(char));
            mms.tt[mms.id] = u;
            //printf("%dsssssssssss", mms.id);
            return u;
        }
    }
    printf("%s  <-Out of space\n", mms.hs);
    return NULL;
    
}

void my_free(int* p){
    int c;
    for(c = 0; c<10 ; c++){
        //printf("c = %x  %x\n", p, mms.tt[c]);
        if(p == mms.tt[c]) break;
        if(c == 9) {
            c = -1;
            break;
        }
    }
    //printf("c = %x  %x\n", p, mms.tt[c]);
    
    //printf("%d", c);
    for(int i = 0; i<10; i++){
        if(g_mem[i] == c){
            
            g_mem[i] = 0;
            mms.hs[i] = '0';
        }
    }
    free(p);
    printf("%s\n", mms.hs);
}

int main()
{
    strcpy(mms.hs,"0000000000");
    int* np1 = my_calloc(1, 1);
    int* np2 = my_calloc(1, 2);
    int* np3 = my_calloc(1, 3);
    int* np4 = my_calloc(1, 4);
    my_free(np1);
    my_free(np4);
    int* np5 = my_calloc(1, 3);
    //printf("%d", g_mem[9]);

    return 0;
}
