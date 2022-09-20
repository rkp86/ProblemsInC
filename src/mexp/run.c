
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int **multiplication_of_matrices(int exponent, int rows, int **matrices, int **multiplier, int **moving);
//void identity(int exponent,int rows, int**multiplier,int**matrices);
void identity(int rows);
//int ** same_Matrix(int exponent,int rows, int**multiplier);
//int ** allocate_Matrix(int rows); //other argument was int**matrices
//int ** negative_exponent(int exponent,int rows,int**multiplier);

/*nt **allocate_Matrix(int rows){//function allocates space
    int **moving = malloc(sizeof(int*)*rows);
    //int **multiplier = malloc(sizeof(int*)*rows);
    for(int i = 0; i < rows;i++){
        moving[i] = malloc(sizeof(int)*rows);
        //multiplier[i] = malloc(sizeof(int)*rows);
    }
   for(int i = 0; i < rows;i++){
        for(int j = 0; j < rows;j++){
            moving[i][j]=matrices[i][j];
        }
    }
    
    return moving;
}
*/

// int** negative_exponent(int exponent,int rows,int**multiplier){
//     allocate_Matrix(rows,multiplier);
//     int exp = exponent;
//    // int exponent=0;
//     if(exp<exponent-1){
//         return multiplier;

//     }
// }
void identity(int rows)
{ //base case if power is 0 return identity matrix
    //allocate_Matrix(rows,multiplier);
    // int **prod = malloc(sizeof(int *) * rows);
    // for(int i = 0; i < rows; i++){
    //     prod[i] = malloc(sizeof(int) * rows);
    // }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            if (i == j)
                printf("1");
            else
                printf("0");
            if (rows != j + 1)
                printf(" ");
        }
        printf("\n");
    }

    /*int exp =exponent;
    if(exp== 0){
        for(int i =0; i < rows;i++){
            for(int j = 0; j<rows;j++){
                if(i ==j){
                prod[i][j]==1;
                }else{
                    prod[i][j]==0;
                }
            }
        }
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < rows; j++){
                multiplier[i][j] = prod[i][j];
    }
    return multiplier;
}
}
*/
}
/*
int **same_Matrix(int exponent,int rows, int**multiplier){ //if the power is one return the same matrix 
  allocate_Matrix(rows,multiplier);
    if(exponent ==1){
        for(int i = 0; i< rows;i++){
            for(int j = 0; j< rows;j++){
            return multiplier[i][j];
            }
        }
    }
}
*/

int **multiplication_of_matrices(int exponent, int rows, int **matrices, int **multiplier, int **moving)
{ //multiplying matrices
    //allocate_Matrix(rows,matrices)
        
            int sum;
            for(int i = 1; i < exponent; i++) {
                for(int j = 0; j< rows; j++){
                    for(int k = 0; k < rows; k++){
                        sum=0;
                        for(int l = 0;  l < rows; l++){
                            sum += moving[j][l]*matrices[l][k];
                         
                        }
                        multiplier[j][k] = sum; 
                       }   
                }
                for (int i = 0 ; i < rows ; i++ ) { 
                    for (int j = 0 ; j < rows ; j++ ) {  //           
                    moving[i][j] = multiplier[i][j];
                }
        }
            }
            for (int i = 0 ; i < rows ; i++ ) { 
                    for (int j = 0 ; j < rows ; j++ ) {  //           
                    matrices[i][j] = moving[i][j];
                    }
            }

  
    return matrices;
    
}

int main(int argc, char *argv[])
{

    // char* v = argv[1];
    FILE *read_file;
    if ((read_file = fopen(argv[1], "r")) == NULL)
    {
        //printf("error");
        return 1;
    }
    else
    {
        read_file = fopen(argv[1], "r");
        int rows;
        //printf("%i:rows" , rows);
        fscanf(read_file, "%i\n", &rows);
        int **matrices = (int **)malloc(sizeof(int *) * rows);
        int **moving = (int **)malloc(sizeof(int *) * rows);
        int **multiplier = (int **)malloc(sizeof(int *) * rows);

        for (int i = 0; i < rows; i++)
        {
            matrices[i] = (int *)malloc(sizeof(int) * rows);
            moving[i] = (int *)malloc(sizeof(int) * rows);
            multiplier[i] = (int *)malloc(sizeof(int) * rows);
        }

        int someVal;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < rows; j++)
            {
                fscanf(read_file, "%i", &someVal);
                matrices[i][j] = someVal;
                moving[i][j] = someVal;
                // printf("[%i][%i]:%i-%i", i, j , someVal, matrices[i][j]);
            }
            //fscanf(read_file,"\n");
        }
        int exponent;
        fscanf(read_file, "%i", &exponent);

        if (exponent == 0)
        {
            identity(rows);
            /* for(int i = 0; i<rows;i++){
               for(int j = 0; j< rows;j++){
                   printf("%i",matrices[i][j]);
                   if(j+1!=rows){
                       printf(" ");
                   }
               }
               printf("\n");
           }
           */
        }

        matrices = multiplication_of_matrices(exponent, rows, matrices, multiplier, moving);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < rows; j++)
            {
                printf("%i", matrices[i][j]);
                if (j + 1 != rows)
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
        for (int i = 0; i < rows; i++)
        {
            free(matrices[i]);
            free(moving[i]);
            free(multiplier[i]);
        }
        free(matrices);
        free(moving);
        free(multiplier);

        fclose(read_file);
    }
}
