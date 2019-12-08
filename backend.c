#include "backend.h"
#include "maze.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>



/*
 * Removes from the list or returns false
 */
//Searches for element elt in the list 
//and removes it (updating the list pointers)
//As the original list is modified, the function accesses it
//via pointer (thus the **list)
bool remove_from_list(PointList* elt, PointList** list) {
  PointList *currP, *prevP;
  prevP = NULL;

  for (currP = *list;
      currP != NULL;
      prevP = currP, currP = currP->next) {
    if (is_same_place(currP, elt)) {
      if (prevP == NULL) {
        *list = currP->next;
      } else {
        prevP->next = currP->next;
      }
      free(currP);
      return true;
    }
  }
  return false;
}
// change existing item's coordinates to different values, e.g. to simulate an item being eaten and respawning somewhere else
bool change_coords(PointList* item, Board* board) {
	PointList* newcell;
	int foundNewLocation = 0;
  if(item){

	while(!foundNewLocation){
	  newcell = create_cell(rand() % board->xmax, rand() % board->ymax);
      if( list_contains(newcell, board->maze) 
      || list_contains(newcell, board->pvpbonus) 
      || list_contains(newcell, board->foods ) 
      || list_contains(newcell, board->snake ) 
      || list_contains(newcell, board->snakeB) 
      || list_contains_fireblock(board->snake->fireBlocks,newcell)
      || (board->snakeB) == NULL ? 0 : list_contains_fireblock(board->snakeB->fireBlocks,newcell)
      || list_contains_anaconda( board->snake, newcell, board->snake) 
      || (board->snakeB) == NULL ? 0 : list_contains_anaconda(board->snakeB,newcell, board->snakeB) )
        foundNewLocation = 0;
      else
        foundNewLocation = 1;
	}
	item->x = newcell->x;
	item->y = newcell->y;
	return true;
  }
  return false;
}

// based on a new location, it goes through each anaconda head point and for each point loops through list to see if list point is in anaconda head, if so it updates list point coordinates 
void update_item_coords_in_list_if_in_anaconda(PointList* beginning, PointList* list, Board* board){
	

	PointList* listLocal = list; // e.g. food list, firebonus list, etc
	PointList* anacondaPoint = create_cell(beginning->x,beginning->y);
	
	// go through list and see if item in list matches an anaconda location
	while(listLocal){
	  // if this element in the list equals an anaconda point, change coords of element
	  if(anacondaPoint->x == listLocal->x && anacondaPoint->y == listLocal->y) // location match
	    change_coords(listLocal,board); 
	  listLocal = listLocal->next;
	}
	
	listLocal = list; // reset pointer
	anacondaPoint->x = anacondaPoint->x + 1;
	anacondaPoint->y = anacondaPoint->y + 1;
	// go through list and see if item in list matches an anaconda location
	while(listLocal){
	  // if this element in the list equals an anaconda point, change coords of element
	  if(anacondaPoint->x == listLocal->x && anacondaPoint->y == listLocal->y)
	    change_coords(listLocal,board); 
	  listLocal = listLocal->next;
	}
		
	listLocal = list; // reset pointer
	anacondaPoint->x = anacondaPoint->x + 1;
    anacondaPoint->y = anacondaPoint->y + 1;
	while(listLocal){
	  // if this element in the list equals an anaconda point, change coords of element
	  if(anacondaPoint->x == listLocal->x && anacondaPoint->y == listLocal->y)
	    change_coords(listLocal,board); 
	  listLocal = listLocal->next;
   }
	  	
   listLocal = list; // reset pointer
   anacondaPoint->x = anacondaPoint->x + -3;
   anacondaPoint->y = anacondaPoint->y + -3;
   while(listLocal){
	// if this element in the list equals an anaconda point, change coords of element
	if(anacondaPoint->x == listLocal->x && anacondaPoint->y == listLocal->y)
	  change_coords(listLocal,board); 
	listLocal = listLocal->next;
  }
	  	
  listLocal = list; // reset pointer
  anacondaPoint->x = anacondaPoint->x + -1;
  anacondaPoint->y = anacondaPoint->y + -1;
  while(listLocal){
	// if this element in the list equals an anaconda point, change coords of element
	if(anacondaPoint->x == listLocal->x && anacondaPoint->y == listLocal->y)
	  change_coords(listLocal,board); 
	listLocal = listLocal->next;
  }
}
// check all items in the list to see if they match beginning, if so change the coords of that item, e.g. that item will be eaten
void update_item_coords_in_list(PointList* beginning, PointList* list, Board* board){
	
	PointList* listLocal = list; // e.g. food list, firebonus list, etc
	PointList* point = create_cell(beginning->x,beginning->y);
	
	// go through list and see if item in list matches the beginning location
    while(listLocal){
	  // if this element in the list equals the point, change coords of element
	  if(point->x == listLocal->x && point->y == listLocal->y) // location match
		change_coords(listLocal,board); 
	  listLocal = listLocal->next;
	}
}

