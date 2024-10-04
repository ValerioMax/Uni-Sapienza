#ifndef __NODE_T__
#define __NODE_T__

typedef struct node_t {
    short elem;             //+0
    struct node_t *next;    //+4
} node_t;                   //sizeof(struct node_t) = 8

void list_new(node_t **l);
int  list_new_from_buffer(node_t **l, short* buf, int n);
void list_delete(node_t **l);
int  list_add_first(node_t **l, short elem);  // <---
int  list_size(const node_t *p);
int  list_sum(const node_t *l);
int  list_equal(const node_t *l1, const node_t *l2);
int  list_find(const node_t *p, short x);
void list_print(const node_t *p);

#endif
