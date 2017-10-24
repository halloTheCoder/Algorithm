#include <iostream>
#include <vector>
#include <algorithm>

#define sc(n) cin>>n

using namespace std;

void _sort(vector<float> &c);
void bucketSort(float a[],int n);
void separate(float a[],int n);

int main(){
    int n;
    sc(n);
    float *a = new float[n];
    for(int i=0;i<n;i++)
        sc(a[i]);
    separate(a,n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<"\t";
    cout<<endl;
    return 0;
}

void bucketSort(vector<float> &a){
    int n = a.size();
    vector<float> b[n];
    for(int i=0;i<n;i++){
        int index = a[i]*n;
        b[index].push_back(a[i]);
    }
    for(int i=0;i<n;i++)
        _sort(b[i]);
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

void separate(float a[],int n){
    vector<float> neg,pos;
    for(int i=0;i<n;i++){
        if(a[i] < 0)
            neg.push_back(-a[i]);
        else
            pos.push_back(a[i]);
    }
    bucketSort(neg);
    bucketSort(pos);
    for(int i=0;i<neg.size();i++)
        a[i] = -neg[neg.size()-i-1];
    for(int i=neg.size();i<n;i++)
        a[i] = pos[i-neg.size()];
}