// based on a new location, it goes through each fireblock point plus aura shifts and for each point loops through list to see if list point is in fireblock, if so it updates list point coordinates 
void update_item_coords_in_list_if_in_fireblock(PointList* beginning, PointList* list, Board* board){
	
	PointList* listLocal = list; // e.g. food list, firebonus list, etc
	PointList* fireblockPoint = create_cell(beginning->x,beginning->y);
	
	// go through list and see if item in list matches an anaconda location
	while(listLocal){
	  // if this element in the list equals an anaconda point, change coords of element
	  if(fireblockPoint->x == listLocal->x && fireblockPoint->y == listLocal->y) // location match
	    change_coords(listLocal,board); 
	  listLocal = listLocal->next;
	}
	
	//mvaddch(snake->y + 1, snake->x + 1, 230);
	listLocal = list; // reset pointer
	fireblockPoint->x = beginning->x + 1;
	fireblockPoint->y = beginning->y + 1;
	// go through list and see if item in list matches an anaconda location
	while(listLocal){
	  // if this element in the list equals an anaconda point, change coords of element
	  if(fireblockPoint->x == listLocal->x && fireblockPoint->y == listLocal->y)
	    change_coords(listLocal,board); 
	  listLocal = listLocal->next;
	}
		
		//mvaddch(snake->y, snake->x + 1, 230);
	listLocal = list; // reset pointer
	fireblockPoint->x = beginning->x + 1;
    fireblockPoint->y = beginning->y;
	while(listLocal){
	  // if this element in the list equals an anaconda point, change coords of element
	  if(fireblockPoint->x == listLocal->x && fireblockPoint->y == listLocal->y)
	    change_coords(listLocal,board); 
	  listLocal = listLocal->next;
   }
	  	
	  	//mvaddch(snake->y, snake->x - 1, 230);
   listLocal = list; // reset pointer
   fireblockPoint->x = beginning->x - 1;
   fireblockPoint->y = beginning->y;
   while(listLocal){
	// if this element in the list equals an anaconda point, change coords of element
	if(fireblockPoint->x == listLocal->x && fireblockPoint->y == listLocal->y)
	  change_coords(listLocal,board); 
	listLocal = listLocal->next;
  }
	  	
	  	 //mvaddch(snake->y + 1, snake->x, 230);
  listLocal = list; // reset pointer
  fireblockPoint->x = beginning->x ;
  fireblockPoint->y = beginning->y + 1;
  while(listLocal){
	// if this element in the list equals an anaconda point, change coords of element
	if(fireblockPoint->x == listLocal->x && fireblockPoint->y == listLocal->y)
	  change_coords(listLocal,board); 
	listLocal = listLocal->next;
  }
  
  //mvaddch(snake->y - 1, snake->x, 230);
  listLocal = list; // reset pointer
  fireblockPoint->x = beginning->x ;
  fireblockPoint->y = beginning->y - 1;
  while(listLocal){
	// if this element in the list equals an anaconda point, change coords of element
	if(fireblockPoint->x == listLocal->x && fireblockPoint->y == listLocal->y)
	  change_coords(listLocal,board); 
	listLocal = listLocal->next;
  }
  
  
  
  //mvaddch(snake->y -1, snake->x - 1, 230);
  listLocal = list; // reset pointer
  fireblockPoint->x = beginning->x - 1;
  fireblockPoint->y = beginning->y - 1;
  while(listLocal){
	// if this element in the list equals an anaconda point, change coords of element
	if(fireblockPoint->x == listLocal->x && fireblockPoint->y == listLocal->y)
	  change_coords(listLocal,board); 
	listLocal = listLocal->next;
  }
  
}

