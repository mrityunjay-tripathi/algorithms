#include<stdio.h>

void bubble_sort(int arr[], int n)
{
	int i,j,t;
	for(i=0;i<n;++i)
	{
		for(j=i+1;j<n;++j)
		{
			if(arr[i]>arr[j])
			{
				t = arr[i];
				arr[i] = arr[j];
				arr[j] = t;
			}
		}
	}
}

void display(int arr[], int n)
{
	int i;
	printf("Sorted array : ");
	for(i=0;i<n;++i)
		printf("%d ", arr[i]);
	printf("\n");
}

int main()
{
	int n, i;
	printf("Enter the number of elements : ");
	scanf("%d", &n);
	
	int arr[n];
	printf("Enter the elements : ");
	for(i=0;i<n;++i)
	{
		scanf("%d", &arr[i]);
	}
	bubble_sort(arr, n);
	display(arr, n);
}
