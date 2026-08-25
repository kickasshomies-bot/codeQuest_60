//this contains code for basic binary tree
//and its traversals
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val=val;
        left=NULL;
        right=NULL;
    }
};

//order -> 1.print 2. left 3. right
void preorder(Node *ptr){
    if(ptr==nullptr)return;
    cout<<ptr->val<<" ";
    preorder(ptr->left);
    preorder(ptr->right);
}

// order -> 1.left 2. print 3. right
void inorder(Node *ptr){
    if(ptr==nullptr)return;
    inorder(ptr->left);
    cout<<ptr->val<<" ";
    inorder(ptr->right);
}

// order -> 1. left 2.right 3.print
void postorder(Node *ptr){
    if(ptr==nullptr)return;
    postorder(ptr->left);
    postorder(ptr->right);
    cout<<ptr->val<<" ";
}

int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);

    root->left->left=new Node(4);
    root->left->right=new Node(5);

    cout<<"root value : "<<root->val<<endl;
    cout<<"preorder traversal: "<<endl;
    preorder(root);
    cout<<endl;
    cout<<"inorder traversal: "<<endl;
    inorder(root);
    cout<<endl;
    cout<<"postorder traversal: "<<endl;
    postorder(root);
    cout<<endl;
}