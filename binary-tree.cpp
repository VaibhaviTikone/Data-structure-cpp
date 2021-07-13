#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node *left, *right;
    Node(int a):val(a),left(NULL),right(NULL){}
};

Node* insert(Node* root, int x)
{
    Node *node=new Node(x);
    if(!root) return node;
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node *tmp=q.front();
        q.pop();
        if(tmp->left) q.push(tmp->left);
        else {tmp->left=node; return root;}
        if(tmp->right) q.push(tmp->right);
        else {tmp->right=node;return root;}
    }
}

Node* insert_arr(int arr[],Node* root, int i, int n)
{
    if(i<n)
    {
        Node *tmp=new Node(arr[i]);
        root=tmp;
        root->left=insert_arr(arr,root->left,2*i+1,n);
        root->right=insert_arr(arr,root->right,2*i+2,n);
    }
    return root;
}

void inorder(Node *root)
{
    if(!root) return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

void preorder(Node *root)
{
    if(!root) return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)
{
    if(!root) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<" ";
}

void deleteDeep(Node *root, Node *dnode)
{
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node *tmp=q.front();
        q.pop();
        if(tmp==dnode){tmp=NULL;free(dnode); return;}
        if(tmp->right && tmp->right==dnode){tmp->right=NULL;free(dnode);return;}
        else if(tmp->right) q.push(tmp->right);
        if(tmp->left && tmp->left==dnode){tmp->left=NULL;free(dnode);return;}
        else if(tmp->left) q.push(tmp->left);
    }
}

Node* deleteNode(Node *root,int x)
{
    if(!root) return NULL;
    if(!root->left && !root->right) return root->val==x?NULL:root;
    queue<Node*> q;
    q.push(root);
    Node *tmp=NULL,*dnode=NULL;
    while(!q.empty())
    {
        tmp=q.front();
        q.pop();
        if(tmp->val==x) dnode=tmp;
        if(tmp->left) q.push(tmp->left);
        if(tmp->right) q.push(tmp->right);
    }
    if(dnode)
    {
        x=tmp->val;
        deleteDeep(root,tmp);
        dnode->val=x;
    } 
    return root;
}

int main()
{
    Node *root=NULL;
    root=insert(root,1);
    root=insert(root,2);
    root=insert(root,3);
    root=insert(root,4);
    root=insert(root,5);
    root=insert(root,6);
    inorder(root);
    cout<<endl;
    root=deleteNode(root,6);
    inorder(root);
    cout<<endl;
    int arr[]={12,14,15,11,63,16,13,30,69,50};
    root=insert_arr(arr,root,0,10);
    preorder(root);
    cout<<endl;
    root=deleteNode(root,11);
    preorder(root);
    return 0;
}