void newFireBlockPosition(PointList* fireblock, Board* board){
	// Update location based on direction of fireblock
    if(fireblock->dir == UP)
	  fireblock->y = fireblock->y - 1;
	if(fireblock->dir == DOWN)
	  fireblock->y = fireblock->y + 1;
	if(fireblock->dir == LEFT)
	  fireblock->x = fireblock->x - 1;
	if(fireblock->dir == RIGHT)
	  fireblock->x = fireblock->x + 1;
	  
	// Allow to wrap through walls
	/*if(fireblock->x > board->xmax)
	  fireblock->x = 1;
	if(fireblock->x < 0)
	  fireblock->x = board->xmax;
	if(fireblock->y > board->ymax)
	  fireblock->y = 1;
	if(fireblock->y < 0)
	  fireblock->y = board->ymax;
	*/
}

// This function moves each fireblock in its starting direction
void move_fireblocks(Board* board, PointList* snakePtr){
	
	if(snakePtr->fireBlocks->beingFired == 1){ // if fireblock being fired, go ahead and move it
		
		PointList* fires = snakePtr->fireBlocks;
		
		if(fires->independentOfSnake == 0){ // if not independent of snake yet, take x y and dir from snake
		  fires->x = snakePtr->x;
		  fires->y = snakePtr->y;
		  fires->dir = snakePtr->dir;
		}
		
		fires->independentOfSnake = 1; // activate
		
		//PointList* newfireCoords = create_cell(fires->x,fires->y);
		
		// Update location based on direction of fireblock
		newFireBlockPosition(fires, board);
		
		// if fireblock will hit a food, increment snake score!!! remove that food, and add another new food
		if (list_contains_fireblock(fires,board->foods)) {
			snakePtr->score = snakePtr->score + 1; // I suspect I might have a race condition for this variable
			snakePtr->justScored = 4;
			//remove_from_list(fires, &(board->foods));
			update_item_coords_in_list_if_in_fireblock(fires,board->foods,board);
	        //add a new food at a random location
            //add_new_food(board);
            
		}
		// Extinguish fireblock if edge of terminal is reached
		if( (fires->x > board->xmax) || (fires->x < 0) || (fires->y > board->ymax) || (fires->y < 0) ){
		    fires->beingFired = 0; //deactivate
            fires->independentOfSnake = 1; //deactivate
            fires->extinguishGraphics = 1;
		}
	}	
}

//This function tries to move the full snake in the given direction
//returns FAILURE if a game termination condition arises 
enum Status move_snake(Board* board, enum Direction dir, PointList* snake, int * pvp) {
  
  PointList* snakePtr = snake; 
  snakePtr->dir = dir;

  // Create a new beginning for the snake (head) with next_move
  PointList* beginning = NULL;
  beginning = next_move(board, dir, snakePtr);
  if (beginning == NULL) { //wall hit, next_move returned NULL
    return FAILURE;
  }

  // If we've gone backwards, don't do anything
  if (snakePtr->next && is_same_place(beginning, snakePtr->next)) {
    beginning->next = NULL;
    free(beginning);
    return SUCCESS;
  }

  // Check for collisions of snake head with other snake points
  if (list_contains(beginning, snakePtr)) {
    return FAILURE; //snake collided with itself!
  }
  
  // Check for collision with maze walls
  if (list_contains(beginning, board->maze)){ // if snake has hit the maze
    // decrement score
    if(snakePtr->score > -9 )
      snakePtr->score = snakePtr->score - 1;
    snakePtr->justScored = 5; // set delay timer
    // dont do anything more 
    return SUCCESS;
  }
  
  // if snake consumes anaconda super bonus
  if (list_contains(beginning, board->anacondaBonus)){ // if snake has hit a superbonus
    remove_from_list( beginning, &(board->anacondaBonus) ); // remove bonus from board
    snakePtr->anacondaCountdown = ANACONDA_TIME; // activate Anaconda Mode by setting countdown value, counts down in frontend.c, gets checked in main.c
  }

