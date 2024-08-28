#ifndef HASH_H
#define HASH_H

#include "student.h"

#define N 101

typedef int (*HashFunctionPtr)(int); 

typedef struct hash {
    Student *v[N];
    HashFunctionPtr hash; 
} Hash;

int hash1(int id);  
int hash2(int id);  

Hash *hsh_create(HashFunctionPtr hash_function);
void hsh_free(Hash *tab);
Student *hsh_search(Hash *tab, int id);
void hsh_insert(Hash *tab, Student *student);

#endif
