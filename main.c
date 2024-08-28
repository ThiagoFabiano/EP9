#include <stdio.h>
#include "hash.h"
#include "student.h"

int main(void) {
    Student *student1 = st_create(123450, "Maria", "maria@email.com", 'A');
    Student *student2 = st_create(123451, "Joao", "joao@email.com", 'B');

    
    Hash *tab1 = hsh_create(hash1);
    hsh_insert(tab1, student1);
    hsh_insert(tab1, student2);

    int ids[] = {123450, 123451, 123452};
    Student *student;
    printf("Testando hash 21:\n");
    for (int i = 0; i < 3; i++) {
        student = hsh_search(tab1, ids[i]);
        if (student)
            st_print(student);
        else
            printf("Record '%d' not found.\n", ids[i]);
    }
    hsh_free(tab1);

    
    Hash *tab2 = hsh_create(hash2);
    hsh_insert(tab2, student1);
    hsh_insert(tab2, student2);

    printf("\nTestando hash2:\n");
    for (int i = 0; i < 3; i++) {
        student = hsh_search(tab2, ids[i]);
        if (student)
            st_print(student);
        else
            printf("Record '%d' not found.\n", ids[i]);
    }
    hsh_free(tab2);

    return 0;
}
