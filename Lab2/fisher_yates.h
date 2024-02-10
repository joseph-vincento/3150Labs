#ifndef _FISHER_YATES_
#define _FISHER_YATES_

void fisher_yates_shuffle(int* arr, int length, int (*random_function)());
void swap(int* x, int* y);

#endif