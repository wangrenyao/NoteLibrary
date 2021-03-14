#include "util.h"



void merge(int left[], int lcnt, int right[], int rcnt, int tmp[])
{
	int idx = 0;
	int l = 0;
	int r = 0;
	memcpy(tmp, left, sizeof(int) * lcnt);
	while (l < lcnt && r < rcnt) {
		if (tmp[l] < right[r]) {
			left[idx++] = tmp[l++];
		}
		else {
			left[idx++] = right[r++];
		}
	}
	while (l < lcnt) {
		left[idx++] = tmp[l++];
	}
	while (r < rcnt) {
		left[idx++] = right[r++];
	}
}

void merge_sort_kernel(int arr[], int cnt, int tmp[])
{
	if (cnt <= 1) {
		return;
	}

	int mid = cnt / 2;
	int *left = arr;
	int *right = arr + mid;

	merge_sort_kernel(left, mid, tmp);
	merge_sort_kernel(right, cnt - mid, tmp);
	merge(left, mid, right, cnt - mid, tmp);
}

void merge_sort(int arr[], int cnt)
{
	int *tmp = (int*)malloc(sizeof(int) * cnt);
	merge_sort_kernel(arr, cnt, tmp);
	free(tmp);
}