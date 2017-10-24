#include <iostream>
#include <vector>
#include <algorithm>

#define sc(n) cin>>n

using namespace std;

void _sort(vector<float> &c);
void bucketSort(float a[],int n);

int main(){
    int n;
    sc(n);
    float *a = new float[n];
    for(int i=0;i<n;i++)
        sc(a[i]);
    bucketSort(a,n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<"\t";
    cout<<endl;
    return 0;
}

void bucketSort(float a[],int n){
    vector<float> b[n];
    for(int i=0;i<n;i++){
        int index = a[i]*n;
        b[index].push_back(a[i]);
    }
    for(int i=0;i<n;i++)
        _sort(b[i]);       //OR sort(b[i].begin(),b[i].end())
    int index = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<b[i].size();j++)
            a[index++] = b[i][j];
    }
}

void _sort(vector<float> &c){
    for(int i=1;i<c.size();i++){
        float temp = c[i],j;
        for(j=i-1;j>=0 && c[j] > c[i];j--){
            c[j+1] = c[j];
        }
        c[j+1] = temp;
    }
}
