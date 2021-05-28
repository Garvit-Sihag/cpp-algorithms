#include<C:/MinGW/lib/gcc/mingw32/9.2.0/include/c++/mingw32/bits/stdc++.h>
using namespace std;

void print(vector<int> arr){
    for(int i=0;i<arr.size();i++) cout<<arr[i]<<" ";

    cout<<endl;
}

vector<int> rev(vector<int> arr,int si,int len,bool flag){
   vector<int> temp;
   if(flag){
       
       for(int i=0;i<si;i++) temp.push_back(arr[i]);
       
       for(int i=len;i>=si;i--){
       
           temp.push_back(arr[i]);
       }
       
       for(int i=len+1;i<arr.size();i++) temp.push_back(arr[i]);
       
   }else{
       
       
       for(int i=0;i<si-len;i++) temp.push_back(arr[i]);
       
       for(int i=si;i>=si-len;i--) temp.push_back(arr[i]);
       
       for(int i=si+1;i<arr.size();i++) temp.push_back(arr[i]);
       
       
       
   }

  return temp;

}

int main(){

    int t;
    cin>>t;
    int test=0;

    while(test++<t){
         int n,c;
       cin>>n>>c;
       vector<int> arr;
         for(int i=0;i<n;i++){
             arr.push_back(i+1);
         }

      if(c<n-1 || c>((n*(n+1))/2)-1){
          cout<<"Case #"<<test<<": "<<"IMPOSSIBLE"<<endl;
      }
      else if(n-1==c){
                 cout<<"Case #"<<test<<": ";print(arr);
      }
      else{
           int curr_cost=n-1;
           
           bool flag=true;

          for(int i=0;i<n-1;i++){
 
                 
              int max_cost=(n-i)+curr_cost; 
            
            if(max_cost >= c){
                
                int si,len;
                if(flag){
                    si=i;
                    len=c-curr_cost;
                }else{
                    si=n-i;
                   len=c-curr_cost;
                }
                
                arr=rev(arr,si,len,flag);
                cout<<"Case #"<<test<<": ";print(arr);
                break;
            }else{

                int si,len;
                if(flag){
                    si=i;
                    len=n-i;
                }else{
                    si=n-i;
                    len=n-i;
                }
                arr=rev(arr,si,len,flag);
                curr_cost=curr_cost+(n-i)-1;
            }
 
              flag=~flag;
          }

      }

    }


    return 0;
}