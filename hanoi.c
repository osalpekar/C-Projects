/*
* File: hanoi.c
* This program gives the steps for the Towers of Hanoi problem.
*/

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <strlib.h>
#define size 100

void Hanoi(int num, char source, char destination, char help);

main()
{
      int num;
      
      printf("Please enter the number of disks ");
      num=GetInteger();
      Hanoi(num,'A','B','C');
      getchar();
}

void Hanoi(int num, char source, char destination, char help)
{
     if (num==1){
          printf("Move top disk from %c to %c\n", source, destination);
     } else {
          Hanoi(num-1,source,help,destination); 
          printf("Move top disk from %c to %c\n", source, destination);
          Hanoi(num-1,help,destination,source); 
     }
}
