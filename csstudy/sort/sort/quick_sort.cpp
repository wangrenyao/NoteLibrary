#include "util.h"


void quick_sort(int arr[], int cnt)
{
	if (cnt <= 1) {
		return;
	}
	int tmp = arr[0];
	int left = 0;
	int right = cnt - 1;

	while (left < right) {
		while (left < right && arr[right] > tmp) {
			right--;
		}
		if (left < right) {
			arr[left++] = arr[right];
		}

		while (left < right && arr[left] < tmp) {
			left++;
		}
		if (left < right) {
			arr[right--] = arr[left];
		}
	}
	arr[left] = tmp;
	quick_sort(arr, left);
	quick_sort(arr + left + 1, cnt - left - 1);
}