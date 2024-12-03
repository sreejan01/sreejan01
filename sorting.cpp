
#include <iostream>
using namespace std;
#define max 100

int binary_sea(int *arr,int low,int high,int x)
{
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        
        if(arr[mid]==x)
        return mid;
        if(arr[mid]<x)
        low=mid+1;
       else
        high=mid-1;
    }
    return -1;
}

void selection_(int *arr,int n)
     {
  for(int i=0;i<n-1;i++)
  {  int pos=i;
  for(int j=i+1;j<n;j++)
  {if(arr[pos]>arr[j])
  {
      pos=j;
  }
  }
  
  if(pos!=i)
  {
      int temp = arr[pos];
      arr[pos]=arr[i];
      arr[i]=temp;
  }
}
for(int i = 0;i<n;i++)
{
cout<<arr[i];
cout<<endl;
}
      }
void insertion_(int *arr,int n)
      {
  for(int i=1;i<n;i++)
  {  int j=i;
  while(j>0&&arr[j]<arr[j-1])
  {
      int temp = arr[j];
      arr[j]=arr[j-1];
      arr[j-1]=temp;
      j--;
  }
}
for(int i = 0;i<n;i++)
{
cout<<arr[i];
cout<<endl;
}
      }
 void bubble_(int *arr,int n)
  {
  for(int i=0;i<n-1;i++)
  {
      for (int j =0;j<n-i-1;j++)
      {
      if(arr[j]>arr[j+1])
      {
       int temp = arr[j];
      arr[j]=arr[j+1];
      arr[j+1]=temp; 
      }
      }
  }
  
  
for(int i = 0;i<n;i++)
{
cout<<arr[i];
cout<<endl;
}
      }
int main()
{
    int arr[max], n,x;
    cout<<"enter the size of array : ";
    cin>>n;
    cout<<endl;
    cout<<"enter the array ";
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
        cout<<endl;
    }
    cout<<"sorting with selection : "<<endl;
selection_(arr,n);

cout<<"sorting with insertion : "<<endl;

insertion_(arr,n);
cout<<"sorting with bubble : "<<endl;
bubble_(arr,n);
 cout<<"enter the element to search : ";
 cin>>x;
int result=binary_sea(arr,0,n-1,x);
if (result==-1)
{
    cout<<"not present";
    
}
else
{
    cout<<"present "<<result;
}

return 0;
}