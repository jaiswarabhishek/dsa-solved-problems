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

int search(int inorder[],int start,int end,int key){
    
    for(int i=start;i<=end;i++){
        if(key==inorder[i])
        return i;
    }
    return -1;
}

node* buildTree(int preorder[],int inorder[],int start,int end){

    static int idx=0;

    if(start>end)
    return NULL;

    int curr=preorder[idx];
    idx++;

    node* n = new node(curr);

    if(start==end)
    return n;

    int pos = search(inorder,start,end,curr);

    n->left=buildTree(preorder,inorder,start,pos-1);  //build the left subtree
    n->right=buildTree(preorder,inorder,pos+1,end);  // build the right subtree
   
     return n;
}

void inorderTraversal(node* root){
    if(root==NULL)
    return;

    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

int main(){

    int preorder[] ={1,2,4,3,5};
    int inorder[]={4,2,1,5,3};

//pass preorder ,inorder array and start and end position of inorder;
   node* newNode= buildTree(preorder,inorder,0,4);
    
  inorderTraversal(newNode);

    return 0;
}