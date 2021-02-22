#include <stdlib.h>
#include "integer_list.h"
#include "sort.h"


/*** Types ***/

struct il_list {
    // TODO 4
    int * x;
    int size;
    int numitems;
};

struct il_iterator {
    // TODO 5
    struct il_list* list;
    int index;
};



/*** Private procedures ***/


/**
 * Compare data[a] and data[b], return -1 if data[a] is smaller, 1 if it is larger, and 0 if they are equal
 */

static int compare(void* datav, int a, int b) {
    // TODO 8
    int * intlist = datav;
    return intlist[a] - intlist[b];
}


/**
 * Swap data[a] and data[b]
 */

static void swap(void* datav, int a, int b) {
    // TODO 8
    int * intlist = datav;
    int t = intlist[a];
    intlist[a] = intlist[b];
    intlist[b] = t;
}



/*** Public procedures for Integer List ***/


/**
 * Create and initialize a new list
 */

struct il_list* il_new(int size) {
    // TODO 4
    struct il_list* intlist = malloc(sizeof(*intlist));
    intlist->size = size;
    intlist->numitems = 0;
    intlist->x = malloc(sizeof(size));
    return intlist;
}


/**
 * Delete list
 */

void il_delete(struct il_list* list) {
    // TODO 4
    free(list->x);
    free(list);
}


/**
 * Add value to end of list
 */

void il_add(struct il_list* list, int value) {
    // TODO 4
    if(list->numitems == list->size)
        return;
    /*if(value > 1000 || value < -1000)  
        return;*/
    list->x[list->numitems] = value;
    list->numitems++;
}


/**
 * Sort list in ascending order by value
 */

void il_sort(struct il_list* list) {
    // TODO 8
    sort(list->x, list->numitems, compare, swap);
}



/*** Public procedures for Integer List Iterator ***/


/**
 * Create and initialize iterator for list
 */

void* il_iterator(void* listv) {
    // TODO 5
    struct il_list* list = listv;
    struct il_iterator* iterator = malloc(sizeof(*iterator));
    iterator->list = list;
    iterator->index = 0;
    return iterator;
}


/**
 * Return TRUE iff iterator has more values to produce
 */

int il_has_next(void* iteratorv) {
    // TODO 5
    struct il_iterator* iterator = iteratorv;
    //printf("%d index\n", iterator->index);
    //printf("%d numitems\n", iterator->list->numitems);
    return (iterator->index < (iterator->list->numitems)) && (iterator->index > -1); // PLACEHOLDER
}


/**
 * Get pointer to next value in iteration and advance interator's cursor
 */

void* il_get_next(void* iteratorv) {
    // TODO 5
    struct il_iterator* iterator = iteratorv;
    if(il_has_next(iteratorv)){
        void * elem = iterator->list->x + iterator->index;
        iterator->index++;
        return elem;
    }
    return NULL; // PLACEHOLDER
}


/**
 * Delete iterator
 */
void il_delete_iterator(void* iteratorv) {
    // TODO 5
    struct il_iterator* iterator = iteratorv;
    free(iterator);
}