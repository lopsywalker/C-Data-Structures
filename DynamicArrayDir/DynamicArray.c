#include <stdio.h>
#include <stdlib.h>

typedef struct dynamic_array {
int size;
void *arr_pointer;
// TODO: arr_pointer can be changed when resizing
} dynamic_array;

struct dynamic_array initialize_dynamic_arr() {
struct dynamic_array *dynamic_arr_ptr = malloc(8);
void *void_arr[8];
struct dynamic_array dynamic_arr = {.size = 0, .arr_pointer = &void_arr};
return dynamic_arr;
}

int main() {

struct dynamic_array dyn_arr = initialize_dynamic_arr();
printf("%d\n", dyn_arr.size);

return 0;
}

