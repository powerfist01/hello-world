#include <bits/stdc++.h>
#include <iostream.h>
using namespace std;
class node{
public:
	int data;
	node* left;
	node* right;
};
node* new_node(int data){
	node* temp = new node;
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
}
node* recur_insert(node* root,int data){
	if(root == NULL){
		root=new_node(data);
	}
	else{
		if(data<=root->data){
			root->left = recur_insert(root->left,data);
		}
		else{
			root->right = recur_insert(root->right,data);
		}
	}
	return root;
}

bool search(node* root,int data){
	if(root==NULL)
		return false;
	else if(root->data==data)
		return true;
	else if(data<=root->data)
		return search(root->left,data);
	else
		return search(root->right,data);

}
int height(node* root) {
    if(root == NULL)
        return -1;
    else
        return 1+max(height(root->left),height(root->right));
}

int maximum(node* root){
	if(root==NULL)
		return -1;
	if(root->right==NULL)
		return root->data;
	else
		return maximum(root->right);
}

int minimum(node* root){
	if(root==NULL)
		return -1;
	if(root->left==NULL)
		return root->data;
	else
		return minimum(root->left);
}

void preOrder(node* root){
	if(root==NULL)
		return;
	else{
		cout<<root->data<<" ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

void inOrder(node* root){
	if(root==NULL)
		return;
	else{
		inOrder(root->left);
		cout<<root->data<<" ";
		inOrder(root->right);
	}
}

void postOrder(node* root){
	if(root==NULL)
		return;
	else{
		postOrder(root->left);
		postOrder(root->right);
		cout<<root->data<<" ";
	}
}

 

void levelOrder(node* root){
	queue <node*> q;
	q.push(root);
	while(!q.empty()){
		node* temp=q.front();
		cout<<temp->data<<" ";
		q.pop();
		if(temp->left!=NULL)
			q.push(temp->left);
		if(temp->right!=NULL)
			q.push(temp->right);
	}
}

int main(){
	node* root=NULL;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int data;
		cin>>data;
		root=recur_insert(root,data);
	}

	levelOrder(root);
	cout<<endl;
	preOrder(root);
	cout<<endl;
	cout<<maximum(root)<<endl<<minimum(root)<<endl;

	return 0;
}
