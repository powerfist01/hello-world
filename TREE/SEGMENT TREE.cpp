#include <bits/stdc++.h>
#define siz 1000000
using namespace std;

long long int arr[siz]={0},seg_tree[4*siz]={0},lazy[4*N] = {0};

void build(int start,int end,int node){
    if(start==end){
        seg_tree[node]=arr[start];
        return;
    }
    else{
    	int mid=(start+end)/2;
    	build(start,mid,2*node);
    	build(mid+1,end,2*node+1);
    	seg_tree[node]=seg_tree[2*node]+seg_tree[2*node+1];
    	return;
    }
}//end of function build


int query(int l,int r,int start,int end,int node){
	if(r<start || l>end)
		return 0;
	else if(l<=start && r>=end)
		return seg_tree[node];
	else{
		int mid=(start+end)/2;
		return query(l,r,start,mid,node*2)+query(l,r,mid+1,end,node*2+1);
	}
}//end of function query


void update(int i,int value,int start,int end,int node){
	if(start==end){
		seg_tree[node]=value;
		return;
	}
	int mid=(start+end)/2;
	if(i<=mid)
		update(i,value,start,mid,node*2);
	else
		update(i,value,mid+1,end,node*2+1);
	seg_tree[node]=seg_tree[2*node]+seg_tree[2*node+1];
}//end of function update


void lazy_update(int s,int e,int node_num){
	seg_tree[node_num] = (e-s+1) * lazy[node_num];
	if(e>s)
		lazy[node_num*2] = lazy[node_num*2+1] = lazy[node_num];
		lazy[node_num] = 0;
}//end of function lazy_update

void set_lazy(int s,int e,int new_val,int node_num){
	if(e>s){
		int m = (s+e)/2;
		lazy[node_num*2] = lazy[node_num*2+1] = new_num;
	}
}//end of function set_lazy
 
void range_update(int l,int r,int new_val,int s,int e,int node_num)
{
	if(lazy[node_num]>0)
		lazy_update(s,e,node_num);
	if(s>r || e<l)
		return;
	else if(s>=l && e<= r)
		seg_tree[node_num] = (e-s+1)*new_val , set_lazy(s,e,new_val,node_num);
	else{
		int m = (s+e)/2;
		range_update(l,r,new_val,s,m,node_num*2);
		range_update(l,r,new_val,m+1,e,node_num*2+1);
		seg_tree[node_num] = seg_tree[node_num*2] + seg_tree[node_num*2+1];
	}
}//end of function range_update

int main(){
	int n;
	cout<<"Enter number of items:\n";
	cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%lld",&arr[i]);

    build(1,n,1);

    int q;
    cout<<"Enter number of queries:\n";
    cin>>q;
    while(q--){
    	int l,r;
    	cin>>l>>r;
    	cout<<query(l,r,1,n,1)<<endl;
    }
    
    int u;
    cout<<"Enter number of updates:\n";
    cin>>u;
    while(u--){
    	int i,value;
    	cin>>i>>value;
    	for(int i=1;i<=20;i++){
    		cout<<seg_tree[i]<<" ";
    	}
    }
	return 0;
}