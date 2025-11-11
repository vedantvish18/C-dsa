#include <stdio.h>

#define MAX_NAME_LENGTH 50

struct Person {
    int id;
    char name[MAX_NAME_LENGTH];
    int age;
};

int main() {
    struct Person people[100];
    FILE *file = fopen("data.txt", "r");

    if (!file) {
        printf("Could not open file.\n");
        return 1;
    }

    for (int i = 0; i < 100; i++) {
        if (fscanf(file, "%d %49s %d", &people[i].id, people[i].name, &people[i].age) != 3) {
            break;
        }
    }

    fclose(file);

    printf("ID\tName\t\tAge\n");
    for (int i = 0; i < 100; i++) {
        if (people[i].id != 0) {
            printf("%d\t%-15s\t%d\n", people[i].id, people[i].name, people[i].age);
        }
    }

    return 0;
}

