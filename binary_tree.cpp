#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

void preorderTraversal(node* root){

    if(root==NULL)
    return;

    cout<<root->data<<" ";

    preorderTraversal(root->left);
    preorderTraversal(root->right);

}

void inorderTraversal(node* root){

    if(root==NULL)
    return;

    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
    
}

void postorderTraversal(node* root){
    if(root==NULL)
    return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->data<<" ";
}

/*        1
        /   \
       2     3
      / \   / \
     4   5  6  7
*/    

int main(){
    node* root = NULL;
    root=new node(1);
    root->left = new node(2);
    root->right=new node(3);
    
    root->left->left=new node(4);
    root->left->right=new node(5);
    
    root->right->left=new node(6);
    root->right->right=new node(7);

 preorderTraversal(root);
 cout<<endl;
 inorderTraversal(root);
 cout<<endl;
 postorderTraversal(root);

    return 0;
}