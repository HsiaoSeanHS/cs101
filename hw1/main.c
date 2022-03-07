#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int RangedRand(int range_min, int range_max){
    int r = ((double)rand() / RAND_MAX) * (range_max - range_min) + range_min;
    return r;
}

int print_num(FILE* name,int num[]){
    for(int i=0;i<7;i++){
        if(num[i]<10){
            fprintf(name,"0");
        }
        fprintf(name,"%d ", num[i]);
    }
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
    int N;
    printf("歡迎光臨長庚樂透彩購買機台\n請問寧要買幾組樂透彩 : ");
    scanf("%d",&N);
    int ant = N;
    printf("以為您購買的 %d 組樂透組合輸出至 lotto.txt\n",ant);

    lotto = fopen("lotto.txt","w+");
    fprintf(lotto,"========= lotto649 =========\n");
    fprintf(lotto,"= %s =\n",tIme);


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

    int num;
    for(int n=0;n<5;n++){
        int temp[6];

        if(n>=N){
            fprintf(lotto,"  [%d]: -- -- -- -- -- -- \n",n+1);
        }else{
            fprintf(lotto,"  [%d]: ",n+1);
            for(int i =0;i<6;i++){
                num = RangedRand(1,69);
                temp[i]=num;
                // print_num(lotto,num);
            }
            num = RangedRand(1,10);
            temp[6]=num;

            for(int i=0;i<6;i++){
                int max_num_index = 0;
                for(int j=0;j<5;j++){
                    if(temp[j]>temp[j+1]){
                        int tempn = temp[j];
                        temp[j] = temp[j+1];
                        temp[j+1] = tempn;
                    }
                }
                
            }
            // temp = bubbol_short(temp,6);

            print_num(lotto,temp);
            fprintf(lotto,"\n");
        }
    }
        
    
    fprintf(lotto,"========= csie@CGU =========\n");





    fclose(lotto); 
}