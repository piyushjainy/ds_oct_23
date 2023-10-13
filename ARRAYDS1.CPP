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
  cout<<"\n12. Remove Duplicates ";
  cout<<"\n13. Move even and odd in different sides of array";
  cout<<"\n14. Rotate Clock wise one time ";
 cout<<"\n15. Rotate Clock wise n times ";
cout<<"\n16. Display all leaders in our array";
cout<<"\n17. Maximum Difference in forward direction";
cout<<"\n18. Display Frequency of element in sorted array";
cout<<"\n19. Display Frequency of element in unsorted array";


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
  void reverseArray(int t[],int s,int d)  // 1    4
  {
    int temp;  //10  20  30  40  50
    for(int i=0;i<(d-s+1)/2;i++)
    {
      temp=t[s+i];
      t[s+i]=t[d-i];
      t[d-i]=temp;
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
  void removeDuplicateSorted(int t[],int &c)
  {

      int i,j=0;

      for(i=0;i<=c-1;i++)
      {
          if(t[i]!=t[i+1])
          {
              t[j++]=t[i];

          }

      }
      t[j]=t[i];

      c=j;
  }

  void evenoddmove(int t[],int c)
  {
       int i,j,temp;
       i=0;
       j=c;

       while(i<j)
       {
            while(t[i]%2==0)
                     i++;

            while(t[j]%2==1)
                     j--;

            if(i<j)
            {


            temp=t[i];
            t[i]=t[j];
            t[j]=temp;
            }

            i++;
            j--;
        }

  }
void rotateRightOne(int t[],int c)
{

    int temp=t[c];
    for(int i=c-1;i>=0;i--)
    {
        t[i+1]=t[i];
    }
    t[0]=temp;
}
void rotateRightMultiple(int t[],int c)
{
    int k;
    cout<<"Enter no of rotation:";
    cin>>k;
    k=k%(c+1);


  reverseArray(t,0,c-k);
  reverseArray(t,c-k+1,c);
  reverseArray(t,0,c);



}
void displayLeaders(int t[],int c)
{
  int i,max=t[c];

    cout<<max<<"  ";
  for(i=c-1;i>=0;i--)
  {
      if(t[i] > max)
      {
          max=t[i];
          cout<<max<<"  ";

      }

  }

}
int maxDifference(int t[],int c)
{
   int i,j,mx,mn;

   mx=t[1]-t[0];
   mn=INT_MAX;

   for(i=0;i<=c;i++)
   {
         if((t[i]-mn)>mx)
             mx=t[i]-mn;

        if(mn>t[i])
            mn=t[i];

   }
   return(mx);

}
void displayFrequencySort(int t[],int c)
{
    //10,10,10,20,30,30,30,40,40,

   int cnt=1,i,j;
   for(i=1;i<=c;i++)
   {
       if(t[i]==t[i-1])
       {
           cnt++;
       }
       else
       {
           cout<<t[i-1]<<"---"<<cnt<<"\n";
           cnt=1;
       }

   }

  cout<<t[c]<<"----"<<cnt;
}

void displayFrequencyUnsort(int t[],int c)
{

}

int main()

{
   int ch,pos,n;
   const int size=10;
   int arr[size]={10,10,10,20,30,30,30,40,40,50};
   int cur=9;


   //reverseArray(arr,1,3);
   //displayAll(arr,cur);

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
		reverseArray(arr,0,cur);
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
               break;
      case 12:
               removeDuplicateSorted(arr,cur);
               break;
      case 13:
               evenoddmove(arr,cur);
               break;
      case 14:
                rotateRightOne(arr,cur);
                displayAll(arr,cur);

                break;
      case 15:
              rotateRightMultiple(arr,cur);
              displayAll(arr,cur);
              break;
      case 16:
                displayLeaders(arr,cur);
                break;
      case 17:
                n= maxDifference(arr,cur);
                cout<<"\nMaximum differnce is "<<n;
                break;
      case 18:
              displayFrequencySort(arr,cur);
              break;
      case 19:
              displayFrequencyUnsort(arr,cur);
              break;

	 default:
	     cout<<"\nInvalid Choice";

      }


   }
   getch();
   return(0);
}
