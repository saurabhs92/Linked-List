#include<stdio.h>

typedef struct node
{
        int data;
        struct node *next; 
}mynode;

void add(mynode **head, mynode **tail, int value);
void print_list(mynode *head);
void create_copy(mynode *p, mynode **q);

int main()
{
    mynode *head, *tail, *head2, *tail2;
    head = (mynode *)0;
    head2 = (mynode *)0;
    
    add(&head, &tail, 6);
    add(&head, &tail, 9);
    add(&head, &tail, 7);
    add(&head, &tail, 5);
    //add(&head, &tail, 1);
    add(&head, &tail, 3);
    //add(&head, &tail, 2);
    add(&head, &tail, 4);
    
    
    print_list(head);
    
    create_copy(head, &head2);
    
    print_list(head2);
    
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
              printf("%d  ->  ", temp -> data);     
     printf("[NULL]\n");
     
}

void create_copy(mynode *p, mynode **q)
{
     if(p != (mynode *)0)
     {
          *q = malloc(sizeof(mynode)); // no need to cast
          (*q) -> data = p -> data;
          (*q) -> next = p -> next;
          create_copy(p -> next, &((*q) -> next));
          
     }
     
}





