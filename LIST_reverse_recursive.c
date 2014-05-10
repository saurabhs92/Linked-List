#include<stdio.h>

typedef struct node
{
        int data;
        struct node *next;        
}mynode;

//Globals
mynode *head, *tail, *temp;

void add(int value);
mynode *reverse_recursive(mynode *root);
void print_list();

int main()
{
    head = (mynode *)0;
    
    add(6);    
    add(2);    
    add(7);    
    add(1);    
    add(5);    
    add(3);
    
    print_list();
    if(head != (mynode *)0)
    {
            temp = reverse_recursive(head);
            temp -> next = (mynode *)0;
            
    }
    print_list();
    
    getch();
    return 0;
}


void add(int value)
{
     temp = (mynode *)malloc(sizeof(struct node));
     temp -> data = value;
     temp -> next = (mynode *)0;
     
     if(head == (mynode *)0)
     {
             head = temp;
             tail = head;        
     }    
     else
     {
             tail -> next = temp; // and not head -> next = temp;
             tail = temp;
     }
}

mynode *reverse_recursive(mynode *root)
{
       if(root -> next != (mynode *)0)
       {
              reverse_recursive(root -> next);
              root -> next -> next = root;
              return(root);
                      
       }else
       {
              head = root;
       }
}
void print_list()
{
     printf("\n");
     for(temp = head; temp != (mynode *)0; temp = temp -> next)
     {
              printf("%d  ->  ", temp -> data);
                       
     }     
     printf("[NULL]\n\n");
}
