#include <stdio.h>
#include <stdlib.h.>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// Create Node 
struct node* create(int value) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node* createBinerytree(struct node* root)
{
	int n;
	int f = 0;
	int r = 0;
	n = 100;

	struct node* q[n];

	struct node *new,*temp;
	int data;
	int ri;
	int le;

	printf("\nEnter root node : ");
	scanf("%d", &data);

	new = create(data);
	root = new;

	q[r++] = new;

	do
	{
		temp = q[f++];

		printf("\nEnter Child of %d\n", temp->data);
		printf("Right child :");
		scanf("%d", &ri);
		printf("Left child :");
		scanf("%d", &le);

		if (ri > 0)
		{
			new = create(ri);

			temp->right = new;
			q[r++] = new;
		}

		if (le > 0)
		{
			new = create(le);

			temp->left = new;
			q[r++] = new;
		}
	} while (f != r);
	return root;
}

struct node* insertInBinaryTree(struct node* node, int data)
{
 
    if (node == NULL)
        return create(data); 
 
    if (data < node->data)
        node->left = insertInBinaryTree(node->left, data);
    else if (data > node->data)
        node->right = insertInBinaryTree(node->right, data);
 
 
    return node;
}

struct node* searchInBST(struct node* root, int key){
    if(root==NULL){
        return NULL;
    }
    if(key==root->data){
        return root;
    }
    else if(key<root->data){
        return searchInBST(root->left, key);
    }
    else{
        return searchInBST(root->right, key);
    }
}
 

void inOrder(struct node* root){

    if(root==NULL)return;

    inOrder(root->left);
    printf("%d -> ",root->data);
    inOrder(root->right);

}
void preOrder(struct node* root){

    if(root==NULL)return;

    printf("%d -> ",root->data);
    preOrder(root->left);    
    preOrder(root->right);

}
void postOrder(struct node* root){

    if(root==NULL)return;

    postOrder(root->left);    
    postOrder(root->right);
    printf("%d -> ",root->data);

}

void levelOrder(struct node* root) {
    if (root == NULL) return;
    struct node* queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        struct node* node = queue[front++];
        printf("%d -> ", node->data);
        if (node->left != NULL)
            queue[rear++] = node->left;
        if (node->right != NULL)
            queue[rear++] = node->right;
    }
}

int countInternalNodes(struct node* root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL) 
        return 0;
    
    return countInternalNodes(root->left) + countInternalNodes(root->right)+1;
}

int countExternalNodes(struct node* root) {
    if (root == NULL) 
        return 0;
    if (root->left == NULL && root->right == NULL) 
        return 1;
    return countExternalNodes(root->left) + countExternalNodes(root->right);
}

int countNodes(struct node* root) {
    if (root == NULL) 
        return 0;
    
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int height(struct node* root) {
    if (root == NULL) 
        return -1;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}


int main(){

    // Create Binary Tree
    printf("*************  Binary Tree ******************");
    struct node* root;
    root =createBinerytree(root);
    

    printf("\n\nInorder Traversal :\n");
    inOrder(root);

    printf("\n\nPreorder Traversal :\n");
    preOrder(root);

    printf("\n\nPostorder Traversal :\n");
    postOrder(root);

    printf("\n\nLevelorder Traversal :\n");
    levelOrder(root);

    // Create BST
    printf("\n\n*************  Binary Search Tree ******************\n");
    int Bnodes,data;
    printf("\nEnter The Number of Node in Binary Search Tree :");
    scanf("%d",&Bnodes);    

    struct node* broot = NULL;
    printf("Enter 1 node :");
    scanf("%d",&data);
    broot =insertInBinaryTree(broot,data);

    for(int i=2; i<=Bnodes; i++){
        
        printf("\nEnter %d node : ",i);
        scanf("%d",&data);
        insertInBinaryTree(broot,data);
    }

    // Search in BST
    int sdata;
    printf("\n\nEnter element for Search in BST :");
    scanf("%d",&sdata);
    
    struct node* n = searchInBST(broot, sdata);
    if(n!=NULL){
        printf("Found: %d", n->data);
    }
    else{
        printf("Element not found");
    } 

    printf("\n\nInorder Traversal :\n");
    inOrder(broot);

    printf("\n\nPreorder Traversal :\n");
    preOrder(broot);

    printf("\n\nPostorder Traversal :\n");
    postOrder(broot);

    printf("\n\nLevelorder Traversal :\n");
    levelOrder(broot);

    printf("\n\nInternal Node in BST : %d\n",countInternalNodes(broot));
    printf("\nExternal Node in BST : %d\n",countExternalNodes(broot));
    printf("\nTotal Node in BST : %d\n",countNodes(broot));
    printf("\nHeight Node in BST : %d\n",height(broot));

    return 0;
    
}