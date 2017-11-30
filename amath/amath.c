#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#include "amath.h"

bool will_mul_size_t_overflow(size_t a, size_t b) {
    return (a > (SIZE_MAX / b)) ? true : false;
}
