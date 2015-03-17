#include <stdio.h>
#include <string.h>

int main() {
    char s[12] ="a-2-345-6";
    char *token;
    token = strtok(s, "-");
    printf("\n%s\n", token); 
    token = strtok(NULL, "-");
    printf("\n%s\n", token); 


}


