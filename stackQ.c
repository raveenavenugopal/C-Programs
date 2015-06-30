#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>

void push();
void display();
void pop();
void deq();

struct node
{
	int data;
	struct node *next;
}*start=NULL,*p,*q;

main()
{
	int choice,n;
	do{
		printf("\n\t1:Push\n\t2:Pop\n\t3:EnQ\n\t4:DeQ\n\t5:Exit\n");
		printf("\t\tEnter Your Choice:\t");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				push();
				display();
				break;
			case 2:
				pop();
				display();
				break;
			case 3:
				push();
				display();
				break;
			case 4:
				deq();
				display();
				break;
			case 5:
				printf("\n\t..........PROGRAM IS EXITING.......\n\n");
				exit(0);
				break;
			default:
				printf("\tWrong Choice\n\tTRY AGAIN.... :)\n");
			}
		}while(choice!=5);
}

void push()
{
	int k;
        struct node *new;
        new=(struct node *)malloc(sizeof(struct node));
        printf("\nEnter the element : ");
        scanf("%d",&k);
        new->data=k;
        new->next=NULL;
        if(start==NULL){
                start=new;
        }
        else{
                p=start;
                while(p->next!=NULL){
                        p=p->next;
                }
                p->next=new;
       }
}

void display()
{
        if(start==NULL){
                printf("\nNo elements in the list...\n");
        }
        else{
                printf("\nElements in the list are : ");
                p=start;
                while(p!=NULL){
                        printf("%d-->",p->data);
                        p=p->next;
                }
               
        }
}

void pop()
{
	int k;
	if(start==NULL){
		printf("\nPop is Not Possible");
	}
	else if(start->next==NULL){
		k=start->data;
		start=NULL;
		printf("\nElement deleted is\t%d",k);
	}
	else{
		p=start;
                while(p->next!=NULL){
			q=p;
                        p=p->next;
                }
                k=p->data;
		q->next=NULL;
       		printf("\nElement deleted is\t%d",k);
	}
}
void deq()
{
	int k;
	if(start==NULL){
		printf("\nDeque is not possible");
	}
	else{
		k=start->data;
		start=start->next;
		printf("\nElement deleted is\t%d",k);
	}
}
