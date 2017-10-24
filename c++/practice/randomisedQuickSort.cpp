#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>

#define sc(n) cin>>n
#define forL(i,n) for(int i=0;i<n;i++)

using namespace std;

void quickSort(int a[],int l,int r);
int rand_partition(int a[],int l,int r);
int _partition(int a[],int l,int r);

int main()
{
    ios::sync_with_stdio(false);
    srand(time(0));
    int n;
    sc(n);
    int *a = new int[n];
    forL(i,n) sc(a[i]);
    quickSort(a,0,n-1);
    forL(i,n) cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}

void quickSort(int a[],int l,int r){
    if(l<r){
        int j = rand_partition(a,l,r);
        quickSort(a,l,j-1);
        quickSort(a,j+1,r);
    }
}

int rand_partition(int a[],int l,int r){
    int random = l + rand()%(r-l+1);
    swap(a[random],a[l]);
    int j = _partition(a,l,r);
    return j;
}

int _partition(int a[],int l,int r){
    int pivot = a[l];
    int i=l+1,j=r;
    while(true){
        while(i<r && a[i]<=pivot)
            i++;
        while(j>l && a[j]>pivot)
            j--;
        if(i>=j)
            break;
        swap(a[i],a[j]);
        i++;
        j--;
    }
    swap(a[l],a[j]);
    return j;
}


