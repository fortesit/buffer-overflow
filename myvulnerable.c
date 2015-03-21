#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <signal.h>

char *shellcode;

void handler(int signum)
{
    exit(-1);
}

void main(int argc, char *argv[]) {
    signal(SIGSEGV, handler);
    
    int *ret;
    ret = (int *)&ret + 2;
    
    shellcode = malloc(sizeof(char)*(strlen(argv[1])+1));
    strncpy(shellcode, argv[1], strlen(argv[1]));
    shellcode[strlen(argv[1])] = 0;
    printf("%s\n",shellcode);
    
    srand((unsigned)time(NULL));
    int len = (int)shellcode;
    char *str = malloc(len+1);
    memset(str, rand()%(126-34)+33, len);
    str[len] = 0;
    
    FILE *fp;
    fp = fopen("/dev/null", "w");
    fprintf(fp, "%s%n", str, (ret));
    
}