/*
Ayan Kumar Chatterjee
MCA (IGNOU), Diploma in Software Engineering (Aptech Computer Education),
Teacher of Computer Science and Software Technology
1/1A, Ananda Chatterjee Lane, Kolkata 700003.  Phone: 99034 63883 // 033 2554 6084.  Email: ayankumarchatterjee@yahoo.com
*/

#include<stdio.h>
#include<malloc.h>

typedef struct node
{
	struct node *left;
	int info;
	struct node *right;
}bnode;
bnode *root;

void CreateTree(bnode **tree)  // CREATE AN EMPTY TREE
{
	*tree = (bnode *)NULL;
}

void PreordertraversalRecursive(bnode *tree)  // ROOT -> LEFT -> RIGHT
{
	if(root == (bnode *)NULL)
	{	printf("\n\n\t\t\tTree empty. Cannot display anything");
		getch();
		return;
	}
	if(tree != (bnode *)NULL)
	{
		printf("\t%d", tree->info);
		PreordertraversalRecursive(tree->left);
		PreordertraversalRecursive(tree->right);
	}
}

/*
	ALGORITHM:
	START
		ACCEPT THE ADDRES OF THE PRESENT NODE INTO POINTER "TREE"

		IF TREE IS NOT NULL THEN
			PRINT TREE->INFO
			CALL ALGORITHM RECURSIVELY WITH TREE->LEFT
			CALL ALGORITHM RECURSIVELY WITH TREE->RIGHT
		ENDIF
	STOP
*/

void InordertraversalRecursive(bnode *tree)  // LEFT -> ROOT -> RIGHT
{
	if(root == (bnode *)NULL)
	{	printf("\n\n\n\t\t\tTree empty. Cannot display anything");
		getch();
		return;
	}
	if(tree != (bnode *)NULL)
	{
		InordertraversalRecursive(tree->left);
		printf("\t%d", tree->info);
		InordertraversalRecursive(tree->right);
	}
}

/*
	ALGORITHM:
	START
		ACCEPT THE ADDRES OF THE PRESENT NODE INTO POINTER "TREE"

		IF TREE IS NOT NULL THEN
			CALL ALGORITHM RECURSIVELY WITH TREE->LEFT
			PRINT TREE->INFO
			CALL ALGORITHM RECURSIVELY WITH TREE->RIGHT
		ENDIF
	STOP
*/

void PostordertraversalRecursive(bnode *tree)  // LEFT -> RIGHT -> ROOT
{
	if(root == (bnode *)NULL)
	{
		printf("\n\n\n\t\t\tTree empty. Cannot display anything");
		getch();
		return;
	}
	if(tree != (bnode *)NULL)
	{
		PostordertraversalRecursive(tree->left);
		PostordertraversalRecursive(tree->right);
		printf("\t%d", tree->info);
	}
}

/*
	ALGORITHM:
	START
		ACCEPT THE ADDRES OF THE PRESENT NODE INTO POINTER "TREE"

		IF TREE IS NOT NULL THEN
			CALL ALGORITHM RECURSIVELY WITH TREE->LEFT
			CALL ALGORITHM RECURSIVELY WITH TREE->RIGHT
			PRINT TREE->INFO
		ENDIF
	STOP
*/

void DetermineHeight(bnode *tree,int *height)
{
	int left_height, right_height;
	if(tree == (bnode *)NULL)  // IF TREE IS EMPTY AT ROOT THEN HEIGHT IS 0
		*height = 0;
	else
	{
		DetermineHeight(tree->left,&left_height);  // RECURSIVE FUNCTION TO DETERMINE HEIGHT OF LEFT & RIGHT SUBTREE
		DetermineHeight(tree->right,&right_height);
		if(left_height>right_height)
			*height = left_height + 1;  // MAXIMUM HEIGHT OF LEFT SUBTREE + 1
		else
			*height = right_height + 1;  // MAXIMUM HEIGHT OF RIGHT SUBTREE + 1
	}
}

