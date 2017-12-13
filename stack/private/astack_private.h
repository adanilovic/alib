#ifndef _ASTACK_PRIVATE_H_
#define _ASTACK_PRIVATE_H_

#ifdef __cplusplus
extern "C" {
#endif // #ifdef __cplusplus

#include "astack.h"
#include "alist.h"

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

struct Stack {
    List * alist;
};

#ifdef __cplusplus
}
#endif // #ifdef __cplusplus

#endif // #ifndef _ASTACK_PRIVATE_H_
