#include <bits/stdc++.h>
#include <string>
#include <bitset>

#define sc(n) cin>>n
#define forL(i,n) for(int i=0;i<n;i++)

using namespace std;

int countBitSet(int bin);
int countBitSetBrianKernighan(int n);

int main(){
    ios::sync_with_stdio(false);
    int bin;
    sc(bin);
    cout<<countBitSet(bin)<<endl;
    cout<<countBitSetBrianKernighan(bin)<<endl;
    return 0;
}

int countBitSet(int n){
    int _count = 0;
    while(n){
        _count += n & 1;
        n >>= 1;
    }
    return _count;
}

int countBitSetBrianKernighan(int n){
    int _count = 0;
    while(n){
        n = n&(n-1);
        _count++;
    }
    return _count;
}
