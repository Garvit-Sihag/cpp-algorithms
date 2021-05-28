#include<C:/VS_code/Cpp/stdc++.h>
using namespace std;

int arr[100000];int tree[4*100000+1];pair<int,int> lazy[4*100000+1];

void create(int i,int j,int node){
    if(i==j){
        tree[node]=arr[i];
        
          lazy[node].first=0;
        lazy[node].second=0;
        return;
    }
    int mid=(i+j)/2;
    create(i,mid,2*node+1);
    create(mid+1,j,2*node+2);
    tree[node]=tree[2*node+1]+tree[2*node+2];
        lazy[node].first=0;
        lazy[node].second=0;
    return;
}

void update(int i,int j,int x,int y,int val,int node){
    //pending update
    if(lazy[node].first!=0){
        int n=lazy[node].first;
        int f=lazy[node].second;
        lazy[node].first=0;
        lazy[node].second=0;
        tree[node]+=n*(j-i+1);
        if(f==0)
        tree[node]+=(((j-i+1)*(i+j))/2);
        else
        tree[node]+=f*(((j-i+1)*(i+j))/2);    
        if(i!=j){
            lazy[2*node+1].first+=n;
            lazy[2*node+1].second++;
            lazy[2*node+2].first+=n;
            lazy[2*node+2].second++;
        }
    }
       // no overlap
        
        if(x>j || i>y) return;
        
      // complete overlap
        
        if(x<=i && j<=y){
            
            // update this node
            tree[node]+=(val*(j-i+1));
              tree[node]+=(((j-i+1)*(i+j))/2);
            
            if(i!=j){
                lazy[node*2+1].first+=val;
                lazy[node*2+1].second++;
                lazy[node*2+2].first+=val;
                lazy[node*2+2].second++;
            }
            return;
        }
    
    // partial overlap
    
        int mid=(i+j)/2;
        update(i,mid,x,y,val,2*node+1);
        update(mid+1,j,x,y,val,2*node+1);
        tree[node]=tree[node*2+1]+tree[2*node+2];
    
  }

int query(int i,int j,int x,int y,int node){
    
    //pending update
    if(lazy[node].first!=0){
        int n=lazy[node].first;
        int f=lazy[node].second;
        lazy[node].first=0;
        lazy[node].second=0;
        tree[node]+=n*(j-i+1);
        if(f==0)
        tree[node]+=(((j-i+1)*(i+j))/2);
        else
        tree[node]+=f*(((j-i+1)*(i+j))/2);    
        if(i!=j){
            lazy[2*node+1].first+=n;
            lazy[2*node+1].second++;
            lazy[2*node+2].first+=n;
            lazy[2*node+2].second++;
    }

    }
       // no overlap
        
        if(x>j || i>y) return 0;
        
      // complete overlap
        
        if(x<=i && j<=y) return tree[node];
       
    
    // partial overlap
    
        int mid=(i+j)/2;
    return (query(i,mid,x,y,2*node+1)+query(mid+1,j,x,y,2*node+2));
}

int main() {

	/*
		1. You have to take the input by yourself as mentioned in the input format.
		2. You have to print the output by yourself as per the output format mentioned.
		3. You may start writing your code below this multi-line comments section.
	*/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   
    
    int n,q;
    cin>>n>>q;  
    
    for(int i=0;i<n;i++) cin>>arr[i];
    
    
    
    create(0,n-1,0);
    
    while(q--){
        int num,x,y;
        cin>>num>>x>>y;
        x--;y--;
        if(num==1){
            int val;
            cin>>val;
            update(0,n-1,x,y,val,0);
        }else{
            cout<<query(0,n-1,x,y,0)<<endl;
        }
    }

	return 0;
}

