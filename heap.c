#include<stdio.h>
#define MAX 50


void max_heapify(int heap[], int n, int i)
{
	int largest = i, l = 2*i+1, r = 2*i+2;
	int t;
	
	if(l<n && heap[l]>heap[largest])
		largest = l;
	
	if(r<n && heap[r]>heap[largest])
		largest = r;
	
	if(largest!=i)
	{
		t = heap[i];
		heap[i] = heap[largest];
		heap[largest] = t;
		
		max_heapify(heap, n, largest);
	}
}

void build_max_heap(int heap[], int n)
{
	int i;
	for(i=n/2-1;i>-1;--i)
	{
		max_heapify(heap, n, i);
	}
}

int *heap_sort(int heap[], int n, int is_heapified)
{
	if(!is_heapified)
	{
		build_max_heap(heap, n);
	}
	
	int i, t;
	static int sorted_arr[MAX];
	for(i=n-1;i>-1;--i)
	{
		sorted_arr[n-1-i] = heap[0];
		//printf("%d ", heap[0]);
		t = heap[0];
		heap[0] = heap[i];
		heap[i] = t;
		
		max_heapify(heap, i, 0);
	}
	
	return sorted_arr;
}

void display(int heap[], int n)
{
	int i;
	for(i=0;i<n;++i)
		printf("%d ", heap[i]);
}


int main()
{
	int heap[MAX], n, i;
	printf("Enter the number of nodes in heap : ");
	scanf("%d", &n);
	
	printf("Enter the elements : ");
	for(i = 0; i<n; ++i)
		scanf("%d", &heap[i]);
	
	
	build_max_heap(heap, n);
	printf("Max Heap : ");
	display(heap, n);
	
	printf("\nSorted Heap : ");
	int *ptr = heap_sort(heap, n, 1);
	for(i=0;i<n;++i)
		printf("%d ", ptr[i]);
	
}