  if (list_contains(beginning, board->pvpbonus) || list_contains_anaconda(beginning,board->pvpbonus,snakePtr)){ // if snake has hit a bonus
    //take the pvpbonus off the board
    board->pvpbonus->x = -10;
    board->pvpbonus->y = -10;
    //add_new_bonus(board); // add a new bonus randomly on the board
    add_snake(board); // add the bonus snake to the board!!!
    *pvp = 0; // set pvp to active
  }
  
  if (list_contains(beginning, board->fireBonuses) || list_contains_anaconda(beginning,board->fireBonuses,snakePtr)){ // if snake has hit a firebonus
    //remove_from_list( beginning, &(board->fireBonuses) ); // remove bonus from board
    
    // remove anaconda eaten firebonus
    if(snakePtr->anacondaCountdown > 0){
		 update_item_coords_in_list_if_in_anaconda(beginning,board->fireBonuses,board);
		//update_item_coords_if_in_anaconda(beginning,board->fireBonuses,board);
	}
	else{
		add_new_firebonus(board);
	}
    add_fireblock_tosnake(snakePtr); // add the fireblock to the snake!!!
    snakePtr->hasFireblock = 1; // activate
    snakePtr->beingFired = 0; // set to inactive to start with
  }
  
  //Also do fireblock move 
  if(snakePtr->usingSpecial == 1){ // using special activated, start 'firing' fireblock
	snakePtr->fireBlocks->beingFired = 1; // activate
	snakePtr->hasFireblock = 0; // snake no longer has fireblock
    move_fireblocks(board,snakePtr);
    snakePtr->usingSpecial = 0; // set back to inactive until next time special key pressed
  }
  
  // Check for collision with food (snake eats it!)
  if (list_contains(beginning, board->foods) || list_contains_anaconda(beginning,board->foods,snakePtr) ) {
	//the snake length increments by 1 thanks to food consumed
	
    // remove anaconda eaten food
    if(snakePtr->anacondaCountdown > 0){
		update_item_coords_in_list_if_in_anaconda(beginning,board->foods,board); // changes coords of food item, simulating it being eaten and a new one added somewhere else
	}
	else{
	  //change coords of food item, simulating it being eaten and then adding a new one
      update_item_coords_in_list(beginning, board->foods, board);
	}

    // increment snake score for eating food
    snakePtr->score = snakePtr->score + 1;
    snakePtr->justScored = 2; // activate justScored variable of snake, used to flare the score
    
	shift_snake(snakePtr,beginning,1); // domino x,y coords through the entire snake and add a new tail

    return SUCCESS;
  }
  
  
  // No food was eaten, snake keeps its length
  // just need to shift all coords along the snake
  shift_snake(snakePtr,beginning,0); // dont need to add a new tail

  return SUCCESS; //all done for this movement
}

// check if this new location plus anaconda shifts are in the list
bool list_contains_anaconda(PointList* beginning, PointList* list, PointList* snakePtr){
	
	if(snakePtr){
		if(snakePtr->anacondaCountdown == 0)
		  return false;
	
		PointList* listLocal = list;

		while(listLocal){ // loop through the list
			
			  
			  if(beginning->x  == listLocal->x && beginning->y  == listLocal->y)
				return true;
			  if(beginning->x + 1 == listLocal->x && beginning->y + 1 == listLocal->y)
				return true;
			  if(beginning->x + 2 == listLocal->x && beginning->y + 2 == listLocal->y)
				return true;
			  if(beginning->x - 1 == listLocal->x && beginning->y - 1 == listLocal->y)
				return true;
			  if(beginning->x - 2 == listLocal->x && beginning->y - 2 == listLocal->y)
				return true;
				
			  listLocal = listLocal->next;
		}
	}
	return false;
}


// check if beginning plus extra fireblock shifts against each item in the list
// it is designed so that if a newfireblock position has been created, e.g. beginning, this can be checked against say a list of foods to see if beginning is the same as any food items
// that way it means that the fireblock has effectively consumed those food items

