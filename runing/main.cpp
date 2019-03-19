#include <stdio.h>
#include <stdlib.h>

int main(){

    char buf[10] = "124";
    float f = atof(buf); //转换
    printf("%f\n", f);
    f = strtod(buf, NULL); //转换
    printf("%f\n", f);
    return 0;
}
