//implementing stack using linked list
#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node * next;
};

struct Node *top = NULL;

void push(int data) {
	struct Node * temp;
	temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = data;
	temp->next = top;
	top = temp;
}

void pop() {
	struct Node * t;
	t = top;
	top = t->next;
}

void show() {
	struct Node *t;
	t = top;
	while (t != NULL) {
		printf("%d ", t->data);
		t = t->next;
	}

}
int menu() {
	int c;
	printf("\npress 1 to push data\n");
	printf("press 2 to pop data\n");
	printf("press 3 to show stack\n");
	printf("press 4 to exit\n");
	scanf("%d", &c);
	return c;
}

int main() {
	int data;
	while (1) {
		switch (menu()) {
		case 1:
			printf("Enter the data to push\n");
			scanf("%d", &data);
			push(data);
			break;
		case 2:
			pop();
			break;
		case 3:
			printf("Stack := \n");
			show();
			break;
		case 4:
			printf("exit");
			exit(0);
		}
	}
	return 0;
}