// when being called from the create_new_foood and similar functions, it is called like (board->snake->fireblock, newcell) 
// because this will check the fireblock plus aura shifts against the list which in this case is jsut a single new item location
bool list_contains_fireblock(PointList* beginning, PointList* list){
	
		PointList* listLocal = list;
		
		if(list){
			if(beginning){
				
				while(listLocal){ // loop through the list
				
				  if(beginning->x + 1 == listLocal->x && beginning->y + 1 == listLocal->y)
					return true;
				  if(beginning->x + 1 == listLocal->x && beginning->y  == listLocal->y)
					return true;
				  if(beginning->x - 1 == listLocal->x && beginning->y  == listLocal->y)
					return true;
				  if(beginning->x == listLocal->x && beginning->y + 1 == listLocal->y)
					return true;
				  if(beginning->x == listLocal->x && beginning->y - 1 == listLocal->y)
					return true;
				  if(beginning->x - 1 == listLocal->x && beginning->y - 1 == listLocal->y)
					return true;
					
				  listLocal = listLocal->next;
			   }
			}
			
			
		}

		
	return false;
}

void shift_snake(PointList* snakePtr, PointList* beginning, int addTail){
  	struct PointList* position = (struct PointList*) calloc(1,sizeof(struct PointList));
  struct PointList* storerPrev = (struct PointList *) calloc(1,sizeof(struct PointList)); 
  struct PointList* storerCurr = (struct PointList *) calloc(1,sizeof(struct PointList)); 

  // Set position to the head of snake
  position = snakePtr;
  position->next = snakePtr->next;
  position->x = snakePtr->x;
  position->y = snakePtr->y;
  
  // Put head values into storerPrev
  storerPrev->x = snakePtr->x; 
  storerPrev->y = snakePtr->y;
  
  // Put new beginning values in head
  snakePtr->x = beginning->x;
  snakePtr->y = beginning->y;
  
  // move position to the next part of snake
  //position = position->next;
  
  while(position->next){
    position = position->next;
    storerCurr->x = storerCurr->x ;
    position->x = position->x;
    
    storerCurr->x = position->x; // Store current position values
    storerCurr->y = position->y;
    position->x = storerPrev->x; // Write current position values with previous values
    position->y = storerPrev->y;
    storerPrev->x = storerCurr->x; // save stored current as previous
    storerPrev->y = storerCurr->y;
    //position = position->next; // move to next position in the list
  }
  
  if(addTail){
	  
	  // Construct new tail
	  struct PointList* newTail = (struct PointList*) calloc(1,sizeof(struct PointList));
	  newTail->x = storerPrev->x;
	  newTail->y = storerPrev->y;
	  newTail->next = NULL;

	  // Here adding the new tail
	  position->next = newTail; 
  }
}

//Checks if two point structures have the same coordinates
bool is_same_place(PointList* cell1, PointList* cell2) {
  return ((cell1->x == cell2->x) && (cell1->y == cell2->y));
}

//Creates and returns a new snake point (the new snake's head position)
//in the corresponding move direction
//If the snake hits the screen limits, it returns NULL instead
PointList* next_move(Board* board, enum Direction dir, PointList* snake) {
  
  int new_x = snake->x;
  int new_y = snake->y;
  switch(dir) {
    case UP:
      new_y = new_y - 1;
      break;
    case DOWN:
      new_y = new_y + 1;
      break;
    case LEFT:
      new_x = new_x - 1;
      break;
    case RIGHT:
      new_x = new_x + 1;
      break;
  }

  // Allow snake to wrap around through walls
  if(new_x < 0 ){ new_x = board->xmax-1; }
	if(new_x == board->xmax){ new_x = 0;  }
	if(new_y < 0){ new_y = board->ymax-1;  }
	if(new_y == board->ymax){ new_y = 0;  }

  return create_cell(new_x, new_y);

}

//creates a cell in a random location
PointList* create_random_cell(int xmax, int ymax) {
  return create_cell(rand() % xmax, rand() % ymax);
}

