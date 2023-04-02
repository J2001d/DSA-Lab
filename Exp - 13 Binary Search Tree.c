// binary search tree
#include<stdio.h>
#include<stdlib.h>
struct BTNode {
	int data;
	struct BTNode *left;
	struct BTNode *right;
};

void insertintree(struct BTNode** root, int data) {
	struct BTNode* temp, *t;
	temp = (struct BTNode*)malloc(sizeof(struct BTNode));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;

	if (*root == NULL) {
		*root = temp;
	}
	else {
		t = *root;
		if (t->data == data) {
			printf("data already exist");
		}
		else {
			while (1) {

				if (t->data < data) {
					if (t->right == NULL) {
						t->right = temp;
						break;
					}
					t = t->right;
				}
				else {
					if (t->left == NULL) {
						t->left = temp;
						break;
					}
					t = t->left;
				}
			}
		}
	}
}
void preorder(struct BTNode* root) {
	printf("%d ", root->data);
	if (root == NULL)
		return;
	if (root->left != NULL)
		preorder(root->left);
	if (root->right != NULL)
		preorder(root->right);
}

void inorder(struct BTNode* root) {
	if (root == NULL)
		return;
	if (root->left != NULL)
		inorder(root->left);
	printf("%d ", root->data);
	if (root->right != NULL)
		inorder(root->right);
}

void postorder(struct BTNode* root) {
	if (root == NULL)
		return;
	if (root->left != NULL)
		postorder(root->left);
	if (root->right != NULL)
		postorder(root->right);
	printf("%d ", root->data);
}
int menu() {
	int c;
	printf("\nPress 1 to insert\n");
	printf("Press 2 to print in preorded format\n");
	printf("Press 3 to print in inordered foramt\n ");
	printf("Press 4 to print in postordered format\n");
	printf("Press 5 to exit\n");
	scanf("%d", &c);
	return c;
}
int main() {
	struct BTNode *root = NULL;
	int data;
	while (1) {
		switch (menu()) {
		case 1:
			printf("Enter the data to insert\n");
			scanf("%d", &data);
			insertintree(&root, data);
			break;
		case 2:
			printf("Printing in preorder format\n");
			preorder(root);
			break;
		case 3:
			printf("Printing in inorder format\n");
			inorder(root);
			break;
		case 4:
			printf("Printing in postorder format\n");
			postorder(root);
			break;
		case 5:
			exit(0);
		default:
			printf("INVALID ENTRY\n");
			break;
		}
	}
	return 0;
}
