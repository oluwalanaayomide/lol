Implementation of stack in C
#include <stdio.h>
int MAXSIZE = 8; 
int stack[8]; 
int top = -1; 
int isempty() {
 if(top == -1)
 return 1;
 else
 return 0;
}
 
int isfull() {
 if(top == MAXSIZE)
 return 1;
 else
 return 0;
}
int peek() {
 return stack[top];
}
int pop() {
 int data;
 if(!isempty()) {
 data = stack[top];
 top = top - 1; 
 return data;
 } else {
 printf("Could not retrieve data, Stack is empty.\n");
 }
}
int push(int data) {
 if(!isfull()) {
 top = top + 1; 
 stack[top] = data;
 } else {
 printf("Could not insert data, Stack is full.\n");
 }
}
int main() {
 // push items on to the stack 
 push(3);
 push(5);
 push(9);
 push(1);
 push(12);
 push(15);
 printf("Element at top of the stack: %d\n" ,peek());
 printf("Elements: \n");
 // print stack data 
 while(!isempty()) {
 int data = pop();
 printf("%d\n",data);
 }
 printf("Stack full: %s\n" , isfull()?"true":"false");
 printf("Stack empty: %s\n" , isempty()?"true":"false");
 
 return 0;
}




#include
#include<stdio.h> 
#include<string.h> 
//char stack
char stack[25]; 
int top = -1; 
void push(char item) {
 stack[++top] = item; 
} 
char pop() {
 return stack[top--]; 
} 
//returns precedence of operators
int precedence(char symbol) {
 switch(symbol) {
 case '+': 
 case '-':
 return 2; 
 break; 
 case '*': 
 case '/':
 return 3; 
 break; 
 case '^': 
 return 4; 
 break; 
 case '(': 
 case ')': 
 case '#':
 return 1; 
 break; 
 } 
} 
//check whether the symbol is operator?
int isOperator(char symbol) {
 switch(symbol) {
 case '+': 
 case '-': 
 case '*': 
 case '/': 
 case '^': 
 case '(': 
 case ')':
 return 1; 
 break; 
 default:
 return 0; 
 } 
} 
//converts infix expression to postfix
void convert(char infix[],char postfix[]) {
 int i,symbol,j = 0; 
 stack[++top] = '#'; 
 for(i = 0;i<strlen(infix);i++) {
 symbol = infix[i]; 
 if(isOperator(symbol) == 0) {
 postfix[j] = symbol; 
 j++; 
 } else {
 if(symbol == '(') {
 push(symbol); 
 }else {
 if(symbol == ')') {
 while(stack[top] != '(') {
 postfix[j] = pop(); 
j++; 
 } 
 pop();//pop out (. 
 } else {
 if(precedence(symbol)>precedence(stack[top])) {
 push(symbol); 
 }else {
 while(precedence(symbol)<=precedence(stack[top])) {
 postfix[j] = pop(); 
j++; 
 } 
 push(symbol); 
 }
 }
 }
 }
 }
 while(stack[top] != '#') {
 postfix[j] = pop(); 
 j++; 
 } 
 postfix[j]='\0';//null terminate string. 
} 
//int stack
int stack_int[25]; 
int top_int = -1; 
void push_int(int item) {
 stack_int[++top_int] = item; 
} 
char pop_int() {
 return stack_int[top_int--]; 
} 
//evaluates postfix expression
int evaluate(char *postfix){
 char ch;
 int i = 0,operand1,operand2;
 while( (ch = postfix[i++]) != '\0') {
 if(isdigit(ch)) {
 push_int(ch-'0'); // Push the operand 
 }else {
 //Operator,pop two operands 
 operand2 = pop_int();
 operand1 = pop_int();
 switch(ch) {
 case '+':
 push_int(operand1+operand2);
 break;
 case '-':
 push_int(operand1-operand2);
 break;
 case '*':
 push_int(operand1*operand2);
 break;
 case '/':
 push_int(operand1/operand2);
 break;
 }
 }
 }
 return stack_int[top_int];
}
void main() { 
 char infix[25] = "1*(2+3)",postfix[25]; 
 convert(infix,postfix); 
 printf("Infix expression is: %s\n" , infix);
 printf("Postfix expression is: %s\n" , postfix);
 printf("Evaluated expression is: %d\n" , evaluate(postfix));
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50
int top = -1, front = 0;
int stack[MAX];
void push(char);
void pop();
/* push a character into stack */
void push(char a)
{
      top++;
      stack[top]  =  a;
}
/* delete an element in stack */
void pop()
{
      top--;
}
int main()
{
      int i, cho;
      char s[MAX], b;
      printf("\tMENU");
      printf("\n---------------------------\n");
      printf("1.Check string is palindrome.\n2.Exit\n");
      printf("---------------------------\n");
      while (1)
      {
            printf("Choose operation : ");
            scanf("%d", &cho);
            switch (cho)
            {
                  case 1:
                        printf("\nEnter string : ");
                        scanf("%s", s);
                        for (i = 0;s[i] != '\0';i++)
                        {
                              b = s[i];
                              push(b);
                        }
                        for (i = 0;i < (strlen(s) / 2);i++)
                        {
                              if (stack[top] == stack[front])
                              {
                                    pop();
                                    front++;
                              }
                              else
                              {
                                    printf("'%s' is not palindrome.\n\n", s);
                                    break;
                              }
                        }
                        if ((strlen(s) / 2)==  front)
                              printf("'%s' is palindrome.\n\n",  s);
                        front  =  0;
                        top  =  -1;
                        break;
                  case 2:
                        exit(0);
                  default: printf("Invalid operation \n");
            }
      }
      return 0;
}
Here is the algorithm:
 Iterate to the node before the node we wish to delete
 Save the node we wish to delete in a temporary pointer
 Set the previous node's next pointer to point to the node after the node we wish to delete
 Delete the node using the temporary pointer
There are a few edge cases we need to take care of, so make sure you understand the code.
#include <stdio.h>
int main() {
 int remove_by_index(node_t ** head, int n) {
 int i = 0;
 int retval = -1;
 node_t * current = *head;
 node_t * temp_node = NULL;
 
 if (n == 0) {
 return pop(head);
 }
 
 for (i = 0; i < n-1; i++) {
 if (current->next == NULL) {
 return -1;
 }
 current = current->next;
 }
 
 temp_node = current->next;
 retval = temp_node->val;
 current->next = temp_node->next;
 free(temp_node);
 
 return retval;
 
 }
 
return 0;
Removing the last item of the list 
Removing the last item from a list is very similar to adding it to the end of the list, but with one big exception 
- since we have to change one item before the last item, we actually have to look two items ahead and see if 
the next item is the last one in the list:
#include <stdio.h>
int main() {
 int remove_last(node_t * head) {
 int retval = 0;
 /* if there is only one item in the list, remove it */
 if (head->next == NULL) {
 retval = head->val;
 free(head);
 return retval;
 }
 
 /* get to the second to last node in the list */
 node_t * current = head;
 while (current->next->next != NULL) {
 current = current->next;
 }
 
 /* now current points to the second to last item of the list, so let's remove current->next */
 retval = current->next->val;
 free(current->next);
 current->next = NULL;
 return retval;
 
 }
 
return 0
Adding an item to the beginning of the list (pushing to the list) 
To add to the beginning of the list, we will need to do the following:
 Create a new item and set its value
 Link the new item to point to the head of the list
 Set the head of the list to be our new item
This will effectively create a new head to the list with a new value, and keep the rest of the list linked to it.
Since we use a function to do this operation, we want to be able to modify the head variable. To do this, we 
must pass a pointer to the pointer variable (a double pointer) so we will be able to modify the pointer itself.
#include <stdio.h>
int main() {
 void push(node_t ** head, int val) {
 node_t * new_node;
 new_node = malloc(sizeof(node_t));
 
 new_node->val = val;
 new_node->next = *head;
 *head = new_node;
 }
 
return 0
Iterating over a list 
Let's build a function that prints out all the items of a list. To do this, we need to use a current pointer that 
will keep track of the node we are currently printing. After printing the value of the node, we set the current 
pointer to the next node, and print again, until we've reached the end of the list (the next node is NULL).
#include <stdio.h>
int main() {
 void print_list(node_t * head) {
 node_t * current = head;
 
 while (current != NULL) {
 printf("%d\n", current->val);
 current = current->next;
 }
 Implementation in C 
Since each node consists of at least two fields, we use a struct to define the format of the node. The next
field is a pointer to a structure which it is a part of. Thus, the definition of the structure includes a field which
points to the structure being defined; this is called self-referencing structure. 
Suppose the data at each node is a positive integer, we can define a node as follow:
struct node {
 int val;
 struct node * next;
};
Or using typedef:
#include <stdio.h>
int main() {
 typedef struct node {
 int val;
 struct node * next;
 } node_t;
 
return 0
