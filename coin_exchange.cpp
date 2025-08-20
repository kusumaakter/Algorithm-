#include<bits/stdc++.h>
using namespace std;
int mincoins(int c[],int n,int a){
    const int INF=1e9;
    int dp[1005];
    for(int i=0;i<=a;i++){
        dp[i]=INF;
    }
    dp[0]=0;
    for(int i=1;i<=a;i++){
        for(int j=0;j<n;j++){
            if(c[j]<=i && dp[i-c[j]]!=INF){
                dp[i]=min(dp[i],dp[i-c[j]]+1);
            }
        }
    }
    return(dp[a]==INF)?-1:dp[a];


}
int main(){
    int n,a;
    cout<<"enter number of coin type:";
    cin>>n;
    int c[n];
    cout<<"enter coin denomination:";
    for(int i=0;i<n;i++){
            cin>>c[i];

    }
    cout<<"enter amount:";
    cin>>a;
    int ans=mincoins(c,n,a);
    if(ans==-1) cout<<"not possible to make the amount\n";
    else
        cout<<"minimun coin required:"<<ans<<endl;
    return 0;



}
