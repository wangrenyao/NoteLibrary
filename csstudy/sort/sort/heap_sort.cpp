#include "util.h"




void init_heap(int arr[], int parent, int len)
{
	int tmp = arr[parent];
	int childLeft = 2 * parent + 1;
	
	while (childLeft <= len) {
		int childSwap = childLeft;
		int childRight = childLeft + 1;
		if (childRight <= len && arr[childRight] > arr[childLeft]) {
			childSwap = childRight;
		}
		if (tmp > arr[childSwap]) {
			break;
		}
		arr[parent] = arr[childSwap];

		parent = childSwap;
		childLeft = 2 * parent + 1;
	}
	arr[parent] = tmp;
}



void heap_sort(int arr[], int cnt)
{
	for (int i = cnt - 1; i >= 0; i--) {
		init_heap(arr, i, cnt);
	}

	for (int i = cnt - 1; i >= 0; i--) {
		swap(arr, 0, i);
		init_heap(arr,0, i - 1);
	}
}