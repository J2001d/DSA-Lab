#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int item;
	struct Node * next;
};

int menu (){
	int c;
	printf("\nPress 1 for adding an element\n");
	printf("Press 2 to show the Linked list\n");
	printf("Press 3 for exit\n");
	
	scanf("%d",&c);
	return c;
}
void showlist(struct Node *s){
	while (s != NULL){
		printf("%d ",s->item);
		s = s->next;
	} 
}
void insertatlast(struct Node **s,int value){
	struct Node *t,*temp;
	temp = (struct Node*) malloc (sizeof(struct Node));
	temp -> item = value;
	temp -> next = NULL;
	if((*s) == NULL){
		(*s) = temp;
	}else{
		t = (*s);
		while (t->next != NULL){
			t = t->next;
		}
		t->next = temp;
	}
}

int main(){
	struct Node *start = NULL;
	while(1){
		switch(menu()){
			case 1:
				printf("\nEnter data to add ");
				int data;
				scanf("%d",&data);
				insertatlast(&start,data);
				break;
			case 2:
				printf("\nPrinting List ");
				showlist(start);
				break;
			case 3:
				exit(0);
		}
	}
	return 0;
}
