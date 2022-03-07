#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int RangedRand(int range_min, int range_max){
    int r = ((double)rand() / RAND_MAX) * (range_max - range_min) + range_min;
    return r;
}

int print_num(FILE* name,int num){
    if(num<10){
        fprintf(name,"0");
    }
    fprintf(name,"%d ", num);
}



int main () {
    char tIme[25];
    srand(time(NULL));

    time_t Time;
    time(&Time);
    FILE* lotto;
    lotto = fopen("lotto.txt","w+");
    fprintf(lotto,"%s", ctime(&Time));
    fclose(lotto); 

    lotto = fopen("lotto.txt","r");
    fgets(tIme, 25, lotto);
    fclose(lotto); 


    lotto = fopen("lotto.txt","w+");
    fprintf(lotto,"========= lotto649 =========\n");
    fprintf(lotto,"= %s =\n",tIme);

    int N = 2,num;

    // for(int n=0;n<N;n++){
    //     fprintf(lotto,"  [%d]: ",n+1);
    //     for(int i =0;i<6;i++){
    //         num = RangedRand(1,69);
    //         print_num(lotto,num);
    //     }
    //     num = RangedRand(1,10);
    //     print_num(lotto,num);
    //     fprintf(lotto,"\n");
    // }

    for(int n=0;n<5;n++){
        

        if(n>=N){
            fprintf(lotto,"  [%d]: -- -- -- -- -- -- \n",n+1);
        }else{
            fprintf(lotto,"  [%d]: ",n+1);
            for(int i =0;i<5;i++){
                num = RangedRand(1,69);
                print_num(lotto,num);
            }
            num = RangedRand(1,10);
            print_num(lotto,num);
            fprintf(lotto,"\n");
        }
    }
        
    
    fprintf(lotto,"========= csie@CGU =========\n");





    fclose(lotto); 
}