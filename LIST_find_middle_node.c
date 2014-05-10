#include<stdio.h>

typedef struct node
{
        int data;
        struct node *next; 
}mynode;

void add(mynode **head, mynode **tail, int value);
void print_list(mynode *head);
void find_middle_element(mynode *head);

int main()
{
    mynode *head, *tail;
    head = (mynode *)0;
    
    add(&head, &tail, 6);
    add(&head, &tail, 9);
    add(&head, &tail, 7);
    add(&head, &tail, 5);
    add(&head, &tail, 1);
    add(&head, &tail, 3);
    add(&head, &tail, 2);
    
    print_list(head);
    
    find_middle_element(head);
    //printf("\n\nMiddle element: %d", middle -> data);
    
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

void find_middle_element(mynode *head)
{
       mynode *slow, *fast;
       slow = head;
       fast = head -> next;
       
       while(fast != (mynode *)0)
       {
                  slow = slow -> next;
                  fast = fast -> next;
                  
                  if(fast != (mynode *)0)
                           fast = fast -> next;
       }
       printf("\nMiddle Element: %d ", slow -> data);
       //return slow;
              
}





