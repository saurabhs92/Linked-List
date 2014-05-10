#include<stdio.h>

typedef struct node
{
       int data;
       struct node *next;
       struct node *prev;       
}mynode;

//Globals
mynode *head, *tail;

void add(int value);
void print_list();
void reverse_doubly_linked_iterative();


int main()
{   
    head = (mynode *)0;
    tail = (mynode *)0;
    
    add(6);
    add(7);
    add(5);
    add(9);
    add(1);
    add(4);
    print_list();
    
    reverse_doubly_linked_iterative();
    
    print_list();
    
    
    getch();
    return 0;    
}


void add(int value)
{
     mynode *temp, *cur;
     temp = (mynode *)malloc(sizeof(mynode));
     temp -> data = value;
     temp -> next = (mynode *)0;
     temp -> prev = (mynode *)0;
     
     if(head == (mynode *)0)
     {
             head = temp;
             tail = temp;        
     }else
     {
             for(cur = head; cur -> next != (mynode *)0; cur = cur -> next);
             
             cur -> next = temp;
             temp -> prev = cur;
             tail -> next = temp;
             tail = temp;     
     }
          
}
void print_list()
{
                 mynode *temp;
                 printf("\n\n[NULL] ");
                 for(temp = head; temp != (mynode *)0; temp = temp -> next)
                 {
                          printf("%d  ", temp -> data);         
                 }               
                 printf("[NULL]\n");
                 
                
}
void reverse_doubly_linked_iterative()
{
     mynode *cur, *save_next, *temp;
     
     for(cur = head; cur != (mynode *)0;)
     {
             temp = cur -> next;
             save_next = cur -> next;
             cur -> next = cur -> prev;
             cur -> prev = temp;
             cur = save_next;
     }
     
     temp = head;
     head = tail;
     tail = temp;
}


