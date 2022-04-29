#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

typedef struct head
{
    unsigned char type;
    unsigned int len;
} head;

typedef struct data_structure
{
    head *header;
    void *data;
} data_structure;

int add_last(void **arr, int *len, data_structure *data)
{   printf(" LEN ESTE : %d\n", *len);
    if (*arr == NULL)
        *arr = malloc(8 + data->header->len);
    else
        *arr = realloc(*arr, *len + 8 + data->header->len);

    void *pointer = *arr;

    *arr = *arr + *len;
    memcpy(*arr, data->header, sizeof(head));

    (*arr) = ((char *)*arr + 4);
    size_t size = *(int *)(*arr);
    (*arr) = ((int *)*arr + 1);

    memcpy(*arr, data->data, size);
    *arr = pointer;

    // free(*arr);

    return 0;
}

int delete_at(void **arr, int *len, int index)
{
    void *pointer = *arr;
    int delete = 0;

    int lungime_data = *(int *)(*arr + 4);
    int suma = 0;
    while (delete != index)
    {
        suma = suma + sizeof(head) + lungime_data;
        *arr = *arr + sizeof(head) + lungime_data;
        lungime_data = *(int *)(*arr + 4);
        delete++;
    }

    int pas = sizeof(head) + lungime_data;
    suma = suma + pas;
    size_t size = *len - suma;

    memcpy(*arr, *arr + pas, size);

    *arr = pointer;

    *arr = realloc(*arr, *len - pas);

    *len = *len - pas;

    return 0;
}

int numar(void *arr, int len) { 
    void *pointer = arr;
    int lungime_data = *(int *)(arr + 4);
    int suma = 0;

    int contor = 0;
    while (suma != len)
    {   
        suma = suma + sizeof(head) + lungime_data;
        arr = arr + sizeof(head) + lungime_data;
        lungime_data = *(int *)(arr + 4);
        printf(" SUMA : %d \n" , suma);
        contor++;
    }
    
    printf(" NUMAR %d \n", contor);
    arr = pointer;
    return contor;


}
int add_at(void **arr, int *len, data_structure *data, int index)
{
    if (index < 0)
    return 0;
 
    size_t structura = sizeof(head) + data->header->len;
    // printf(" STRUCTURA %zu \n", structura);
    *arr = realloc(*arr, *len + structura);
    void *pointer = *arr;
    int add = 0;

    int lungime_data = *(int *)(*arr + 4);
    int suma = 0;
    while (add != index)
    {
        suma = suma + sizeof(head) + lungime_data;
        *arr = *arr + sizeof(head) + lungime_data;
        lungime_data = *(int *)(*arr + 4);
        add++;
    }

    memcpy(*arr + (int)structura, *arr, *len - suma);
    memcpy(*arr,data->header,sizeof(head));
    *arr = *arr + sizeof(head);
    memcpy(*arr,data->data,data->header->len);

    // *len = *len + (int)structura;

    *arr = pointer;
    
    
    return 0;
}

void find(void *data_block, int len, int index)
{
    if (index < 0)
        return;

    void *pointer = data_block;
    int find = 0;

    int lungime_data = *(int *)(data_block + 4);
    while (find != index)
    {
        data_block = data_block + sizeof(head) + lungime_data;
        lungime_data = *(int *)(data_block + 4);
        find++;
    }

    printf("Tipul %c\n", *(char *)(data_block));
    char tip = *(unsigned char *)(data_block);

    if (tip == '3')
    {
        int lungime = strlen((char *)(data_block + 8)) + 1;
        printf("%s pentru %s\n", (char *)(data_block + 8), (char *)(data_block + 8 + lungime + 8));
        printf("%d\n", *(int *)(data_block + 8 + lungime));
        printf("%d\n", *(int *)(data_block + 12 + lungime));
        printf("\n");
    }

    if (tip == '1')
    {
        int lungime = strlen((char *)(data_block + 8)) + 1;
        printf("%s pentru %s\n", (char *)(data_block + 8), (char *)(data_block + 8 + lungime + 2));
        printf("%" PRId8 "\n", *(int8_t *)(data_block + 8 + lungime));
        printf("%" PRId8 "\n", *(int8_t *)(data_block + 9 + lungime));
        printf("\n");
    }

    if (tip == '2')
    {
        int lungime = strlen((char *)(data_block + 8)) + 1;
        printf("%s pentru %s\n", (char *)(data_block + 8), (char *)(data_block + 8 + lungime + 6));
        printf("%" PRId16 "\n", *(int16_t *)(data_block + 8 + lungime));
        printf("%" PRId32 "\n", *(int32_t *)(data_block + 10 + lungime));
        printf("\n");
    }

    data_block = pointer;
}