/*
	ALGORITHM:
	START
		ACCEPT THE ADDRES OF THE PRESENT NODE INTO POINTER "TREE" AND ADDRESS OF HEIGHT VARIABLE INTO INTEGER POINTER HEIGHT
		DECLARE INTEGER VARIABLES LEFT_HEIGHT AND RIGHT_HEIGHT

		IF TREE IS NULL THEN
			RETURN 0
		ELSE
			CALL ALGORITHM RECURSIVELY WITH TREE->LEFT AND ADDRESS OF LEFT_HEIGHT
			CALL ALGORITHM RECURSIVELY WITH TREE->RIGHT AND ADDRESS OF RIGHT_HEIGHT
		ENDIF
	STOP
*/

int TotalNodes(bnode *tree)
{
	if (tree == (bnode *)NULL)
		return 0;
	else
		return (TotalNodes(tree->left) + TotalNodes(tree->right) + 1);  // KEEP ADDING 1 TO THE TOTAL UNTIL THE END OF THE TREE WHERE NODE IS FOUND i.e. NOT NULL
}

/*
	ALGORITHM:
	START
		ACCEPT THE ADDRES OF THE PRESENT NODE INTO POINTER "TREE" AND ADDRESS OF HEIGHT VARIABLE INTO INTEGER POINTER HEIGHT
		DECLARE INTEGER VARIABLES LEFT_HEIGHT AND RIGHT_HEIGHT

		IF TREE IS NULL THEN
			RETURN 0
		ELSE
			CALL ALGORITHM RECURSIVELY WITH TREE->LEFT
			CALL ALGORITHM RECURSIVELY WITH TREE->RIGHT
			RETURN THE VALUE RETURNED BY THE PREVIOUS TWO ALGORITHM CALLS + 1
		ENDIF
	STOP
*/

int InternalNodes(bnode *tree)
{
	if((tree == NULL) || ((tree->left == NULL) && (tree->right == NULL)))
		return 0;
	else
		return(InternalNodes(tree->left) + InternalNodes(tree->right) + 1);  // KEEP ADDING 1 TO THE TOTAL UNTIL THE END OF THE TREE WHERE NODE HAS ATLEAST ONE SUBTREE
}

/*
	ALGORITHM:
	START
		ACCEPT THE ADDRES OF THE PRESENT NODE INTO POINTER "TREE" AND ADDRESS OF HEIGHT VARIABLE INTO INTEGER POINTER HEIGHT
		DECLARE INTEGER VARIABLES LEFT_HEIGHT AND RIGHT_HEIGHT

		IF TREE IS NULL OR TREE->LEFT IS NULL AND TREE->RIGHT IS NULL THEN
			RETURN 0
		ELSE
			CALL ALGORITHM RECURSIVELY WITH TREE->LEFT
			CALL ALGORITHM RECURSIVELY WITH TREE->RIGHT
			RETURN THE VALUE RETURNED BY THE PREVIOUS TWO ALGORITHM CALLS + 1
		ENDIF
	STOP
*/

int ExternalNodes(bnode *tree)
{
	if(tree == (bnode *)NULL)
		return 0;
	else if((tree->left == (bnode *)NULL) && (tree->right == (bnode *)NULL))
		return 1;
	else
		return(ExternalNodes(tree->left) + ExternalNodes(tree->right));
}

/*
	ALGORITHM:
	START
		ACCEPT THE ADDRES OF THE PRESENT NODE INTO POINTER "TREE" AND ADDRESS OF HEIGHT VARIABLE INTO INTEGER POINTER HEIGHT
		DECLARE INTEGER VARIABLES LEFT_HEIGHT AND RIGHT_HEIGHT

		IF TREE IS NULL THEN
			RETURN 0
		ELSE IF TREE->LEFT IS NULL AND TREE->RIGHT IS NULL
			RETURN 1
		ELSE
			CALL ALGORITHM RECURSIVELY WITH TREE->LEFT
			CALL ALGORITHM RECURSIVELY WITH TREE->RIGHT
			RETURN THE VALUE RETURNED BY THE PREVIOUS TWO ALGORITHM CALLS
		ENDIF
	STOP
*/

