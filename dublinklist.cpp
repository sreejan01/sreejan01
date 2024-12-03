#include <iostream>

using namespace std;
int f=0;
struct node
{
 int data;
 node *prev,*next;

}*start,*tail,*nn,*temp,*loc;
void insert_beg(int v)
{ nn=new node;
 nn->data=v;
 nn->prev=NULL;
 if(start==NULL)
 {
 nn->next=NULL;
 start=nn;
 tail=nn;
 }
 else
 {
 nn->next=start;
 start->prev=nn;
 start=nn;
 }
}

void insert_end(int v)
{
 nn = new node;
 nn->data=v;
 nn->next=NULL;
 if(start==NULL)
 {
 start=nn;
 tail=nn;
 nn->prev=NULL;

 }

 else
 {
 tail->next=nn;
 nn->prev=tail;
 tail=nn;


 }


}

void insert_after(int v,int a)
{
 nn = new node;
 nn->data=v;
 if(start==NULL)
 {
 cout<<"No element";
 }
 else if(tail->data==a)
 {

 tail->next=nn;
 nn->prev=tail;
 tail=nn;
 }

 else
 {
 temp=start;
 while(temp!=NULL)
 {
 if(temp->data==a)
 {

 nn->next=temp->next;
 nn->prev=temp;
 temp->next->prev=nn;
 temp->next=nn;
 f++;

 }


 temp=temp->next;

 }



 }

 if(f>0)
 {

 }
 else
 {
 cout<<"\n not exits \n";
 }




}


void traverse()
{
 temp=start;
 while(temp!=NULL)
 {

 cout<<temp->data<<"\t";
 temp=temp->next;
 }
}

void delbeg()
{
 if(start==NULL)
 {
 cout<<"Nothing in list";
 }
 else
 {

 loc=start;
 start=start->next;
 start->prev=NULL;
 delete(loc);
 }

}


void delend()
{
 if(start==NULL)
 {
 cout<<"Nothing in list";
 }
 else
 {

 loc=tail;
 tail=tail->prev;
 tail->next=NULL;
 delete(loc);
 }

}


void deletion_ele(int p)
{

 temp=start;
 while(temp!=NULL)
 {
 if(temp->data==p && temp==start)
 {
 loc=start;
 start=start->next;
 start->prev=NULL;
 delete(loc);
 }
 else if(temp->data==p && temp==tail)
 {
 loc=tail;
 tail=tail->prev;
 tail->next=NULL;
 delete(loc);
 }
 else if(temp->data==p)
 {
 loc=temp;
 temp->next->prev=temp->prev;
 temp->prev->next=temp->next;
 delete loc;
 }
 temp=temp->next;

 }


}

void searching(int s)
{
 int f=0;
 temp=start;
 while(temp!=NULL)
 {
 if(temp->data==s)
 {

 f++;
 break;
 }
 temp=temp->next;
 }

 if(f>0)
 {
 cout<<"\n"<<s<<"\t element found";
 }
 else
 {
 cout<<"\n"<<s<<"\t Not found";
 }
}

int main()
{
 cout<<"\n Insertion at beg \n";
 insert_beg(40);
 insert_beg(30);
 insert_beg(20);
 insert_beg(10);
 cout<<endl;
 traverse();
 cout<<"\n Insertion at end \n";
 cout<<endl;
 insert_end(50);
 insert_end(60);
 traverse();
 cout<<"\n Insertion after \n";
 cout<<endl;
 insert_after(40,80);
 traverse();
 cout<<"\n Deletion beg \n";
 cout<<endl;
 delbeg();
 traverse();
 cout<<"\n Deletion end \n";
 cout<<endl;
 delend();
 traverse();
 cout<<"\n Deletion of specific element \n";
 cout<<endl;

 deletion_ele(30);
 traverse();

 searching(100);

  return 0;
}
