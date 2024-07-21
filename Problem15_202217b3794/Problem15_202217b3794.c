#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Linked List node
struct node {
    char* key;
    char* value;
    struct node* next;
};

// Initialize a node
struct node* createNode(char* key, char* value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->key = (char*)malloc(strlen(key) + 1);
    strcpy(newNode->key, key);
    newNode->value = (char*)malloc(strlen(value) + 1);
    strcpy(newNode->value, value);
    newNode->next = NULL;
    return newNode;
}

// Hash Table structure
struct hashMap {
    int numOfElements;
    int capacity;
    struct node** arr;
};

// Initialize hash table
void initializeHashMap(struct hashMap* mp) {
    mp->capacity = 100; // Default capacity
    mp->numOfElements = 0;
    mp->arr = (struct node**)malloc(mp->capacity * sizeof(struct node*));
    if (mp->arr == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < mp->capacity; ++i) {
        mp->arr[i] = NULL;
    }
}

// Hash function
int hashFunction(struct hashMap* mp, char* key) {
    unsigned long hash = 5381;
    int c;
    while ((c = *key++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % mp->capacity;
}

// Insert key-value pair into hash table
void insert(struct hashMap* mp, char* key, char* value) {
    int bucketIndex = hashFunction(mp, key);
    struct node* newNode = createNode(key, value);
    
    if (mp->arr[bucketIndex] == NULL) {
        mp->arr[bucketIndex] = newNode;
    } else {
        newNode->next = mp->arr[bucketIndex];
        mp->arr[bucketIndex] = newNode;
    }
    mp->numOfElements++;
}

// Search for a key in the hash table
char* search(struct hashMap* mp, char* key) {
    int bucketIndex = hashFunction(mp, key);
    struct node* currNode = mp->arr[bucketIndex];
    
    while (currNode != NULL) {
        if (strcmp(currNode->key, key) == 0) {
            return currNode->value;
        }
        currNode = currNode->next;
    }
    
    return "Oops! No data found.\n";
}

// Delete a key from the hash table
void delete (struct hashMap* mp, char* key) {
    int bucketIndex = hashFunction(mp, key);
    struct node* prevNode = NULL;
    struct node* currNode = mp->arr[bucketIndex];
    
    while (currNode != NULL) {
        if (strcmp(currNode->key, key) == 0) {
            if (prevNode == NULL) {
                mp->arr[bucketIndex] = currNode->next;
            } else {
                prevNode->next = currNode->next;
            }
            free(currNode->key);
            free(currNode->value);
            free(currNode);
            mp->numOfElements--;
            return;
        }
        prevNode = currNode;
        currNode = currNode->next;
    }
}

// Driver code
int main() {
    struct hashMap* mp = (struct hashMap*)malloc(sizeof(struct hashMap));
    if (mp == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    initializeHashMap(mp);

    insert(mp, "Yogaholic", "Anjali");
    insert(mp, "pluto14", "Vartika");
    insert(mp, "elite_Programmer", "Manish");
    insert(mp, "GFG", "BITS");
    insert(mp, "decentBoy", "Mayank");

    printf("%s\n", search(mp, "elite_Programmer"));
    printf("%s\n", search(mp, "Yogaholic"));
    printf("%s\n", search(mp, "pluto14"));
    printf("%s\n", search(mp, "decentBoy"));
    printf("%s\n", search(mp, "GFG"));

    delete(mp, "decentBoy");
    printf("\nAfter deletion:\n");
    printf("%s\n", search(mp, "decentBoy"));

    // Clean up
    for (int i = 0; i < mp->capacity; ++i) {
        struct node* temp = mp->arr[i];
        while (temp != NULL) {
            struct node* next = temp->next;
            free(temp->key);
            free(temp->value);
            free(temp);
            temp = next;
        }
    }
    free(mp->arr);
    free(mp);
    
    return 0;
}
