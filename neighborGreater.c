/*
* File: neighborGreater.c
* This program checks whether an element in a multidimensional array is greater than its neighbors or not
*/

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#define size 5

void getArray(int numbers[size][size]);
void displayArray(int numbers[size][size]);
int checkGreater (int m,int n,int numbers[size][size]);

main()
{
      int numbers [size][size]=
      {
          {-1000,-1000,-1000,-1000,-1000},
          {-1000,1,1,1,-1000},
          {-1000,1,1,1,-1000},
          {-1000,1,1,1,-1000},
          {-1000,-1000,-1000,-1000,-1000}
      };
      getArray(numbers);
      displayArray(numbers);
      getchar();
}

/* This function reads the user inputs into the array*/
void getArray(int numbers[size][size])
{
      int i,j;
      
      printf("Please enter numbers greater than -1000.\n");
      for (i=1;i<=3;i++)
      for (j=1;j<=3;j++)
      {
          numbers[i][j]=GetInteger();
      }
}

/* This function displays the elements and location that are greater than its neighbors*/ 
void displayArray(int numbers[size][size])
{
     int m,n;
     bool flag;
     
     for (m=1;m<=size-2;m++)
     {
         for (n=1;n<=size-2;n++)
         {
              flag=checkGreater(m,n,numbers);
              if (flag)
                   printf("%d at location (%d,%d)\n", numbers[m][n], m-1, n-1);
         }
     }
}

/* This function checks if any given value is greater than all of its neighbors*/
int checkGreater(int m, int n, int numbers[size][size])
{
     int i,j;
     bool flag;
     
     for (i=m-1;i<=m+1;i++)
     {
          for (j=n-1;j<=n+1;j++)
          {
              if (numbers[m][n] >= numbers[i][j]) {
                   flag=TRUE;
              } else {
                   flag=FALSE;
                   return(flag);
              }
          }
     }
     return(flag);
}
