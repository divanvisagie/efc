#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

const int TABLE_SIZE = 30;

int hash_string(const char* s) {
    unsigned long int hashval;
    int i = 0;

    while(hashval < ULONG_MAX && i < strlen(s)) {
        hashval = hashval << 8;
        hashval += s[i];
        i++;
    }
    
    return hashval % TABLE_SIZE;
}