//Adds a new food point to the food list in a random location
void add_new_food(Board* board) {
  PointList* new_food;
  //UPDATED by Mario: original code (now commented) was not releasing memory
  // for cells allocated in non-valid positions, they were just ignored (mem leak!)
   bool ok = false;
   while(!ok){
	new_food = create_random_cell(board->xmax, board->ymax);
	if(list_contains(new_food, board->foods) 
	|| list_contains(new_food, board->maze)
	|| list_contains(new_food, board->pvpbonus) 
	|| list_contains(new_food, board->snake ) 
	|| list_contains(new_food, board->snakeB) 
	|| list_contains_anaconda(board->snake, new_food, board->snake) 
	|| list_contains_anaconda(board->snakeB, new_food, board->snakeB) 
	|| list_contains_fireblock(board->snake->fireBlocks,new_food) 
	|| ( (board->snakeB) == NULL ? 0 : list_contains_fireblock(board->snakeB->fireBlocks,new_food)) )
	  free(new_food); //not a valid location!
    else //valid location for new food
	  ok = true;
   }

  //update food list with the newly created food cell
  new_food->next = board->foods;
  board->foods = new_food;
}

// for PvP bonus
void add_new_bonus(Board* board){
  PointList* new_pvpbonus;
  
	  //UPDATED by Mario: original code (now commented) was not releasing memory
	  // for cells allocated in non-valid positions, they were just ignored (mem leak!)
	   bool ok = false;
	   while(!ok){
	  new_pvpbonus = create_random_cell(board->xmax, board->ymax);
	  if( list_contains(new_pvpbonus, board->pvpbonus) 
	  || list_contains(new_pvpbonus, board->maze)
	  || list_contains(new_pvpbonus, board->foods ) 
	  ||list_contains(new_pvpbonus, board->snake ) 
	  || list_contains(new_pvpbonus, board->snakeB) 
	  || list_contains_anaconda( board->snake,new_pvpbonus, board->snake) 
	  || list_contains_anaconda(board->snakeB,new_pvpbonus, board->snakeB) 
	  || list_contains_fireblock(board->snake->fireBlocks,new_pvpbonus) 
	  || ((board->snakeB) == NULL ? 0 : list_contains_fireblock(board->snakeB->fireBlocks,new_pvpbonus) ) )
		free(new_pvpbonus); //not a valid location!
		else //valid location for new food
		ok = true;
	   }

	  //update pvpbonus list with the newly created cell
	  board->pvpbonus = new_pvpbonus;
      board->pvpbonus->next = NULL;
}


//if firebonus exists then update coords of existing firebonus, otherwise add a new one to the board
void add_new_firebonus(Board* board){
  PointList* new_firebonus;
  if(board->fireBonuses){
	  
	  bool ok = false;
	  PointList* newcell = create_random_cell(board->xmax,board->ymax);
	   while(!ok){
		  newcell->x = rand() % board->xmax;
		  newcell->y = rand() % board->ymax;
		   
		  if( list_contains(newcell, board->pvpbonus) 
		  || list_contains(newcell, board->maze)
		  || list_contains(newcell, board->foods ) 
		  || list_contains(newcell, board->snake ) 
		  || list_contains(newcell, board->snakeB) 
		  || list_contains_anaconda(board->snake,newcell, board->snake) 
		  || list_contains_anaconda(board->snakeB,newcell, board->snakeB) 
		  || list_contains_fireblock(board->snake->fireBlocks,newcell) 
	      || ((board->snakeB) == NULL ? 0 : list_contains_fireblock(board->snakeB->fireBlocks,newcell) ))
			ok = false;
		   
		   else{
			 ok = true;
			 board->fireBonuses->x = newcell->x;
			 board->fireBonuses->y = newcell->y;
			 free(newcell);
		   }
	  }
  }
  else{
	  //UPDATED by Mario: original code (now commented) was not releasing memory
	  // for cells allocated in non-valid positions, they were just ignored (mem leak!)
	  
	  //calls to list_contains_fireblock have parameters in reverse compared to when calling for a newly created fireblock to see if fireblock should consume
	   bool ok = false;
	   while(!ok){
	  new_firebonus = create_random_cell(board->xmax, board->ymax);
	  if( list_contains(new_firebonus, board->pvpbonus) 
	  || list_contains(new_firebonus, board->maze)
	  || list_contains(new_firebonus, board->foods ) 
	  || list_contains(new_firebonus, board->snake ) 
	  || list_contains(new_firebonus, board->snakeB) 
	  || list_contains_anaconda(board->snake,new_firebonus, board->snake) 
	  || list_contains_anaconda(board->snakeB,new_firebonus, board->snakeB) 
	  || list_contains_fireblock(board->snake->fireBlocks,new_firebonus) 
	  || ((board->snakeB) == NULL ? 0 : list_contains_fireblock(board->snakeB->fireBlocks,new_firebonus) ))
		free(new_firebonus); //not a valid location!
		else //valid location for new food
		ok = true;
	   }

	  //update food list with the newly created food cell
	  board->fireBonuses = new_firebonus;
  }
}

