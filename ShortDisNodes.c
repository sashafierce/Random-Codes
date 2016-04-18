#include<stdio.h>
#include<stdlib.h>
struct node
{
	int val;
	struct node *left , *right;
};
struct node *nn(int value)
{
	struct node *n = (struct node *)malloc(sizeof(struct node));
	n->val = value;
	n->left = NULL;
	n->right = NULL;
	return n;
}
void inOrder(struct node *root)
{
	if(root == NULL)
		return;
	else
	{
		inOrder(root->left);
		printf("%d_",root->val);
		inOrder(root->right);
	}
}
void insert(struct node** root, int value)
{
	if(*root == NULL)
	{
		*root = nn(value);
	}
	else
	{
		struct node* trav  = *root;
		if(trav->val < value)
			insert(&(trav->right),value);
		else insert(&(trav->left),value);
	}
}
int BSTd( struct node *root, int key)
{
    if(root->val > key)
        return 1 + BSTd(root->left , key);
    else if(root->val < key)
        return 1 + BSTd(root->right , key);
    else return 0;
}
int distance(struct node *root , int a , int b)
{
    if( (a > root->val && b < root->val) || (a < root->val && b > root->val) )
    {
        return BSTd(root,a) + BSTd(root,b);
    }
    else if(a > root->val && b > root->val)
    {
        distance(root->right, a , b);
    }
    else if(a < root->val && b < root->val)
    {
        distance(root->left , a , b);
    }
    else if(a == root->val && (b < root->val) || (b > root->val))
    {
        return BSTd(root,b);
    }
    else if(b == root->val && (a < root->val) || (a > root->val))
    {
        return BSTd(root,a);
    }
}
int main()
{
	struct node *root = NULL;
	int ch , v , a , b;
	printf("Choose from the following tasks for the BST:\n1.Insert a key\n2.Shortest distance between given two keys\n3.exit\n");
	while(1)
	{
		scanf("%d",&ch);
		if(ch == 1)
		{
			scanf("%d",&v);
			insert(&root,v);
		}
		else if(ch == 2)
		{
			scanf("%d",&a);
			scanf("%d",&b);
			printf("%d\n", distance(root,a , b));
		}
        else if(ch == 3)
			exit(1);
	}
	return 0;
}






