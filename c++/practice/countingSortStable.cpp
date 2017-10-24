#include <iostream>
#include <algorithm>
#include <vector>

#define sc(n) cin>>n;
#define forL(i,n) for(int i=0;i<n;i++)

using namespace std;

void countSortStable(int a[],int n);

int main(){
    ios::sync_with_stdio(false);
    int n;
    sc(n);
    int *a = new int[n];
    forL(i,n) sc(a[i]);
    countSortStable(a,n);
    forL(i,n) cout<<a[i]<<"\t";
    cout<<endl;
    return 0;
}

void countSortStable(int a[],int n){
    int k = *max_element(a,a+n);
    int *countA = new int[k+1];
    forL(i,k+1) countA[i] = 0;
    forL(i,n) countA[a[i]]++;
    int l;
    for(l=0;l<=k;l++){
        if(countA[l] != 0)
            break;
    }
    for(int j = l+1;j<=k;j++){
        cout<<l<<j<<endl;
        if(countA[j] == 0)
            continue;
        countA[j]+=countA[l];
        l = j;
    }
    forL(i,k+1) cout<<countA[i]<<"\t";
    cout<<endl;
    int *b = new int[n];
    for(int i=n-1;i>=0;i--){
        countA[a[i]]--;
        b[countA[a[i]]] = a[i];
    }
    forL(i,n) a[i] = b[i];
}

