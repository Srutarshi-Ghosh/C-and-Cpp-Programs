#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node *right;
	struct Node *left;
	int height;
}node;

node* createNode();
node* insertNode(node*, int);
node* deleteNode(node*, int);
node* rightRotate(node*);
node* leftRotate(node*);
int heightOfTree(node*);
int balance(node*);
node* search(node*, int);
void display_inorder(node*);
void display_preorder(node*);
void display_postorder(node*);
int max(int, int);


int main(){
	node *root = NULL, *res;
	int ch, flag = 1, elem;
		
	printf("1. Insert\n2. Delete\n3. Search\n4. Display Inorder\n5. Display Preorder\n6. Display Postorder\n7. Exit\n\n");
	while(flag){
		printf("Enter your choice: ");
		scanf("%d", &ch);
		
		switch(ch){
			case 1: printf("Enter element to Insert: ");
					scanf("%d", &elem);
					root = insertNode(root, elem);
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
					
			case 7: flag = 0;
					break;
					
			default: printf("Invalid Input!!");
			
		}
	}
	
}


node* createNode(int item){
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data = item;
	newnode->left = newnode->right = NULL;
	newnode->height = 1;
	return newnode;
}

int max(int a, int b){
	return (a > b)? a : b;
}

int heightOfTree(node* root){
	if(root == NULL)
		return 0;
	return root->height;
}


node* minNode(node* root){
	node* curr = root;
	
	while(curr->left)
		curr = curr->left;
	
	return curr;
}


int balance(node* root){
	if(root == NULL)
		return 0;
		
	return heightOfTree(root->left) - heightOfTree(root->right);
}


node* rightRotate(node *root){
	node *L = root->left;
	node *sub_R = L->right;
	
	L->right = root;
	root->left = sub_R;
	
	root->height = max(heightOfTree(root->left), heightOfTree(root->right)) + 1; 
	(L->height) = max(heightOfTree(L->left), heightOfTree(L->right)) + 1; 

	return L;
}


node* leftRotate(node *root){
	node *R = root->right;
	node *sub_L = R->left;
	
	R->left = root;
	root->right = sub_L;
	
	root->height = max(heightOfTree(root->left), heightOfTree(root->right)) + 1; 
	(R->height) = max(heightOfTree(R->left), heightOfTree(R->right)) + 1; 

	return R;
}


node* insertNode(node* root, int item){
	
	if(root == NULL)
		return createNode(item);
		
	if(item < root->data)
		root->left = insertNode(root->left, item);
		
	else if(item > root->data)
		root->right = insertNode(root->right, item);
		
	else
		return root;
		
	root->height = 1 + max(heightOfTree(root->left), heightOfTree(root->right));
	
	int bal = balance(root);
	
	if(bal > 1 && item < root->left->data)
		return rightRotate(root);

	if(bal < -1 && item > root->right->data)
		return leftRotate(root);
		
	if(bal > 1 && item > root->left->data){
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	
	if(bal < -1 && item < root->right->data){
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	
	return root;
	
}


node* deleteNode(node* root, int item){
	
	if(!root)
		return root;
		
	else if(item > root->data)
		root->right = deleteNode(root->right, item);
		
	else if(item < root->data)
		root->left = deleteNode(root->left, item);
		
	else{
		
		if(!root->left || !root->right){
			node *temp = NULL;
			if(root->left)
				temp = root->left;
			else if(root->right)
				temp = root->right;
		
			if(!temp){
				temp = root;
				root = NULL;
			}
			else
				*root = *temp;
				
			free(temp);
		}
		else{
			node *temp = minNode(root->right);
			root->data = temp->data;
			root->right = deleteNode(root->right, temp->data);
		}
	}
	
	if(!root)
		return root;
		
	root->height = 1 + max(heightOfTree(root->left), heightOfTree(root->right));	
	int bal = balance(root);
	
	if(bal > 1 && balance(root->left) >= 0)
		return rightRotate(root);
		
	if(bal < -1 && balance(root->right) <= 0)
		return leftRotate(root);
		
	if(bal > 1 && balance(root->left) < 0){
		root->left = leftRotate(root);
		return rightRotate(root);
	}
	
	if(bal < -1 && balance(root->right) > 0){
		root->right = rightRotate(root);
		return leftRotate(root);
	}
	
	return root;
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





