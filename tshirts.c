#include <stdio.h>
#include <assert.h>

char size(int cms) {
    if (cms < 38) {
        return 'S';
    } else if (cms <= 42) {
        return 'M';
    } else {
        return 'L';
    }
}

int main() {
    assert(size(37) == 'S');
    assert(size(38) == 'M');
    assert(size(39) == 'M');
    assert(size(40) == 'M');
    assert(size(42) == 'M');
    assert(size(43) == 'L');
    assert(size(-1) == '\0'); 
    assert(size(0) == '\0'); 

    printf("All tests passed successfully!\n");
    return 0;
}
