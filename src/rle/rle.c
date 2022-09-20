#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//48-57 are digits
/*
repeated letter/punctuation becomes a single char + integer
if compressed string is longer than original string, rle prints original


*/
int main(int argc, char *argv[]) {
    //base check
    if (argc != 2 || (strcmp(argv[1],"")==0))
       return EXIT_SUCCESS;

    int i=1, count=1; //i =index for characters; count=to find how many repeated letters there are
    char current;
    int length = strlen(argv[1]);
    char *compress = malloc(2* length * sizeof(char)), *p; 
    p=compress;
    //  for (i = 0; i < length; ++i) 
    //  compress[i] = malloc(2*length * sizeof(char));
    char *argvv = argv[1];
    int index=0, w;
    char test = argvv[0];


    while (argvv[i] != '\0') {
        current = argvv[i];

        //printf("%c\n" , current);
        if (current >= 48 && current <= 57) { //if it's a digit
            printf("error\n");
            count = -1;
            //return EXIT_FAILURE;
            break; 
        }
        else if (current == test) {
            count++;

        }

        else {
            
           // compress[index] = test;
            //compress[index+1] = count;

            w = sprintf(p, "%c", test);
            p += w;
            w = sprintf(p, "%d", count);
            p+=w;
            //printf("%c%d",compress[index], compress[index+1]);

            index = index+2;
            count = 1;
            test = current; 
        }

        i++;
    }

    w = sprintf(p, "%c", test);
    p += w;
    w = sprintf(p, "%d", count);
    p+=w;

   // printf("%s\n", compress);

    //compress[index] = test;
    //compress[index+1] = count;
    int lengths = strlen(compress);
    
    if (count != -1) {
        if (lengths > length){
            printf("%s\n", argv[1]);
        }
        else printf("%s\n",compress);
    }

    free(compress);
}