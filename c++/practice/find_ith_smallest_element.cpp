#include <iostream>
#include <random>
#include <ctime>
#include <algorithm>

#define sc(n) cin>>n
#define forL(i,n) for(int i=0;i<n;i++)

using namespace std;

int _find(int a[],int l,int r,int k);
int _partition(int a[],int l,int r);

int main(){
    ios::sync_with_stdio(false);
    srand(time(0));
    int n;
    sc(n);
    int *a = new int[n];
    forL(i,n) sc(a[i]);
    int k;
    sc(k);
    cout<<_find(a,0,n-1,k)<<endl;
    return 0;
}

int _find(int a[],int l,int r,int k){
    if(l==r)
        return a[l];
    int j = _partition(a,l,r);
    //ALTERNATIVE
    //int check = j-l+1;
    if((j+1) == k)
        return a[j];
    else if((j+1) > k){
        _find(a,l,j-1,k);
    }
    else{
        _find(a,j+1,r,k);    //FOR ALTERNATIVE REPLACE k WITH k-j-1
    }
}

int _partition(int a[],int l,int r){
    int i=l+1,j=r;
    int _rand = l+rand()%(r-l+1);
    swap(a[_rand],a[l]);
    int pivot=a[l];
    while(true){
        while(i<r && a[i] <= pivot)
            i++;
        while(j>l && a[j] > pivot)
            j--;
        if(i>=j)
            break;
        swap(a[j],a[i]);
        i++;
        j--;
    }
    swap(a[j],a[l]);
    return j;
}
