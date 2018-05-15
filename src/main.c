#include <stdio.h>
#include "futhark.h"

int main(int argc, char * argv[]) {

    printf("%s \n", get_futhark_for_latin("z"));
    printf("%s \n", get_futhark_for_latin("x"));
    printf("%s \n", get_futhark_for_latin("a"));
    printf("%s \n", get_futhark_for_latin("ch"));
    printf("%s \n", get_futhark_for_latin("Hello World"));


    return 0;
}
