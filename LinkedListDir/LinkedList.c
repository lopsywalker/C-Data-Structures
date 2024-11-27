#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* Struct for individual linked list nodes */
typedef struct list_node 
{
/* Struct pointer needs to have explicit name */ 
struct list_node* next_node;
void *value_ptr;
char type[8];
bool head; 
} list_node_t;


/**
 * \brief Creates a new node for linked list
 * \param value The value being held by the list node
 * \param type The type of the value as a string
 */
struct list_node* new_list_node(void *value, char type[])
{
    /*
     If head does not exist, make new node head
     if head does exist move pointer
     change values of new nodes being made.
     */
    struct list_node* newNode = malloc(sizeof(list_node_t));
    newNode->value_ptr  = value;
    strncpy(newNode->type, type, sizeof(newNode->type));
    newNode->next_node = NULL;
    return newNode;
}

void make_head_node(struct list_node* head_node)
{
    head_node -> head = true;
}

/**
 * \brief Adds node to list linked to the given head pointer
 * \param head node head that you want to add a node to
 * \param append node that you want added to the list
 */
void add_to_list(struct list_node* head, struct list_node* append)
{
    if( head-> head)
    {
        if (head->next_node == NULL) 
        {
            head->next_node = append;
        }

        else
        {
            struct list_node* current_node = head; 
            while(current_node != NULL)
            {
                current_node = current_node->next_node;
            }
            current_node->next_node = append;
            append->next_node = NULL;
        }
    }    

    else
    {
        printf("Given head node is not head");
    }
}

/**
 * \brief Iterates through a listen give a node to start at
 * \param list_node The node to start from that it needs to iterate through
 */
void iterate(struct list_node* list_node)
{
    while(list_node != NULL) 
    {
        if(strcmp(list_node->type, "String") == 0) {
            char *stringP = (list_node->value_ptr);
            printf("%s\n", stringP);
        }

        else if(strcmp(list_node->type, "Integer") == 0) {
            int *intP = (list_node->value_ptr);
            printf("%d\n", *(intP));
        }

        else if(strcmp(list_node->type, "Double") == 0) {
            double *doubleP = (list_node->value_ptr);
            printf("%lf\n", *(doubleP));
        }

        else if(strcmp(list_node->type, "Float") == 0) {
            float *floatP = (list_node->value_ptr);
            printf("%f\n", *(floatP));
        }

        else {
            printf("Given type not found\n");
        }

        list_node = list_node->next_node;
    }
}

void remove_node(struct list_node *head_node, int index)
{
    int curr_index = 0;
    struct list_node *before_node = NULL;
    struct list_node *after_node = NULL; 
    if((head_node -> head) && (head_node->next_node == NULL) && (index == 0))
    {
        free(head_node);
        return;
    }


    else if(head_node -> head)
    {
        while(head_node -> next_node != NULL)
        {
            if(curr_index == (index-1))
            {
                before_node = head_node;
            }

            else if (curr_index == index)
            {
                after_node = head_node -> next_node;
                break;
            }

            curr_index++;
            head_node = head_node -> next_node;
        }

        if((before_node != NULL) && (after_node != NULL))
        {
            before_node -> next_node = after_node;
            free(head_node);
        }

        else if(after_node != NULL)
        {
            make_head_node(after_node);
            free(head_node);
        }
        
        else
        {
            before_node -> next_node = NULL;
            free(head_node);
        }

    }
}

int main()
{
// TODO:  convert to void in the first place
// TODO: delete Nodes

/* Sample node initialization */
int a = 5;
void * new_val = &a;

/* Sample node initialization */
int b = 3;
void * new_val2 = &b;

/* Sample node initialization */
int c = 4;
void * new_val3 = &c;

/* Sample node creation */
struct list_node* new_node = new_list_node(new_val, "Integer");
make_head_node(new_node);

/* Sample node creation */
struct list_node* new_node_1 = new_list_node(new_val2, "Integer");

struct list_node* new_node_2 = new_list_node(new_val3, "Integer");


/* Added to a new list */
add_to_list(new_node, new_node_1);
add_to_list(new_node, new_node_2);
// remove_node(new_node, 0);

/* Iterate through the list with given head node */
iterate(new_node);

return 0;
}