#include "queue.h"
#include "tile_game.h"

void enqueue(struct queue *q, struct game_state state) 
{
    int val = serialize(state);
    insert_at_head(&(q -> data), val);
}

struct game_state dequeue(struct queue *q) 
{
    int val = remove_from_tail(&(q -> data)); 
    return(deserialize(val)); 
}

int number_of_moves(struct game_state start) 
{ 
    struct queue q;
    struct linked_list list; 
    int cur_row;
    int cur_col;
    int steps = 0;
    list.head = NULL;
    q.data = list;
    enqueue(&q, start);
    struct game_state cur;
    while(q.data.head != NULL)
    {
        if(steps == 0)
        {
            cur = start;
        }
        else
        {
            cur = dequeue(&q);
        }
        
        if(cur.tiles[0][0] == 1 && 
           cur.tiles[0][1] == 2 &&
           cur.tiles[0][2] == 3 &&
           cur.tiles[0][3] == 4 &&
           cur.tiles[1][0] == 5 &&
           cur.tiles[1][1] == 6 &&
           cur.tiles[1][2] == 7 &&
           cur.tiles[1][3] == 8 &&
           cur.tiles[2][0] == 9 &&
           cur.tiles[2][1] == 10 &&
           cur.tiles[2][2] == 11 &&
           cur.tiles[2][3] == 12 &&
           cur.tiles[3][0] == 13 &&
           cur.tiles[3][1] == 14 &&
           cur.tiles[3][2] == 15)
        {
            return(cur.num_steps);
        }

        else
        {
            cur_row = cur.empty_row;
            cur_col = cur.empty_col;
            if((cur_row + 1) < 4)
            {
                steps = steps + 1;
                struct game_state next = cur;
                next.num_steps = steps;
                move_down(&next);
                enqueue(&q, next);
            }

            if((cur_row - 1) > -1)
            {
                steps = steps + 1;
                struct game_state next = cur;
                next.num_steps = steps;
                move_up(&next);
                enqueue(&q, next);
            }

            if((cur_col + 1) < 4)
            {
                steps = steps + 1;
                struct game_state next = cur;
                next.num_steps = steps;
                move_right(&next);
                enqueue(&q, next);
            }

            if((cur_col - 1) > -1)
            {
                steps = steps + 1;
                struct game_state next = cur;
                next.num_steps = steps;
                move_left(&next);
                enqueue(&q, next);
            }
        }
    }
    free_list(list);
    return steps; 
}
