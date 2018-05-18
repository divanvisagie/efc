#include <stdio.h>
#include <stdbool.h>

#include "futhark.h"
#include "deps/flag/flag.h"

#define VERSION "v0.2.0"

int main(int argc, const char** argv) {

    bool phonetics = false;


    flag_bool(&phonetics, "phonetics", "Should we convert phonetics like 'th'?");
    flag_parse(argc, argv, VERSION);

    printf("%s \n", get_futhark_for_latin("the", phonetics));


    return 0;
}
