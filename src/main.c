#include <stdio.h>
#include "futhark.h"
#include <stdbool.h>

int main(int argc, char * argv[]) {

    bool phonetics = true;

    printf("%s \n", get_futhark_for_latin("z", phonetics));
    printf("%s \n", get_futhark_for_latin("x", phonetics));
    printf("%s \n", get_futhark_for_latin("a", phonetics));
    printf("%s \n", get_futhark_for_latin("ch", phonetics));
    printf("%s \n", get_futhark_for_latin("the", phonetics));
    printf("%s \n", get_futhark_for_latin("Hello World", phonetics));


    return 0;
}
