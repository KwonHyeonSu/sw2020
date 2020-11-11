//2016115572
//Kwon Hyeon Su
//https://dojang.io/mod/page/view.php?id=619
//https://gmlwjd9405.github.io/2018/05/10/algorithm-quick-sort.html

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define SIZE    1000000

volatile int offset=1;

//////Node//////

typedef struct node{
    char val[100];
    int num;
}Node;


typedef struct list{
    int n;
    Node package[SIZE];
}List;

void swap(Node* a, Node* b){
    Node temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void insertNode(List* list, char* val, int num){
    Node *newNode;
    newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        perror("Node create error : ");
        exit(1);
    }
    newNode->num = num;
    strcpy(newNode->val, val);

    list->package[++(list->n)] = *newNode;

}

void sliceAndInput(FILE* fp_a, List* list){
    char val[50];
    int index=0;

    while(feof(fp_a) == 0){
        memset(val, 0, sizeof(val));
        fscanf(fp_a, "%s", val);
        if(strcmp(val,"")==0) break;

        insertNode(list, val, 1);
    }
}

void print_make_List(List* list, char* out){
    int i;
    char val[100];
    FILE* fp;
    fp = fopen(out, "w");
    for(i=1;i<=list->n;i++){
        //printf("%s %d   -%d\n",list->package[i].val, list->package[i].num, i);
        fprintf(fp, "%s %d\n", list->package[i].val, list->package[i].num);
    }
}

int Partition(List* list, int l, int r){
    int pivot = list->package[l].num;
    int low = l + 1;
    int high = r;

    while(low <= high){
        while(low <= r && pivot <= list->package[low].num) low++;
        while(high >= (l+1) && pivot >= list->package[high].num) high--;
        if(low <= high) swap(&(list->package[low]), &(list->package[high]));
    }
    swap(&(list->package[l]),&(list->package[high]));
    return high;
}

void QuickSort(List* list, int l, int r){
    int pivot;
    if(l <= r){
        pivot = Partition(list, l, r);
        QuickSort(list, l, pivot-1);
        QuickSort(list, pivot+1, r);
    }
}

int Partition_string(List* list, int l, int r){
    char* pivot_val;
    int low = l + 1;
    int high = r;

    pivot_val = (char*)malloc(sizeof(char)*50);
    if(pivot_val == NULL){
        perror("malloc error : ");
        exit(1);
    }
    strcpy(pivot_val,list->package[l].val);

    while(low <= high){

        while(low <= r && strcmp(pivot_val, list->package[low].val)>=0) low++;
        while(high >= (l+1) && strcmp(pivot_val, list->package[high].val)<=0) high--;
        if(low <= high) swap(&(list->package[low]), &(list->package[high]));
    }
    swap(&(list->package[l]),&(list->package[high]));
    return high;
}

void QuickSort_string(List* list, int l, int r){
    int pivot;

    if(l <= r){
        pivot = Partition_string(list, l, r);
        QuickSort_string(list, l, pivot-1);
        QuickSort_string(list, pivot+1, r);
    }
}



void compress(List* list){
    int i, j;
    int index=1;
    offset = 0;
    for(i=1;i<=list->n;i++){
        j = i+1;
        while(strcmp(list->package[i].val, list->package[j].val)==0){
            j++;
            list->package[j-1].num = 0;
            offset++;
        }
        list->package[i].num = j-i;

        i = j-1;
    }

    for(i=1;i<=list->n;i++){
        if(list->package[i].num!= 0){
                swap(&(list->package[index]),&(list->package[i]));
                index++;
        }

    }
}

int main()
{
    FILE *fp_a, *fp_b, *fp_c;
    List *list_a, *list_b, *list_c;

    list_a = (List*)malloc(sizeof(List));
    if(list_a == NULL){
        perror("list");
        exit(1);
    }
    list_b = (List*)malloc(sizeof(List));
    if(list_b == NULL){
        perror("list");
        exit(1);
    }
    list_c = (List*)malloc(sizeof(List));
    if(list_c == NULL){
        perror("list");
        exit(1);
    }


    list_a->n = 0;
    list_b->n = 0;
    list_c->n = 0;

    fp_a = fopen("input4a.txt", "r");
    if(fp_a == NULL){
        perror("fp_a open failed!");
        exit(1);
    }

    fp_b = fopen("input4b.txt", "r");
    if(fp_b == NULL){
        perror("fp_a open failed!");
        exit(1);
    }


    fp_c = fopen("input4c.txt", "r");
    if(fp_c == NULL){
        perror("fp_a open failed!");
        exit(1);
    }

    sliceAndInput(fp_a, list_a);
    QuickSort_string(list_a, 1, list_a->n);
    compress(list_a);
    list_a->n -= offset;
    QuickSort(list_a, 1, list_a->n);
    print_make_List(list_a, "out4a.txt");


    sliceAndInput(fp_b, list_b);
    QuickSort_string(list_b, 1, list_b->n);
    compress(list_b);
    list_b->n -= offset;
    QuickSort(list_b, 1, list_b->n);
    print_make_List(list_b, "out4b.txt");


    sliceAndInput(fp_c, list_c);
    QuickSort_string(list_c, 1, list_c->n);
    compress(list_c);
    list_c->n -= offset;
    QuickSort(list_c, 1, list_c->n);
    print_make_List(list_c, "out4c.txt");

    fclose(fp_a);
	fclose(fp_b);
	fclose(fp_c);

	free(list_a);
	free(list_b);
	free(list_c);

    return 0;
}
