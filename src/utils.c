#include <stdlib.h>
#include <time.h>
#include "utils.h"

int nombre_random(int max) {
    static int initialized = 0;
    if (!initialized) {
        srand(time(NULL));
        initialized = 1;
    }
    return rand() % max;
} 