cmake_minimum_required(VERSION 3.12)
project(CCollections C)

set(CMAKE_C_STANDARD 99)

add_executable(CCollections main.c collections/list/list.h collections/list/list.c collections/stack/stack.h collections/node.h collections/stack/stack.c collections/queue/queue.c collections/queue/queue.h collections/hashmap/hashmap.c collections/hashmap/hashmap.h)
