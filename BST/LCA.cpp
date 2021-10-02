// By Surya Sidhartha.S (https://github.com/S-Surya)
// Program to return the least common ancestral node of two given nodes in the BST
#include <bits/stdc++.h>
using namespace std;
#define INF 100000000
#define val data
#define key data

//Structure of Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    struct Node* nextRight;
    struct Node* next;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

//Function to find the height of the tree from root
int height(Node* root) {
    if (!root) {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}

//Recursive approach 
Node* lcaBST(Node* root, int x, int y) {
    if (!root) return NULL;

    int key = root->data;

    if (key < x && key < y) {
        return lcaBST(root->right, x, y);
    } else if (key > x && key > y) {
        return lcaBST(root->left, x, y);
    } else {
        //if key is x or y or it is b/w x and y then this is the lca
        return root;
    }
}

/*
    O(logN) Time. Assumes both n1 & n2 exist. If it is not guarenteed then do a search after calling LCA()
    Since this is tail-call recursion function just use iteration to do it in O(1) space without involving any stack
*/

//Iterative approach
Node* lcaIterative(Node* root, int x, int y) {
    if (!root) return NULL;

    Node* current = root;
    while (current) {
        int key = current->data;
        if (key < x && key < y) {
            current = current->right;
        } else if (key > x && key > y) {
            current = current->left;
        } else {
            return current;
        }
    }
    return NULL;
}

int main(){
    //construct a BST
    //call LCA on two of the nodes
    return 0;
}
