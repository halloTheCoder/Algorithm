#include <iostream>
#include <vector>
#include <algorithm>

#define sc(n) cin>>n
#define forL(i,n) for(int i=0;i<n;i++)

using namespace std;

void bucketSortNegative(vector<float> &a){
    int n = a.size();
    vector<float> c[n+1];
    forL(i,n){
        int index = a[i]*n;
        c[index].push_back(a[i]);
    }
    forL(i,n)
        sort(c[i].begin(),c[i].end());
    int index = 0;
    forL(i,n){
        for(int j=0;j<c[i].size();j++){
            a[index++] = c[i][j];
        }
    }
}

void separate(float a[],int n){
    vector<float> pos,neg;
    forL(i,n){
        if(a[i] >= 0)
            pos.push_back(a[i]);
        else
            neg.push_back(-a[i]);
    }
    bucketSortNegative(neg);
    bucketSortNegative(pos);
    int index = 0;
    for(int i=neg.size()-1;i>=0;i--){
        a[index++] = -neg[i];
    }
    for(int i=0;i<pos.size();i++)
        a[index++] = pos[i];
}

int main(){
    ios::sync_with_stdio(false);
    int n;
    sc(n);
    float *a = new float[n];
    forL(i,n) sc(a[i]);
    separate(a,n);
    forL(i,n) cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