void RemoveTree(bnode **tree)
{
	if(root == (bnode *)NULL)
	{	printf("\n\n\n\t\t\tTree empty. Cannot remove anything");
		getch();
		return;
	}
	if(*tree != (bnode *)NULL)  // REMOVE NODES ONE BY ONE IN POST ORDER MANNER
	{
		RemoveTree( &(*tree)->left);
		RemoveTree( &(*tree)->right);
		free(*tree);
	}
}

/*
	ALGORITHM:
	START
		ACCEPT THE ADDRES OF THE PRESENT NODE INTO POINTER "TREE"

		IF TREE IS NOT NULL THEN
			CALL ALGORITHM RECURSIVELY WITH TREE->LEFT
			CALL ALGORITHM RECURSIVELY WITH TREE->RIGHT
			DELETE THE NODE POINTED BY POINTER TREE
		ENDIF
	STOP
*/

bnode *SearchElement(bnode *tree,int value)
{
	if((tree->info == value) || (tree == (bnode *)NULL))  // IF NODE IS FOUND RETURN ITS ADDRESS OR RETURN NULL IF NODE IS NOT FOUND
		return tree;
	else if(value < (tree)->info)
		return SearchElement(tree->left, value);
	else
		return SearchElement(tree->right,value);
}

/*
	ALGORITHM:
	START
		ACCEPT THE ADDRES OF THE PRESENT NODE INTO POINTER "TREE" AND THE VALUE TO BE SEARCHED INTO VARIABLE "VALUE"

		IF TREE->INFO = VALUE OR TREE IS NULL THEN
			RETURN THE ADDRESS POINTED BY POINTER TREE
		ELSE IF VALUE < TREE->INFO THEN
			CALL ALGORITHM RECURSIVELY WITH TREE->LEFT AND VALUE
		ELSE
			CALL ALGORITHM RECURSIVELY WITH TREE->RIGHT AND VALUE
		ENDIF
	STOP
*/

void InsertElement(bnode **tree,int element)
{
	if(*tree == (bnode *)NULL)  // CREATING AND INSERTING A NODE AT THE NULL POINTER SO THAT ITS ADDRESS IS AUTOMATICALLY PUT IN ITS PARENT NODE'S APPROPRIATE POINTER
	{	*tree = (bnode *)malloc(sizeof(bnode));
		(*tree)->info = element;
		(*tree)->left = (*tree)->right = (bnode *)NULL;
	}
	else if(element < (*tree)->info)
		InsertElement(&((*tree)->left), element);
	else if(element > (*tree)->info)
		InsertElement(&((*tree)->right), element);
	else
		printf("\n\tDuplicate value not allowed.");
}

/*
	ALGORITHM:
	START
		ACCEPT THE ADDRES OF THE PRESENT NODE INTO POINTER "TREE" AND THE VALUE TO BE INSERTED INTO VARIABLE "VALUE"

		IF TREE IS NULL THEN
			CREATE A NEW NODE AND STORE THE ADDRESS OF THE NEW NODE INTO POINTER TREE
			SET TREE->INFO = ELEMENT
			SET TREE->LEFT = NULL
			SET TREE->RIGHT = NULL
		ELSE IF VALUE < TREE->INFO THEN
			CALL ALGORITHM RECURSIVELY WITH TREE->LEFT AND VALUE
		ELSE
			CALL ALGORITHM RECURSIVELY WITH TREE->RIGHT AND VALUE
		ENDIF
	STOP
*/

bnode *FindLargestNode(bnode *tree)  // THE RIGHTMOST NODE OF THE TREE IS ALWAYS THE LARGEST NODE
{
	if((tree == (bnode *)NULL) || (tree->right == (bnode *)NULL))
		return tree;
	else
		return FindLargestNode(tree->right);
}

/*
	ALGORITHM:
	START
		ACCEPT THE ADDRES OF THE PRESENT NODE INTO POINTER "TREE"

		IF TREE IS NULL OR TREE->RIGHT IS NULL THEN
			RETURN THE ADDRESS POINTED BY POINTER TREE
		ELSE
			CALL ALGORITHM RECURSIVELY WITH TREE->RIGHT
		ENDIF
	STOP
*/

