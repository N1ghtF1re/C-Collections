//
// HASHMAP INTERFACE
//

#ifndef HASHMAP_H
#define HASHMAP_H

#include "../node.h"

typedef char* Key;
typedef NodeInfo Value;

typedef struct HashMapEntry {
    Key key;
    Value value;
    struct HashMapEntry *next;
    unsigned int hash;
} HashMapEntry;

typedef struct HashMap {
    int size;
    HashMapEntry **table;
} HashMap;

HashMap hashmap_create(int size);
unsigned int hashmap_hashCode(Key key);
void hashmap_put(HashMap map, Key key, Value value);
Value hashmap_get(HashMap map, Key key);
int hashmap_isEmpty(HashMap map);
int hashmap_containsKey(HashMap map, Key key);
int hashmap_size(HashMap map);
HashMapEntry hashmap_remove(HashMap map, Key key);
void hashmap_clear(HashMap map);
void hashmap_removeMap(HashMap *map);
HashMapEntry* hashmap_entryArr(HashMap map);

#endif //HASHMAP_H
