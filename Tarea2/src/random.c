
#include <random.h>
#include <stdlib.h>
#include <time.h>

void initialize_random(void) {
    srand((unsigned int)time(NULL));
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int generate_random_between(int min, int max)  {
    if (min > max) {
        swap(&min, &max);
    }
    int rd_num = rand() % (max - min + 1) + min;
    if (rd_num < min || rd_num > max) {
        rd_num = (rd_num < min) ? min : max;
    }
    return rd_num;
}