bnode *FindSmallestNode(bnode *tree)  // THE LEFTMOST NODE OF THE TREE IS ALWAYS THE SMALLEST NODE
{
	if((tree == (bnode *)NULL) || (tree->left == (bnode *)NULL))
		return tree;
	else
		return FindSmallestNode(tree->left);
}

/*
	ALGORITHM:
	START
		ACCEPT THE ADDRES OF THE PRESENT NODE INTO POINTER "TREE"

		IF TREE IS NULL OR TREE->LEFT IS NULL THEN
			RETURN THE ADDRESS POINTED BY POINTER TREE
		ELSE
			CALL ALGORITHM RECURSIVELY WITH TREE->LEFT
		ENDIF
	STOP
*/

void DeleteNode(bnode **tree,int element)
{
	bnode *temp;
	if(*tree == (bnode *)NULL)
	{	printf("\n\n\n\t\t\tElement %d not found in BST",element);
		return;
	}
	else if(element < (*tree)->info)
		DeleteNode(&((*tree)->left), element);
	else if(element > (*tree)->info)
		DeleteNode(&((*tree)->right), element);
	else if((*tree)->left != NULL && (*tree)->right != NULL)  // WHEN MATCH IS FOUND
	{	temp = FindLargestNode((*tree)->left);  // IF IT IS A NODE HAVING BOTH SUBTREES, THEN REPLACE THE VALUE OF THE NODE TO BE DELETED WITH THE VALUE OF THE LARGEST NODE IN ITS LEFT SUBTREE, AND THEN DELETE THAT LARGEST NODE
		(*tree)->info = temp->info;
		DeleteNode(&((*tree)->left), temp->info);
	}
	else
	{	temp=*tree;
		if(((*tree)->left) == NULL) &&((*tree)->right) == NULL))  // IF BOTH THE SUBTREES ARE EMPTY, i.e. IT IS A LEAF NODE THEN PUT A NULL AT ITS PARENT NODE'S APPROPRIATE POINTER
			*tree = (bnode *)NULL;
		else if((*tree)->left) != NULL)  // ELSE, IF THE NODE HAS NO RIGHT SUBTREE, MOVE THE POINTER LEFT
			*tree = (*tree)->left;
		else  // ELSE, IF THE NODE HAS NO LEFT SUBTREE, MOVE THE POINTER RIGHT
			*tree = (*tree)->right;
		free(temp);
	}
}

/*
	THEORY OF DELETING A NODE FROM BINARY SEARCH TREE:
		IF THE NODE TO BE DELETED IS A LEAF NODE THEN
			1. SET NULL TO THE APPROPRIATE POINTER IN THE PARENT NODE
			2. DELETE THE NODE
		IF THE NODE TO BE DELETED HAS ONE SUBTREE THEN
			1. SET THE APPROPRIATE POINTER OF THE PARENT NODE TO THE NOT NULL POINTER OF THE NODE TO BE DELETED
			2. DELETE THE NODE
		IF THE NODE TO BE DELETED HAS BOTH SUBTREES
			1. FIND THE LARGEST VALUE IN THE LEFT SUBTREE OF THE NODE TO BE DELTED
			   (ALTERNATIVELY, FIND THE SMALLEST VALUE IN THE RIGHT SUBTREE)
			2. REPLACE THE VALUE OF THE NODE TO BE DELETED WITH THE FOUND VALUE
			3. DELETE THE LARGEST VALUE IN THE LEFT SUBTREE
			   (ALTERNATIVELY, THE SMALLEST VALUE IN THE RIGHT SUBTREE)
*/
/*
	ALGORITHM:
	START
		ACCEPT THE ADDRES OF THE PRESENT NODE INTO POINTER "TREE" AND THE VALUE TO BE SEARCHED INTO VARIABLE "VALUE"

		IF VALUE < TREE->INFO THEN
			CALL ALGORITHM RECURSIVELY WITH TREE->LEFT AND VALUE
		ELSE IF VALUE > TREE->INFO THEN
			CALL ALGORITHM RECURSIVELY WITH TREE->RIGHT AND VALUE
		ELSE
			IF THE NODE IS A LEAF NODE THEN
				SET NULL AT THE APPROPRIATE POINTER OF THE PARENT NODE
			ELSE IF THE NODE HAS ONLY ONE SUBTREE THEN
				SET THE APPROPRIATE POINTER OF THE PARENT NODE TO THE NOT NULL POINTER OF THE NODE TO BE DELETED
			ELSE
				FIND THE LARGEST NODE IN THE LEFT SUBTREE OF THE NODE TO BE DELETED
				REPLACE THE INFO OF THE NODE TO BE DELETED WITH THE FOUND VALUE
				RECURSIVELY CALL THE ALGORITHM AGAIN TO DELETE THE LARGEST NODE IN THE LEFT SUBTREE
			ENDIF
		ENDIF
	STOP
*/

