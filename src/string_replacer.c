#include "string_replacer.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <stdbool.h>


/**
 * Taken from https://www.geeksforgeeks.org/c-program-replace-word-text-another-given-word/
*/
char* replace(char* s, char* victim, char* with) {
    char *result;
    int i, cnt = 0;
    int withlen = strlen(with);
    int victimlen = strlen(victim);
 
    // Counting the number of times old word
    // occur in the string
    for (i = 0; s[i] != '\0'; i++) {
        if (strstr(&s[i], victim) == &s[i]) {
            cnt++;
 
            // Jumping to index after the old word.
            i += victimlen - 1;
        }
    }
 
    // Making new string of enough length
    result = (char *)malloc(i + cnt * (withlen - victimlen) + 1);
 
    i = 0;
    while (*s) {
        // compare the substring with the result
        if (strstr(s, victim) == s) {
            strcpy(&result[i], with);
            i += withlen;
            s += victimlen;
        }
        else {
            result[i++] = *s++;
        }
    }
 
    result[i] = '\0';
    return result;
}