void print(void *arr, int len)
{
    if (len == 0)
        return;
    void *pointer = arr;
    int ok = 0;
    int lungime_finala = 0;
    int add = 0;

    while (ok == 0)
    {
        printf("Tipul %c\n", *(char *)(arr));
        char tip = *(unsigned char *)(arr);

        if (tip == '3')
        {
            int lungime = strlen((char *)(arr + 8)) + 1;
            int lungime2 = strlen((char *)(arr + 8 + lungime + 8)) + 1;
            printf("%s pentru %s\n", (char *)(arr + 8), (char *)(arr + 8 + lungime + 8));
            printf("%d\n", *(int *)(arr + 8 + lungime));
            printf("%d\n", *(int *)(arr + 12 + lungime));
            printf("\n");

            lungime_finala = 8 + 8 + lungime + lungime2;
            add = add + lungime_finala;
        }

        if (tip == '1')
        {
            int lungime = strlen((char *)(arr + 8)) + 1;
            int lungime2 = strlen((char *)(arr + 8 + lungime + 2)) + 1;
            printf("%s pentru %s\n", (char *)(arr + 8), (char *)(arr + 8 + lungime + 2));
            printf("%" PRId8 "\n", *(int8_t *)(arr + 8 + lungime));
            printf("%" PRId8 "\n", *(int8_t *)(arr + 9 + lungime));
            printf("\n");

            lungime_finala = 8 + 2 + lungime + lungime2;
            add = add + lungime_finala;
        }

        if (tip == '2')
        {
            int lungime = strlen((char *)(arr + 8)) + 1;
            int lungime2 = strlen((char *)(arr + 8 + lungime + 6)) + 1;
            printf("%s pentru %s\n", (char *)(arr + 8), (char *)(arr + 8 + lungime + 6));
            printf("%" PRId16 "\n", *(int16_t *)(arr + 8 + lungime));
            printf("%" PRId32 "\n", *(int32_t *)(arr + 10 + lungime));
            printf("\n");

            lungime_finala = 8 + 6 + lungime + lungime2;
            add = add + lungime_finala;
        }

        if (add < len)
            arr = arr + lungime_finala;
        else
            ok = 1;
    }

    arr = pointer;
}

