#pragma once

typedef enum action {
    ACTION_NULL,
    ACTION_MOVE,
    ACTION_WAIT,
} action;

typedef struct Action {
    action type;
    int row, col;   // these will change with more action types
} Action;

