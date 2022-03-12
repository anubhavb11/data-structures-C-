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

class Pair{
    public:
    int diameter;
    int height;
};


node* createBT(){
    int data;
    cin>>data;
    if(data ==-1){
        return NULL;
    }
    node* root = new node(data);
    root->left = createBT();
    root->right = createBT();

    return root;
}

void preorder(node* root ){
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}

void postorder(node* root){
    if(root == NULL){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void inorder(node* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}


int countNodes(node* root){
    if(root == NULL){
        return 0;
    }

    int left_count = countNodes(root->left);
    int right_count = countNodes(root->right);
    return left_count + right_count +1;
}

int height(node* root){
    if(root == NULL){
        return 0;
    }
    int right = height(root->right);
    int left = height(root->left);
    // cout<<right<<" "<<left<<endl;

    return max(right,left) +1;
}

int diameter(node* root){
    if(root == NULL){
        return 0;
    }
    int op1 = height(root->left) + height(root->right) ;
    int op2 = diameter(root->left);
    int op3 = diameter(root->right);
    return max(op1, max(op1,op2));
}

Pair fastDiameter(node* root){
    Pair p;
    if(root == NULL){
        p.height = p.diameter = 0;
        return p;
    }
    Pair left = fastDiameter(root->left);
    Pair right = fastDiameter(root->right);
    int op1 = right.height + left.height;
    int op2 = right.diameter;
    int op3 = left.diameter;
    p.height = max(right.height, left.height) +1;
    p.diameter = max(op1, max(op2,op3));
    return p;
}

node* find_nodes(node*n ,node*p ,node* q){
    static bool a =false;
    static bool b = false;
    if(n == NULL){
        return NULL;
    }
    if(n == p){
        cout<<"s";
        a = true;
        return n;
    }
    if(n == q){
        b= true;
        return n;
    }
    if(p&& q){
        // return true;
        cout<<"FOUND";
    }
    // else{
    //     return false;
    // }
    node* left = find_nodes(n->left,p,q);
    if(left!= NULL){
        return left;
    }
    node* right = find_nodes(n->right,p,q);
    return right;
}

vector<int> path;
node* searchdfs(node* root,int key){
    if(root == NULL){
        return NULL;
    }
    path.push_back(root->data);
    if(root->data == key){
        return root;
    }
    node* ans = searchdfs(root->left,key);
    if(ans!= NULL){
        return ans;
    }

    ans = searchdfs(root->right,key);
    path.pop_back();
    return ans;
}

void level_order2(node* root,node* p,node* b){
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
            find_nodes(n ,p ,b);
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

node* create_level_order_bt(){
    node* root = new node(8);
    queue<node*> q;
    while(!q.empty()){
        node* n = q.front();
        q.pop();
        int a,b;
        cout<<"ether right and left";
        cin>>a>>b;
        if(a!=-1){
            n->left = new node(a);
            q.push(n->left);
        }
        if(b!=-1){
            n->right = new node(b);
            q.push(n->right);
        }
    }
    return root;
}


void right_view(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    cout<<root->data<<" ";
    while(!q.empty()){
        node* n= q.front();
        q.pop();
        if(n==NULL){
            if(!q.empty()){
                cout<<q.front()->data<<" "; // for left view use back(rear) 
                q.push(NULL);
            }
        }
        else{
            if(n->left!=NULL){
                q.push(n->left);
            }
            if(n->right!=NULL){
                q.push(n->right);
            }
            
        }
    }
}

void left_view(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    cout<<root->data<<" ";
    while(!q.empty()){
        node* n= q.front();
        q.pop();
        if(n==NULL){
            if(!q.empty()){
                cout<<q.back()->data<<" ";  // for right view use front
                q.push(NULL);
            }
        }
        else{
            if(n->left!=NULL){
                q.push(n->left);
            }
            if(n->right!=NULL){
                q.push(n->right);
            }
            
        }
    }
}


int replace_node_with_sum(node* root){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        return root->data;
    }
    int leftsum = replace_node_with_sum(root->left);
    int rightsum = replace_node_with_sum(root->right);
    int temp = root->data;
    root->data = leftsum + rightsum;
    return temp + root->data;

}


node*  mirror_tree(node* root){
    if(root == NULL){
        return NULL;
    }
    swap(root->left,root->right);
    node* left = mirror_tree(root->left);
    node* right = mirror_tree(root->right);
    
    return root;

}

void digonal_treversal(node* root, map<int,vector<int>> &m,int d){
    if(root == NULL){
        return;
    }
    m[d].push_back(root->data);
    // for rleft inc the map key 
    digonal_treversal(root->left,m,d+1);
    // no need for right
    digonal_treversal(root->right,m,d);

    /*
           (0)
            5
          /  \
        (1).  (0)
         2      2
         for left we increase for right we do nothing
    */ 
}

int width_binary_tree(node*root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    int width =0;
    int ans = -1;
    while(!q.empty()){
        node* n = q.front();
        q.pop();
        if(n == NULL){
            cout<<width;
            ans = max(width,ans);
            width = 0;
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            if(n->left){
                width++;
                q.push(n->left);
            }
            if(n->right){
                width++;
                q.push(n->right);
            }
        }
    }
    return ans;
}

int main() {
    //  cout<<"Hello World!";
     node* root = createBT();
    //  preorder(root);
    // node *root = new node(1);
 
    // root->left = new node(2);
    // root->right = new node(3);
    // root->right->right = new node(4);
    //     root->right->right->right = new node(4);
    //             root->right->right->right->right = new node(4);


    // root->left->right = new node(5);
   
    //  create_level_order_bt();
    //    level_order(root,root->right->right->right,root->right->right);
    //    cout<<endl;
    //    replace_node_with_sum(root);
    //    level_order(root);
    // mirror_tree(root);
    //   level_order(root);
    node*x  = searchdfs(root,12);
    // cout<<x->data;
    // for(int i=0;i<path.size();i++){
    //     cout<<path[i]<<" ";
    // }
    // cout<<endl;
    // map<int,vector<int> >m;
    // digonal_treversal(root,m,0);
    // for(auto i:m){
    //     for(int j=0;j<i.second.size();j++){
    //         cout<<i.second[j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<width_binary_tree(root);

}
