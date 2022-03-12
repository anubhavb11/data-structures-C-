#include <iostream>
#include<queue>
#include<vector>
#include<map>
using namespace std;

class node{
    public:
    int data;
    node* right;
    node* left;
    node(int d){
        data = d;
        left = right = NULL;
    }
};

node* insertBST(node*root,int data){
    if(root == NULL){
        root = new node(data);
        return root;
    }
    if(data < root->data){
        root->left  = insertBST(root->left, data);
    }
    else{
        root->right = insertBST(root->right,data);
    }
    return root;
}


node* createBST(){
    node* root = NULL;
    int data ;
    cin>>data;
    while(data!=-1){
        root = insertBST(root, data);
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
    // node* root = createBST();
    // level_order(root);

    // bst from a sorted array 
    int arr[] = {1,2,4,6,7,8,9};
    int s = 0;
    int e = sizeof(arr)/sizeof(int);
    node* temp = NULL;
    temp = build_bst(arr,s,e-1);
      level_order(temp);
    // cout<<"Hello World!";
}
