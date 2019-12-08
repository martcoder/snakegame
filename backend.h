#include <stdbool.h> //bool type (uchar) and true/false defines
#define ANACONDA_TIME 500

//enum to handle movement directions
enum Direction { UP, DOWN, LEFT, RIGHT, SPACE, ENTER };
enum Status { SUCCESS, FAILURE };
//Simply linked list of (x,y) points 
// x, y are text screen coordinates
// (0, 0) is top-left corner
// x = column
// y = row

//struct Coords{int x; int y; Coords* next;};

struct PointList {
  int x;
  int y;
  struct PointList* next;
  
  // For snakes
  char id;
  int score;
  int justScored; // delay countdown for score changed graphic
  enum Direction dir; // current direction
  int hasFireblock; // snake has picked up a fireblock bonus
  int usingSpecial; // special key has been pressed
  struct PointList* fireBlocks; // fireblock within a snake
  int anacondaCountdown; // to timeout anaconda mode

  // For fireblocks
  int beingFired; // if fireblock has been fired
  int independentOfSnake; // if fireblock is now travelling outside the snake
  int extinguishGraphics; // if the fireblock extinguish graphics need to be shown
};

typedef struct PointList PointList;

//typedef struct Coords Coords;

//struct containing the full game board info
typedef struct {
  PointList* snake; //list of snake points
  PointList* snakeB; 
  PointList* foods; //list of food points
  PointList* pvpbonus; // pvp bonus
  PointList* fireBonuses; // fireblocks bonus
  PointList* anacondaBonus; // anaconda super bonus
  PointList* maze; // list of maze blocks
  int xmax; //screen cols
  int ymax; // screen rows
  //Coords* generalCoords;
} Board;

//Checks if two point structures have the same coordinates
bool is_same_place(PointList* cell1, PointList* cell2);
// Changes the x and y values of the fireblock
void newFireBlockPosition(PointList* fireblock, Board* board);
// Move each fireblock
void move_fireblocks(Board* board, PointList* snakePtr);
//This function tries to move the full snake in the given direction
enum Status move_snake(Board* board, enum Direction dir, PointList* snake, int * pvp);
//shift snake does the actual tranferring of x,y coords each snake part in turn
void shift_snake(PointList* snakePtr, PointList* beginning, int addTail);
//Creates and returns a new snake point (the new snake's head position)
PointList* next_move(Board* board, enum Direction dir, PointList* snake);
//Creates a new point element dynamically allocating it
PointList* create_cell(int x, int y);
//creates a cell in a random location
PointList* create_random_cell(int xmax, int ymax);
//Generates the initial snake (length 2)
PointList* create_snake();
//fills in the Board structure from the given lists and dimensions
Board* create_board(PointList* foods, PointList* snake, PointList* snakeA, PointList* bonuses, PointList* anacondaBonus,PointList* maze, int xmax, int ymax);
// Checks if a given point is contained in a list of points
bool list_contains(PointList* cell, PointList* list);
bool list_contains_anaconda(PointList* beginning, PointList* list, PointList* snakePtr);
bool list_contains_fireblock(PointList* beginning, PointList* list);
//remove element elt from list, update list pointer
bool remove_from_list(PointList* elt, PointList** list);
// change item x and y to different values
bool change_coords(PointList* item, Board* board);
// Updates the item in list's coordinates if in anaconda
void update_item_coords_in_list_if_in_anaconda(PointList* beginning, PointList* list, Board* board);
void update_item_coords_in_list_if_in_fireblock(PointList* beginning, PointList* list, Board* board);
// Updates the item in list's coordinates if same as new point
void update_item_coords_in_list(PointList* beginning, PointList* list, Board* board);
//Adds a new food point to the food list in a random location
void add_new_food(Board* board);

void add_new_bonus(Board* board);

void add_new_firebonus(Board* board);

void add_new_anacondabonus(Board* board);

void add_snake(Board* board);

void add_fireblock_tosnake(PointList* snakePtr);
