#include <bits/stdc++.h>
using namespace std;

int solve(int**arr,int n,int m,int i=0,int j=0){
    if(i>=n || j>=m)
        return 0;
    
    int ans1=solve(arr,n,m,i+1,j)+arr[i][j];
    
    int ans2=solve(arr,n,m,i,j+1)+arr[i][j];
    
    if(ans1<0 && ans2<0){
        return max(ans1,ans2);
    }

 return min(ans1,ans2);
    
}

int main()
{
    int t;
    cin>>t;
    
    while(t!=0){
        int n,m;
        cin>>n>>m;
        int**arr=new int*[n];
        
        for(int i=0;i<n;i++){
            arr[i]=new int[m];
           for(int j=0;j<m;j++){
               cin>>arr[i][j];
           }
        }
        cout<<arr[n-1][m-1]<<endl;
        int ans=solve(arr,n,m);
        
        if(ans<=0){
            ans=(ans*(-1))+1;
        }
        cout<<"test"<<" "<<ans<<endl;
        t--;
    }
}
