#include<bits/stdc++.h>
using namespace std;
void egyptianfraction(int n,int d){
    cout<<"egyptian fraction of"<<n<<"/"<<d<<"is:";
    while(n!=0){
        int unitden=ceil((double)d/n);
        cout<<"1/"<<unitden;
        n=n*unitden-d;
        d=d*unitden;
        if(n!=0) cout<<"+";
    }
    cout<<endl;


}
int main(){
    int n,d;
    cin>>n;
    cin>>d;
    egyptianfraction(n,d);


}
