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

node* insertBST(node* root,int val){
     
     if(root==NULL)
     return new node(val);

    if(root->data<val){
        root->right = insertBST(root->right,val);
    }

    else{
        root->left = insertBST(root->left,val);
    }
  
    return root;

}

node* search(node* root , int key){
   
     if(root==NULL)
     return NULL;

    if(key==root->data)
    return root;

    if(root->data > key)
    return search(root->left,key);

    return search(root->right,key);
}

void inorderTraversal(node* root){
    if(root==NULL)
    return;

    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}
 

int main(){
     
node* root=NULL;

int arr[]={5,1,3,4,2,7};

root=insertBST(root,arr[0]);

for(int i=1;i<6;i++)
insertBST(root,arr[i]);

  if(search(root,0))
  cout<<"Element exist"<<endl;
  else
  cout<<"Not exist"<<endl;



    return 0;
}