int main()
{
    void *arr = NULL;
    int len = 0;

    int lungime_vector = 0;

    int run = 1;
    char buffer[256];
    int type;

    data_structure elem;

    do
    {
        scanf("%s", buffer);

        if (strcmp(buffer, "insert") == 0)
        {
            lungime_vector++;

            // stocare type
            scanf("%d", &type);
            elem.header = (head *)malloc(sizeof(head));
            if (type == 1)
            {
                elem.header->type = '1';
            }
            if (type == 2)
            {
                elem.header->type = '2';
            }
            if (type == 3)
            {
                elem.header->type = '3';
            }

            if (type == 3)
            {
                char *sir = malloc(256 * sizeof(char));
                scanf("%s", sir); // citire sir

                int bancnota1;
                int bancnota2;
                scanf("%d%d", &bancnota1, &bancnota2); // citire bani

                char *sir2 = malloc(256 * sizeof(char));
                scanf("%s", sir2); // citire sir

                size_t size1 = strlen(sir) + 1;
                size_t size2 = strlen(sir2) + 1;
                size_t bani = sizeof(int);
                size_t total_size = size1 + size2 + 2 * bani;
                elem.header->len = (int)total_size;

                elem.data = malloc(total_size);
                memcpy(elem.data, sir, size1);
                elem.data = ((char *)elem.data + size1);
                memcpy(elem.data, &bancnota1, bani);
                elem.data = ((int *)elem.data + 1);
                memcpy(elem.data, &bancnota2, bani);
                elem.data = ((int *)elem.data + 1);
                memcpy(elem.data, sir2, size2);
                elem.data = ((char *)elem.data + size2);
                elem.data = (char *)elem.data - total_size;

                if (add_last(&arr, &len, &elem) != 0)
                {
                    exit(-1);
                }

                len = len + elem.header->len + (int)sizeof(head);

                free(elem.data);
                free(sir);
                free(sir2);
                free(elem.header);
            }

            if (type == 1)
            {
                char *sir = malloc(256 * sizeof(char));
                scanf("%s", sir); // citire sir

                int8_t bancnota1;
                int8_t bancnota2;
                scanf("%" SCNd8 " %" SCNd8 "", &bancnota1, &bancnota2); // citire bani

                char *sir2 = malloc(256 * sizeof(char));
                scanf("%s", sir2); // citire sir

                size_t size1 = strlen(sir) + 1;
                size_t size2 = strlen(sir2) + 1;
                size_t bancnota1_size = sizeof(int8_t);
                size_t bancnota2_size = sizeof(int8_t);
                size_t total_size = size1 + size2 + bancnota1_size + bancnota2_size;
                elem.header->len = (int)total_size;

                elem.data = malloc(total_size);
                memcpy(elem.data, sir, size1);
                elem.data = ((char *)elem.data + size1);
                memcpy(elem.data, &bancnota1, bancnota1_size);
                elem.data = ((int8_t *)elem.data + 1);
                memcpy(elem.data, &bancnota2, bancnota2_size);
                elem.data = ((int8_t *)elem.data + 1);
                memcpy(elem.data, sir2, size2);
                elem.data = ((char *)elem.data + size2);
                elem.data = (char *)elem.data - total_size;

                if (add_last(&arr, &len, &elem) != 0)
                {
                    exit(-1);
                }

                len = len + elem.header->len + (int)sizeof(head);

                free(elem.data);
                free(sir);
                free(sir2);
                free(elem.header);
            }

            if (type == 2)
            {
                char *sir = malloc(256 * sizeof(char));
                scanf("%s", sir); // citire sir

                int16_t bancnota1;
                int32_t bancnota2;
                scanf("%" SCNd16 " %" SCNd32 "", &bancnota1, &bancnota2); // citire bani

                char *sir2 = malloc(256 * sizeof(char));
                scanf("%s", sir2); // citire sir

                size_t size1 = strlen(sir) + 1;
                size_t size2 = strlen(sir2) + 1;
                size_t bancnota1_size = sizeof(int16_t);
                size_t bancnota2_size = sizeof(int32_t);
                size_t total_size = size1 + size2 + bancnota1_size + bancnota2_size;
                elem.header->len = (int)total_size;

                elem.data = malloc(total_size);
                memcpy(elem.data, sir, size1);
                elem.data = ((char *)elem.data + size1);
                memcpy(elem.data, &bancnota1, bancnota1_size);
                elem.data = ((int16_t *)elem.data + 1);
                memcpy(elem.data, &bancnota2, bancnota2_size);
                elem.data = ((int32_t *)elem.data + 1);
                memcpy(elem.data, sir2, size2);
                elem.data = ((char *)elem.data + size2);
                elem.data = (char *)elem.data - total_size;

                if (add_last(&arr, &len, &elem) != 0)
                {
                    exit(-1);
                }

                len = len + elem.header->len + (int)sizeof(head);

                free(elem.data);
                free(sir);
                free(sir2);
                free(elem.header);
            }
        }

        if (strcmp(buffer, "print") == 0)
        {
            print(arr, len);
        }

        if (strcmp(buffer, "find") == 0)
        {
            int index;
            scanf("%d", &index);
            find(arr, len, index);
        }

        if (strcmp(buffer, "delete_at") == 0)
        {
            int index;
            scanf("%d", &index);
            if (delete_at(&arr, &len, index) != 0)
                exit(-2);
            lungime_vector--;
        }

        if (strcmp(buffer, "insert_at") == 0)
        {
            int index;
            scanf("%d", &index);

            if(index > 10)
            index = 1;

            scanf("%d", &type);
            elem.header = (head *)malloc(sizeof(head));
            if (type == 1)
            {
                elem.header->type = '1';
            }
            if (type == 2)
            {
                elem.header->type = '2';
            }
            if (type == 3)
            {
                elem.header->type = '3';
            }

            if (type == 3)
            {
                char *sir = malloc(256 * sizeof(char));
                scanf("%s", sir); // citire sir

                int bancnota1;
                int bancnota2;
                scanf("%d%d", &bancnota1, &bancnota2); // citire bani

                char *sir2 = malloc(256 * sizeof(char));
                scanf("%s", sir2); // citire sir

                size_t size1 = strlen(sir) + 1;
                size_t size2 = strlen(sir2) + 1;
                size_t bani = sizeof(int);
                size_t total_size = size1 + size2 + 2 * bani;
                elem.header->len = (int)total_size;

                elem.data = malloc(total_size);
                memcpy(elem.data, sir, size1);
                elem.data = ((char *)elem.data + size1);
                memcpy(elem.data, &bancnota1, bani);
                elem.data = ((int *)elem.data + 1);
                memcpy(elem.data, &bancnota2, bani);
                elem.data = ((int *)elem.data + 1);
                memcpy(elem.data, sir2, size2);
                elem.data = ((char *)elem.data + size2);
                elem.data = (char *)elem.data - total_size;

                if(add_at(&arr,&len,&elem,index) != 0)
                exit(-3);

                len = len + elem.header->len + (int)sizeof(head);

                free(elem.data);
                free(sir);
                free(sir2);
                free(elem.header);
            }

            if (type == 1)
            {
                char *sir = malloc(256 * sizeof(char));
                scanf("%s", sir); // citire sir

                int8_t bancnota1;
                int8_t bancnota2;
                scanf("%" SCNd8 " %" SCNd8 "", &bancnota1, &bancnota2); // citire bani

                char *sir2 = malloc(256 * sizeof(char));
                scanf("%s", sir2); // citire sir

                size_t size1 = strlen(sir) + 1;
                size_t size2 = strlen(sir2) + 1;
                size_t bancnota1_size = sizeof(int8_t);
                size_t bancnota2_size = sizeof(int8_t);
                size_t total_size = size1 + size2 + bancnota1_size + bancnota2_size;
                elem.header->len = (int)total_size;

                elem.data = malloc(total_size);
                memcpy(elem.data, sir, size1);
                elem.data = ((char *)elem.data + size1);
                memcpy(elem.data, &bancnota1, bancnota1_size);
                elem.data = ((int8_t *)elem.data + 1);
                memcpy(elem.data, &bancnota2, bancnota2_size);
                elem.data = ((int8_t *)elem.data + 1);
                memcpy(elem.data, sir2, size2);
                elem.data = ((char *)elem.data + size2);
                elem.data = (char *)elem.data - total_size;

                if(add_at(&arr,&len,&elem,index) != 0)
                exit(-3);

                len = len + elem.header->len + (int)sizeof(head);

                free(elem.data);
                free(sir);
                free(sir2);
                free(elem.header);
            }

            if (type == 2)
            {
                char *sir = malloc(256 * sizeof(char));
                scanf("%s", sir); // citire sir

                int16_t bancnota1;
                int32_t bancnota2;
                scanf("%" SCNd16 " %" SCNd32 "", &bancnota1, &bancnota2); // citire bani

                char *sir2 = malloc(256 * sizeof(char));
                scanf("%s", sir2); // citire sir

                size_t size1 = strlen(sir) + 1;
                size_t size2 = strlen(sir2) + 1;
                size_t bancnota1_size = sizeof(int16_t);
                size_t bancnota2_size = sizeof(int32_t);
                size_t total_size = size1 + size2 + bancnota1_size + bancnota2_size;
                elem.header->len = (int)total_size;

                elem.data = malloc(total_size);
                memcpy(elem.data, sir, size1);
                elem.data = ((char *)elem.data + size1);
                memcpy(elem.data, &bancnota1, bancnota1_size);
                elem.data = ((int16_t *)elem.data + 1);
                memcpy(elem.data, &bancnota2, bancnota2_size);
                elem.data = ((int32_t *)elem.data + 1);
                memcpy(elem.data, sir2, size2);
                elem.data = ((char *)elem.data + size2);
                elem.data = (char *)elem.data - total_size;

                if(add_at(&arr,&len,&elem,index) != 0)
                exit(-3);

                len = len + elem.header->len + (int)sizeof(head);

                free(elem.data);
                free(sir);
                free(sir2);
                free(elem.header);
            }


         }

        if (strcmp(buffer, "exit") == 0)
        {
            run = 0;
        }

    } while (run == 1);

    free(arr);

    return 0;
}
