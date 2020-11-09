#include <stdio.h>

int main()
{

    char a[] = "192.168.2.5";
    unsigned int ip = 0;
    unsigned char *p = (unsigned char *)&ip;
    int a1, a2, a3, a4;
    sscanf(a, "%d.%d.%d.%d", &a1, &a2, &a3, &a4);
    *p = a4;
    p++;
    *p = a3;
    p++;
    *p = a2;
    p++;
    *p = a1;
    printf("%u\n", ip);
    return 0;
}



