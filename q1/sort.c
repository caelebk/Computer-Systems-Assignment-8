#include <stdio.h>
#include <string.h>
#include "sort.h"


int compare(void* list, int a, int b, int* comp (void* l, int x, int y)) {
    return comp (list, a, b);
}

void swap(void* list, int a, int b, void* swaptype (void* l, int x, int y)) {
    swaptype(list, a, b);
    /*
    char* t = list[a];
    list[a] = list[b];
    list[b] = t;*/
}
void swapint(void*list, int a, int b) {
    int * intlist = list;
    int t = intlist[a];
    intlist[a] = intlist[b];
    intlist[b] = t;
}
void swapstr(void*list, int a, int b) {
    char** strlist = list;
    char* t = strlist[a];
    strlist[a] = strlist[b];
    strlist[b] = t;
}

// TODO 7: Change this procedure sort generic arrays (i.e., arrays of any type) 
//         by replacing char** with void* and adding function pointer parameters.
//         Update test_sort to use the new sort to sort 
//             (a) this arrays of strings; AND
//             (b) an array of integers (this will help you with TODO 9)
//         See also TODO 8 in sort.h
void sort(void* list, int length, int* comp, void* swaptype) {
    for (int i = 0; i < length; i++)
        for (int j = i + 1; j < length; j++)
            if (compare(list, i, j, comp) > 0) 
                swap(list, i, j, swaptype);
}

int strcompare(void* list, int a, int b){
    char** strlist = list;
    return strcmp(strlist[a], strlist[b]);
}
int intcompare(void* list, int a, int b){
    int * intlist = list;
    return intlist[a] - intlist[b];
}

void test_sort() {
    char* list[] = {"Cat", "Elephant", "Dog", "Lion", "Zebra", "Ape"};
    sort (list, 6, strcompare, swapstr);
    for (int i = 0; i < 6; i++)
        printf("%s\n", list[i]);
}
void test_sort2() {
    int list[] = {8, 3, 2, 1, 5, 6};
    sort (list, 6, intcompare, swapint);
    for (int i = 0; i < 6; i++)
        printf("%d\n", list[i]);
}

