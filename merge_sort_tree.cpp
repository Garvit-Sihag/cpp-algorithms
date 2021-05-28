#include<C:/VS_code/Cpp/stdc++.h>
using namespace std;
// answering the query (l,r) range which are strictly larger than k

void create(vector<int> tree[],int*arr,int si,int sj,int node){
    
    if(si==sj){
        tree[node].push_back(arr[si]);
        return;
    }
    
    int mid=(si+sj)/2;
    
    create(tree,arr,si,mid,2*node+1);
    create(tree,arr,mid+1,sj,2*node+2);
    int i=0,j=0;
    while(i<tree[2*node+1].size() && j<tree[node*2+2].size()){
        
        if(tree[2*node+1][i]>tree[2*node+2][j]){
            tree[node].push_back(tree[node*2+2][j]);
            j++;
        }else{
            tree[node].push_back(tree[node*2+1][i]);
            i++;
        }
        
    }
    
     while(i<tree[2*node+1].size()){
            tree[node].push_back(tree[node*2+1][i]);
            i++;
    }
    
    
     while(j<tree[node*2+2].size()){
            tree[node].push_back(tree[node*2+2][j]);
            j++;
    }
    
}


int query(vector<int> tree[],int x,int y,int i,int j,int k,int node){
    
    // no overlap
    if(x>j || y<i) return 0;
    
    // complete overlap
    
    if(x<=i && j<=y) {
      return tree[node].end() - upper_bound(tree[node].begin(),tree[node].end(),k); 
    }
    
    // partial overlap
    int mid=(i+j)/2;
    
    return query(tree,x,y,i,mid,k,node*2+1)+ query(tree,x,y,mid+1,j,k,node*2+2);
    
    
}

int main(void){

   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

   int n;
   cin>>n;
   int arr[30000];
   for(int i=0;i<n;i++) cin>>arr[i];
    
     vector<int> tree[4*30001];
    create(tree,arr,0,n-1,0);
     

    int q;
    cin>>q;
    
    while(q--){
        
        
    	int x,y,k;
    	cin>>x>>y>>k;
    	x--;y--;
    	
    	cout<<query(tree,x,y,0,n-1,k,0)<<endl;
    }
    
}
