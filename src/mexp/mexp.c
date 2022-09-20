#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void identityMatrix(int k);

void identityMatrix(int k){
    int r, c;
    for (r = 0; r < k; r++) {
        for (c=0; c < k; c++) {
            if (r==c)
                printf("1");
            else printf ("0");
            if (c + 1 != k) printf (" ");
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    int r, c, n;
    //printf("%s\n", argv[1]);

    if ((file = fopen(argv[1],"r"))==NULL){
        return EXIT_FAILURE;
    }
    else {
        file = fopen(argv[1], "r");
        int k;
        fscanf(file, "%d", &k);
        //printf("%d\n", k);  //takeout
        int **matrix = (int**)malloc(k * sizeof(int*));  // this matrix will stay the same throughout
        for (int i = 0; i < k; ++i) {
	        matrix[i] = (int*)malloc(k * sizeof(int));
        }

        int **mult = (int**)malloc(k * sizeof(int*));  //this matrix will update as it's multiplied
        for (int i = 0; i < k; ++i) {
            mult[i] = (int*)malloc(k * sizeof(int));
        }

        int **temp = (int**)malloc(k * sizeof(int*));  //this matrix will update as it's multiplied
        for (int i = 0; i < k; ++i) {
            temp[i] = (int*)malloc(k * sizeof(int));
        }

        for (r = 0; r < k; r++){
            for (c = 0; c < k; c++) {
                fscanf(file, "%d", &n);
                matrix[r][c] = n;
                mult[r][c] =n;
                //printf("[%d][%d]:%d\n",r,c,n); //takeout
            }
        }
      
        int exponent;
        fscanf(file, "%d", &exponent);
       // printf("the exponent is %d\n", exponent); //takeout

        if (exponent == 0)
            identityMatrix(k);

        else { //calculate the product
            int a, b, d, p;
            

            //check linear algebra notes/ draw it out
            int sum;
            for(p = 1; p < exponent; p++) {
                for(a = 0; a < k; a++){
                    for(b = 0; b < k; b++){
                        sum=0;
                        //printf("row: %d column %d\n", a, b);
                        for(d = 0; d < k; d++){
                            sum += mult[a][d]*matrix[d][b];
                          //  printf("the product of %d*%d: %d\n" ,mult[a][d],mult[d][b], sum);
                            
                        }
                        temp[a][b] = sum; 
                       // printf("[%d][%d]: %d\n",a,b, mult[a][b]);
                    }   
                }
                for (a = 0 ; a < k ; a++ ) { 
                    for (b = 0 ; b < k ; b++ ) {  //m[b][d] = r[b][d];           
                    mult[a][b] = temp[a][b];
                }
        }
            }

            //printf("final matrix\n");

            //after product is taken, print matrix        
            for(r = 0; r < k; r++){
                for(c = 0; c < k; c++){
                    printf("%d", mult[r][c]);
                    if(c + 1 != k) printf(" ");
                }
                printf("\n");
            } 

            // FREE MATRIX HERE
            for(int i = 0; i < k; i++) {
                free(mult[i]);
                free(matrix[i]);   
                free(temp[i]);         
            }
            free(mult);
            free(matrix);
            free(temp);
       
    
            //close file
            fclose(file);
        }   
    }   
}
