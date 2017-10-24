#include <iostream>
#include <bits/stdc++.h>

#define sc(n) cin>>n
#define forL(i,n) for(int i=0;i<n;i++)

using namespace std;

int countSetBits(int n);
void bucketSort(int a[],int n);

int main()
{
    int n;
    sc(n);
    int *a = new int[n];
    forL(i,n) sc(a[i]);
    bucketSort(a,n);
    return 0;
}

void bucketSort(int a[],int n){
    vector<int> v[12];
    forL(i,n){
        v[countSetBits(a[i])].push_back(a[i]);
    }

    for(int i=0;i<12;i++)
        sort(v[i].begin(),v[i].end());

    for(int i=0;i<=11;i++){
        for(int j=0;j<v[i].size();j++)
            cout<<v[i][j]<<" ";
        cout<<endl;
    }
}

int countSetBits(int n){
    int _count = 0;
    while(n){
        n = n & (n-1);
        _count++;
    }
    return _count;
}
