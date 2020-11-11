//2016115572
//Kwon Hyeon Su
//https://www.zerocho.com/category/Algorithm/post/584b9033580277001862f16c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int arr_index=0;

typedef struct vertex{
    int x;
    int y;
    int city;
    double distance;
    struct vertex* next[99];
    struct vertex* prev;
}Vertex;

void printarr(Vertex* arr){
    int i;

    for(i=0;i<100;i++){
        //if(arr[i].distance != 0)
        printf("(%2d,%2d) dist: %.1f city : %d- %d\n",
               arr[i].x, arr[i].y, arr[i].distance,arr[i].city , i);

    }
}

void CreateVertex(Vertex* arr, int x, int y){
    Vertex vertex;
    int i;

    vertex.x = x;
    vertex.y = y;
    vertex.city = 1;
    vertex.distance = 0.0f;
    vertex.prev = NULL;
    for(i=0;i<100;i++){
        vertex.next[i] = (Vertex*)malloc(sizeof(Vertex));
        vertex.next[i] = NULL;
    }

    arr[arr_index++] = vertex;
}

double dist(Vertex a, Vertex b){
    double dist;

    dist = sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));

    return dist;
}

double min(double a, double b){
    if(a>b || a == 0) return b;
    else return b;
}

void addEdge(Vertex* a, Vertex* b){
    int i;
    Vertex *vertex = (Vertex*)malloc(sizeof(Vertex));

    *vertex = *b;

    vertex->prev = a;
    vertex->city = 1;
    vertex->distance = a->distance + dist(*a, *vertex);

    i=0;

    a->next[i] = vertex;

    //printf("edge added %d to %d in %d\n", a->x, vertex->x, i);
}



void insertNode(Vertex* arr, Vertex* IndexNode, int index, int fuel, Vertex* result_vertex){
    int i, j=0;
    Vertex* Node = (Vertex*)malloc(sizeof(Vertex));
    for(i=0;i<100;i++){
        Node->next[i] = (Vertex*)malloc(sizeof(Vertex));
        Node->next[i] = NULL;
    }

    Node->prev = (Vertex*)malloc(sizeof(Vertex));
    double offset;
    //printf("insert node start\n");

    if(index == 99){
        //printf("end\n");
        return;
    }


    for(i=index;i<index+5;i++){
        if(i==99) break;
        *Node = arr[i+1];

        while(arr[i].next[j] != NULL){
            j++;
        }

        offset = dist(*Node, arr[99]);
        Node->distance = IndexNode->distance + dist(*Node, *IndexNode);
        Node->city = IndexNode->city+1;
        IndexNode->next[j] = Node;
        Node->prev = IndexNode;


        if(Node->distance+offset > fuel){
            //printf("over !\n");
            IndexNode->next[j] = NULL;
            //free(IndexNode->next[j]);
            break;
        }

        else if(result_vertex->city <= Node->city){
                    *result_vertex = *Node;
                    //printf("overwrittnd\n");
                    insertNode(arr,IndexNode->next[j], i+1, fuel, result_vertex);
        }

    }

}


void simulate_overwrite_distance(Vertex* arr, int fuel){
    int i, j;
    double test;
    char** result_coor;
    char* temp;

    temp = (char*)malloc(sizeof(char)*10);
    result_coor = (char**)malloc(sizeof(char*)*1000);
    for(i=0;i<1000;i++){
        result_coor[i] = (char*)malloc(sizeof(char)*10);
    }
    Vertex* result_vertex = (Vertex*)malloc(sizeof(Vertex));
    Vertex* searchNode = (Vertex*)malloc(sizeof(Vertex));

    //result_vertex = &(arr[0]);

    for(i=1;i<100;i++){

        addEdge(&(arr[0]), &(arr[i]));
        //printf("debug\n");
        insertNode(arr, &(arr[i]), i, fuel, result_vertex);
    }

    printf("%d %.1f\n", fuel, result_vertex->distance+ dist(*result_vertex, arr[99]));

    searchNode = result_vertex;
    i=0;
    while(searchNode->prev != NULL){

        //printf("%d %d ",searchNode->x, searchNode->y);
        memset(result_coor[i],0,5);
        itoa(searchNode->x, temp, 10);
        strcat(result_coor[i], temp);

        //printf("%s ",temp);

        strcat(result_coor[i], " ");
        itoa(searchNode->y, temp, 10);

        //printf("%s ",temp);

        strcat(result_coor[i], temp);
        strcat(result_coor[i], " ");
        i++;



        searchNode = searchNode->prev;
    }
    printf("0 0 ");
    for(j=0;j<i;j++){
        printf("%s ", result_coor[i-j-1]);
    }

    printf("100 100\n\n");

    result_vertex = NULL;
    free(result_vertex);
    searchNode = NULL;
    free(searchNode);
}

void swap(Vertex* a, Vertex* b){
    Vertex temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(Vertex* arr, int l, int r){
    int pivot=arr[l].x;
    int low = l+1;
    int high = r;

    while(low <= high){
        while(low <= r && pivot >= arr[low].x) low++;
        while(high >= (l+1) && pivot <= arr[high].x) high--;
        if(low<=high) swap(&(arr[low]), &(arr[high]));
    }
    swap(&(arr[l]), &(arr[high]));

    return high;
}

void QuickSort(Vertex* arr, int l, int r){
    int pivot;

    if(l < r){
        pivot = Partition(arr, l, r);
        QuickSort(arr, l, pivot-1);
        QuickSort(arr, pivot+1, r);
    }
}

int main(void){

    Vertex *arr;
    Vertex trash;
    int garbage;
    int i, j;
    int x, y;

    FILE *fp;
    trash.x = 0;
    trash.y = 0;
    trash.city = 0;
    trash.distance = -1.0f;

    arr = (Vertex*)malloc(sizeof(Vertex)*100);
    if(arr == NULL){
        perror("malloc error : ");
        exit(1);
    }

    fp = fopen("hw5-3_ex1.txt", "r");
    if(fp == NULL){
        perror("fopen error : ");
        exit(1);
    }

    fscanf(fp, "%d", &garbage);


    for(i=0;i<100;i++){
        fscanf(fp, "%d %d", &x, &y);
        CreateVertex(arr, x, y);
    }

    for(i=1;i<100;i++){
        arr[i].distance = dist(arr[i],arr[0]);

    }

    QuickSort(arr, 0, 99);

    simulate_overwrite_distance(arr, 300);
    simulate_overwrite_distance(arr, 700);
    simulate_overwrite_distance(arr, 1100);
    simulate_overwrite_distance(arr, 1500);
    //printarr(arr);

    fclose(fp);


    return 0;
}
