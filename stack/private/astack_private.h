#ifndef _ASTACK_PRIVATE_H_
#define _ASTACK_PRIVATE_H_

#ifdef __cplusplus
extern "C" {
#endif // #ifdef __cplusplus

#include "astack.h"

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

typedef struct stack_frame_meta stack_frame_meta;

struct stack_frame_meta {
    void *data_p;
    size_t size_of_stack_frame_data;
};

struct Stack {
    stack_frame_meta *sf_p;
};

#ifdef __cplusplus
}
#endif // #ifdef __cplusplus

#endif // #ifndef _ASTACK_PRIVATE_H_
