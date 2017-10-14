#include <bits/stdc++.h>
using namespace std;
class node{
public:
	int data;
	node* left;
	node* right;
};

node* newnode(int data){
	node* temp = new node;
	temp->left = NULL;
	temp->right = NULL;
	temp->data = data;
	return temp;
}

void preorder(node* root){
	if(root!=NULL){
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(node* root){
	if(root!=NULL){
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}

void postorder(node* root){
	if(root!=NULL){
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<" ";
	}
}

void levelorder(node* root){
	queue <node*> q;
	q.push(root);
	while(!q.empty()){
		node* temp = q.front();
		cout<<temp->data<<" ";
		q.pop();
		if(temp->left!=NULL){
			q.push(temp->left);
		}
		if(temp->right!=NULL){
			q.push(temp->right);
		}
	}
}

int maxheight(node* root){
	if(root==NULL)
		return -1;
	else
		return max(1+maxheight(root->left),1+maxheight(root->right));
}

int main(){
	node* root = newnode(1);
	root->left = newnode(2);
	root->right = newnode(3);
	root->left->left = newnode(4);
	root->left->right = newnode(5);
	root->right->left = newnode(6);
	root->right->right = newnode(7);

	cout<<"Pre-Order:"<<endl;
	preorder(root);
	cout<<endl;

	cout<<"In-Order:"<<endl;
	inorder(root);
	cout<<endl;

	cout<<"Post-Order:"<<endl;
	postorder(root);
	cout<<endl;

	cout<<"Level-Order:"<<endl;
	levelorder(root);
	cout<<endl;

	cout<<"Height:"<<maxheight(root);
	cout<<endl;
	return 0;
}