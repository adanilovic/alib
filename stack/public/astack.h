#ifndef _STACK_H_
#define _STACK_H_

#ifdef __cplusplus
extern "C" {
#endif // #ifdef __cplusplus

typedef struct Stack Stack;

int stack_init(Stack *astack);
void stack_destroy(Stack *astack);

#ifdef __cplusplus
}
#endif // #ifdef __cplusplus

#endif // #ifndef _STACK_H_
