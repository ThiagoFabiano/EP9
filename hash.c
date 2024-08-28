#include "hash.h"
#include <stdlib.h>
#include <string.h>

int hash1(int id) {
    return id % N;
}

int hash2(int id) {
    return (id / 10) % N;
}

Hash *hsh_create(HashFunctionPtr hash_function) {
    Hash *tab = (Hash *)malloc(sizeof(Hash));
    for (int i = 0; i < N; i++)
        tab->v[i] = NULL;
    tab->hash = hash_function; 
    return tab;
}

void hsh_free(Hash *tab) {
    for (int i = 0; i < N; i++)
        free(tab->v[i]);
    free(tab);
}

Student *hsh_search(Hash *tab, int id) {
    int h = tab->hash(id); 
    while (tab->v[h] != NULL) {
        if (st_get_id(tab->v[h]) == id)
            return tab->v[h];
        h = (h + 1) % N;
    }
    return NULL;
}

void hsh_insert(Hash *tab, Student *student) {
    int h = tab->hash(st_get_id(student)); 
    while (tab->v[h] != NULL)
        h = (h + 1) % N;
    tab->v[h] = student;
}
