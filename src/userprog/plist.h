#ifndef _PLIST_H_
#define _PLIST_H_


/* Place functions to handle a running process here (process list).
   
   plist.h : Your function declarations and documentation.
   plist.c : Your implementation.

   The following is strongly recommended:

   - A function that given process inforamtion (up to you to create)
     inserts this in a list of running processes and return an integer
     that can be used to find the information later on.

   - A function that given an integer (obtained from above function)
     FIND the process information in the list. Should return some
     failure code if no process matching the integer is in the list.
     Or, optionally, several functions to access any information of a
     particular process that you currently need.

   - A function that given an integer REMOVE the process information
     from the list. Should only remove the information when no process
     or thread need it anymore, but must guarantee it is always
     removed EVENTUALLY.
     
   - A function that print the entire content of the list in a nice,
     clean, readable format.
     
 */

/* do not forget the guard against multiple includes */
#pragma once 
#include <stdbool.h>
#include <stddef.h> 
#include "threads/synch.h"

#define PLISTMAP_SIZE 128

extern struct lock plock;

struct processMeta
{
    bool free;
    int proc_id;
    int parent_id;
    int exit_status;
    bool alive;
    bool parent_alive;
    struct semaphore psema; 
};

typedef struct processMeta value_p;
typedef int key_p; 

struct plist
{
    value_p content[PLISTMAP_SIZE];
};

void plist_init(struct plist* m);
key_p plist_insert(struct plist* m, int proc_id, int parent_id);
void plist_remove(struct plist* m, key_p k);
void plist_print(const struct plist* m); 
value_p* plist_find(struct plist* m, key_p id);
void plist_set_status(struct plist* m, key_p id, int status);


#endif
