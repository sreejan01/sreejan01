#include<iostream>
using namespace std;
struct node
{
int data;
node* next;
}*head=nullptr, * temp,*current;

 void traverse()
{
 temp=head;
 while(temp!=NULL)
 {
 cout<<temp<<"\t"<<temp->data<<"\t"<<temp->next<<endl;
 temp=temp->next;
 }
}
void insert_end(int x)
{
 node*nn=new node;
 nn->data=x;
 nn->next=NULL;
 if(head==NULL)
 {
 head=nn;
 }
 else
 {
 temp=head;
 while(temp->next!=NULL)
 {
 temp=temp->next;
 }
 temp->next=nn;
 }
}
void del_beg()
{
 if(head==NULL)
 {
 cout<<"Linked list is empty";
 }
 else
 {
 temp=head;
 head=head->next;
 delete temp;
 }
}
int main(){
    int n,v;
    cin>>n;
    for (int i=0 ;i<n;i++){
    cin>>v;
    insert_end(v);;
    }
    traverse();
    del_beg();
    traverse();
    
    return 0;
}