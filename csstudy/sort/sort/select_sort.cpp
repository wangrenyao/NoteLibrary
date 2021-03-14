#include "util.h"

/*
选择排序：
使用两个循环，每次找出最大\小值的Idx，然后进行交换；
*/

void select_sort(int arr[], int cnt)
{
	for (int i = 0; i < cnt; i++) {
		int minIdx = i;
		for (int j = i + 1; j < cnt; j++) {
			if (arr[j] < arr[minIdx]) {
				minIdx = j;
			}
		}
		swap(arr, i, minIdx);
	}
}