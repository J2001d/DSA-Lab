#include <stdio.h>
#include <stdlib.h>
struct Queue {
	struct Queue *next;
	int data;
};
struct Queue*front = NULL;
struct Queue*rear = NULL;

void insertqueue(int data) {
	struct Queue *temp;
	temp = (struct Queue*)malloc(sizeof(struct Queue));
	temp->data = data;
	if (rear == NULL) {
		temp->next = NULL;
		front = temp;
		rear = temp;
	}
	else {
		temp->next = NULL;
		rear->next = temp;
		rear = temp;
	}
}
void deletequeue() {
	if (front == NULL) {
		printf("queue is empty");
	}
	else if (front == rear) {
		front = NULL;
		rear = NULL;
		return;
	}
	front = front->next;
}
void printqueue() {
	struct Queue*t;
	t = front;
	if (front == NULL)
		printf("queue is empty");
	else {
		while (t != NULL) {
			printf("%d ", t->data);
			t = t->next;
		}
	}
}
int menu() {
	printf("Press 1 to insert an element in the Queue\n");
	printf("Press 2 to delete an element from the Queue\n");
	printf("Press 3 to print Queue\n");
	printf("Press 4 to exit\n");
	int choice;
	scanf("%d", &choice);
	return choice;
}

int main() {
	int data;
	while (1) {
		switch (menu()) {
		case 1:
			printf("Enter the element to enter in the queue\n");
			scanf("%d", &data);
			insertqueue(data);
			break;
		case 2:
			deletequeue();
			printf("Deleted");
			break;
		case 3:
			printqueue();
			break;
		case 4:
			exit(0);
		}

	}
	return 0;
}
