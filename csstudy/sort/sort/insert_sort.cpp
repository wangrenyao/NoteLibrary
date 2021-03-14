#include "util.h"


/*
插入排序：
	对于后续的每个元素，找到对应的位置后，将元素整体后移；

*/

void insert_sort(int arr[], int cnt)
{
	for (int i = 1; i < cnt; i++) {
		for (int j = i; j >= 1; j--) {
			if (arr[j] < arr[j - 1]) {
				swap(arr, j, j - 1);
			}
		}
	}
}

/*
优化思路：
每一个交换是不划算的，可以先备份值，向后挪到直到找到位置：
*/
void insert_sort_op1(int arr[], int cnt)
{
	for (int i = 1; i < cnt; i++) {
		int tmp = arr[i];
		int j = i;
		for (; j >= 1; j--) {
			if (tmp < arr[j - 1]) {
				arr[j] = arr[j - 1];
				continue;
			}
			break;
		}
		arr[j] = tmp;
	}
}


/*
优化思路：
找到插入可以使用二分查找的思想
*/

int binary_search2(int arr[], int i, int j, int val)
{
	while (i < j) {
		int mid = (i + j) / 2;
		if (val < arr[mid]) {
			j = mid;
		} else {
			i = mid + 1;
		}
	}
	return i;
}

int binary_search(int arr[], int i, int j, int val)
{
	/* [i, j] 的场景，左闭右闭 */
	j--;
	while (i <= j) {
		int mid = (i + j) / 2;
		if (val < arr[mid]) {
			j = mid - 1;
		}
		else {
			i = mid + 1;
		}
	}
	return i;
}

void insert_sort_op2(int arr[], int cnt)
{
	for (int i = 1; i < cnt; i++) {
		if (arr[i] >= arr[i - 1]) {
			continue;
		}
		int idx = binary_search(arr, 0, i, arr[i]);
		int tmp = arr[i];
		for (int j = i; j > idx; j--) {
			arr[j] = arr[j - 1];
		}
		arr[idx] = tmp;
	}
}