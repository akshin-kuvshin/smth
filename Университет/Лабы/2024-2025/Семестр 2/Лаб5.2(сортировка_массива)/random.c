#include "random.h"

#include <stdlib.h>

int random(int _min, int _max) {
    int raw_rand = (rand() << 15) + rand(); // потому что у меня RAND_MAX = 2^15 - 1,
                                            // а я хочу числа в большом диапазоне.
    return raw_rand % (_max - _min + 1) + _min;
}
