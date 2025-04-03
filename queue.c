#include "queue.h"
#include "tile_game.h"

int check_state(size_t, struct queue*);

void enqueue(struct queue *q, struct game_state state) 
{
    size_t val = serialize(state);
    // printf("Add: %d\n", val);
    insert_at_head(&(q -> data), val);
}

struct game_state dequeue(struct queue *q) 
{
    size_t val = remove_from_tail(&(q -> data)); 
    return(deserialize(val)); 
}

int number_of_moves(struct game_state start) 
{ 
    
    struct queue q;
    //int first_val = serialize(start);
    //struct linked_list list; 
    //list.head = NULL;
    //q.data = list;
    enqueue(&q, start);
    // struct game_state new = dequeue(&q);
    // printf("%d %d\n", new.empty_col, new.empty_row);
    
    int cur_row;
    int cur_col;

    struct game_state cur;
    while(q.data.head != NULL)
    {
        
        cur = dequeue(&q);
        //fprintf(stderr, "here\n");
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
            //fprintf(stderr, "SUCESS!\n");
            free_list(q.data);
            return(cur.num_steps);
        }


        //printf("Here\n");
        cur_row = cur.empty_row;
        cur_col = cur.empty_col;
        if((cur_row) < 3)
        {
            struct game_state next = cur;
            move_up(&next);
            if(check_state(serialize(next), &q))
            {
                enqueue(&q, next);
            }
        }

        if((cur_row) > 0)
        {
            struct game_state next = cur;
            move_down(&next);
            if(check_state(serialize(next), &q))
            {
                enqueue(&q, next);
            }
        }

        if((cur_col) < 3)
        {
            struct game_state next = cur;
            move_left(&next);
            if(check_state(serialize(next), &q))
            {
                enqueue(&q, next);
            }
        }

        if((cur_col) > 0)
        {
            struct game_state next = cur;
            move_right(&next);
            if(check_state(serialize(next), &q))
            {
                enqueue(&q, next);
            }
        }
    }

    //free_list(q -> data);
    return -1; 
}

int check_state(size_t check, struct queue *q)
{
    if(q -> data.head != NULL)
    {
        struct list_node *node = q -> data.head;
        while((node -> next) != NULL)
        {
            if(check == node -> value)
            {
                return 0;
            }
            node = node -> next;
        }

        if(check == node -> value)
        {
            return 0;
        }
        return 1;
    }
    return 1;
}
