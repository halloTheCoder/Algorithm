#include <iostream>
#include <vector>

#define sc(n) cin>>n
#define forL(i,n) for(int i=0;i<n;i++)

class Uf{
private:
    vector<int> a;
public:
    Uf(vector<int> a);
    bool unionFind(int m,int n);
    void _union(int m,int n);
    void display();
    int root(int a);
};

Uf::Uf(vector<int> a){
    this->a = a;
}

int root(int a){

}

int main(){
    int n;
    sc(n);

    return 0;
}

