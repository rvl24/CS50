// Implements a dictionary's functionality
//Thanks to https://www.geeksforgeeks.org/trie-insert-and-search/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"

// Represents number of children for each node in a trie
#define N 27

//Counter to determine number of words in dictionary
int dict_size = 0;


//Define a trie node
typedef struct node
{
    bool is_word;
    struct node *children[N];
}
node;

// Represents first node of trie
node *root;

//Make a new trie node
node * make_node(void)
{
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL)
    {
        return false;
    }
    new_node->is_word = false;
    for (int i = 0; i < N; i++)
    {
        new_node->children[i] = NULL;
    }
    return new_node;
}

//Get index for node array from character
int get_index(char character)
{
    int index;
    if (character == '\'')
    {
        index = N - 1;
    }
    else
    {
        index = tolower(character) - 'a';
    }
    return index;
}

//free all nodes in a trie
void free_trie(node *current)
{
    for (int i = 0; i < N; i++)
    {
        if (current->children[i] != NULL)
        {
            free_trie(current->children[i]);
        }
    }
    free(current); 
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Initialize trie
    root = make_node();

    // Open dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        unload();
        return false;
    }

    // Buffer for a word
    char word[LENGTH + 1];
    // Insert words into trie
    while (fscanf(file, "%s", word) != EOF)
    {
        node *current = root;
        for(int i = 0, index = 0; i < strlen(word); i++)
        {
            index = get_index(word[i]);
            if (current->children[index] == NULL)
            {
                current->children[index] = make_node();
            }
            current = current->children[index];
        }
        current->is_word = true;
        dict_size++;
    }

    // Close dictionary
    fclose(file);

    // Indicate success
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return dict_size;
}

// Returns true if word is in dictionary else false
//This function assumes that there is at least one word in the dictinary that starts with every letter.
bool check(const char *word)
{
    node *current = root;
    int i = 0; 
    int index = get_index(word[i]);
    int word_length = strlen(word);

    //traverse the trie 
    while (i < word_length)
    {
        if (current->children[index] != NULL)
        {
            current = current->children[index];
            i++;
            index = get_index(word[i]);
        }
        else
        {
            return false;
        }
    }
    if (current->is_word)
    {
        return true;
    }
    else
    {
        return false;
    }
}


// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    node *current = root;
    free_trie(current); 
    return true; 
}
