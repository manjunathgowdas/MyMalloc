# MyMalloc

ALLOCATION POLICY USED :
	 FIRST FIT

BOOKKEEPING STRUCTURE:
	An integer variable to store the size of allocated/free memory
	An integer variable to store the state of the block i.e stores 0 for allocated block or 1 for free block 
	A pointer which points to the next bookkeeping structure

I have used linked list data structure to store the bookkeeping structure

LOGIC USED IN MYMALLOC FUNCTION
     ->	The first step is to traverse the entire linked list  until  the first  free block of size greater than or equal to 	required size is found.
     ->	If not found just return null.
     ->	If the size of the  free block found is equal to the size required or if the remaining size after allocation is 	less than or equal to  the size of bookkeeping structure ,return the address of the block itself
    ->if enough space is present to store the bookkeeping structure ,Create a new node which holds the 
	remaining size and make the free node found as allocated and modify its size to the required size and
	return the address of the first element by incrementing the pointer

LOGIC USED IN MYFREE FUNCTION:
     ->traverse through the entire linked list to check the validity of the received pointer 
     ->Then mark the allocated block as free.
     ->Check for adjacent free block .If present,Merge the free blocks
 
LOGIC USED IN DISPLAY_MEM_MAP FUNCTION
     ->An integer variable to store the starting address of each block.
     ->After printing the  address of bookkeeping structure ,the variable is updated with the size of the 	bookkeeping      structure
     ->After printing the the address of allocated or free block ,the variable is updated with size of the block
   
Use of init function
  	-> It initialises the bookkeeping structure 	after allocating the character array
