#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

// Complete the stringSimilarity function below.
long stringSimilarity(char* s) {
    int len = strlen(s);
    long *z_arr = malloc(len*sizeof(long));

    int L, R, k;
    L = R = 0;
    for (int i = 1; i < len; i++) {
        if (i > R) {
            L = R = i;
            while (R < len && s[R - L] == s[R]) {
                R++;
            }
            z_arr[i] = R - L;
            R--;
        }
        else {
            k = i - L;
            if (z_arr[k] < R - i + 1) {
                z_arr[i] = z_arr[k];
            }
            else {
                L = i;
                while (R < len && s[R - L] == s[R]) {
                    R++;
                }
                z_arr[i] = R - L;
                R--;
            }
        }
    }
    long similarities = len;
    for (int i = 1; i < len; i++) {
        similarities += z_arr[i];
    }
    return similarities;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* t_endptr;
    char* t_str = readline();
    int t = strtol(t_str, &t_endptr, 10);

    if (t_endptr == t_str || *t_endptr != '\0') { exit(EXIT_FAILURE); }

    for (int t_itr = 0; t_itr < t; t_itr++) {
        char* s = readline();

        long result = stringSimilarity(s);

        fprintf(fptr, "%ld\n", result);
    }

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}
