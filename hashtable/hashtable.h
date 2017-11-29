#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_

#ifdef __cplusplus
extern "C" {
#endif // #ifdef __cplusplus

void hashtable_init();
int hashtable_insert(char c);
bool hashtable_get(char c);

#ifdef __cplusplus
}
#endif // #ifdef __cplusplus

#endif // #ifndef _HASHTABLE_H_
