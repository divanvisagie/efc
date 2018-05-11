#include <string.h>
#include <wchar.h>

const char* fehu = "ᚠ";
const char* uruz = "ᚢ";


int get_unicode(char character) {
    return (int) character;
}


int main(int argc, char ** argv) {

    printf("%d \n", get_unicode('a'));
    printf("%d \n", get_unicode('b'));
    printf("%d \n", get_unicode('c'));

    printf("%s \n", fehu);
    printf("%s \n", uruz);

    return 0;
}
