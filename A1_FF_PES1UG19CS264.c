#include<stdio.h>
#include<stdlib.h>
#include"assignment_1.h"
char *p;
int size;

typedef struct bookkeeping      //bookkeeping structure
{
int len;						//to store the size of the block allocated
int flag;						// stores 1 for free block or 0 for allocated block
struct bookkeeping *next;		// pointer to point to the next metablock(free or allocated)
}node;
node *freelist;					
long int size_of_structure=sizeof(node); //Stores the size of the bookkeeping  structure

static void init(int n)  //function to initialize the bookeeping structure
{
	freelist=(void*)p;  
	
	freelist->len=n-size_of_structure;
	freelist->flag=1;
	freelist->next=NULL;
	


}
void allocate(int n)  //function to allocate n bytes 
{
	
	size=n;
	p=(char*)malloc(sizeof(char)*n);
	init(n);
}
void* mymalloc(int size) //function to allocate 'size' bits
{
	node *ft;
	ft=freelist;

	while(ft&&((ft->flag==0)||(ft->len<size))) //To find the free block present in the linked list
	{
		
		ft=ft->next;
	}
	if(!ft) // if not found then return null
	{
	return NULL;
	}
	else if(ft->len==size || ft->len-size<=size_of_structure) //if the free size of the block is equal to the required block or if the remaining space after allocation is less than or equal to  the size of bookkeeping structure 
	{
		ft->flag=0;           
		return (void*)++ft;      //returns the address of the whole free block itself
	}
	else 
	{
		
	node *new=(void*)((void*)ft+size+size_of_structure); //new block is created of 'size' + 'size_of_structure' bits
	new->next=ft->next; //new block links to the block which was linked by the free block
	ft->next=new; 
	ft->flag=0;
	new->len=ft->len-size-size_of_structure; //new block holds the remaining space in the memory(array)
	ft->len=size; 
	new->flag=1;
	
	return (void*)++ft; //return the address of allocated block

	}
}
void myfree(void *b)
{
	
	node *curr,*delete;
	delete=b;
	--delete;//after decrementing the 'delete' pointer ,It points to the bookkeeping structure 
	curr=freelist; //points to the head of the linkedlist
	while(curr && curr!=delete) //To filter out the invalid pointers
	{
		curr=curr->next;
	}
	if(curr==NULL) //if the pointer is invalid  return NULL
		return;
	curr->flag=1; //mark the block as free
	curr=freelist; 
	while(curr->next) //block to check if any adjacent free blocks are present
	{
		if(curr->flag && curr->next->flag)//if present 
			{
				curr->len=curr->len+curr->next->len+size_of_structure; //new size is equal to the sum of first block size,second block size and size of the bookkeeping structure of the second block
				curr->next=curr->next->next; //removes the second block and links to the block present next to  the  second block
			}
		else
				curr=curr->next; 
	}
}
void print_book()
{
	printf("%ld",size_of_structure);
}
void display_mem_map()
{
	node *ft;
	ft=freelist;
	int count=0; //to store the starting address of each block
	while(ft)
	{
		printf("%d\t%ld\t%d\n",count,size_of_structure,0);
		count+=size_of_structure;
		if(!ft->flag) // if the block is allocated block
		printf("%d\t%d\t%d\n",count,ft->len,1);
		else
		printf("%d\t%d\t%d\n",count,ft->len,2);
		count+=ft->len;
		ft=ft->next;
	}
}

