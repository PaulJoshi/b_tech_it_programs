/* Write a menu driven C program to implement a binary tree
and perform the following traversals on it
    (i) In-order
    (ii) Pre order
    (iii) Post-order */

#include<stdio.h>
#include<stdio.h>

struct binary {
	int data;
	struct binary *left, *right;
};

struct binary *insert(struct binary *,int);
void inorder(struct binary *);
void postorder(struct binary *);
void preorder(struct binary *);
struct binary *delet(struct binary *,int);
struct binary *search(struct binary *);
int main(void) {
	struct binary *root;
	int choice, item,item_no;
	root = NULL;
	/* rear  = NULL;*/
	do {
		do {
			printf("\n \t 1. Insert in binary tree  ");
			printf("\n\t 2. Delete from binary tree ");
			printf("\n\t 3. Inorder traversal of binary tree");
			printf("\n\t 4. Postorder traversal of binary tree");
			printf("\n\t 5. Preorder traversal of binary tree");
			printf("\n\t 6. Search and replace ");
			printf("\n\t 7. Exit ");
			printf("\n\t Enter choice : ");
			scanf(" %d",&choice);
			if(choice<1 || choice>7)
			      printf("\n Invalid choice - try again");
		}
		while (choice<1 || choice>7);
		switch(choice) {
			case 1:
				   printf("\n Enter new element: ");
			scanf("%d", &item);
			root= insert(root,item);
			printf("\n root is %d",root -> data);
			printf("\n Inorder traversal of binary tree is : ");
			inorder(root);
			break;
			case 2:
				  printf("\n Enter the element to be deleted : ");
			scanf(" %d",&item_no);
			root=delet(root,item_no);
			inorder(root);
			break;
			case 3:
				  printf("\n Inorder traversal of binary tree is : ");
			inorder(root);
			break;
			case 4:
				  printf("\n Postorder traversal of binary tree is : ");
			postorder(root);
			break;
			case 5:
				  printf("\n Preorder traversal of binary tree is : ");
			preorder(root);
			break;
			case 6:
				  printf("\n Search and replace operation in binary tree ");
			root=search(root);
			break;
			default:
				   printf("\n End of program ");
		}
		/* end of switch */
	}
	while(choice != 7);
	return(0);
}
struct binary *insert(struct binary *root, int x) {
	if(!root) {
		root=(struct binary*)malloc(sizeof(struct binary));
		root -> data = x;
		root -> left = NULL;
		root -> right = NULL;
		return(root);
	}
	if(root -> data > x)
	     root -> left = insert(root -> left,x); else {
		if(root -> data < x)
			root -> right = insert(root -> right,x);
	}
	return(root);
}
void inorder(struct binary *root) {
	if(root != NULL) {
		inorder(root -> left);
		printf(" %d",root -> data);
		inorder(root -> right);
	}
	return;
}
void postorder(struct binary *root) {
	if(root != NULL) {
		postorder(root -> left);
		postorder(root -> right);
		printf(" %d",root -> data);
	}
	return;
}
void preorder(struct binary *root) {
	if(root != NULL) {
		printf(" %d",root -> data);
		preorder(root -> left);
		preorder(root -> right);
	}
	return;
}

struct binary *delet(struct binary *ptr,int x) {
	struct binary *p1,*p2;
	if(!ptr) {
		printf("\n Node not found ");
		return(ptr);
	} else {
		if(ptr -> data < x) {
			ptr -> right = delet(ptr -> right,x);
			/*return(ptr);*/
		} else if (ptr -> data >x) {
			ptr -> left=delet(ptr -> left,x);
			return ptr;
		} else                     
		/* no. 2 else */ {
			if(ptr -> data == x)    
			/* no. 2 if */ {
				if(ptr -> left == ptr -> right) 
				/*i.e., a leaf node*/ {
					free(ptr);
					return(NULL);
				} else if(ptr -> left==NULL)  
				/* a right subbinary */ {
					p1=ptr -> right;
					free(ptr);
					return p1;
				} else if(ptr -> right==NULL)   
				/* a left subbinary */ {
					p1=ptr -> left;
					free(ptr);
					return p1;
				} else {
					p1=ptr -> right;
					p2=ptr -> right;
					while(p1 -> left != NULL)
						    p1=p1 -> left;
					p1 -> left=ptr -> left;
					free(ptr);
					return p2;
				}
			}
			/*end of no. 2 if */
		}
		/* end of no. 2 else */
		/* check which path to search for a given no. */
	}
	return(ptr);
}
/* function to search and replace an element in the binary binary */
struct binary *search(struct binary *root) {
	int no,i,ino;
	struct binary *ptr;
	ptr=root;
	printf("\n Enter the element to be searched :");
	scanf(" %d",&no);
	fflush(stdin);
	while(ptr) {
		if(no>ptr -> data)
		    ptr=ptr -> right; else if(no<ptr -> data)
		    ptr=ptr -> left; else
		    break;
	}
	if(ptr) {
		printf("\n Element %d which was searched is found and is = %d",no,ptr -> data);
		printf("\n Do you want replace it, press 1 for yes : ");
		scanf(" %d",&i);
		if(i==1) {
			printf("\n Enter new element :");
			scanf(" %d",&ino);
			ptr -> data=ino;
		} else
		    printf("\n\t It's okay");
	} else
	   printf("\n Element %d does not exist in the binary binary",no);
	return(root);
}