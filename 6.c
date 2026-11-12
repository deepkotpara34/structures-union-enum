
// Unions
#include <stdio.h>
#include <string.h>

// Union definition
typedef union {
    int i;
    float f;
    char str[20];
} UnionData;

// Structure definition
typedef struct {
    int i;
    float f;
    char str[20];
} StructData;

int main() {

    UnionData udata;
    StructData sdata;

    // Assign values to structure
    sdata.i = 10;
    sdata.f = 220.5f;
    strcpy(sdata.str, "Struct Programming");

    // Assign and display union integer
    udata.i = 10;
    printf("Union Integer: %d\n", udata.i);

    // Assign and display union string
    strcpy(udata.str, "Union Programming");
    printf("Union String: %s\n", udata.str);

    // Assign and display union float
    udata.f = 220.5f;
    printf("Union Float: %.2f\n", udata.f);

    // Display current active union member
    printf("\nAfter overwriting:\n");
    printf("Union Float: %.2f\n", udata.f);

    // Memory addresses of union members
    printf("\nMemory Addresses - Union:\n");
    printf("udata.i:   %p\n", (void *)&udata.i);
    printf("udata.str: %p\n", (void *)&udata.str);
    printf("udata.f:   %p\n", (void *)&udata.f);

    // Memory addresses of structure members
    printf("\nMemory Addresses - Structure:\n");
    printf("sdata.i:   %p\n", (void *)&sdata.i);
    printf("sdata.str: %p\n", (void *)&sdata.str);
    printf("sdata.f:   %p\n", (void *)&sdata.f);

    // Display memory sizes
    printf("\nSize of Union: %zu bytes\n",
           sizeof(UnionData));

    printf("Size of Structure: %zu bytes\n",
           sizeof(StructData));

    return 0;
}
