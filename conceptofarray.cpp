#include<iostream>
using namespace std;
#define max 10
void traverse_(int*array,int m)
{
    for (int i = 0; i < m; i++)
    {
        cout<<array[i]<<",";
    }
    cout<< endl;
}
void insert_(int *array,int m)
{
  for( int i=0;i<m;i++)
{
    cout<<"Enter the rollno"<<i+1<<endl;
    cin>>array[i];
}
}
void delete_(int *array,int m,int value)
{
    if(value<0||value>=m)
    {
        cout<<"Invalid roll no"<<endl;
    }
    for(int i= value;i<m-1;i++)
     {
        array[i]=array[i+1];
     }
    m--;
}


int main(){
int array[max] ,m,value;
cout<<"Enter the size of the array"<<endl;
cin>>m;
insert_(array,m);
traverse_(array,m);
cout<<"enter the index of deleting roll no"<< endl;
cin>>value;

delete_(array,m,value);
cout<<"after deletion " ;
traverse_(array,m);

    return 0;
}
