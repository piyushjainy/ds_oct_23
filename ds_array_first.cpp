#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
void menu()
{
  cout<<"\n1. Add element ";
  cout<<"\n2. Delete element by position";
  cout<<"\n3. Delete element by value";
  cout<<"\n4. Display all elements";
  cout<<"\n5. Search any element:";
  cout<<"\n6. Insert any element at particular position";
  cout<<"\n7. Reverse the array";
  cout<<"\n8. highest value in array";
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
     int n,pos;
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
	for(int j=c;j>=pos;j--)
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
void reverse(int t[],int c)
{
	int temp;
	for(int i = 0; i<c/2;i++)
	{
	   temp = t[i];
	   t[i]= t[c-i];
	   t[c-i]= temp;}

	}

 void greatest(int t[], int c)
 {
      int max=t[0];

	for(int i=1;i<=c;i++ )
	{
	    if (t[i]>max)
	    max=i;

	}
    cout<<"\ngreatest value is: "   <<t[max]<<" at position  "<<max+1;
 }

void main()

{
   int ch,pos,n;
   const int size=5;
   int arr[size]={10,20,30,40};
   int cur=3;
   clrscr();
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
	 case 7 :
		reverse(arr,cur);
		break;
	 case 8:
		greatest(arr,cur);
		break;
	 default:
	     cout<<"\nInvalid Choice";

      }


   }
   getch();
}
