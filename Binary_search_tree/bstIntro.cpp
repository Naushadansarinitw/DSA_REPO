// Insertion Complexity T.C O(logn)

#include <iostream>
#include <queue>f
using namespace std;

class node {
    public:
        int data;
        node* left;
        node* right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};


void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else {
            cout<< temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}


node* insertIntoBST(node* root, int d){
    // base case 
    if(root == NULL){
        root = new node(d);
        return root;
    }

    if(d > root->data){
        // right part me  insert kara hai 
        root -> right = insertIntoBST(root->right, d);
    }
    else {
        // left part me insert karna hai
        root->left = insertIntoBST(root->left, d);
    }

return root;
}


void takeInput(node* &root){
    int data;
    cin>>data;

    while(data != -1){
        root = insertIntoBST(root,data);
        cin>>data;
    }
}

int main(){
     
     node* root = NULL;

     cout<< "Enter the data to create a BST"<<endl;

     takeInput(root);

     levelOrderTraversal(root);
return 0;
}