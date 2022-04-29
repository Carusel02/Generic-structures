#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

// structura tip head (are 8 bytes)
typedef struct head
{   unsigned char type; // (ocupa 4 bytes si se foloseste de primul)
    unsigned int len; // (ocupa si foloseste 4 bytes)
} head;

// structura tip data_structure
typedef struct data_structure
{   head *header; // (structura de 8 bytes)
    void *data; // (structura de dimensiune variabila)
} data_structure;

int main() {
    data_structure elem;
        printf(" SIZE %zu \n", sizeof(elem));
    elem.header = malloc(sizeof(head));
    elem.data = malloc(100);

    elem.header->type = 'c';
    elem.header->len = 12;
        printf(" SIZE %zu \n", sizeof(elem));
    
    void *arr;
    memcpy(arr, &elem, sizeof(head));

    printf(" CHAR %c , LEN %d\n", *(char *)arr , *(int *)arr+4);

    free(elem.header);
    free(elem.data);

    return 0;
}