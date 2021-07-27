#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left, *right;
    Node(int x):val(x),left(NULL),right(NULL){}
};

//insert in bst
Node* insert(Node* root, int x)
{
    Node* node= new Node(x);
    if(!root) return node;
    if(root->val<x) root->right=insert(root->right,x);
    if(root->val>x) root->left=insert(root->left,x);
    return root;
}

//find next min val of current
Node* nextMin(Node* root)
{
    Node* cur=root;
    while(cur && cur->left)
    cur=cur->left;
    return cur;
}
//deletion in bst
Node* deleteNode(Node* root, int x)
{
    if(!root) return root;
    if(root->val<x) root->right=deleteNode(root->right,x);
    else if(root->val>x) root->left= deleteNode(root->left,x);
    else if(root->val==x)
    {
        if(!root->left && !root->right) return NULL;
        if(!root->left) 
        {
            Node* tmp=root->right;
            free(root);
            return tmp;
        }
        else if(!root->right)
        {
            Node* tmp=root->left;
            free(root);
            return tmp;
        }
        Node *tmp=nextMin(root->right);
        root->val=tmp->val;
        root->right=deleteNode(root->right,tmp->val);
    }
    return root;
}

//search in bst
bool search(Node* root, int x)
{
    if(!root) return false;
    if(root->val==x) return true;
    bool f=false;
    if(root->val<x) f=search(root->right,x);
    if(root->val>x) f=search(root->left,x);
    return f;
}

//inorder of bst
void inorder(Node* root)
{
    if(!root) return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

int main()
{
    Node* root=NULL;
    root=insert(root,2);
    root=insert(root,1);
    root=insert(root,4);
    root=insert(root,6);
    root=insert(root,5);
    root=insert(root,7);
    inorder(root);
    cout<<endl;
    root=deleteNode(root,4);
    inorder(root);
    cout<<endl;
    cout<<search(root,4)<<" "<<search(root,7)<<endl;
    return 0;
}