#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// 40-( 41-) 91-[ 93-] 123-{ 125-}

int main(int argc, char *argv[]) {
    int i;
    int length = strlen(argv[1]);
    char *stack = malloc(length * sizeof(char)); 
    char *argvv = argv[1];
    int index = -1;  //i-1

    if (argc != 2)
       return EXIT_FAILURE;

// else {   
    i=0;
    char delimiter;
    while (argvv[i] != '\0') {
        delimiter = argvv[i];
        //printf("delimiter is %c ASCII %d because argv is %c\n", delimiter, delimiter, argvv[i]);
        if (delimiter != 40 && delimiter != 91 && delimiter != 123 && delimiter != 41 && delimiter != 93 && delimiter != 125) {   //ignore all other characters 
            //printf("I'm not a bracket: %c\n", delimiter);
            i++;
            continue;
        }
        else if (delimiter == 40 || delimiter == 91 || delimiter == 123) {
            
            index++;
            stack[index] = delimiter;      //printf("%c\n", stack[j]);
            //printf("%d:%c\n",index, stack[index]);
        }

        else if (index>=0){
            if((delimiter == 41 && stack[index] == 40 ) || (delimiter == 93 && stack[index] == 91) || (delimiter == 125 && stack[index]==123)) {
                // printf("%c : %c\n", stack[index],delimiter);
                index--;
                // printf("index %d was removed\nat index %d\n", index+1, index);
            }
            else { //if (index==-1) {
            printf("%d: %c\n", i, delimiter);
                index = -1;
                free(stack);
                return EXIT_FAILURE;
                break;
        }
        }
        else { //if (index==-1) {
            printf("%d: %c\n", i, delimiter);
            index = -1;
            free(stack);
            return EXIT_FAILURE;
            break;
        }

        i++;
    }
//}
    if(index != -1){
        printf("open: ");
        while (index != -1){
            if (stack[index]==40)
            printf(")");
            else if (stack[index] == 91)
            printf("]");
            else if (stack[index] == 123) 
            printf("}");
            index--;
        }
        printf("\n");
        free(stack);
        return EXIT_FAILURE;
    }
    else {
        free(stack);
        return EXIT_SUCCESS;
    }
/*
    printf("%d ", length);
    printf("%s", argv[1]);
*/

}