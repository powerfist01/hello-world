#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node *right = NULL;
	struct node *left = NULL;	
};
int main(){
	node *root = new node();
	//node *neww = new node();
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	root->data = a[0];
	for(int i=1; i<n; i++){
		if(root->data > a[i]){
			
		}
	}

}