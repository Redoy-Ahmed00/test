// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 709;
int wordcount = 0;

// Hash table
node *table[N] = {NULL};
// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    unsigned int idx = 0;
    idx = hash(word);
    node *trav = table[idx];
    while (trav != NULL)
    {
        if (strcasecmp(trav->word, word) == 0)
        {
            return true;
        }
        trav = trav->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    //word frequency accoding to University of notre dome
    int frequency[] = {80, 16, 30, 44, 120, 20, 17, 64, 80, 4, 8, 40, 30, 80,
                       80, 17, 5, 62, 80, 90, 34, 12, 20, 4, 20, 2};
    unsigned long value = 0;
    int length = strlen(word);
    for(int i = 0; i < length; i++)
    {
       if (ispunct(word[i]) == 0)
        {
            value += tolower(word[i]) * (frequency[(tolower(word[i]) - 'a')]) % 26;
            return value % N;
        }
        value += tolower(word[i]) * (frequency[(tolower(word[i]) - 'a')]);
    }
    return value % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *fptr = fopen(dictionary, "r");
    if (fptr == NULL)
    {
        printf("Couldn't open %s file", dictionary);
        return false;
    }

    // 2. read words from file and store them in hash table.
    //  we need a buffer to store word and a int to word count.
    //   there you have it the loooop

    char buffer[LENGTH + 1];

    while (fscanf(fptr, "%s", buffer) != EOF)
    {
        node *n = (node *) malloc(sizeof(node));
        if (n == NULL)
        {
            fclose(fptr);
            unload();
            return false;
        }

        //copying
        strcpy(n->word, buffer);
        n->next = NULL;

        // now hashword.

        unsigned int idx = hash(n->word);

        //head
        node *head = table[idx];
        if (head == NULL)
        {
            table[idx] = n;
            wordcount++;
        }
        else
        {
            n->next = table[idx];
            table[idx] = n;
            wordcount++
        }
    }
    fclose(fptr);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    if (wordcount > 0)
        return wordcount;
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *trav = table[i];
        while (trav != NULL)
        {
            node *temp = trav;
            trav = trav->next;
            free(temp);
        }
        if (trav == NULL)
        {
            return true;
        }
    }
    return false;
}
