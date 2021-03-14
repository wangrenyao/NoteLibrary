#include "util.h"

/*
冒泡排序：
	对每一个元素，比较和他的下一个元素，如果大于，则进行交换；
*/

void bubble_sort(int arr[], int cnt)
{
	for (int i = cnt; i > 0; i--) {
		for (int j = 1; j < i; j++) {
			if (arr[j] < arr[j - 1]) {
				swap(arr, j, j - 1);
			}
		}
	}
}

/*
	优化一：已经有序的场景
*/
void bubble_sort_op1(int arr[], int cnt)
{
	for (int i = cnt; i > 0; i--) {
		bool sorted = true;
		for (int j = 1; j < i; j++) {
			if (arr[j] < arr[j - 1]) {
				swap(arr, j, j - 1);
				sorted = false;
			}
		}
		/* 从第0个元素扫描都没有需要交换的，下一轮扫描也是不需要交换 */
		/* 此时数据已经有序了，则退出扫描 */
		if (sorted == true) {
			break;
		}
	}
}

/* 
	优化二：针对部分有序的场景
*/
void bubble_sort_op2(int arr[], int cnt)
{
	for (int i = cnt; i > 0; i--) {
		int sorted = 0;
		for (int j = 1; j < i; j++) {
			if (arr[j] < arr[j - 1]) {
				swap(arr, j, j - 1);
				sorted = j;
			}
		}
		/* 考虑数据： 1 3 2 0 6 7 8 9 */
		/* 这一轮需要交换的是数据0，后面的不需要交换，那么可以减少需要更新的轮次 */
		i = sorted;
	}
}