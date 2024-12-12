#include <stdio.h>
#include <stdlib.h>

typedef struct dynamic_array {
int size;
int num_of_elems;
int *arr_pointer;
} dynamic_array;

dynamic_array initialize_dynamic_arr() {
int *dynamic_arr_ptr = (int *) calloc(1, sizeof(int *));
dynamic_array dynamic_arr = {.size = 1, .num_of_elems = 0, .arr_pointer = dynamic_arr_ptr};
return dynamic_arr;
}

// Appending new element to array
void append_array_element(dynamic_array *appending_arr, int appending_elem) {
if(appending_arr->size <= appending_arr->num_of_elems ) {
    int *new_ptr = (int *) realloc(appending_arr->arr_pointer, appending_arr->size*2);
    appending_arr->size = 2 * appending_arr->size;
    appending_arr->arr_pointer = new_ptr;
    new_ptr[appending_arr->num_of_elems] = appending_elem;
    appending_arr->num_of_elems = appending_arr->num_of_elems+1;
    return;
}
    
appending_arr->arr_pointer[appending_arr->num_of_elems] = appending_elem;
appending_arr->num_of_elems = appending_arr->num_of_elems+1;
}

// Size getter
int get_num_of_elems(dynamic_array *dynamic_arr) {
return dynamic_arr->num_of_elems;
}

// Element removal 
void remove_elem(dynamic_array *dynamic_array) {
}


int main() {

struct dynamic_array dyn_arr = initialize_dynamic_arr();

append_array_element(&dyn_arr, 3);

printf("%d, %d\n", get_num_of_elems(dyn_arr), dyn_arr.size);

return 0;
}

