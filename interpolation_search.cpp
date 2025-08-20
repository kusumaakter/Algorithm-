#include<bits/stdc++.h>
using namespace std;
int interpolationsearch(int a[],int l,int h,int x){
    if(l>h||x<a[l]||x>a[h]) return 0;
    int pos=l+((h-l)/(a[h]-a[l]))*(x-a[l]);
    if(a[pos]==x) return pos;
    else if(a[pos]>x) return interpolationsearch(a,l,pos-1,x);
    else return interpolationsearch(a,pos+1,h,x);


}
int main(){
    int n,x;

    cout<<"enter number of data set:";
    cin>>n;
    int a[n];
    cout<<"enter data set:";

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"enter the number of search:";
    cin>>x;

    cout<<"sorted dataset:";
    sort(a,a+n);

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    int ans=interpolationsearch(a,0,n-1,x);
    if(ans==0) cout<<"element not found!"<<endl;
    else cout<<"element found at position:"<<ans<<endl;



}
