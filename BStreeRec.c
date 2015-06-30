#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *rchild;
	struct node *lchild;
}*start=NULL,*root,*q,*new;

void build_tree(int,struct node *);
void inorder(struct node *);
void preorder(struct node *);
void postorder(struct node *);

main()
{
	int choice,n,k,another=1;
	do{
		printf("\n1:Build A Binary Search Tree\n2:Traversal\n3:Exit\n");
		scanf("%d",&choice);
		switch(choice)		
		{
			case 1:
				while(another!=2){
				printf("Enter A Number\t");
				scanf("%d",&n);
				build_tree(n,start);
				printf("Another nodes?\nEnter 1 for YES or 2 for NO :\t");
				scanf("%d",&another);
				}
				printf("Enter a Number:\t");
				scanf("%d",&n);
				build_tree(n,start);	
				break;
			case 2:
				printf("\nINORDER TRAVERSAL IS\n");				
				inorder(start);
				printf("\nPREORDER TRAVERSAL IS\n");
				preorder(start);
				printf("\nPOSTORDER TRAVERSAL IS\n");
				postorder(start);
				another=1;
				break;
			case 3:
				printf("\t........PROGRAM IS EXITING..........\n\n");
				exit(0);
				break;
			default:
				printf("Wrong Entry\nTRY AGAIN...\n");
		}
	}while(choice!=3);
}


void build_tree(int k,struct node *p)
{
	new=(struct node *)malloc(sizeof(struct node));
	new->data=k;
	new->lchild=NULL;
	new->rchild=NULL;
	if(start==NULL){
		start=new;
	}
			
	else if(k<p->data){
		if(p->lchild==NULL){
			p->lchild=new;
		}else{
		build_tree(k,p->lchild);
		}
	}
	else if(k>p->data){
		if(p->rchild==NULL){
			p->rchild=new;
		}else{
			build_tree(k,p->rchild);
		}
	}
	else{
		printf("Data Exists\n");
	}  
}
void inorder(struct node *p)
{
	if(start==NULL){
		printf("Tree Is Empty..\n");
		
	}
	else{
		if(p!=NULL){
			inorder(p->lchild);
			printf("%d-->",p->data);
			inorder(p->rchild);
		}
	}
}

void preorder(struct node *p)
{
	if(start==NULL){
		printf("Tree Is Empty..\n");
		}
	else{
		if(p!=NULL){
			
			printf("%d-->",p->data);
			preorder(p->lchild);
			preorder(p->rchild);
		}
	}

}

void postorder(struct node *p)
{
	if(start==NULL){
		printf("Tree Is Empty..\n");
		
	}
	else{
		if(p!=NULL){
			postorder(p->lchild);
			postorder(p->rchild);
			printf("%d-->",p->data);
			
		}
	}
}


