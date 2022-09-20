#include <string.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h>
 
struct bst{
    int num;
    struct bst* right;
    struct bst* left;
} ;
 
struct bst* root;

void insert(struct bst* tree, int input);
void delete(struct bst* tree, int input);
void search(struct bst* tree, int input);
void print(struct bst* tree);
void freebst(struct bst* tree);
int maximum(struct bst* sub, struct bst* pt);



int main(int argc, char **argv){
    FILE* file;
    if (argc > 1) {
        if ((file = fopen(argv[1],"r"))==NULL){
        return EXIT_FAILURE;
        }
        else {
            char c;
            int d;
            file = fopen(argv[1], "r");
            while(fscanf(file, "%c", &c) != -1){
        
                if(c == 'i'){
                    fscanf(file, "%d", &d);
                    insert(root, d);
                }
                else if(c == 'd'){
                    fscanf(file, "%d", &d);
                    delete(root,d);
                }
            
                else if(c == 's'){
                    fscanf(file, "%d", &d);
                    search(root, d);
                }
            
                else if(c == 'p'){
                
                    print(root);
                    printf("\n");     
                }
            }   

        }
    }

    else {

    int num;
    char c;
    while(scanf("%c", &c)!= -1 ){
    
      if(c == 'i'){
          scanf("%d", &num);
          insert(root, num);
 
      }
      else if(c == 'd'){
        scanf("%d", &num);
        delete(root, num);
      }
 
      else if(c == 's'){
          scanf("%d", &num);
          search(root, num);      
      }
 
       else if(c == 'p'){
           print(root);
           printf("\n");     
       }
    }   
    

    freebst(root);
    return EXIT_SUCCESS;
}
}
 
 
void freebst(struct bst* tree){
    if(tree == NULL){
        return;
        }
    freebst((*tree).left);
    freebst((*tree).right);
    free(tree);
    return;
}

void insert(struct bst* tree, int input){
    if(tree == NULL){
        tree = malloc(sizeof(struct bst));
        (*tree).num = input;
        (*tree).right = NULL;
        (*tree).left = NULL;
        root = tree;
        printf("inserted\n");
        return;
 
    }
 
    else if(input > (*tree).num){
            //go right subtree
            if((*tree).right == NULL){
                struct bst *extra = malloc(sizeof(struct bst));
                (*extra).num = input;
                (*tree).right = extra;
                (*extra).right = NULL;
                (*extra).left = NULL;
                printf("inserted\n");
                return;
            }
            insert((*tree).right, input);
 
    }
    else if(input < (*tree).num){
            //go to left subtree
            if((*tree).left == NULL){
                struct bst *extra = malloc(sizeof(struct bst));
                (*extra).num = input;
                (*tree).left = extra;
                (*extra).right = NULL;
                (*extra).left = NULL;
                printf("inserted\n");
                return;
            }
            insert((*tree).left, input);
 
    }
    else if(input == (*tree).num){
        printf("not inserted\n");
        return;
    }
    return;
}


void delete(struct bst* tree, int input){
    if(tree == NULL){
        printf("absent\n");
        return;

    }
    if((*root).num == input){
        if((*root).right == NULL && (*root).left == NULL){
            free(tree);
            root = NULL;
            printf("deleted\n");
            return;
        }
        else if((*root).left != NULL && (*root).right == NULL){
            struct bst* temp = (*root).left;
            free(root);
            root = temp;
            printf("deleted\n");
            return;
        }
        else if((*root).right != NULL && (*root).left == NULL){
            struct bst* temp = (*root).right;
            free(root);
            root = temp;
            printf("deleted\n");
            return;
        }
        
        else if((*root).left != NULL && (*root).right != NULL){
            (*root).num = maximum((*root).left, root);
            printf("deleted\n");
            // printf("%d", (*root).num);
            return;
        }
        
    }
    else if(input > (*tree).num){
        if((*tree).right == NULL){
            printf("absent\n");
            return;
        }
        else{
            if((*tree).right->num == input){
                if((*tree).right->right == NULL && (*tree).right->left == NULL){
                    free((*tree).right);
                    (*tree).right = NULL;
                    printf("deleted\n");

                }
               
                else if((*tree).right->right != NULL && (*tree).right->left == NULL){
                    struct bst* temp = (*tree).right->right;
                    free((*tree).right);
                    (*tree).right = temp;
                    printf("deleted\n");
                }

                else if((*tree).right->left != NULL && (*tree).right->right == NULL){
                    struct bst* temp = (*tree).right->left;
                    free((*tree).right);
                    (*tree).right = temp;
                    printf("deleted\n");


                }
                else if((*tree).right->left != NULL && (*tree).right->right != NULL){
                    (*tree).right->num = maximum((*tree).right->left, (*tree).right);
                    printf("deleted\n");
                    return;
                }
            }
            else{
                delete((*tree).right, input);
            }
            
        }

    }

    else if(input < (*tree).num){
        if((*tree).left == NULL){
            printf("absent\n");
            return;
        }
        else{
            if((*tree).left->num == input){
                if((*tree).left->left == NULL && (*tree).left->right == NULL){
                    free((*tree).left);
                    (*tree).left = NULL;
                    printf("deleted\n");

                }
                else if((*tree).left->right != NULL && (*tree).left->left == NULL){
                    struct bst* temp = (*tree).left->right;
                    free((*tree).left);
                    (*tree).left = temp;
                    printf("deleted\n");


                }
                else if((*tree).left->left != NULL && (*tree).left->right == NULL){
                    struct bst* temp = (*tree).left->left;
                    free((*tree).left);
                    (*tree).left = temp;
                    printf("deleted\n");
                }
                else if((*tree).left->left != NULL && (*tree).left->right != NULL){
                    (*tree).left->num = maximum((*tree).left->left, (*tree).left);
                    printf("deleted\n");
                    return;
                }
            }
            else{
                delete((*tree).left, input);
            }  
        }
    }
    return;
}
 
void search(struct bst* tree, int input){
    if(tree == NULL){
        printf("absent\n");
        
    }
    else if(input == (*tree).num){
        printf("present\n");
        }
    else if(input > (*tree).num){
            //go right subtree
            if((*tree).right == NULL){
                printf("absent\n");
                return;
            }
            search( (*tree).right, input);
 
    }
    else if(input < (*tree).num){
            //go to left subtree
            if((*tree).left == NULL){
                printf("absent\n");
                return;
            }
            search( (*tree).left, input);
 
        }
    }
 
int maximum(struct bst* sub, struct bst* pt){
    if((*sub).right == NULL && (*sub).left == NULL && sub == (*pt).left){
        int i = (*sub).num;
        free(sub);
        (*pt).left = NULL;
        return i;
    }
    while((*sub).right != NULL){
        pt = sub;
        sub = (*sub).right;
        
    }
    int i = (*sub).num;
    if((*sub).left != NULL){
        (*pt).right = (*sub).left;
        free(sub);
    }
    else{
        free(sub);
        (*pt).right = NULL;
    }
    
    return i;
}
 

 
void print(struct bst* tree){
    if(tree != NULL){
        printf("(");
        if((*tree).left != NULL){
            print((*tree).left);
        }

        printf("%d", (*tree).num);
        if((*tree).right != NULL){
            print((*tree).right);
        }
        
        printf(")");
    }
    return;
}
 