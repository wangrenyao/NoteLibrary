#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "util.h"

void swap(int arr[], int i, int j)
{
	if (i != j) {
		int tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}
}



typedef void(*SORT_FUNC)(int arr[], int cnt);


typedef struct tagSortTestInfo {
	SORT_FUNC sort;
	char name[32];
	long time;
	bool fail;
} SortTestInfo;

SortTestInfo g_stSortTestInfo[32];
void init_test()
{
	srand(time(NULL));
	memset(g_stSortTestInfo, 0x00, sizeof(g_stSortTestInfo));
	add_test((SORT_FUNC)qsort, "qsort");
}


bool add_test(void (*sort)(int arr[], int cnt), const char *name)
{
	for (int i = 0; i < _countof(g_stSortTestInfo); i++) {
		if (g_stSortTestInfo[i].sort == NULL) {
			strcpy_s(g_stSortTestInfo[i].name, sizeof(g_stSortTestInfo[i].name), name);
			g_stSortTestInfo[i].sort = sort;
			g_stSortTestInfo[i].time = 0;
			g_stSortTestInfo[i].fail = false;
			return true;
		}
	}
	return false;
}
int cmp(const void *a, const void *b)
{
	return *(const int*)a - *(const int*)b;
}



void print_test_head()
{
	printf("%4s\t%8s", "id", "count");
	for (int i = 0; i < _countof(g_stSortTestInfo); i++) {
		if (g_stSortTestInfo[i].sort == NULL) {
			break;
		}
		printf("\t%8s", g_stSortTestInfo[i].name);
	}
	printf("\r\n");
}

void print_test_time(int idx, int count)
{
	printf("%4d\t%8d", idx, count);
	for (int i = 0; i < _countof(g_stSortTestInfo); i++) {
		if (g_stSortTestInfo[i].sort == NULL) {
			break;
		}
		if (g_stSortTestInfo[i].fail) {
			printf("\t%8s", "fail");
		}
		printf("\t%6ums", g_stSortTestInfo[i].time);
	}
	printf("\r\n");
}


static void run_one_test(int idx)
{
	int num = rand();
	int *data = (int*)malloc(num * sizeof(int));
	int *right = (int*)malloc(num * sizeof(int));
	int *tmpData = (int*)malloc(num * sizeof(int));
	for (int i = 0; i < num; i++) {
		data[i] = rand();
	}
	memcpy(right, data, num * sizeof(int));
	clock_t start = clock();
	qsort(right, num, sizeof(int), cmp);
	clock_t end = clock();
	
	g_stSortTestInfo[0].time = end - start;

	for (int i = 1; i < _countof(g_stSortTestInfo); i++) {
		if (g_stSortTestInfo[i].sort == NULL) {
			break;
		}
		memcpy(tmpData, data, num * sizeof(int));
		clock_t start = clock();
		g_stSortTestInfo[i].sort(tmpData, num);
		clock_t end = clock();
		g_stSortTestInfo[i].fail = false;
		if (memcmp(right, tmpData, num * sizeof(int)) != 0) {
			g_stSortTestInfo[i].fail = true;
		}
		g_stSortTestInfo[i].time = end - start;
	}
	print_test_time(idx, num);
	free(data);
	free(right);
	free(tmpData);
}


void run_test(int cnt)
{
	print_test_head();
	for (int i = 0; i < cnt; i++) {
		run_one_test(i);
	}
}