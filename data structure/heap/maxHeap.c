#include <stdio.h>

struct heap{
    int *harr;
    int heap_size;
    int capacity;
}h;

int left(int i){return 2*i+1;}
int right(int i){return 2*i+2;}
int parent(int i){return (i-1)/2;}

int swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int i){
    if(i<=parent(h.heap_size-1)){
        int largest = i;
        if(left(i) < h.heap_size && h.harr[left(i)] > h.harr[i])
            largest = left(i);
        if(right(i) < h.heap_size && h.harr[right(i)] > h.harr[largest])
            largest = right(i);
        if(largest != i){
            swap(&(h.harr[largest]),&(h.harr[i]));
            heapify(largest);
        }
    }
}

void buildMaxHeap(){
    int i;
    for(i = parent(h.heap_size-1);i>=0;i--){
        heapify(i);
    }
}

void heapSort(){
    buildMaxHeap();
    while(h.heap_size > 1){
        int i = --h.heap_size;
        swap(&(h.harr[0]),&(h.harr[i]));
        heapify(0);
    }
}

void displayHeap(){
    int i;
    for(i=0;i<h.capacity;i++){
        printf("%d\t",h.harr[i]);
    }
    printf("\n");
}

int main(){
    int n;
    scanf("%d",&n);
    h.heap_size = n;
    h.capacity = n;
    int i;
    for(i=0;i<n;i++)
        scanf("%d",&h.harr[i]);
    displayHeap();
    heapSort();
    displayHeap();
    return 0;
}
