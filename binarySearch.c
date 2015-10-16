/*
* File: binarySearch.c
* This program searches for a value in an array of integers.
*/

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <strlib.h>
#define size 100

int initArray(int intArray[]);
void bubbleSort(int intArray[], int count);
int Swap (int intArray[], int i, int j);
int Prompt(void);
int binarySearch(int value, int intArray[], int count);
int display(int index, int value);

main()
{
      int intArray[size];
      int i,count,value,index;
      
      count=initArray(intArray);
      bubbleSort(intArray,count);
      value=Prompt();
      index=binarySearch(value,intArray,count);
      display(index,value);
      getchar();
}

/* This function initializes the arrays */
int initArray(int intArray[])
{
     int i,j;
     
     printf("Please enter integers and type 0 to signal end\n");
     for(i=0;i<size;i++)
     { 
          j=GetInteger();
          if (j==0)
          {
               break;
          } else {
               intArray[i]=j;
          }     
     }
     return i;
}

/* This function determines whether a swap is needed throughout the passes */
void bubbleSort(int intArray[], int count)
{
     int i,j,k,swapnum,passnum;
     
     swapnum=1;
     passnum=0;
     while(swapnum!=0)
     {
          swapnum=0;
          for (i=0;i<count-passnum-1;i++)
          {
              j=i+1;
              if (intArray[i]>intArray[j])
              {
                   Swap(intArray,i,j);
                   swapnum++;
              }
          }
          passnum++;
     }
}
/* This function swaps two arguments given to it */
int Swap (int intArray[], int i, int j)
{
    int k;
    
    k=intArray[i];
    intArray[i]=intArray[j];
    intArray[j]=k;
}

/* This function asks the user which value to look for */
int Prompt(void)
{
    int value;
    
    printf("Please enter the value you want to search for in the array ");
    value=GetInteger();
    return(value);
}

/* This function searches for the value in the array */
int binarySearch(int value, int intArray[], int count)
{
    int low,high,mid;
    
    low=0;
    high=count-1;
    while(low<=high)
    {
         mid=(low+high)/2;
         if (value<intArray[mid]) {
              high=mid-1;
         } else { 
              if (value>intArray[mid]) {
                   low=mid+1;
              } else {
                   return(mid);
              }
         }    
    }
    return(-1);
}

/* This function displays the index of the found value */
int display(int index, int value)
{
    if (index==-1) {
         printf("The value %d was not found.\n", value);
    } else {
         printf("The value %d was found.\n", value);
    }
}
