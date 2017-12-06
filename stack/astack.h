#ifndef _STACK_H_
#define _STACK_H_

#ifdef __cplusplus
extern "C" {
#endif // #ifdef __cplusplus

/*
|-----------------------|
|Frame 1                |
|Frame mata data        | 
|Frame data             | 
|-----------------------| 
|Frame 2                |
|Frame mata data        | 
|Frame data             | 
|-----------------------| 
*/

typedef struct {
    void *data_p;
    size_t size_of_stack_frame_data;
} stack_frame_meta;

typedef struct {
    stack_frame_meta *sf_p;
} Stack;

int stack_init(Stack *astack);
void stack_destroy(Stack *astack);

#ifdef __cplusplus
}
#endif // #ifdef __cplusplus

#endif // #ifndef _STACK_H_
