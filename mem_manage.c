#include <stdlib.h>
#include <stdio.h>

#define BLOCK_SIZE 256

#define BLOCK_COUNT 20

char buf[BLOCK_SIZE*BLOCK_COUNT] = {0};

char *allocate() {
    int loc, i=1;
    memcpy((char *)&loc, buf, BLOCK_SIZE);
    while ((loc & i) != 0) {  
        i = i << 1;
    }
    loc = loc | i;
    memcpy(buf, (char *)(&loc), BLOCK_SIZE);
}

void deallocate(char *l) {
    int i=0, loc;
    while ((buf + i*BLOCK_SIZE) != l) {
        i++;    
    }
    memcpy((char *)&loc, buf, BLOCK_SIZE);
    loc = loc & (~(1 << i));
    memcpy(buf, (char *)(&loc), BLOCK_SIZE);
}

int put(char *l, char *data, int nbytes) {
    int nblocks = (nbytes)/(BLOCK_SIZE), loc, i=1, n=0, cont = 0, found = 0;
    memcpy((char *)&loc, buf, BLOCK_SIZE);
    while (n < BLOCK_COUNT) {
        if ((i << n) & loc) {
            cont++;
            if (count == nblocks) {
                found = 1;
                break;
            }
        }
        else {
            cont = 0;
        }
    }
    if (found) {
        return 1;
    }    
    else {
        return 0;
    }
}

int main()
{
                

}



