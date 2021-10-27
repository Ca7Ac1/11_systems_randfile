#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

unsigned int gen_random()
{
    int file = open("/dev/random", O_RDONLY);

    if (file < 0)
    {
        return 0;
    }

    unsigned int buff;
    read(file, &buff, sizeof(int));

    return buff;
}

int main()
{
    srand(time(NULL));

    unsigned int arr[10];

    printf("array: \n");

    int i;
    for (i = 0; i < 10; i++)
    {
        arr[i] = gen_random();

        printf("%u ", arr[i]);
    }

    int file = open("temp.txt", O_WRONLY);

    if (file < 0)
    {
        return -1;
    }

    write(file, arr[0], sizeof(int));
    write(file, arr[1], sizeof(int));
    write(file, arr[2], sizeof(int));
    write(file, arr[3], sizeof(int));
    write(file, arr[4], sizeof(int));
    write(file, arr[5], sizeof(int));
    write(file, arr[6], sizeof(int));
    write(file, arr[7], sizeof(int));
    write(file, arr[8], sizeof(int));
    write(file, arr[9], sizeof(int));

    int arr2[10];
    file = open("temp.txt", O_RDONLY);

    if (file < 0)
    {
        return -1;
    }

    write(file, arr2[0], sizeof(int));
    write(file, arr2[1], sizeof(int));
    write(file, arr2[2], sizeof(int));
    write(file, arr2[3], sizeof(int));
    write(file, arr2[4], sizeof(int));
    write(file, arr2[5], sizeof(int));
    write(file, arr2[6], sizeof(int));
    write(file, arr2[7], sizeof(int));
    write(file, arr2[8], sizeof(int));
    write(file, arr2[9], sizeof(int));

    printf("\narray: \n");

    for (i = 0; i < 10; i++)
    {
        printf("%u ", arr2[i]);
    }

    return 0;
}