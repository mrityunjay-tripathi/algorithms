#include<stdio.h>
#include<stdlib.h>
#define MAX 100

// create a node structure having 'data' and 'pointer to next node' columns.
struct node
{
	int data;
	struct node *next;
};


// create a function for new node
struct node *newNode(int val)
{
	struct node *ptr = (struct node *)malloc(sizeof(struct node));
	ptr->data = val;
	ptr->next = NULL;
	return ptr;
}

// create hash structure having room for linked list.
struct hash
{
	struct node *next; // next is a pointer to next element of chain.
} 
hash_table[MAX]; // create a hash table having (say) 100 rows.


// function to insert values at some row in the hash table.
// the row can have multiple values.
struct hash insert(struct hash h, int val) // h is hash_table[i]. i.e. ith row of hash table
{
	if (!h.next) // if that particular row of hash table don't have any element
	{
		h.next = newNode(val); // create new node and assign it as first node
		                       // of that row of hash table
	}
	else // insert the new node at first position.
	{
		struct node *temp = newNode(val);
		temp->next = h.next;
		h.next = temp;
	}
	return h; // return the same row of hash table.
}

// display function to display possibly multiple values in same row of hash table.
void display(struct hash h)
{
	struct node *temp = h.next;
	while(temp->next!=NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("%d\n", temp->data);
}

// search function to find elements
int search(struct hash h[], int value, int n) // h[] means complete hash table
{
	// first find the key of value using hash function.
	int k = key(value, n);
	if(k>MAX-1)
		return 0;
	
	// search iteratively kth row of hash table.
	struct node *temp = h[k].next;
	while(temp->next!=NULL)
	{
		if(temp->data == value)
			return k;
		temp = temp->next;
	}
	// since the last element is still left to be checked
	// so check on it also.
	if(temp->data == value)
		return k;
	return 0;
}

// The function to generate key values.
// you can experiment here different hash functions.
// for simplicity I used modulo function.
int key(int x, int n)
{
	return x%n;
}

int main()
{
	int i,k;

	int n, t;
	printf("Enter the number of elements : ");
	scanf("%d", &n);	
	
	printf("Enter the elements : ");
	for(i=0;i<n;++i)
	{
		scanf("%d", &t);
		k = key(t, 12);
		if(k<MAX)
			hash_table[k] = insert(hash_table[k], t);
		else
			printf("Hash Table Overflow: Value dropped!");
	}
	
	printf("Hash Table Content : \n");
	printf("Key\tValue\n");
	for(i=0;i<12;++i)
	{
		printf("%3d\t", i);
		if(hash_table[i].next!=NULL)
		{
			display(hash_table[i]);
		}
		else
			printf("--\n");		
	}
	
	int x;
	printf("\nEnter the element to be searched : ");
	scanf("%d", &x);
	int search_key = search(hash_table, x, 12);
	if(search_key)
		printf("Successful : Element %d found with key %d.\n", x, search_key);
	else
		printf("Error: Couldn't find %d\n", x);
}






