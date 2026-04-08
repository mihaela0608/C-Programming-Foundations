#include <stdio.h>

int main(){
    struct Node{
        int num;
        struct Node* next;
    };
    // Последният next задължително трябва да е равен на NULL
    // първия елемент -> head или root  *
    // загубим ли първия pointer губим целия списък завинаги
    // започваме с три ponter-а -> head, temp, current
    struct Node* head = NULL;
    struct Node* temp = NULL;
    struct Node* current = NULL;
    for(int i = 0; i < 5; i++){
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->num = i;
        temp->next = NULL;
        if(head == NULL){
            head = temp;
            current = head;
        } else {
            current->next = temp;
            current = temp;
        }
    }

    while(current != NULL){
        current = current->next;
    }
    // създаваме нов node
    // cur->next = temp;

    
    // вмъкване на елемент
    // създаваме нов елемент, записваме в отделна променлива n+1, а на n->next записваме новото, след това новото->next е нашата отделна променлива
    
    // триене
    // free(current->next)
    // current->next = current->next->next

    // създаване на стек

}