// Checks if a given point is contained in a list of points
// Checks if a given point is contained in a list of points
bool list_contains(PointList* cell, PointList* list) {
  PointList* s = list;
  while (s) { //while not NULL
    if (is_same_place(s, cell)) {
      return true;
    }
    s = s->next; //select next element in the list
  }
  return false;
}

//Creates a new point element dynamically allocating it
//Initializes x and y elements to the ones given
//pointer to next element is set to NULL so far
PointList* create_cell(int x, int y) {
  PointList* cell = malloc(sizeof(*cell));
  cell->x = x;
  cell->y = y;
  cell->next = NULL;
  return cell;
}

//fills in the Board structure from the given lists and dimensions
Board* create_board(PointList* snake, PointList* snakeB, PointList* foods, PointList* pvpbonus, PointList* anacondaBonus, PointList* maze, int xmax, int ymax) {
  Board* board = malloc(sizeof(*board));
  board->foods = foods;
  board->snake = snake;
  board->snakeB = snakeB;
  board->pvpbonus = pvpbonus;
  board->anacondaBonus = anacondaBonus;
  board->maze = maze;
  board->xmax = xmax;
  board->ymax = ymax;
  return board;
}

//Generates the initial snake (length 2)
PointList* create_snake() {
  //create the initial 2 point elements of the snake
  PointList* a = create_cell(2,3); //head
  PointList* b = create_cell(2,2); //tail
  a->id = 'a';
  a->next = b; //point head element to tail element
  a->hasFireblock = 0; // set to false initially 
  a->usingSpecial = 0; // set to false initially
  a->score = 0;
  a->justScored = 0;
  a->fireBlocks = NULL;
  a->beingFired = 0; // set to false initially
  a->anacondaCountdown = 0; // set to 0 initially
  return a; //return head element address (start of list)
}

void add_snake(Board* board){
  if(board->snakeB == NULL){
    board->snakeB = create_snake();
    board->snakeB->id = 'b';
    board->snakeB->justScored = 0;
  }
}

void add_fireblock_tosnake(PointList* snakePtr){
	
	struct PointList * new_fireblock = calloc( 1,sizeof(PointList) );
	new_fireblock->x = 0;
	new_fireblock->y = 0;
	new_fireblock->beingFired = 0; // inactive initially 
	new_fireblock->independentOfSnake = 0; // inactive initially
	new_fireblock->extinguishGraphics = 0; // inactive initially 
	new_fireblock->next = NULL;
	snakePtr->fireBlocks = new_fireblock; // assign fireblock to the snake in question
}

void add_new_anacondabonus(Board* board){
	PointList* new_bonus;
  //UPDATED by Mario: original code (now commented) was not releasing memory
  // for cells allocated in non-valid positions, they were just ignored (mem leak!)
   bool ok = false;
   while(!ok){
  new_bonus = create_cell(board->xmax /2, board->ymax / 2 + 3);
  
  if(list_contains(new_bonus, board->pvpbonus) 
  || list_contains(new_bonus, board->maze)
  || list_contains(new_bonus, board->foods ) 
  || list_contains(new_bonus, board->snake ) 
  || list_contains(new_bonus, board->snakeB) 
  || list_contains_anaconda(board->snake,new_bonus, board->snake) 
  || list_contains_anaconda(board->snakeB,new_bonus, board->snakeB)  )
    free(new_bonus); //not a valid location!
    else //valid location for new food
    ok = true;
   }

  //update board anacondabonus as the newly created cell
  new_bonus->next = board->anacondaBonus;
  board->anacondaBonus = new_bonus;
}

