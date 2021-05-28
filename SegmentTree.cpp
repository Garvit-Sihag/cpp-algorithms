#include<iostream>
using namespace std;
void create(int*arr,int*tree,int i,int j,int node){
    
    if(i==j){
        tree[node]=arr[i];
        return;
    }
    
    int mid=(i+j)/2;
    create(arr,tree,i,mid,2*node+1);
    create(arr,tree,mid+1,j,2*node+2);
    tree[node]=tree[node*2+1]+tree[node*2+2];
    return;
}

void update(int*arr,int*tree,int i,int j,int index,int v,int node){
    
    int mid=(i+j)/2;
    if(i==j){
        arr[index]=v;
        tree[node]=v;
        return;
    }else if(mid>=index){
        update(arr,tree,i,mid,index,v,2*node+1);
    tree[node]=tree[node*2+1]+tree[node*2+2];
        
    }else{
        update(arr,tree,mid+1,j,index,v,2*node+2);
        tree[node]=tree[node*2+1]+tree[node*2+2];
    }
    
    }
    
  int query(int*tree,int i,int j,int l,int r, int node){
   
   // total overlap
   if(l<=i && j<=r)  return tree[node];


// no overlap

if(l>j || r<i){
    return 0;
}

//partial overlap

else{
    int mid=(i+j)/2;
return query(tree,i,mid,l,r,node*2+1)+query(tree,mid+1,j,l,r,node*2+2);
}

  }

int main(){

    cout<<"running"<<endl;
int n=6;
int arr[]={1,2,3,4,5,6}; 
int*tree=new int[4*n];    
 
 for(int i=0;i<4*n;i++) tree[i]=0;

create(arr,tree,0,n-1,0);
   
   for(int i=0;i<4*n;i++) cout<<tree[i]<<" ";
   
//    update(arr,tree,0,n-1,3,7,0);
//    cout<<endl;
//    cout<<"------------"<<endl;
//    for(int i=0;i<4*n;i++) cout<<tree[i]<<" ";

   cout<<"query"<<endl;
   cout<<query(tree,0,n-1,1,4,0)<<endl;
   cout<<"done"<<endl;

return 0;    
}
