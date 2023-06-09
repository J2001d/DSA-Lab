//linkedlist program
#include <stdio.h>
#include<stdlib.h>
struct Node{
    int item;
    struct Node* next;
};

void showlist(struct Node *s){
    
    while (s!=NULL){
        printf("%d ",s->item);
        s=s->next;
    }
}
void deleteNode(struct Node**s,int item){
    if(*s==NULL){
        printf("underflow");
    }
    struct Node *temp,*prev=NULL;
    temp=*s;
    while(1){
        if(temp->item==item){
            prev->next=temp->next;
            free(temp);
            return;
        }
        prev=temp;
        temp=temp->next;
        
    }
}


void deleteatfirst(struct Node**s){
    struct Node *r;
    if(*s==NULL){
        printf("underflow");
    }
    else{
        r=*s;
        *s=r->next;
        free(r);
    }
}


void deleteatlast(struct Node **s){
    struct Node *t1,*t2;
    if(*s==NULL)                // no node in the list i.e. list is empty
        printf("underflow");
    else{
        if((*s)->next==NULL){       //only one node in list
            free(*s);
            *s=NULL;
            
        }
        else{
            t2=NULL;
            t1=*s;
            while(t1->next!=NULL)       //while(t1->next)
            {
                t2=t1;   
                t1=t1->next;
            }
            // condition false means t1->next == NULL so free t1 and t2->next =NULL
            free(t1);
            t2->next=NULL;
        }
    }
    
}

void insertafter(struct Node *t,int data){
    struct Node *temp;
    temp=(struct Node*)malloc(sizeof(struct Node));
    temp->item=data;
    temp->next=t->next;
    t->next = temp;
}

void insertatstart(struct Node **s,int data){
    struct Node *temp;
    temp=(struct Node*)malloc(sizeof(struct Node));
    temp->item=data;
    temp->next=*s;
    *s=temp;
}

void insertatlast(struct Node **s,int data){ 
    struct Node *t,*temp;
    temp=(struct Node*)malloc(sizeof(struct Node));
    temp->item=data;
    temp->next=NULL;
    
    if((*s)==NULL)
        (*s)=temp;
    else{
        t=(*s);
        while(t->next!=NULL)
            t=t->next;
        t->next=temp;            
    }
    
}
int menu(){
    int c;
    printf("\nPRESS 1 FOR ADDING AN ELEMENT AT LAST\n");
    printf("PRESS 2 FOR ADDING AN ELEMENT AT FIRST\n");
    printf("PRESS 3 FOR ADDING AN ELEMENT AFTER A NODE\n");
    printf("PRESS 4 FOR DELETING AN ELEMENT FROM LAST\n");
    printf("PRESS 5 FOR DELETING AN ELEMENT AT FIRST\n");
    printf("PRESS 6 FOR DELETING A NODE OF GIVEN ELEMENT\n");
    printf("PRESS 7 TO SHOW THE CURRENT LIST\n");
    printf("PRESS 8 TO EXIT \n");
    scanf("%d",&c);
    return c;
}
int main()
{
    struct Node *start=NULL;
    int data,x=0,search;
    while(1){
    switch(menu()){
        case 1:
            printf("Enter data to add in the last of list ");
            scanf("%d",&data);
            insertatlast(&start,data);
            break;
        case 2:
            printf("Enter data to add in the start of list ");
            scanf("%d",&data);
            insertatstart(&start,data);
            break;
        case 3:
            printf("Enter data to after a node ");
            scanf("%d",&data);
            insertafter(start->next,data); 
            break;
        case 4:
            printf("deleting from last ");
            deleteatlast(&start); 
            break;
        case 5:
            printf("deleting first node ");
            deleteatfirst(&start); 
            break;
        case 6:
            scanf("%d",&data);
            printf("deleting the node having the the %d",data);
            deleteNode(&start,data); 
            break;   
        case 7:
            showlist(start);
            break;
        case 8:
            exit(0);
        default:
            printf("invalid choice");
    }
    
    
    }
    return 0;
}
