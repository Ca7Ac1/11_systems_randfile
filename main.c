#include <stdlib.h>
#include <stdio.h> 
#include <string.h>
#include <fcntl.h> 
#include <unistd.h>
#include <time.h>  

unsigned int gen_random()
{
    int file = open("/dev/random", O_RDONLY);

    unsigned int buff;
    read(file, &buff, sizeof(int));

    return buff;
}

int main()
{
        srand(time(NULL));

        printf("%u", gen_random());
}