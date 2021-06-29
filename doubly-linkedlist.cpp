#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node *next, *prev;
    Node(int x):val(x),next(NULL),prev(NULL){}
};

Node* insert_beg(Node *head,int x)
{
    Node *node=new Node(x);
    if(head==NULL) return node;
    else{node->next=head;head->prev=node;head=node;}
    return head;
}

Node* insert_end(Node *head,int x)
{
    Node *node=new Node(x);
    if(!head)return node;
    if(!head->next){head->next=node;node->prev=head;return head;}
    Node *tmp=head;
    while(tmp->next){tmp=tmp->next;}
    tmp->next=node;
    node->prev=tmp;
    return head;
}

Node* delete_beg(Node* head)
{
    if(!head){cout<<"list is empty";return NULL;}
    if(!head){free(head); return NULL;}
    Node* tmp=head;
    head=head->next;
    free(tmp);
    return head;
}

Node* delete_end(Node* head)
{
    if(!head){cout<<"list is empty";return NULL;}
    if(!head){free(head); return NULL;}
    Node* tmp=head,*prev=NULL;
    while(tmp->next){ prev=tmp;tmp=tmp->next;}
    prev->next=NULL;
    free(tmp);
    return head;
}

void print(Node *head)
{
    if(!head) {cout<<"List is empty.\n";return;}
    Node *tmp=head;
    while(tmp)
    {
        cout<<tmp->val<<" ";
        tmp=tmp->next;
    }
    cout<<endl;
}

int main()
{
    Node *head=new Node(1);
    head=insert_beg(head,25);
    head=insert_beg(head,36);
    print(head);
    head=insert_beg(head,85);
    print(head);
    head=insert_end(head,50);
    head=insert_end(head,63);
    print(head);
    head=delete_beg(head);
    print(head);
    head=delete_end(head);
    print(head);
    return 0;
}