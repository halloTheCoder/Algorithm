#include <bits/stdc++.h>

#define sc(n) cin>>n

using namespace std;

int heap_size = 0;

class MaxHeap{

public:
    MaxHeap(vector<int> a);
    void insertKey(int k);
    int getMax(){return harr[0];}
    int extractMax();
    vector<int> harr;
    int capacity;
    int left(int i){return 2*i+1;}
    int right(int i){return 2*i+2;}
    int parent(int i){return (i-1)/2;}
    void maxHeapify(int i);

};

MaxHeap::MaxHeap(vector<int> a){
    harr.assign(a.begin(),a.end());
}

void MaxHeap::insertKey(int k){
    int i = heap_size;
    heap_size++;
    this->harr[i] = k;
    while(i!=0 && this->harr[i] > this->harr[parent(i)]){
        swap(this->harr[i], this->harr[parent(i)]);
        i = parent(i);
    }
}

void MaxHeap::maxHeapify(int i){
    if(i<=parent(heap_size-1)){
        int largest = i;
        if(left(i) < heap_size && this->harr[left(i)] > this->harr[i])
            largest = left(i);
        if(right(i) < heap_size && this->harr[right(i)] > this->harr[largest])
            largest = right(i);
        if(largest != i){
            swap(this->harr[i],this->harr[largest]);
            maxHeapify(largest);
        }
    }
}

int MaxHeap::extractMax(){
    if(heap_size < 1)
        return -1;
    if(heap_size == 1)
        return this->harr[--heap_size];
    swap(harr[0],harr[--heap_size]);
    maxHeapify(0);
    return 0;
}

void printMax3(vector<int> b){
    MaxHeap h1(b);
    if(heap_size < 3){
        cout<<-1<<endl;
        return;
    }
    for(int i=0;i<3;i++){
        cout<<h1.getMax()<<" ";
        h1.extractMax();
    }
}

int main(){
    ios::sync_with_stdio(false);
    vector<int> a;
    MaxHeap h(a);
    int t;
    sc(t);
    while(t--){
        int k;
        sc(k);
        h.insertKey(k);
        printMax3(h.harr);
    }
    return 0;
}