void main()
{
	int choice,value,height=0;
	bnode *node;
	CreateTree(&root);
	while(1)
	{
		clrscr();
		printf("\n\n\n\n\t\tBINARY SEARCH TREE MENU");
		printf("\n\t\t***********************");
		printf("\n\t\t 1. Preorder Traversal");
		printf("\n\t\t 2. Inorder Traversal");
		printf("\n\t\t 3. Postorder Traversal");
		printf("\n\t\t 4. Determine Height");
		printf("\n\t\t 5. Total Nodes");
		printf("\n\t\t 6. Internal Nodes");
		printf("\n\t\t 7. External Nodes");
		printf("\n\t\t 8. Remove Tree");
		printf("\n\t\t 9. Search Element");
		printf("\n\t\t10. Insert Element");
		printf("\n\t\t11. Find Largest Node");
		printf("\n\t\t12. Find Smallest Node");
		printf("\n\t\t13. Delete Node");
		printf("\n\t\t14. Exit.");
		printf("\n\n\t\t\tEnter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case(1) : printf("\n\n");
				  PreordertraversalRecursive(root);
					break;
			case(2) : printf("\n\n");
				  InordertraversalRecursive(root);
					break;
			case(3) : printf("\n\n");
				  PostordertraversalRecursive(root);
					break;
			case(4) : DetermineHeight(root,&height);
					printf("\n\n\t\t\tThe height of the tree is %d",height);
					getch();
					break;
			case(5) : value=TotalNodes(root);
					printf("\n\n\t\t\tThe total number of nodes in the tree is %d",value);
					getch();
					break;
			case(6) : value = InternalNodes(root);
					printf("\n\n\t\t\tThe total number of internal nodes in the tree is %d",value);
					getch();
					break;
			case(7) : value = ExternalNodes(root);
					printf("\n\n\t\t\tThe total number of external nodes in the tree is %d",value);
					getch();
					break;
			case(8) : RemoveTree(&root);
					root = (bnode *)NULL;
					printf("\n\n\t\t\tThe tree is deleted.");
					getch();
					break;
			case(9) : printf("\n\n\t\t\tEnter the Element: ");
					scanf("%d",&value);
					node = SearchElement(root,value);
					if(node == (bnode *)NULL)  // IF NULL VALUE IS RETURNED THEN THE NODE DOES NOT EXIST
						printf("\n\n\t\t\tThe element is not found in the tree");
					else
						printf("\n\n\t\t\tThe element is found in the tree");
					break;
			case(10): printf("\n\n\t\t\tEnter the Element : ");
					 scanf("%d",&value);
					 InsertElement(&root,value);
					 break;
			case(11): node = FindLargestNode(root);
					printf("\n\n\t\t\tThe largest node in the tree is %d",node->info);
					getch();
					break;
			case(12): node = FindSmallestNode(root);
					printf("\n\n\t\t\tThe smallest node in the tree is %d",node->info);
					getch();
					break;
			case(13): printf("\n\n\t\t\tEnter the element to be deleted : ");
					scanf("%d",&value);
					fflush(stdin);
					DeleteNode(&root,value);
					break;
			case(14): printf("\n\n\t\t\tExiting.");
					getch();
					clrscr();
					exit(0);
		}
		getch();
	}
}