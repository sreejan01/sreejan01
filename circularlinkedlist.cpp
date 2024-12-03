#include <iostream>

using namespace std;
struct node
{
 int data;
 node *next;

}*start,*nn,*temp,*last,*loc;

void insert1(int v)
{
nn= new node;
nn->data=v;
if(start==NULL)
{
 start=nn;
 nn->next=nn;
 last=start;
}
else
{
 last->next=nn;
 nn->next=start;
 last=nn;

}

}

void traverse()
{
 temp=start;
 do
 {
 cout<<temp<<" \t" <<temp->data<<"\t "<<temp->next<<endl;
 temp=temp->next;

 }while(temp!=start);


}

void deletion(int v)
{
 temp=start;
 do
 {
 if(start->data==v)
 {
 loc=start;
 start=start->next;
 last->next=start;
 delete(loc);
 }
 else if(last->data==v)
 {
 while(temp->next->next!=start)
 {
 temp=temp->next;
 }
 loc=last;
 temp->next=last->next;
 last=temp;
 delete(loc);




 }

 else if (temp->next->data==v)
 {
 loc=temp->next;
 temp->next=loc->next;
 cout<<loc<<"\t is deleted \n ";
 delete(loc);
 break;

}
else
{
 cout<<"\n Element does not exixts";
}
temp=temp->next;

 }while(temp!=start);



}


int main()
{
 insert1(10);
 insert1(20);
 insert1(30);
 insert1(40);
 traverse();

 cout<<"\n Deletion \n";
 deletion(10);
 traverse();

return 0;
}
