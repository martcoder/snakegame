// Additional comments by Mario Mata, GCU
#include "backend.h" //core functionalities and data structures
#include "frontend.h" //paint functions and key processing
#include "maze.h"
#include "splash.h"
#include <ncurses.h>

void draw(Board* board){
	start_color();
    // from https://stackoverflow.com/questions/10487166/ncurses-multi-colors-on-screenv 
    init_pair(1, COLOR_BLACK, COLOR_RED);
    init_pair(2, COLOR_BLACK, COLOR_GREEN);
    init_pair(3, COLOR_WHITE, COLOR_BLACK);
    init_pair(9, COLOR_WHITE, COLOR_BLUE);
    init_pair(8, COLOR_CYAN, COLOR_BLACK);
    init_pair(12, COLOR_CYAN, COLOR_GREEN);
    init_pair(14, COLOR_CYAN, COLOR_RED);
    init_pair(38, COLOR_BLUE, COLOR_MAGENTA);
    
    // draw the scores
    if(board->snake)
      showScores(board->snake,board->xmax,board->ymax);
    

    if(board->snakeB) 
        showScores(board->snakeB,board->xmax,board->ymax); 

    // draw snake
	attron(COLOR_PAIR(1));
	display_points(board,board->snake, ACS_BLOCK); 

    // draw snakeB
	attron(COLOR_PAIR(2));
    display_points(board,board->snakeB, ACS_BLOCK); 
    
    // draw foods
    attron(COLOR_PAIR(3));
    display_points(board,board->foods, ACS_DIAMOND);
    
    // draw pvp bonus   
    attron(COLOR_PAIR(2));
    display_points(board,board->pvpbonus, 167);
    
    // draw fireblock bonus
    attron(COLOR_PAIR(9));
    display_points(board,board->fireBonuses, 230);
    
    // draw anaconda bonus
    attron(COLOR_PAIR(38));
    display_points(board,board->anacondaBonus, 198);
    
    // draw fireblocks
    attron(COLOR_PAIR(8));
    if(board->snake->fireBlocks){
	  if(board->snake->fireBlocks->beingFired == 1)
        display_points(board,board->snake->fireBlocks, 230);
	}
	if(board->snakeB){
	  if(board->snakeB->fireBlocks){
        if(board->snakeB->fireBlocks->beingFired == 1)
          display_points(board,board->snakeB->fireBlocks, 230);
      }
    }
    
    // draw the maze blocks
    init_pair(34, COLOR_BLACK, COLOR_YELLOW);
    attron(COLOR_PAIR(34));
    show_maze(board->maze);
    
    

    
    refresh(); //paint screen
}

void moveFireblocks(Board* board){
 
  	if(board->snake->fireBlocks){
	  if(board->snake->fireBlocks->beingFired == 1)
        move_fireblocks(board,board->snake);
    }
    
    if(board->snakeB){
	  if(board->snakeB->fireBlocks){
        if(board->snakeB->fireBlocks->beingFired == 1)
          move_fireblocks(board,board->snakeB);
      }
    }

}

int main() {
  //ncurses screen initialization
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE); // make ncurses handle key presses
  curs_set(0); // hide cursor
  
  int xmax;
  int ymax;
  //get current text screen size
  getmaxyx(stdscr, ymax, xmax); //it is a macro, no & needed in ymax, xmax

  splashScreen(xmax,ymax);

  //start snake moving to the right
  enum Direction dir_playerA = RIGHT;
  enum Direction dir_playerB = DOWN;
  enum Direction * dir_playerAptr = &dir_playerA; 
  enum Direction * dir_playerBptr = &dir_playerB; 

  //create snake list, and pass it to create_board.
  // snakeA doesnt exist yet, passing as NULL
    //Food list is not passed yet (NULL passed instead).
    // Bonus list doesnt exist yet, passing as NULL. 
  Board* board = create_board(create_snake(), NULL, NULL, NULL, NULL, create_maze(xmax,ymax), xmax, ymax);
  int i;
  for (i = 0; i < board->xmax -50; i++) { // base the number of foods on the size of the board
    add_new_food(board); //add food pieces to the board
  }
  
  // Add pvp bonus to board
  add_new_bonus(board);
  // Add firesnake bonus to board
  add_new_firebonus(board);
  // Add anaconda super bonus to board
  add_new_anacondabonus(board);
  
  //MAIN LOOP
  while(true) {
    clear(); //clear screen
	//Draw snake and food lists
    draw(board);
    
    // first time
    moveFireblocks(board);

    // to show updated fireblocks
    //draw(board);wdsdwwdawdaw
    
    
    //showScores(board);
    
    refresh(); //paint screen

    
    int pvpactivator = 1;
    int * pvp = &pvpactivator;
    
    int pAscore = 0;
    int * pAscorePtr = &pAscore;
    
    int pBscore = 0;
    int * pBscorePtr = &pBscore;
    
    
    
    get_next_move(*dir_playerAptr, *dir_playerBptr, dir_playerAptr, dir_playerBptr,board->snake,board->snakeB ? board->snakeB : NULL); //get next move direction
	//update snake direction
    enum Status status = move_snake(board, *dir_playerAptr,board->snake, pvp);
    
    if (status == FAILURE) break; //finish game

    if(board->snakeB){
      
       status = move_snake(board, *dir_playerBptr,board->snakeB, pvp);
      if (status == FAILURE) break; //finish game
    }
    
    //Move fireblocks for 2nd time to simulate double speed
    moveFireblocks(board);
    
    // Show 2 player splash screen if that bonus has been activated
    if(*pvp == 0){
	  	timeout(10000); //do not keep waiting for keypress longer than this
  
        //get current text screen size
        getmaxyx(stdscr, ymax, xmax); //it is a macro, no & needed in ymax, xmax

        splash2player(xmax,ymax);
        
        *pvp = 1; // deactivate again
	}
	
	
	
	// If anaconda in play is about to expire, add new anaconda bonus to board
	if(board->snakeB){
	  if(board->snakeB->anacondaCountdown == ANACONDA_TIME)
	    splashAnaconda(board->xmax,board->ymax);
	  if(	board->snakeB->anacondaCountdown > 0 &&  board->snakeB->anacondaCountdown < 3 ){
	    add_new_anacondabonus(board);
	  }
	}
	if(board->snake->anacondaCountdown == ANACONDA_TIME)
	  splashAnaconda(board->xmax,board->ymax);
	if(board->snake->anacondaCountdown > 0 && board->snake->anacondaCountdown < 3 ){
	  	add_new_anacondabonus(board);
	}
    
  }
  //release ncurses resources
  endwin();

  return 0;
}
