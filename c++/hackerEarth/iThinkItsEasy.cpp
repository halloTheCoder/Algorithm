#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define sc(n) cin>>n
#define forL(i,n) for(int i=0;i<n;i++)

bool myCompare(string a,string b){
    return a.size() < b.size();
}

int main(){
    ios::sync_with_stdio(false);
    int t;
    sc(t);
    cin.get();
    while(t--){
        string str,temp="";
        getline(cin,str);
        vector<string> v_str;
        int i;
        for(i=0;i<str.size();i++){
            if(str[i] != ' ')
                temp+=str[i];
            else{
                v_str.push_back(temp);
                temp.clear();
            }
        }
        v_str.push_back(temp);
        temp.clear();
        v_str.shrink_to_fit();
        stable_sort(v_str.begin(),v_str.end(),myCompare);
        forL(i,v_str.size())
            cout<<v_str[i]<<" ";
        cout<<endl;
    }
    return 0;
}
