/*
* File: fillPerimeter.c
* This program fills the area of a shape based on a given point.
*/

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <strlib.h>
#define size 100

int inpShape(char inpArray[][size]);
void printShape(char inpArray[][size]);
void fill(char inpArray[][size], int i, int j, bool start, int x);
void prompt(char inpArray[][size], int x);

main()
{
      int x;
      char inpArray[size][size];
      
      x=inpShape(inpArray);
      prompt(inpArray,x);
      printShape(inpArray);
      getchar();
}

int inpShape(char inpArray[][size])
{
      char ch;
      int x=0,y=0;
      
      printf("Please enter the characters and press . when you are done.\n");
      while((ch=getchar())!='.')
      {
           inpArray[x][y]=ch;
           y++;
           if(ch=='\n'){
                x++;
                y=0;
           }
      }
      inpArray[x][y]=ch;
      return(x);
}

void prompt(char inpArray[][size], int x)
{
      int i,j;
      
      printf ("Which x coordinate do you want to start from? ");
      i=GetInteger();
      printf ("Which y coordinate do you want to start from? ");
      j=GetInteger();

      fill(inpArray,i,j,TRUE,x);
}

void printShape(char inpArray[][size])
{
      int i=0,j=0;
      
      while(inpArray[i][j]!='.')
      {
           putchar(inpArray[i][j]);
           if (inpArray[i][j]=='\n'){
                 i++;
                 j=0;
           }
           else 
                j++;
      }
}

void fill(char inpArray[][size], int i, int j, bool start, int x)
{
     /*printf("Fil called with i=%d, j=%d\n", i, j);*/
     if (i==x) {
          return;
     }
     while (start==FALSE){
           if (inpArray[i][j]=='*'){
                break;
           } else {
                j++;
           }
     }
     while (inpArray[i][j]!='\n') 
     {
           if ((inpArray[i][j]==' ')&&(start==TRUE)) {
               inpArray[i][j] = '*';
           }
           else if (inpArray[i][j] == '*') {
                start=!start;
           }
           j++;
     }
     i++;
     j=0;
     start=FALSE;
     fill(inpArray,i,j,start,x);
}
