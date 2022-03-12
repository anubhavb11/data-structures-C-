\#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    node(int d){
        data = d;
        left = right = NULL;
    }
};

node* insertBST(node* root, int data){
    if(root == NULL){
        root = new node(data);
        return root;
    }
    if(data<root->data){
        root->left = insertBST(root->left,data);
    }
    else{
        root->right = insertBST(root->right,data);
    }
    return root;
}

node* buildBST(){
    int data;
    cin>>data;
    // if(data == -1){
    //     return NULL;
    // }
    node* root;
    while(data!=-1){
        if(root == NULL){
            root  = new node(data);
        }
        else{
            insertBST(root,data);
        }
        // if(data!=-1){
           
        // }
        cin>>data;
    }
    return root;
}



void level_order(node* root){
    queue<node*>   q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* n = q.front();
        q.pop();
        if(n ==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<n->data<<" ";
            if(n->left!=NULL){
                q.push(n->left);
            }
            if(n->right!=NULL){
                q.push(n->right);
            }
        }
    }
}


bool search(node* root,int data){
    if(root == NULL){
        return false;
    }
    if(root->data == data){
        return true;
    }
    if(data < root->data){
       return search(root->left,data);
   }
   else{
      return search(root->right,data);
   }
//    return false;

}

node* deleteNode(node* root,int data){
    if(root == NULL){
        return NULL;
    }
    if(data < root->data){
        root->left = deleteNode(root->left,data);
        return root;
    }
    else if(data == root->data){
        // case 1 
        if(root->right == NULL && root->left== NULL){
            delete root;
            return NULL;
        }
        // case 2 
        if(root->right!=NULL && root->left == NULL){
            node* temp = root->right;
            delete root;
            return temp;
        }
        if(root->left!=NULL && root->right == NULL){
            node* temp = root->left;
            delete root;
            return temp;
        }
        /// case 3;
         if(root->left!=NULL && root->right!= NULL){
            node* replace = root->right;
            while(replace->left!=NULL){
                replace = replace->left;
            }
            root->data = replace->data;
            root->right = deleteNode(root->right,data);
            return root;


        }
    }
     else{
             root->right = deleteNode(root->right,data);
            return root;
        }
        return root;
}


void preorder(node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

bool isBST(node*root , int left = INT_MIN , int right = INT_MAX){
    if(root == NULL){
        return true;
    }
    if(root->data >= left && root->data <= right && isBST(root->left,left,root->data) && isBST(root->right,root->data,right) ){
        return true;
    }
    else{
        return false;
    }
}

class Pair{
    public:
    int height;
    bool balanced;
};

Pair isBalanced(node* root){
    Pair p;
    if(root == NULL){
        p.balanced = true;
        p.height = 0;
        return p;
    }
    Pair left = isBalanced(root->left);
    Pair right = isBalanced(root->right);
    p.height = max(left.height,right.height) +1;
    if(abs(left.height - right.height) <=1 && left.balanced && right.balanced ){
        p.balanced = true;
    }
    else{
        p.balanced = false;
    }
    return p;
}



node* build_bst_sorted_array(int arr[100], int s, int e){
    if(s>e){
        return NULL;
    }
    int mid = (s+e)/2;
    node* root = new node(arr[mid]);
    root->left = build_bst(arr,s,mid-1);
    root->right = build_bst(arr,mid+1,e);
    return root;
}


int main() {
   node*root = buildBST();
   level_order(root);

//    deleteNode(root,4);
   cout<<endl;
   preorder(root);
    if(isBalanced(root).balanced){
		cout<<"BST"<<endl;
	}
	else{
		cout<<"Not a BST"<<endl;
	}
    // isBalanced(root);
//    cout<<search(root,5);
}
