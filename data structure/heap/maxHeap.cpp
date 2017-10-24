#include <iostream>
#include <climits>
#include <algorithm>

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

public:
    MaxHeap(int capacity);
    void increaseKey(int i,int new_val);
    void deleteKey(int i);
    void insertKey(int k);
    int extractMax();
    void displayHeap();
    int getMax(){return this->harr[0];}

};

MaxHeap::MaxHeap(int capacity){
    this->heap_size = 0;
    this->capacity = capacity;
    this->harr = new int[this->capacity];
}

void MaxHeap::insertKey(int k){
    if(this->heap_size == this->capacity){
        cout<<"OVERFLOWN!!!!"<<endl;
        return;
    }
    int i = this->heap_size;
    this->heap_size++;
    this->harr[i] = k;
    while(i!=0 && this->harr[parent(i)] < this->harr[i]){
        swap(this->harr[parent(i)],this->harr[i]);
        i = parent(i);
    }
}

void MaxHeap::increaseKey(int i,int new_val){
    this->harr[i] = new_val;
    while(i!=0 && this->harr[parent(i)] < this->harr[i]){
        swap(this->harr[parent(i)],this->harr[i]);
        i = parent(i);
    }
}

void MaxHeap::maxHeapify(int i){
    if(i<=parent(heap_size-1)){
        int largest = i;
        if(left(i) < heap_size && harr[left(i)] > harr[i])
            largest = left(i);
        if(right(i) < heap_size && harr[right(i)] > harr[largest])
            largest = right(i);
        if(largest != i){
            swap(harr[largest(i)],harr[i]);
            maxHeapify(largest);
        }
    }
}

void MaxHeap::deleteKey(int i){
    this->increaseKey(0,INT_MAX);
    this->extractMax();
}

int MaxHeap::extractMax(){
    if(heap_size==0)
        return INT_MIN;
    if(heap_size==1){
        heap_size--;
        return harr[heap_size];
    }
    int i = harr[0];
    swap(harr[0],harr[--heap_size]);
    maxHeapify(0);
    return i;
}

void MaxHeap::displayHeap(){
    for(int i=0;i<heap_size;i++)
        cout<<this->harr[i]<<"\t";
    cout<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    MaxHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    cout << h.extractMax() << " ";
    cout << h.getMax() << " ";
    h.increaseKey(2, 16);
    cout << h.getMax();
    return 0;
}
