#include<stdio.h>

typedef struct node
{
    int data;
    struct node *next;        
}mynode;

void add(mynode **head, mynode **tail, int value);
void print_list(mynode *head);
void reverse_iterative(mynode **head);


int main()
{   
    mynode *head = (mynode *)0;
    mynode *tail = (mynode *)0;
    
    add(&head, &tail, 7);
    add(&head, &tail, 3);
    add(&head, &tail, 9);
    add(&head, &tail, 6);
    add(&head, &tail, 5);
    
    print_list(head);
    reverse_iterative(&head);
    print_list(head);
    
    getch();
    return 0;        
}

void add(mynode **head, mynode **tail, int value)
{
     mynode *temp = (mynode *)malloc(sizeof(struct node));
     temp -> data = value;
     temp -> next = (mynode *)0;
     
     if(*head == (mynode *)0)
              *head = temp;
     else       
              (*tail) -> next = temp;
              
     *tail = temp;
                
}

void print_list(mynode *head)
{
     mynode *temp;
     printf("\n\n");
     for(temp = head; temp != (mynode *)0; temp = temp -> next)
     {
              printf("%d  ", (temp -> data));
     }     
     printf("[NULL]\n\n");
}

void reverse_iterative(mynode **head)
{
     mynode *p, *q, *r;
     
     if(*head == (mynode *)0)
             return;
             
     p = *head;
     q = p -> next;
     p -> next = (mynode *)0;
     
     while(q != (mynode *)0)
     {
             r = q ->next;
             q -> next = p;
             p = q;
             q = r;        
     }
     
     *head = p;
          
}
