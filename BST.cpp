#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	struct Node *left;
	int data;
	struct Node *right;
}node;


void insert(node**, int);
node* deleteNode(node*, int);
node* search(node*, int);
void display_inorder(node*);
void display_preorder(node*);
void display_postorder(node*);
node* minValueNode(node*);



int main(){
	node *root = NULL, *res;
	int ch, flag = 1, elem;
	
	printf("1. Insert\n2. Delete\n3. Search\n4. Display Inorder\n5. Display Preorder\n6. Display Postorder\n8. Exit\n");
	while(flag){
		printf("Enter your choice: ");
		scanf("%d", &ch);
		
		switch(ch){
			case 1: printf("Enter element to Insert: ");
					scanf("%d", &elem);
					insert(&root, elem);
					break;
					
			case 2: printf("Enter element to Delete: ");
					scanf("%d", &elem);
					root = deleteNode(root, elem);
					break;
					
			case 3: printf("Enter element to Search: ");
					scanf("%d", &elem);
					res = search(root, elem);
					if(res == NULL)
						printf("The element is not present in the node\n");
					else{
						printf("The node at which the element is present is\n");
						display_inorder(res);
						printf("\n");
					}
					break;
					
			case 4: printf("Inorder Display of the Tree\n");
					display_inorder(root);
					printf("\n");
					break;
					
			case 5: printf("Preorder Display of the Tree\n");
					display_preorder(root);
					printf("\n");
					break;
					
			case 6: printf("Postorder Display of the Tree\n");
					display_postorder(root);
					printf("\n");
					break;
					
			case 8: flag = 0;
					break;
					
			default: printf("Invalid Input!!");
			
		}
	}
	
}


void insert(node **root, int item){
	node *newnode = (node*)malloc(sizeof(node));
	newnode->data = item;
	newnode->left = newnode->right = NULL;
	
	if(*root == NULL)
		*root = newnode;
	else{
		if(item > (*root)->data){
			if(!(*root)->right)
				(*root)->right = newnode;
			else
				insert(&(*root)->right, item);
		}
		
		else if(item < (*root)->data){
			if(!(*root)->left)
				(*root)->left = newnode;
			else
				insert(&(*root)->left, item);
		}
		
		else
			printf("Invalid Input!! Value already exists in tree\n");
	}
}

void display_inorder(node *root){
	if(root){
		display_inorder(root->left);
		printf("%d ", root->data);
		display_inorder(root->right);
	}
}

void display_postorder(node *root){
	if(root){
		display_postorder(root->left);
		display_postorder(root->right);
		printf("%d ", root->data);
	}
}

void display_preorder(node *root){
	if(root){
		printf("%d ", root->data);
		display_preorder(root->left);
		display_preorder(root->right);
	}
}

node* search(node *root, int item){
	if(!root)
		return NULL;
		
	if(root->data == item)
		return root;
		
	if(item > root->data)
		search(root->right, item);
		
	else
		search(root->left, item);	
}

node* minValueNode(node* root){
	node *curr = root;
	while(curr && curr->left)
		curr = curr->left;
	
	return curr;
}


node* deleteNode(node* root, int item){
	
	if(root == NULL)
		return root;
		
	else if(item < root->data)
		root->left = deleteNode(root->left, item);
		
	else if(item > root->data)
		root->right = deleteNode(root->right, item);
		
	else{

		if(!root->left && !root->right){
			root = NULL;
			free(root);
		}
			
		else if(!root->left){
			node *temp = root;
			root = root->right;
			free(temp);
		}
		
		else if(!root->right){
			node *temp = root;
			root = root->left;
			free(temp);
		}
		
		else{
			node *temp = minValueNode(root->right);
			root->data = temp->data;
			root->right = deleteNode(root->right, temp->data);
		}
		
	}
	return root;	
}



