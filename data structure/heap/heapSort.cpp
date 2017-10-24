#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

class MaxHeap{
private:
    int *harr;
    int heap_size;
    int capacity;

    int left(int i){return 2*i+1;}
    int right(int i){return 2*i+2;}
    int parent(int i){return (i-1)/2;}
    void maxHeapify(int i);
    void buildMaxHeap();

public:
    MaxHeap(int a[],int n);
    void displayHeap();
    void heapSort();

};


MaxHeap::MaxHeap(int a[],int n){
    this->heap_size = n;
    this->capacity = n;
    this->harr = a;
}

void MaxHeap::maxHeapify(int i){
    if(i<=parent(heap_size-1)){
        int largest = i;
        if(left(i) < heap_size && harr[left(i)] > harr[i])
            largest = left(i);
        if(right(i) < heap_size && harr[right(i)] > harr[largest])
            largest = right(i);
        if(largest != i){
            swap(harr[largest],harr[i]);
            maxHeapify(largest);
        }
    }
}

void MaxHeap::displayHeap(){
    for(int i=0;i<capacity;i++)
        cout<<this->harr[i]<<"\t";
    cout<<endl;
}

void MaxHeap::buildMaxHeap(){
    for(int i = parent(heap_size-1);i>=0;i--)
        maxHeapify(i);
}

void MaxHeap::heapSort(){
    buildMaxHeap();
    displayHeap();
    while(heap_size > 1){
        swap(harr[0],harr[--heap_size]);
        maxHeapify(0);
    }
}

int main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int *a = new int[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    MaxHeap h(a,n);
    h.displayHeap();
    h.heapSort();
    h.displayHeap();
    return 0;
}
