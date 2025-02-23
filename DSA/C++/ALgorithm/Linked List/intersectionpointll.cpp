#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;
    node(int value){
    data =value;
    next=NULL;
    prev=NULL;
    }
};

void insertAtTail(node* &head, int value){

 node* n=new node(value);
    if(head==NULL){
        head=n;
        return;
    }
   
    node* temp=head;
    while (temp->next!=NULL){
        temp=temp->next;
    }

   temp->next=n;
    n->prev=temp;
}

int length(node* &head){
    int l=0;
    node* temp =head;
    while(temp!=NULL){
        temp=temp->next;
        l++;
        
    }
    return l;
}

int intersection(node* &head1, node* &head2){
    int l1=length(head1);
    int l2=length(head2);
    int d=0;
    node* ptr1;
    node* ptr2;
    if(l1>l2){
        d=l1-l2;
        ptr1=head1;
        ptr2=head2;
    }
    else{
        d=l2-l1;
        ptr1=head2;
        ptr2=head1;
    }
    while (d)
    {
        /* code */
        ptr1=ptr1->next;
        if(ptr1==NULL){
            return -1;
        }
        d--;
    }
    while (ptr1!=NULL && ptr2!=NULL)
    {
        /* code */
        if(ptr1==ptr2){
            return ptr1->data;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;

    }
    return -1;
    
}

void intersect(node* &head1,node* &head2, int pos){
    node* temp1=head1;
    pos--;
    while(pos--){
        temp1=temp1->next;
    }
    node* temp2=head2;
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    temp2->next=temp1;
}

void display(node* head){

     node* temp =head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
   cout<<endl;
}

int main(){
    node* head1=NULL;
    node* head2=NULL;
insertAtTail(head1,1);
insertAtTail(head1,2);
insertAtTail(head1,3);
insertAtTail(head1,4);
insertAtTail(head1,6);
insertAtTail(head1,7);
insertAtTail(head2,8);
insertAtTail(head2,9);
intersect(head1,head2,3);
display(head1);
display(head2);
cout<<intersection(head1,head2);
}