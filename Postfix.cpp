/*
* File: Final Postfix.c
* This Project Computes Postfix Expressions.
*/

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <strlib.h>
#define maxStack 100

int Push(char stack[], int top, int val);
int Pop(char stack[], int top, int val[]);
int getResult(int val1, int val2, char op);

main()
{
      char ch;
      char stack[maxStack];
      int top = 0,result;
      int val1[1], val2[1];
      bool operand=FALSE;
      
      printf("Please enter the postfix expression you would like to compute.\n"); 
      printf("Please separate the all the operators and operands by spaces.\n"); 
      printf("For example: 2 17 *\n"); /*Prompting*/
      val1[0]=0;
      while ((ch = getchar()) != '\n')
      {
            if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
            {
                 top = Pop(stack, top, val1);
                 top = Pop(stack, top, val2); // This gets the top 2 values from the stack
                 result = getResult(val1[0], val2[0], ch);
                 top = Push(stack, top, result);  // This pushes the computed value into the stack
                 operand=FALSE;
                 val1[0]=0;
                 val2[0]=0;
            } else if (ch != ' ') {
                 if (val1[0]==0)
                      val1[0]=ch-'0'; // This initializes the val1[0] to the integer equivalent of the character we read
                 else 
                      val1[0]=val1[0]*10+(ch-'0'); // This takes care of multi-digit numbers by multiplying the previous by 10 and adding
                 operand=TRUE;
            } else if (operand) {
                 top=Push(stack, top, val1[0]); // This pushes the read values into the stack
                 val1[0]=0;
            }
      }
      printf("Result = %d\n", result);
      getchar();
}

/* This function puts the passed value into the stack and returns the new top index */
int Push(char stack[], int top, int val)
{
    stack[top] = val;
    return ++top;
}

/* This function adds the top of the stack to the array val and returns the new top index */
int Pop(char stack[], int top, int val[])
{ 
    top--;
    val[0] = stack[top];
    return top;
}

/* This function computes the expression based on the operator */
int getResult(int val1, int val2, char op)
{
    switch (op)
    {
           case '+' : return(val2+val1);
           case '-' : return(val2-val1);
           case '*' : return(val2*val1);
           case '/' : return(val2/val1);
    }
}
