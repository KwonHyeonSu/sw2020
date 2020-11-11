//2016115572
//Kwon Hyeon Su
//in linux, have to include '-lm' in compiling
//https://hsp1116.tistory.com/42

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void printarr(double* arr, int num){
    int i;

    for(i=0;i<num;i++){
        printf("[%d]  : %.1f\n", i, arr[i]);
    }
}

double absol(double a){
    if (a>=0) return a;
    else return -a;
}

int find(double start, int* temparr, int num_of_slit, char* option, int width){

    int i;
    int index = 0;
    int found = 0;
    double shortest;
    double distance;

    shortest = (double)width;
    if(strcmp(option, "left")==0){
       // printf("numofslit : %d\n", num_of_slit);
        for(i=0;i<num_of_slit;i++){
            if((double)(temparr[i])<=start){
                distance = absol((double)(temparr[i]) - start);
                if(absol(distance < shortest)){
                    shortest = distance;
                    //printf("left temp[%d] : %d - distance :%.2f\n", i, temparr[i], distance);
                    index = i;

                }
                found = 1;
            }
        }
        if(found == 1) return temparr[index];
        else return -1;
    }

    else if(strcmp(option, "right")==0){
           // printf("numofslit : %d\n", num_of_slit);
        for(i=0;i<num_of_slit;i++){
            if((double)(temparr[i])>start){
                distance = absol((double)(temparr[i]) - start);
                if(absol(distance < shortest)){
                    shortest = distance;
                    //printf("right temp[%d] : %d - distance :%.2f\n", i, temparr[i], distance);
                    index = i;
                }
                found = 1;
            }
        }
        if(found == 1) return temparr[index];
        else return -1;
    }

    else{
        printf("Wrong\n");
        exit(1);
    }

}
/*
int pow(int a, int b){
	int i;
	int re = a;
	for(i=0;i<b;i++){
		re *= b;
	}
}
*/
double min(double a, double b){
    if(a>=b) return b;
    else return a;
}

void simulate(double* arr, double* distance, int n){
    int i;

    distance[1] = 0;
    for(i=2;i<=n;i++){
        //printf("compare %.2f  :  %.2f\n", distance[i], distance[i/2]+abs(arr[i/2]-arr[i]));
        if(arr[i]!= -1) distance[i] = distance[i/2]+absol(arr[i/2]-arr[i]);
        else distance[i] = -1;
    }
/*
    printf("\n\n distance\n\n");
    printarr(distance, n);
    printf("\n\n distance end\n\n");
*/
}

void find_distance(double* arr, double* distance, int num_of_plate){
    int i;
    int index = 0;
    double shortest = 1000000;
    int start = (int)pow(2, (double)num_of_plate);
    int end = (int)pow(2, (double)(num_of_plate+1));

    double* path;
    int path_num=0;
    int temp= 0;

    for(i=start;i<end;i++){
        //printf("shortest :%.1f, %.2f\n", shortest, distance[i]);
        if( distance[i] < shortest && distance[i] != -1){
            shortest = distance[i];
            if(shortest == -1) shortest = distance[i];
            index = i;
        }


    }
    if((shortest - (int)shortest) == 0) printf("%.0f ", shortest);
    else printf("%.1f ", shortest);

    for(i=index; i>1;i/=2){
        path_num++;
        //printf("%.2f ", arr[i]);
    }

    path = (double*)malloc(sizeof(double)*path_num);
    if(path == NULL){
        perror("malloc error : ");
        exit(1);
    }

    for(i=index; i>1;i/=2){
        path[temp++] = arr[i];
    }

    for(i=path_num-1;i>=0;i--){
        if((path[i]-(int)(path[i]))==0) printf("%.0f ", path[i]);
        else printf("%.2f ", path[i]);

    }
}

int main(void){

    int num_of_plate;
    int width;
    int option;

    int num_of_slit;
    int slit;

    int i, j;

    double* arr;
    double* distance;
    int* temparr;

    fscanf(stdin, "%d", &num_of_plate);
    fscanf(stdin, "%d", &width);
    fscanf(stdin, "%d", &option); //-1


    arr = (double*)malloc(sizeof(double)*pow(2,(num_of_plate+1)));
    if(arr == NULL){
        perror("malloc error : ");
        exit(1);
    }

    distance = (double*)malloc(sizeof(double)*pow(2,(num_of_plate+1)));
    if(distance == NULL){
        perror("malloc error : ");
        exit(1);
    }

    temparr = (int*)malloc(sizeof(int)*(width+1));
    if(temparr == NULL){
        perror("malloc error : ");
        exit(1);
    }


    for(i=0;i<pow(2,(num_of_plate+1));i++){
        arr[i] = 0;
        distance[i] = -1;
    }

    arr[0] = 0;
    arr[1] = (double)width/2;
    //printf("arr[1] : %.1f\n", arr[1]);

    for(i=1;i<=num_of_plate;i++){
        fscanf(stdin, "%d", &num_of_slit);

        for(j=0;j<num_of_slit;j++){
            fscanf(stdin, "%d", &slit);
            temparr[j] = slit;
           // printf("temparr[%d] : %d, slit :%d\n",j, temparr[j], slit);
        }

        for(j=pow(2,i-1);j<pow(2,i);j++){
            if(arr[j] != -1){
                arr[j*2] = find(arr[j], temparr, num_of_slit, "left", width);
                arr[j*2+1] = find(arr[j], temparr, num_of_slit, "right", width);
            }
            else{
                arr[j*2] = arr[j*2+1] = -1;
            }
        }
        fscanf(stdin, "%d", &option); //-2
    }

    simulate(arr, distance, pow(2,(num_of_plate+1)));
    //printarr(arr, pow(2,(num_of_plate+1)));

    find_distance(arr, distance, num_of_plate);
    fscanf(stdin, "%d", &option); //-3


    free(arr);
    free(distance);
    free(temparr);

    return 0;
}
