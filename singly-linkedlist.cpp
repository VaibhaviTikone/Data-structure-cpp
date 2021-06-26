#include<bits/stdc++.h>
using namespace std;
struct node
{
    int val;
    node *next;
    node(int c):val(c),next(nullptr){};
};

node* insert_end(node* head, int val)
{
    node *t= new node(val);
    if(head==nullptr){return t;}
    node *tmp = head;
    while(tmp->next) tmp=tmp->next;
    tmp->next=t;
    return head;
}

node* insert_n(node *head, int val, int id)
{
    node *nd=new node(val);
    if(!head) return nd;
    node *tmp=head;id--;
    while(tmp && --id)
        tmp=tmp->next;
    if(id>0){cout<<"Enter valid position.";return head;}
    node *dummy=tmp->next;
    tmp->next=nd;
    nd->next=dummy;
    return head; 
}

node* insert_beg(node* head, int val)
{
    node *t = new node(val);
    t->next=head;
    return t;
}

node* delete_beg(node* head)
{
    if(!head || !head->next) return NULL;
    node *t= head;
    head=head->next;
    free(t);
    return head;
}

node* delete_end(node *head)
{
    if(!head || !head->next) return NULL;
    if(!head->next->next){head->next=NULL;return head;}
    node* t=head;
    while(t->next->next)
        t=t->next;
    node *n=t->next;
    t->next=NULL;
    free(n);
    return head;
}

node* delete_n(node *head, int id)
{
    if(!head) return NULL;
    if(id==1) {node *t=head; head=head->next; free(t); return head;}
    id--;
    node *t=head;
    while(t && --id)
        t=t->next;
    if(id>0){cout<<"Enter valid position:\n";return head;}
    node *dummy =  t->next;
    t->next=dummy->next;
    free(dummy);
    return head;
}

void print(node *head)
{
    if(head==NULL) cout<<"List is empty";
    else{
        node *t=head;
        while(t)
        {
            cout<<t->val<<" ";
            t=t->next;
        }
        cout<<endl;
    }
}

void print_reverse(node *head)
{
    if(!head) return;
    print_reverse(head->next);
    cout<<head->val<<" ";
}

void search(node *head,int x)
{
    if(!head) cout<<"list is empty.\n";
    else{
        node *t=head;
        while(t)
        {
            if(t->val==x) {cout<<x<<" found.\n";break;}
            t=t->next;
        }
        if(!t) cout<<x<<" not found.\n";
    }
}

int main()
{
    node *head= nullptr;
    int n,x;
    cout<<"Enter total number of elements to be inserted: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        head= insert_end(head,x);
    }
    print(head);
    // cout<<"Enter value to be searched: ";
    // cin>>x;
    // search(head, x);
    head= delete_beg(head);
    print(head);
    head=insert_n(head,7,3);
    cout<<"after inserting at 3rd position: \n";
    print(head);
    head=delete_end(head);
    print(head);
    head=delete_n(head,4);
    print(head);
    print_reverse(head);
    return 0;
}