#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,c;
    cout<<"enter number of item:";
    cin>>n;
    cout<<"enter knapsack capacity:";
    cin>>c;
    int p[100],w[100];
    double r[100];
    for(int i=0;i<n;i++){
        cin>>p[i]>>w[i];
        r[i]=(double)p[i]/w[i];
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<=n;j++){
            if(r[i]<r[j]){
                swap(r[i],r[j]);
                swap(p[i],p[j]);
                swap(w[i],w[j]);

            }
        }
    }
    double totalprofit=0.0;
    for(int i=0;i<n;i++){
        if(c>=w[i]){
            c-=w[i];
            totalprofit+=p[i];

        }
        else{
            totalprofit+=p[i]*((double)c/w[i]);
            break;
        }
    }
    cout<<"maximum profit in knapsack:"<<totalprofit<<endl;
    return 0;





}
