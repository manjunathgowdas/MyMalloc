#ifndef assignment1_h
#define assignment1_h

extern char *p;
extern int size;



 //free the block pointed to by the parameter

void print_book();
void allocate(int n);// prints bytes used by the bookkeeping structure
void myfree(void* d);
void display_mem_map();

void* mymalloc(int size);
#endif