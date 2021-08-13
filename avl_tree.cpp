#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *left, *right;
    int height;
    Node(int x):val(x),left(NULL),right(NULL),height(0){}
};

int Height(Node* node)
{
    if(!node) return 0;
    return node->height;
}

int getBalance(Node* node)
{
    if(!node) return 0;
    return Height(node->left) - Height(node->right);
}

Node* LeftRotate(Node* x)
{
    cout<<"left rotation\n";
    Node* y=x->right;
    Node* lef=y->left;
    y->left=x;
    x->right=lef;
    y->height=max(Height(y->left),Height(y->right))+1;
    x->height=max(Height(x->left),Height(x->right))+1;
    return y;
}

Node* RightRotate(Node* x)
{
    cout<<"righ t rotation\n";
    Node* y=x->left;
    Node* lef=y->right;
    y->right=x;
    x->left=lef;
    y->height=max(Height(y->left),Height(y->right))+1;
    x->height=max(Height(x->left),Height(x->right))+1;
    return y;
}

Node* newNode(int key)
{
    Node* node=new Node(key);
    return node;
}

Node* minNode(Node* root)
{
    Node* cur=root;
    while(cur && cur->left)
        cur=cur->left;
    return cur;
}

Node* insert(Node* root,int key)
{
    if(!root) return newNode(key);
    if(key<root->val) root->left=insert(root->left,key);
    else if(key>root->val) root->right= insert(root->right,key);
    else return root;
    root->height= max(Height(root->left),Height(root->right))+1;
    
    int balance=getBalance(root);
    //LL rotation
    if(balance>1 && root->left->val > key) return RightRotate(root);
    //LR rotation
    if(balance>1 && root->left->val <   key)
    {
        root->left=LeftRotate(root->left);
        return RightRotate(root);
    }
    // RR rotation
    if(balance<-1 && root->right->val<key) return  LeftRotate(root);
    //RL rotation
    if(balance<-1 && root->right->val>key)
    {
        root->right= RightRotate(root->right);
        return LeftRotate(root);
    }
    return root;
}

Node* deleteNode(Node* root, int key)
{
    if(!root) return NULL;
    if(root->val<key) root->right=deleteNode(root->right,key);
    else if(root->val>key) root->left= deleteNode(root->left,key);
    else{
        if(!root->left || !root->right)
        {
            Node* tmp=root->left?root->left:root->right;
            if(!tmp) {tmp=root;root=NULL;}
            else {*root=*tmp; }
            free(tmp);
        }
        else
        {
            Node* tmp=minNode(root->right);
            root->val=tmp->val;
            root->right=deleteNode(root->right,tmp->val);
        }
    }
    if(!root) return root;
    root->height=max(Height(root->right), Height(root->left))+1;
    int balance= getBalance(root);
    if(balance>1 && getBalance(root->left)>=0) return RightRotate(root);
    //LR rotation
    if(balance>1 && getBalance(root->left)<0)
    {
        root->left=LeftRotate(root->left);
        return RightRotate(root);
    }
    // RR rotation
    if(balance<-1 && getBalance(root->right)<=0) return  LeftRotate(root);
    //RL rotation
    if(balance<-1 && getBalance(root->right)<0)
    {
        root->right= RightRotate(root->right);
        return LeftRotate(root);
    }
    return root;
}

void preorder(Node* root)
{
    if(!root) return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    Node* root= NULL;
    cout<<"insert 1\n";
    root= insert(root,1);
    cout<<"insert 2\n";
    root= insert(root,2);
    cout<<"insert 3\n";
    root= insert(root,3);
    cout<<"insert 4\n";
    root= insert(root,4);
    cout<<"insert 5\n";
    root= insert(root,5);
    cout<<"insert 6\n";
    root= insert(root,6);
    preorder(root);
    cout<<endl;
    root=deleteNode(root,5);
    preorder(root); 
    cout<<endl;
    root=deleteNode(root,6);
    preorder(root); 
    return 0;
}