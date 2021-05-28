#include<C:/VS_code/Cpp/stdc++.h>
using namespace std;
int main(void){
int n;int sum;
cin>>n;
vector<int> arr;
for(int i=0;i<n;i++) {
    int num;
    cin>>num;
    arr.push_back(num);
}

cin>>sum;
int m=sum;
vector<vector<int>> dp(n+1,vector<int>(sum+1,0));

dp[0][0]=1;

for(int i=1;i<=m;i++) dp[0][i]=0;

for(int i=1;i<=n;i++) dp[i][0]=1;

for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
        
        
        if(dp[i-1][j]==1) dp[i][j]=1;
        
        else{
            int sum=j;
            int need=sum-arr[i-1];
            
            if(need<0) dp[i][j]=0;
            else dp[i][j]=dp[i-1][need];
            
        }
        
    }
}

if(dp[n][m]){
    
    cout<<"yes"<<endl;
    
}else{
    cout<<"Not Possible"<<endl;
}
    
}
