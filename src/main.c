#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "futhark.h"
#include "deps/flag/flag.h"

#define VERSION "v0.8.2"

int main(int argc, const char** argv) {

    bool phonetic = false;
    bool reverse = false;

    flag_bool(&phonetic, "phonetic", "Replace phonetic sounds such as th with ᚦ");
    flag_bool(&reverse, "reverse", "Convert Elder Futhark to Latin");
    flag_parse(argc, argv, VERSION);

    /**
     * Read from standard input
    */
    char* line = NULL;
    size_t linecap = 0;
    ssize_t linelen;
    while ((linelen = getline(&line, &linecap, stdin)) > 0) {
        char* translated = NULL;
        if (reverse) {
            translated = get_latin_for_futhark(line, phonetic);
        } else {
            translated = get_futhark_for_latin(line, phonetic);
        }
        fputs(translated, stdout);
    }

    return 0;
}
