#ifndef ACTION_H
#define ACTION_H

typedef enum action_t {
    ACTION_MOVE,
    ACTION_WAIT,
    ACTION_NULL,
} action_t;

typedef struct Action {
    action_t type;
    int row, col;   // these will change with more action types
} Action;

#endif

