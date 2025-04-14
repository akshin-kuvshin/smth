#include "random.h"

#include <stdlib.h>

int random(int _min, int _max) {
    return rand() % (_max - _min + 1) + _min;
}
