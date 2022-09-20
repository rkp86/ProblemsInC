#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    int i,j;
    
    if (argc < 2) 
        printf("\n");
    else if (strcmp(argv[1],"")==0)
        printf("\n");
    else {
        for (i = 1; argv[i] != NULL; i++) {
            for (j = 0; argv[i][j] != '\0'; j++) {
                char letter = argv[i][j];
                argv[i][j] = toupper(letter);
            }
        printf("%s", argv[i]);  
        
        }
        printf("%c%c\n",'!','!'); 
    }
}

