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
        
        if(cur.num_steps == 1/*find end condition*/)
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
