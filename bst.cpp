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

node* inorderSucc(node* root){
    node* curr=root;
    while(curr && curr->left !=NULL){
        curr= curr->left;
    }

    return curr;
}


node* deleteBST(node* root , int key){

    if(root->data>key){
       root->left= deleteBST(root->left,key);
    }

    else if (root->data<key){
       root->right= deleteBST(root->right,key);
    }

    else{
       if(root->left==NULL){
        node* temp = root->right;
        delete root;
        return temp;
       }
       else if(root->right==NULL){
        node* temp = root->left;
        delete root;
        return temp;
       }
     
       
        node* temp = inorderSucc(root->right);
        root->data = temp->data;
        root->right = deleteBST(root->right,temp->data);
     
    }
 
   return root;


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

  inorderTraversal(root);
  cout<<endl;

inorderTraversal(deleteBST(root,3));

    return 0;
}
