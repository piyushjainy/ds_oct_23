#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
void menu()
{
  cout<<"\n1. Add element ";
  cout<<"\n2. Delete element by position";
  cout<<"\n3. Delete element by value";
  cout<<"\n4. Display all elements";
  cout<<"\n5. Search any element:";
  cout<<"\n6. Insert any element at particular position";
  cout<<"\n7. Get Highest value in array.";
  cout<<"\n8. Reverse Array";
  cout<<"\n10. Get Second Maximum Value";
  cout<<"\n11. Check Sorted or not ";

  cout<<"\n9. Exit";
}
void addElement(int t[],int s,int &c)
{
   if(c==s-1)
     cout<<"\nArray is already full";
   else
     {
       cout<<"\nEnter any value:";
      // c=c+1;
      // cin>>t[c];
	cin>>t[++c];
     }


}
void deleteByPosition(int t[],int &c)
{
  if(c==-1)
    cout<<"\nArray is empty";
  else
  {
     int p;
     cout<<"\nEnter position to be delete:";
     cin>>p;
     p--;
      if(p<0 || p>c)
	cout<<"\nInvalid position has been given";
      else
	{
	   cout<<"\n"<<t[p]<<" has been deleted!!!!!!!!!!";
	    for(int i=p;i<=c-1;i++)
	     {
		t[i]=t[i+1];
	     }
	     c--;
	}
  }

}
void displayAll(int t[],int c)
{
   cout<<"\n";
   for(int i=0;i<=c;i++)
   {
      cout<<t[i]<<"   ";
   }

}
int searchValue(int t[],int c,int x)
{
  for(int i=0;i<=c;i++)
  {
    if(t[i]==x)
      return(i);
  }

   return(-1);

}
void deleteByValue(int t[],int &c)
{
    int x,in;
    cout<<"\nEnter any value:";
    cin>>x;
    in=searchValue(t,c,x);
    if(in==-1)
      cout<<"\nElement is not present for delete";
    else
      {
	cout<<"\n"<<x<<" has been deleted";
	for(int j=in;j<=c-1;j++)
	{
	   t[j]=t[j+1];
	}
	c--;
      }
}
  void insertValue(int t[],int &c)
  {
     int n,pos,j;
     if(c==4)
     {
	cout<<"\nArray is full";
	return;
     }
     cout<<"\nEnter any position";
     cin>>pos;
     if(pos>=1 && pos<=c+2)
     {
	cout<<"\nEnter new value to insert at "<<pos<<" location:";
	cin>>n;
	pos--;
	for(j=c;j>=pos;j--)
	{
	   t[j+1]=t[j];
	}
	t[j+1]=n;
	c++;

     }
     else
     {
       cout<<"\nInvalid position";
     }
  }
  int highestValue(int t[],int c)
  {
    int mp=0;
    for(int i=1;i<=c;i++)
    {
       if(t[i]>t[mp])
       {
	 mp=i;
       }
    }
    return(mp);

  }
  void reverseArray(int t[],int c)
  {
    int temp;
    for(int i=0;i<c/2;i++)
    {
      temp=t[i];
      t[i]=t[c-i];
      t[c-i]=temp;
    }

  }
  int secondMax(int t[],int c)   // "10,70,30,40,70,30,70"
  {
     int fmp=0;
     int smp=-1;

     for(int i=1;i<=c;i++)
     {
         if(t[i]>t[fmp])
         {
             smp=fmp;
             fmp=i;
         }
         else if(t[i]<t[fmp])
         {
             if(i!=smp && t[i] > t[smp])
                smp=i;
         }

     }
     return(smp);
  }

  int isSorted(int t[],int c)
  {
      for(int i=1;i<=c;i++)
      {
          if(t[i]<t[i-1])
            return(0);
      }
      return(1);
  }
int main()

{
   int ch,pos,n;
   const int size=10;
   int arr[size]={10,22,34,44,25,67,77};
   int cur=6;

   while(1)
   {
      menu();
      cout<<"\nEnter your choice:";
      cin>>ch;
      if(ch==9)
	exit(0);
      switch(ch)
      {
	 case 1:
	     addElement(arr,size,cur);
	    break;
	 case 2:
	      deleteByPosition(arr,cur);
	      break;
	 case 3:
	      deleteByValue(arr,cur);
	      break;
	 case 4:
	       displayAll(arr,cur);
	       break;
	 case 5:
		cout<<"\nEnter any value:";
		cin>>n;
		pos=searchValue(arr,cur,n);
		if(pos==-1)
		 cout<<"\nElement Not Present";
		else
		 cout<<"\nFound at "<<pos+1;
		break;
	 case 6:
	       insertValue(arr,cur);
	       break;
	 case 7:
		  pos=highestValue(arr,cur);
		  cout<<"\n Highest element "<<arr[pos]<<" at "<<pos+1<<" location";
		  break;
	 case 8:
		reverseArray(arr,cur);
		break;
     case 10:
            pos=secondMax(arr,cur);
            if(pos==-1)
                cout<<"\nNot having second highest element";
            else
                 cout<<"\n Second highest value is "<<arr[pos]<<" at "<<pos<<" location";
             break;
      case 11:
              n=isSorted(arr,cur);
              if(n==1)
                cout<<"\nGiven array is in sorted order";
              else
                 cout<<"\nGiven array is unsorted";

	 default:
	     cout<<"\nInvalid Choice";

      }


   }
   getch();
   return(0);
}
