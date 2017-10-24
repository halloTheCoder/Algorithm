#include <iostream>
#include <vector>

#define sc(n) cin>>n
#define forL(i,n) for(int i=0;i<n;i++)

using namespace std;

class Uf{
private:
    vector<int> a;
public:
    Uf(vector<int> a);
    bool unionFind(int m,int n);
    void _union(int m,int n);
    void display();
};

Uf::Uf(vector<int> a){
    this->a = a;
}

bool Uf::unionFind(int m,int n){
    return this->a[m] == this->a[n];
}

void Uf::_union(int m,int n){
    int temp = this->a[m];
    for(int i=0;i<this->a.size();i++){
        if(a[i] == temp)
            a[i] = a[n];
    }
}

void Uf::display(){
    forL(i,10)
        cout<<a[i]<<" ";
    cout<<endl;
}

int main(){
    vector<int> a(10);
    forL(i,10) a[i] = i;
    Uf uf(a);
    uf._union(0,5);
    uf._union(1,6);
    uf._union(5,6);
    uf._union(3,8);
    uf._union(9,3);
    uf._union(9,4);
    uf._union(1,7);
    uf._union(2,7);
    uf.display();
    cout<<boolalpha<<uf.unionFind(0,7)<<endl;
    cout<<boolalpha<<uf.unionFind(0,4)<<endl;
    return 0;
}
