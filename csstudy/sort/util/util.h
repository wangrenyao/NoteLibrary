#pragma once

#include <stdlib.h>
#include <string.h>

void swap(int arr[], int i, int j);

void run_test(int cnt);
void init_test();
bool add_test(void(*sort)(int arr[], int cnt), const char *name);