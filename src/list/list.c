#include <string.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h>

 struct node{
    int data;
    struct node* next;
};

struct node* head;


void insert(int value);
void delete (int value);
void count();


void insert(int value){
    if(head == NULL){
        struct node *newhead = malloc(sizeof(struct node));
        (*newhead).data = value;
        (*newhead).next = NULL;
        head = newhead;
        return;
    }
    else if(value < (*head).data){
        struct node *newhead = malloc(sizeof(struct node)); 
        (*newhead).data = value;
        (*newhead).next = head;
        head = newhead;  
        return;
        
        }
    else if(value > (*head).data){
        struct node *newnode = malloc(sizeof(struct node)); 
        (*newnode).data = value;
        (*newnode).next = NULL;
        if((*head).next == NULL){
            (*head).next = newnode;
            return;
            
        }
        //error: adding node to end of node if one isnt there already
        else{
            struct node *behind;
            struct node *front;
            behind = head;
            front = (*head).next;
            if((*behind).data == value){
                    return;
                }

            while(front != NULL){
                if((*front).data > value){
                    (*behind).next = newnode;
                    (*newnode).next = front;
                    return;

                }
                if((*front).data == value){
                    return;
                }
                behind = (*behind).next;
                front = (*front).next;

            }
            if((*behind).next == NULL){
                (*behind).next = newnode;
                
            }
        }
    }
}

void delete(int value){
    if(head == NULL){

    }
    else if((*head).data == value){
        struct node *copy = head;
        head = (*head).next;
        free(copy);
    }
    else{
        struct node *behind;
        struct node *front;
        behind = head;
        front = (*head).next;
        while(front != NULL){
            if((*front).data == value){
                (*behind).next = (*front).next;
                (*front).next = NULL;
                free(front);
                break;
            }
            front = (*front).next;
            behind = (*behind).next;
            
        }
    }
   
} 



void count(){
    int i = 0;
    struct node* move = head;
    while(move != NULL){
        //printf("%d, %p\n", ((*move).data), move);
        i++;
        move = (*move).next;
    }
    printf("%i :", i);

}



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
        while(fscanf(file, "%c %d", &c, &d) != -1){

            if(c == 'i'){
                int num;
                insert(d);
                count();
                struct node* move = head;
                while(move != NULL){
                    num = (*move).data;
                    printf(" %i", num);
                    move = (*move).next;
                }
                printf("\n");
            
        }
            else if(c == 'd'){
                int num;
                delete(d);
                count();
                struct node* move = head;
                while(move != NULL){
                    num = (*move).data;
                    printf(" %i", num);
                    move = (*move).next;
                }
                printf("\n");
            }
           
        }
    }


}
        
  
 else{
    int d;
    char c;
    while(scanf("%c %d", &c, &d) != -1){
    
        if(c == 'i'){
            int num;
            insert(d);
            count();
            struct node* move = head;
            while(move != NULL){
                num = (*move).data;
                printf(" %i", num);
                move = (*move).next;
            }
            printf("\n");
          
      }
        else if(c == 'd'){
            int num;
            delete(d);
            count();
            struct node* move = head;
            while(move != NULL){
                num = (*move).data;
                printf(" %i", num);
                move = (*move).next;
            }
            printf("\n");
        }
        
    }
 }

    while(head!=NULL){
        //printf("%d\n", (*head).data);
        struct node* copy = head;
        head = (*head).next;
        free(copy);
    }

    return EXIT_SUCCESS;
}