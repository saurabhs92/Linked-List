#include<stdio.h>

struct node
{
        int data;
        struct node *next;        
};
typedef struct node mynode; // different way of declaring a structure   

mynode *head, *tail;

void add(int value);
void print_list();
void bubble_sort(int n);

int main()
{
    head = (mynode *)0;
    
    add(5);
    add(9);
    add(2);
    add(4);
    add(11);
    add(8);
    
    print_list();
    
    bubble_sort(6);
    print_list();
    
    getch();
    return 0;
}

void add(int value)
{
     mynode *temp = (mynode *)malloc(sizeof(mynode));
     temp -> data = value;
     temp -> next = (mynode *)0;
     
     if(head == (mynode *)0)
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
     mynode *temp;
     printf("\n\n");
     for(temp = head; temp != (mynode *)0; temp = temp -> next )
     {
              printf("%d  ", temp -> data);
                      
     }     
     printf("[NULL]\n");
}
void bubble_sort(int n)
{
    int temp, i, j, k = n;
    
    mynode *p, *q;
    
    for(i = 0; i < n - 1; i++, k--)
    {
            p = head;
            q = head -> next;
            
            for(j = 1; j < k; j++)
            {
                  if(p -> data > q -> data)
                  {
                       temp = p -> data;
                       p -> data = q -> data;
                       q -> data = temp;
                            
                  }      
                  p = p -> next;
                  q = q -> next;
                  
            }
                    
    }
    
}

