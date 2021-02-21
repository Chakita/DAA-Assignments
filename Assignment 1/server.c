#include "proto.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void make_array(int array_size,int a[])
{
   int i;
   for(i=0;i<array_size;i++)
   {
     a[i]=rand();
   }
}

long int sel_sort(int size,int a[])
{   
    long int comparisons=0;
    
    for(int i=0;i<size-1;i++)
    {
       int mp=i;
       for(int j = mp+2;j<size;j++)
        {   comparisons++;
           if(a[j]<a[mp])
           mp=j;
          
          }
       if(mp!=i)
       {
         int temp = a[mp];
           a[mp] = a[i];
           a[i]=temp;
       }
    
    }
   return comparisons;
  }
      
  
  long int qs(int n,int a[],int low,int high)
  {  	static long int comparisions=0;
     int j;
     if(low<high)
     {
       j=partition(n,a,low,high,&comparisions);
       qs(n,a,low,j-1);
       qs(n,a,j+1,high);
       
     } 
     
     return comparisions;
  
  }
  
  int partition(int n,int a[],int low,int high,long int *c)
  {
     int pivot=a[low];
     int i=low+1;
     int j=high;int temp;
     while(i<=j)
     { 
       if(i>high && a[i]>pivot)
       	(*c)++;
       if(j<low && a[j]<pivot)
       	(*c)++;
        while(i<=high && a[i]<=pivot) 
        {
        
         i++;
         (*c)++;
         
         }

        while(j>low && a[j]>=pivot)
        {
        j--;
        (*c)++;
        }
        if(i<j)
        {
          temp=a[i];
          a[i]=a[j];
          a[j]=temp;
      }
    }
        if(j!=low)
       {
          a[low]=a[j];
          a[j]=pivot;
         }
   return j;      
  
  } 
  long int quick_sort(int size,int a[size])
  {
      long int c = qs(size,a,0,size-1);
      return c;
  
  }    
  
 long int merge_sort(int size,int a[size])
 {
   long int c=msort(size,a,0,size-1);
   return c;
 } 
 
 long int msort(int n,int a[n], int low, int high)
{
   static long int comparisons=0;    
   if(low<high)
   {
      int mid = (low+high)/2;
      msort(n,a,low,mid);
      msort(n,a,mid+1,high);
      merge(n,a,low,mid,high,&comparisons);    
      
   }
   return comparisons;

}

void merge(int n,int a[n],int low,int mid,int high,long int *c)
{

     int i=low;
     int j= mid+1;
     int k=0;
     int b[n];
     while(i<=mid && j<=high)
     {   (*c)++;
        if(a[i]<a[j])
        { 
          b[k++] = a[i];
          i++;
         }
        else
        {
          b[k++]=a[j];
          j++;
        
        }     
     
     }
  
   while(i<=mid)
   {
     b[k++] =a[i];
     i++; 
   }

 while(j<=high)
 {
 
   b[k++]=a[j];
   j++;
 }
 int l=low;
 for(i=0;i<k;i++)
 {
   a[l++]=b[i];
 
 }


}


long int bubble_sort(int n, int a[])
{
  long int comparisons=0;
  int temp;
  for(int i=0;i<=n-2;i++)
  {
     for(int j=0;j<n-1-i;j++)
     {  
        comparisons++;
        if(a[j]>a[j+1])
        {
          temp=a[j];
          a[j]=a[j+1];
          a[j+1]=a[j];
        }
        
     }
  }
  return comparisons;

}









  
