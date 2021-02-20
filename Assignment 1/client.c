#include "proto.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main()
{

   long int sizes[19];
   long int s =100000;
for(int i=0;i<19;i++)
{
  sizes[i]=s;
  s=s+50000;

}
   int a[1000000];
   make_array(1000000,a);
   int choice=0;
   long int comp=0;
   clock_t start,end;
   float tt;
   printf("1.Selection sort\n2.Bubble sort\n3.Quick sort\n4.Merge Sort\n");
   scanf("%d",&choice);
   FILE *fptr1;
   FILE *fptr2;
   switch(choice)
   {
     case 1:
     fptr1 = fopen("selection_time.txt","w");
     fptr2 = fopen("selection_comp.txt","w");
     if (fptr1 == NULL) 
    { 
        printf("Could not open file1"); 
    } 
    if (fptr2 == NULL) 
    { 
        printf("Could not open file2"); 
    } 
     for(int i=0;i<19;i++)
     {
     start = clock();
     comp=sel_sort(sizes[i],a);
     end=clock();
     tt=(float)(end-start)/CLOCKS_PER_SEC;
     fprintf(fptr1,"%ld\t%f\n",sizes[i],tt);
     fprintf(fptr2,"%ld\t%ld\n",sizes[i],comp);
     fflush(fptr1);
     fflush(fptr2);
     printf("%ld\t%f\n",sizes[i],tt);
     printf("%ld\t%ld\n",sizes[i],comp);
    }
    
    fclose(fptr1);
    fclose(fptr2); 
     break;
     case 2:
     fptr1 = fopen("bubble_time.txt","w+");
     fptr2 = fopen("bubble_comp.txt","w+");
     for(int i=0;i<19;i++)
     {
     start = clock();
     comp=bubble_sort(sizes[i],a);
     end=clock();
     tt=(float)(end-start)/CLOCKS_PER_SEC;
     fprintf(fptr1,"%ld\t%f\n",sizes[i],tt);
     fprintf(fptr2,"%ld\t%ld\n",sizes[i],comp);
     fflush(fptr1);
     fflush(fptr2);
     printf("%ld\t%f\n",sizes[i],tt);
     printf("%ld\t%ld\n",sizes[i],comp); 
    } 
    fclose(fptr1);
    fclose(fptr2); 
     break;
     case 3:
     fptr1 = fopen("quick_time.txt","w+");
     fptr2 = fopen("quick_comp.txt","w+");
     for(int i=0;i<19;i++)
     {
     start = clock();
     comp=quick_sort(sizes[i],a);
     end=clock();
     tt=(float)(end-start)/CLOCKS_PER_SEC;
     fprintf(fptr1,"%ld\t%f\n",sizes[i],tt);
     fprintf(fptr2,"%ld\t%ld\n",sizes[i],comp);
     fflush(fptr1);
     fflush(fptr2);
     printf("%ld\t%f\n",sizes[i],tt);
     printf("%ld\t%ld\n",sizes[i],comp); 
    } 
    fclose(fptr1);
    fclose(fptr2); 
     break;
     case 4:
     fptr1 = fopen("merge_time.txt","w+");
     fptr2 = fopen("merge_comp.txt","w+");
     for(int i=0;i<19;i++)
     {
     start = clock();
     comp=merge_sort(sizes[i],a);
     end=clock();
     tt=(float)(end-start)/CLOCKS_PER_SEC;
     fprintf(fptr1,"%ld\t%f\n",sizes[i],tt);
     fprintf(fptr2,"%ld\t%ld\n",sizes[i],comp);
     fflush(fptr1);
     fflush(fptr2);
     printf("%ld\t%f\n",sizes[i],tt);
     printf("%ld\t%ld\n",sizes[i],comp); 
    } 
    fclose(fptr1);
    fclose(fptr2); 
     break;
     
     default:
     break;
   
   } 
}

