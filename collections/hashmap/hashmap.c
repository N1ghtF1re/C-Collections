//
// HASHMAP IMPLEMENTATION
//

/**
 * @file hashmap.c
 * @author Alexandr Pankratiew
 * @brief File containing implementation of hashMap
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include "hashmap.h"

#define true 1
#define false 0

/**
 * Creating a hash map
 * @param size - "basket" number
 * @return HashMap struct
 */
HashMap hashmap_create(int size) {
    HashMap map;
    map.size = size;
    map.table = (HashMapEntry**) malloc(size * sizeof(HashMapEntry*));
    for(int i = 0; i < size; i++) {
        HashMapEntry *entry = (HashMapEntry*) malloc(sizeof(HashMapEntry));
        entry->next = NULL;
        entry->hash = 0;
        map.table[i] = entry;
    }

    return map;
}

/**
 * Getting a hash for a key (String)
 * @param key - Key
 * @return hash for a key
 */
unsigned int hashmap_hashCode(Key key) {
    unsigned int hash = 5381;
    int c;

    while (c = *key++) {
        hash = ((hash << 5) + hash) ^ c;
    }
    return hash;
}

/**
 * Associates the specified value with the specified key in the map.
 * If the map previously contained a mapping for the key, the old value is replaced by the specified value.
 * @param key - key with which the specified value is to be associated
 * @param value - value to be associated with the specified key
 */
void hashmap_put(HashMap map, Key key, Value value) {
    if (key == NULL)
        exit(-1);
    unsigned int hash = hashmap_hashCode(key); // HASH OF STRING

    unsigned int i = hash % map.size; // INDEX IN TABLE (BASKET)
    HashMapEntry *e;

    // Check if there is such a key in the [i] item of the table. And if there is, replace the value
    for (e = map.table[i]; e != NULL; e = e->next) {
        Key k;
        if (e->hash == hash && ((k = e->key) == key || !strcmp(k, e->key))) {
            e->value = value;
            return;
        }
    }

    // If the key is new => add the item to the end

    HashMapEntry *el = (HashMapEntry*) malloc(sizeof(HashMapEntry));
    HashMapEntry *tmp = map.table[i];

    while(tmp->next) tmp = tmp->next;

    el->next = NULL;
    el->value = value;
    el->key = key;
    el->hash = hash;

    tmp->next = el;
}

/**
 * Returns the value to which the specified key is mapped
 * @param map HashMap
 * @param key the key whose associated value is to be returned
 * @return the value to which the specified key is mapped
 */
Value hashmap_get(HashMap map, Key key) {
    if (key == NULL) exit(-1);


    unsigned int hash = hashmap_hashCode(key);

    unsigned int i = hash % map.size; // INDEX IN TABLE (BUCKET)

    HashMapEntry *e;
    for (e=map.table[i]; e != NULL; e = e->next){
        Key k;
        if (e->hash == hash && ((k = e->key) == key || !strcmp(k, e->key)))
            return e->value;
    }

    errno = EINVAL;
    perror("Appeal to non-existent key");

    exit(-1); // an attempt to access a non-existent key is an undefined behavior. I do what I want ;)
}

/**
 * Returns 1 if this map contains a mapping for the specified key, otherwise - 0
 * @param map - HashMap
 * @param key - key whose presence in this map is to be tested
 * @return 1 if this map contains a mapping for the specified key
 */
int hashmap_containsKey(HashMap map, Key key) {
    if (key == NULL) exit(-1);

    unsigned int hash = hashmap_hashCode(key);
    unsigned int i = hash % map.size; // INDEX IN TABLE (BUCKET)

    HashMapEntry *e;
    for (e=map.table[i]; e != NULL; e = e->next){
        Key k;
        if (e->hash == hash && ((k = e->key) == key || !strcmp(k, e->key)))
            return true;
    }

    return false;
}

/**
 * Returns the number of key-value mappings in the map.
 *
 * @warning ATTENTION! FUNCTION DOES NOT RETURN NUMBER OF BASKETS. THIS INFORMATION IS STORED IN THE STRUCTURE HashMap
 *
 * @param map HashMap
 * @return number of key-value mappings in this map.
 */
int hashmap_size(HashMap map) {
    int size = 0;
    for(int i = 0; i < map.size; i++) {
        for(HashMapEntry *e = map.table[i]->next; e != NULL; e = e->next) {
            size++;
        }
    }

    return size;
}

/**
 * Returns 1 if this map contains no key-value mappings.
 * @param map HashMap
 * @return 1 if this map contains no key-value mappings
 */
int hashmap_isEmpty(HashMap map) {
    int size = hashmap_size(map);
    return size == 0 ? true : false;
}


/**
 * Returns a Array view of the mappings contained in the map.
 *
 * The array must be released by the caller.
 *
 * @param map Hashmap
 * @returna array view of the mappings contained in this map
 */
HashMapEntry* hashmap_entryArr(HashMap map) {
    int size = hashmap_size(map);

    HashMapEntry *arr = malloc(size * sizeof(HashMapEntry));

    int currentIndex = 0;

    for(int i = 0; i < map.size; i++) {
        for(HashMapEntry *e = map.table[i]->next; e != NULL; e = e->next) {
            arr[currentIndex++] = *e;
        }
    }

    return arr;
}

/**
 * Removes the mapping for a key from this map if it is present
 * @param map HashMap
 * @param key key whose mapping is to be removed from the map
 * @return the previous value associated with key
 */
HashMapEntry hashmap_remove(HashMap map, Key key) {
    if (key == NULL) exit(-1);


    unsigned int hash = hashmap_hashCode(key);

    unsigned int i = hash % map.size; // INDEX IN TABLE (BUCKET)

    HashMapEntry *e;
    HashMapEntry *prev = map.table[i];
    for (e=map.table[i]->next; e != NULL; e = e->next){
        Key k;
        if (e->hash == hash && ((k = e->key) == key || !strcmp(k, e->key))) {
            HashMapEntry entry = *e;
            prev->next = e->next;
            free(e);

            return entry;
        }
        prev = e;
    }
}

/**
 * Removes all of the mappings from the map
 * @param map HashMap
 */
void hashmap_clear(HashMap map) {
    int size = hashmap_size(map);

    for(int i = 0; i < map.size; i++) {
        for(HashMapEntry *e = map.table[i]->next; e != NULL; ) {
            HashMapEntry *next = e->next;
            free(e);
            e = next;
        }
        map.table[i]->next = NULL;
    }

}

/**
 * Destruction of the map
 * @param map HashMap
 */
void hashmap_removeMap(HashMap *map) {
    hashmap_clear(*map);
    for(int i = 0; i < (*map).size; i++) {
        free(map->table[i]);
    }
    free(map->table);
    (*map).size = -1;
    (*map).table = NULL;
}