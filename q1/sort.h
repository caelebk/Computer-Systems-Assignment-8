#pragma once

// TODO 7: Add declaration of generic sort procedure by uncommenting next line and replacing ... with appropriate parameter(s)
void sort(void* list, int length, int* comp, void* swaptype);
int strcompare(void* list, int a, int b);
int intcompare(void* list, int a, int b);
void swapint(void*list, int a, int b);
void swapstr(void*list, int a, int b);
void test_sort();
