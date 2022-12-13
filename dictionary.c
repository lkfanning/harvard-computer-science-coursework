// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <strings.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Declare variables
unsigned int word_count;
unsigned int hash_value;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO: take a word and check to see if it's in the dictionary or not

    // Hash word to obtain a hash value
    hash_value = hash(word);

    // Access linked list at that index in the hash table
    node *cursor = table[hash_value];

    // Traverse linked list, start with cursor set to first item in linked list
    while (cursor != 0)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function: takes an input word, outputs a numerical index between 0 and n-1
    unsigned long total = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        total += tolower(word[i]);
    }
    return total % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open dictionary file: use fopen, check if return value is null
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("Unable to open %s\n", dictionary);
        return false;
    }

    // Declare a variable called word
    char word[LENGTH + 1];
    // Read strings from file one at a time, return "EOF" when it reaches end of file
    while (fscanf(file, "%s", word) != EOF)
    {
        // Create a new node for each word, use malloc, check if return value is NULL
        node *n = malloc(sizeof(node));

        // If malloc returns NULL, return false
        if (n == NULL)
        {
            return false;
        }

        // Hash word to obtain a hash value, use the hash function, takes a string returns an index
        strcpy(n->word, word);
        hash_value = hash(word);
        n->next = table[hash_value];
        table[hash_value] = n;
        word_count++;
    }

    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO: return the number of words in your dictionary, keep track as you load the hash table
    if (word_count > 0)
    {
        return word_count;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO: free up any memory you've allocated using the spell checker
    // Iterate through buckets
    for (int i = 0; i < N; i++)
    {
        // Set cursor to the start of the linked list
        node *cursor = table[i];

        //If cursor is not NULL, free memory
        while (cursor != NULL)
        {
            // Create temp
            node *tmp = cursor;

            // Move cursor to the next node
            cursor = cursor->next;

            //Free up temp
            free(tmp);
        }

        // If cursor is NULL
        if (cursor == NULL && i == N - 1)
        {
            return true;
        }
    }
    return false;
}
