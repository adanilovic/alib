#ifndef _ASTACK_H_
#define _ASTACK_H_

#ifdef __cplusplus
extern "C" {
#endif // #ifdef __cplusplus

typedef struct Stack Stack;

Stack * stack_init();
int stack_push(Stack *astack);
void * stack_pop();
void stack_destroy(Stack *astack);

#ifdef __cplusplus
}
#endif // #ifdef __cplusplus

#endif // #ifndef _ASTACK_H_
