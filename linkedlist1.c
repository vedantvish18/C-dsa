#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head = NULL;
    struct node *n1, *n2, *n3;

    n1 = (struct node *) malloc(sizeof(struct node));
    n2 = (struct node *) malloc(sizeof(struct node));
    n3 = (struct node *) malloc(sizeof(struct node));

    printf("n1 = %p\n", (void*)n1);
    printf("n1 is pointer variable, its address = %p\n", (void*)&n1);
    printf("n2 = %p\n", (void*)n2);
    printf("n2 is pointer variable, its address = %p\n", (void*)&n2);
    printf("n3 = %p\n", (void*)n3);
    printf("n3 is pointer variable, its address = %p\n", (void*)&n3);

    head = n1;
    n1->data = 12;
    n1->next = n2;
    n2->data = 22;
    n2->next = n3;
    n3->data = 63;
    n3->next = NULL;

    struct node *temp = head;

    printf("\nLinked list:\n");
    while (temp != NULL) {
        printf("%d  %p -> ", temp->data, (void*)&temp->next);
        temp = temp->next;
    }
    printf("NULL\n");

    free(n1);
    free(n2);
    free(n3);

    return 0;
}