#include<iostream>
#define fr(i,n) for(int i=0;i<n;i++)
#define INT_MAX 1000000001
using namespace std;


void print(int*arr,int n){
    fr(i,n) cout<<arr[i]<<" ";
    
    cout<<endl;
    
}

int min(int i,int j){
    if(i>j) return j;
    return i;
}

int main(){
     int n;
     
     cin>>n;
     int**arr=new int*[n];
    fr(i,n) arr[i]=new int[n];

    fr(i,n){
        fr(j,n){
            arr[i][j]=0;
            
        }
    }
    
   int e;
   cin>>e;
   


   fr(i,e){
     
       int x,y,z;
            cin>>x>>y>>z;
              
            arr[x][y]=z;
   }
   
   //node from which min path to every vertex is to be calculated

 
  
     int node;
     cin>>node;

    int*distance=new int[n];
     fr(i,n) distance[i]=INT_MAX;
     distance[node]=0;

   //bellmman ford algorithm

   fr(k,n){
       
        cout<<"- ---- --- -"<<endl;
     fr(i,n){
        
             fr(j,n){
                 if(distance[i]!=INT_MAX && arr[i][j]!=0){
                     distance[j]=min(distance[j] ,distance[i]+arr[i][j]);
                 }
                 
             }
           
         
     }

   }
 cout<<endl;
 fr(i,n) cout<<distance[i]<<" ";

    return 0;
}