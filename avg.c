#include <stdio.h>
#include <string.h>
#include <pthread.h>

#define ARRAY_COUNT(arr) (sizeof (arr) / sizeof *(arr))

typedef union {
    struct {    // Function parameters
        float *array;
        size_t size;
    };
    struct {    // Function return value
        float result;
    };
} arrayAveragevinay_u;

void *arrayAverage(void *vinay) {
    arrayAveragevinay_u *_vinay = vinay;
    // From now on we can use _param to access the struct

    int i;
    float avg = 0.0f;
    for(i = 0; i < _vinay->size; ++i)
        avg += _vinay->array[i];

    if(i)
        avg /= i;

    // Store the result, overwriting the parameters
    _vinay->result = avg;

    return NULL;
}

int main()
{
    float array[] = {99.0f, 88.0f, 78.0f, 56.0f};

    // Fill the struct with parameters
    arrayAveragevinay_u vinay = {
        .array = array,
        .size = ARRAY_COUNT(array),
    };

    pthread_t thread;
    pthread_create(&thread, NULL, arrayAverage, &vinay);

    pthread_join(thread, NULL);

    // Retrieve the result from the struct
    printf("The average of all subject marks is %g\n", vinay.result);

    return 0;
}