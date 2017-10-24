#include <iostream>
#include <algorithm>
#include <vector>

#define sc(n) cin>>n;
#define forL(i,n) for(int i=0;i<n;i++)

using namespace std;

void countSort(vector<int> &a,int n);

int main(){
    ios::sync_with_stdio(false);
    int n;
    sc(n);
    vector<int> a(n);
    forL(i,n) cin>>a[i];
    countSort(a,n);
    forL(i,n) cout<<a[i]<<"\t";
    cout<<endl;
    return 0;
}

void countSort(vector<int> &a,int n){
    int k = *max_element(a.begin(),a.end());
    vector<int> countA(k+1,0);
    forL(i,n) countA[a[i]]++;
    int index = 0;
    for(int i=0;i<=k;i++){
        for(int j=0;j<countA[i];j++)
            a[index++] = i;
    }
}
