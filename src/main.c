#include <stdio.h>
#include "futhark.h"

int main(int argc, char * argv[]) {

    init_futhark();

    printf("%s \n", get_futhark_for_latin("z"));
    printf("%s \n", get_futhark_for_latin("x"));
    printf("%s \n", get_futhark_for_latin("a"));
    printf("%s \n", get_futhark_for_latin("ch"));

    deinit_futhark();

    return 0;
}
