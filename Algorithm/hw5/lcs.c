//2016115572
//Kwon Hyeon Su
//referenced FROM GilJin-Jang professor lecture note

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b){
    if(a<b) return b;
    else return a;
}


void LCS(char* a, char* b, int** array){
    int m = strlen(a);
    int n = strlen(b);
    int i, j;

    for(i=0;i<=m;i++){
        for(j=0;j<=n;j++) array[i][j] = 0;
    }
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            if(*(a+i-1) == *(b+j-1)) array[i][j] = array[i-1][j-1]+1;
            else array[i][j] = max(array[i-1][j],array[i][j-1]);
        }
    }
}

void findLCS(int** array, char* a, char* b, int m, int n, char* re){
    int i, j, index = 0;
    j=n;

    for(i=m;i>0;){
        for(;j>0;){
            if(array[i][j] == array[i-1][j-1]+1){

                if(array[i][j]== array[i-1][j]) i--;
                else if(array[i][j]==array[i][j-1]) j--;

                else{
                    //printf("%c, %d %d\n",*(a+i-1), i, j);
                    *(re+(index++)) = *(a+i-1);
                    //printf("re = %s\n", re);
                    i--;
                    j--;
                }

            }
            else i--;
            if(array[i][j]==0) break;

        }
        if(array[i][j]==0) break;

    }
    *(re+index) = '\0';

}

void reversing(char* re, int n){
    char* temp = malloc(sizeof(char)*(n+1));
    int i;
    if(temp == NULL){
        perror("malloc error : ");
        exit(1);
    }

    memset(temp, 0, n);

    for(i=0;i<strlen(re);i++) *(temp+i) = *(re+strlen(re)-1-i);
    strcpy(re, temp);
    *(re+n) = '\0';

    free(temp);
}

void printresult(char* a, char* b, int** array, char* re, int m, int n){
    int i, j;
    printf("\n\nLCS\t%s\n\n", re);
    printf("\t  ");
    for(i=0;i<n;i++) printf("%c ", *(b+i));
    printf("\n\n\t");
    for(i=0;i<=m;i++){
        if(i!=0) printf("%c\t", *(a+i-1));
        for(j=0;j<=n;j++){
                printf("%d ", array[i][j]);

        }
        printf("\n");

    }

}

int main()
{
    char *input_a, *input_b, *re;
    int** array;
    int m, n, i;

    input_a = (char*)malloc(sizeof(char)*1000);
    if(input_a == NULL){
        perror("malloc error : ");
        exit(1);
    }

    input_b = (char*)malloc(sizeof(char)*1000);
    if(input_b == NULL){
        perror("malloc error : ");
        exit(1);
    }

    fscanf(stdin, "%s", input_a);
    fscanf(stdin, "%s", input_b);

    m = strlen(input_a);
    n = strlen(input_b);

    re = (char*)malloc(sizeof(char)*m);
    if(re == NULL){
        perror("malloc error : ");
        exit(1);
    }
    memset(re, 0, m);

    array = (int**)malloc(sizeof(int*)*(m+1));
    if(array == NULL){
        perror("malloc error : ");
        exit(1);
    }
    for(i=0;i<=m;i++){
        array[i] = (int*)malloc(sizeof(int)*(n+1));
        if(array[i] == NULL){
            perror("malloc error : ");
            exit(1);
        }
    }

    LCS(input_a, input_b, array);

    findLCS(array, input_a, input_b, m, n, re);

    reversing(re, strlen(re));

    printresult(input_a, input_b, array, re, m, n);

    printf("\ndone!\n");

    free(input_a);
    free(input_b);
    free(re);
    for(i=0;i<n;i++){
        free(array[i]);
    }
    free(array);
    //printf("%s %s, %d %d", input_a, input_b, strlen(input_a), strlen(input_b));

}
