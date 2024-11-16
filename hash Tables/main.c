// hash table with linear probing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10
#define DELETE_NODE (person *)(0xFFFFFFFFFFFFFUL)

typedef struct
{
  char name[MAX_NAME];
  int age;
} person;

person *hash_table[TABLE_SIZE];

unsigned int hash(char *name)
{
  int length = strnlen(name, MAX_NAME);
  unsigned int hash_value = 0;

  for (int i = 0; i < length; i++)
  {
    hash_value += name[i];
    hash_value = (hash_value * name[i]) % TABLE_SIZE;
  }
  return hash_value;
}

bool init_hash_table()
{
  for (int i = 0; i < TABLE_SIZE; i++)
    hash_table[i] = NULL;
}

void print_table()
{
  printf("\nSTART\n");
  for (int i = 0; i < TABLE_SIZE; i++)
  {
    if (hash_table[i] == NULL)
      printf("---\n");
    else if (hash_table[i] == DELETE_NODE)
      printf("---<deleted>\n");
    else
      printf("%s => %d\n", hash_table[i]->name, hash_table[i]->age);
  }
  printf("\nEND\n");
}

person *hash_table_lookup(char *name)
{
  int index = hash(name);
  for (int i = 0; i < TABLE_SIZE; i++)
  {
    int try = (i + index) % TABLE_SIZE;
    if (hash_table[try] == NULL)
      return false;
    if (hash_table[try] == DELETE_NODE)
      continue;
    if (hash_table[try] != NULL && strncmp(hash_table[try]->name, name, MAX_NAME) == 0)
      return hash_table[try];
  }
  return NULL;
}

bool hash_table_insert(person *p)
{
  if (p == NULL)
    return false;
  int index = hash(p->name);

  for (int i = 0; i < TABLE_SIZE; i++)
  {
    int try = (i + index) % TABLE_SIZE;
    if (hash_table[try] == NULL || hash_table[try] == DELETE_NODE)
    {
      hash_table[try] = p;
      return true;
    }
  }
  return false;
}

person *hash_table_delete(char *name)
{
  int index = hash(name);
  for (int i = 0; i < TABLE_SIZE; i++)
  {
    int try = (i + index) % TABLE_SIZE;
    if (hash_table[try] == NULL)
      return NULL;
    if (hash_table[try] == DELETE_NODE)
      continue;
    if (hash_table[try] != NULL && strncmp(hash_table[try]->name, name, TABLE_SIZE) == 0)
    {
      person *tmp = hash_table[try];
      hash_table[try] = DELETE_NODE;
      return tmp;
    }
  }
  return NULL;
}

int main()
{
  init_hash_table();

  person jacob = {.name = "jacob", .age = 256};
  person yash = {.name = "yash", .age = 25};
  person gugu = {.name = "gugu", .age = 26};
  person gaga = {.name = "gaga", .age = 56};
  person nigger = {.name = "nigger", .age = 65};

  hash_table_insert(&jacob);
  hash_table_insert(&yash);
  hash_table_insert(&gugu);
  hash_table_insert(&gaga);
  hash_table_insert(&nigger);

  hash_table_delete("jacob");

  person *tmp = hash_table_lookup("jacob");
  if (tmp != NULL)
    printf("Found %s\n", tmp->name);
  else
    printf("NOT FOUND \n");

  tmp = hash_table_lookup("gaga");
  if (tmp != NULL)
    printf("Found %s\n", tmp->name);
  else
    printf("NOT FOUND \n");

  print_table();

  // printf("Jacob=> %u\n", hash("Jacob"));
  // printf("Yash=> %u\n", hash("Yash"));
  // printf("Oni=> %u\n", hash("Oni"));
  // printf("Ayush=> %u\n", hash("Ayush"));
  // printf("Mishra=> %u\n", hash("Mishra"));
  // printf("gugu=> %u\n", hash("gugu"));
  // printf("gaga=> %u\n", hash("gaga"));
  // printf("nigger=> %u\n", hash("nigger"));
  // printf("man=> %u\n", hash("man"));
  // printf("shinchan=> %u\n", hash("shinchan"));
  return 0;
}