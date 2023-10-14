#include<iostream>
#include<malloc.h>
using namespace std;
///creating the structure
struct Node
{
	int data;
	Node *next;    //inter-referential pointer
};
Node *first , *temp , *ttemp , *p, *q, *r;    //global variable declaration

///initialization
void init()
{
	first=temp=ttemp = NULL;
}
void create_first(int x)
{
	//dynamic memory allocation at first pointer 
	first = (Node *)malloc(sizeof(Node));
	///adding first node 
	first->data=x;
	first->next=NULL;
}
///adding  other nodes 
void add_nodes(int x)
{
	temp=first;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	//creating  another memory location for  other nodes
	ttemp=(Node *)malloc(sizeof(Node));
	ttemp->data=x;
	ttemp->next= NULL;
	temp->next=ttemp;
}

////reverse the linked list
void reverse()
{
	p=first;
	q=p->next;
	r=q->next;
	while(q!=NULL)
	{
		q->next=p;
		p=q;
		q=r;
		if(r!=NULL)
		  r=r->next;	
	}	
	first->next=NULL;
	first=p;
}

//displaying the  linked list
void  disp()
{
	temp=first;
	while(temp!=NULL)
	{
		std::cout<<"\n"<<temp->data;
		temp=temp->next;
	}
}
///driver code
int main()
{
	init();
	create_first(10);
	add_nodes(20);
	add_nodes(30);
	add_nodes(40);
	add_nodes(50);
	add_nodes(60);
	add_nodes(70);
	add_nodes(80);
	add_nodes(90);
	disp();
	std::cout<<"\n\n after reversing ";
	reverse();
	disp();
}
