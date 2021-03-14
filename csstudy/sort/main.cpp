#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "sort.h"

int main()
{
	init_test();
	add_test(select_sort, "ssort");
	add_test(bubble_sort, "bsort");
	add_test(insert_sort, "isort");
	add_test(insert_sort_op1, "isort1");
	add_test(insert_sort_op2, "isort2");
	add_test(heap_sort, "hsort");
	add_test(merge_sort, "msort");
	add_test(quick_sort, "qsort");
	run_test(20);
	return 0;
}