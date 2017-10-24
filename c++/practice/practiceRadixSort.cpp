#include <iostream>
#include <algorithm>
#include <cmath>

#define sc(n) cin>>n
#define forL(i,n) for(int i=0;i<n;i++)

using namespace std;

void countingSortStable(int a[],int n,int i);
void radixSort(int a[],int n);
int len(int n);

int main(){
    ios::sync_with_stdio(false);
    int n;
    sc(n);
    int *a = new int[n];
    forL(i,n) sc(a[i]);
    radixSort(a,n);
    forL(i,n) cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}

void countingSortStable(int a[],int n,int x){
    int *c = new int[10];
    int *b = new int[n];
    forL(i,10) c[i]=0;
    forL(i,n) c[int((a[i]/pow(10,x)))%10]++;
    int f;
    for(f=0;f<=9;f++){
        if(c[f] != 0)
            break;
    }
    for(int s=f+1;s<=9;s++){
        if(c[s] == 0)
            continue;
        c[s]+=c[f];
        f=s;
    }
    for(int i=n-1;i>=0;i--){
        c[int((a[i]/pow(10,x)))%10]--;
        b[c[int((a[i]/pow(10,x)))%10]] = a[i];
    }
    forL(i,n) a[i] = b[i];
}

void radixSort(int a[],int n){
    int k = *max_element(a,a+n);
    for(int i=0;i<len(k);i++){
        countingSortStable(a,n,i);
    }
}

int len(int n){
    int _count = 0;
    while(n!=0){
        _count++;
        n = n/10;
    }
    return _count;
}
