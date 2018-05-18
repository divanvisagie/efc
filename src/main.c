#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "futhark.h"
#include "deps/flag/flag.h"

#define VERSION "v0.2.0"

int main(int argc, const char** argv) {

    bool phonetics = false;

    flag_bool(&phonetics, "phonetics", "Should we convert phonetics like 'th'?");
    flag_parse(argc, argv, VERSION);

    /**
     * Read from standard input
    */
    char* line = NULL;
    size_t linecap = 0;
    ssize_t linelen;
    while ((linelen = getline(&line, &linecap, stdin)) > 0) {
        char* translated = get_futhark_for_latin(line, phonetics);
        printf("%s", translated);
    }

    return 0;
}
