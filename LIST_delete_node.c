#include<stdio.h>

typedef struct node
{
        int data;
        struct node *next;        
}mynode;

//Globals
mynode *head, *tail, *temp;

void add(int value);
void print_list();
void delete_node(mynode *del);
mynode *pointer_from_index(int index);

int main()
{
     head = (mynode *)0;
     add(7);
     add(8);
     add(1);
     add(5);
     add(3);
     print_list();
     
     int index_to_delete = 3;
     mynode *del;
     del = pointer_from_index(index_to_delete);
     //printf("")
     delete_node(del);
     print_list();
     
     
     getch();
     return 0;   
}

void add(int value)
{
     //mynode *temp;
     temp = (mynode *)malloc(sizeof(mynode));
     temp -> data = value;
     temp -> next = (mynode *)0;
     
     if(head == (mynode *)0)    // if by mistake head = (mynode *)0 then it compiles but stops working.. and very hard to find error!
     {
             head = temp;
             tail = temp;             
     
     }else
     {
             tail -> next = temp;
             tail = temp; 
     }       

     
}

void print_list()
{
     //mynode *temp;
     printf("\n\n");
     for(temp = head; temp != (mynode *)0; temp = temp -> next)
     {
              printf("%d  ", temp -> data);
     }
     printf("[NULL] \n");
          
}

void delete_node(mynode *del)
{
     //mynode *temp;
     temp = head;
     while(temp -> next != del && temp -> next != (mynode *)0)
                temp = temp -> next;
     
     if(temp == (mynode *)0)
     {
             printf("\n The given node is not present in the linked list.");
             return;        
     }
     
     temp -> next =  temp -> next -> next;
     free(del);  
  
}   

mynode *pointer_from_index(int index)
{
    int i;
    //mynode *temp = head;
    temp = head;
    for(i = 1; i < index; i++, temp = temp -> next);
    return temp;
    
}
