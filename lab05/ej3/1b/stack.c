#include <stdlib.h>
#include <assert.h>
#include "stack.h"
 
 struct _s_stack{
        stack next;
        stack_elem elem;
        unsigned int size;
 };

/**
* @brief Creates an empty stack
* @return An empty stack
*/
stack stack_empty(){
    stack ns = NULL;
    return ns;
}

/**
* @brief Inserts an element at the top of the stack
* @param s A stack
* @param e An element to push into the stack
* @return The new stack with 'e' at the top
*/
stack stack_push(stack s, stack_elem e){
    stack ns =malloc(sizeof(struct _s_stack));
    if(s==NULL){
        ns->size=1;
    }else{
        ns->size=s->size+1;
    }
    ns->elem=e;
    ns->next=s;
    return ns;
}

/**
* @brief Removes the element at the top of the stack
* @param s A stack
* @return The new stack with the top element removed
* @note Only applies to non-empty stacks
*/
stack stack_pop(stack s){
    assert(!stack_is_empty(s));
    stack ns = s->next;
    free(s);
    return ns;
}

/**
* @brief Returns the size of the stack
* @param s A stack
* @return The size of the stack
*/
unsigned int stack_size(stack s){
    if(s==NULL){
        return 0;
    }else{
        return s->size;
    }
}

/**
* @brief Returns the element at the top of the stacks
* @param s A stacks
* @return The element at the top of the stack
* @note Only applies to non-empty stacks
*/
stack_elem stack_top(stack s){
    assert(!stack_is_empty(s));
    return s->elem;
}

/**
* @brief Check if the given stack is empty
* @param s A stack
* @return true if the stack is empty, false otherwise
*/
bool stack_is_empty(stack s){
    return s==NULL;
}

/**
* @brief Creates an array with all the elements of the stack
* @param s A stack
* @return An array containing all the elements of the stack. The stack top element
* becomes the rightmost element of the array. The size of the resulting
* array is determined by 'stack_size(s)'
*/
stack_elem *stack_to_array(stack s){
    stack_elem *array = NULL;
    array = calloc(stack_size(s),sizeof(stack_elem));
    stack p = s;
    for(unsigned int i=stack_size(s)-1;p!=NULL;i--){
        array[i]=p->elem;
        p=p->next;
    }
    return array;
}

/**
* @brief Destroys the stack
* @param s A stack
* @note All memory resources are freed
*/
stack stack_destroy(stack s){
    stack p;
    while (s != NULL){
        p = s;
        s = s->next;
        free(p);
    }
    return s;
}
