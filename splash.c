#include <ncurses.h>

void splashScreen(int xmax, int ymax){
	
  start_color();

  init_pair(8, COLOR_BLACK, COLOR_RED);
  attron(COLOR_PAIR(8));
    
  int x = 0;
  int y = 0;
  // fill in screen
  for(x = 0; x < xmax; x++){
    for(y = 0; y < ymax; y++){
      mvaddch(y, x, ACS_BLOCK);
    }
  }

  init_pair(4, COLOR_BLACK, COLOR_GREEN);
  attron(COLOR_PAIR(4));
    
// S
mvaddch(2, 2, ACS_BLOCK);
mvaddch(2, 3, ACS_BLOCK);
mvaddch(2, 4, ACS_BLOCK);
mvaddch(2, 5, ACS_BLOCK);
mvaddch(2, 6, ACS_BLOCK);
mvaddch(2, 7, ACS_BLOCK);
mvaddch(2, 8, ACS_BLOCK);
mvaddch(2, 9, ACS_BLOCK);
mvaddch(3, 1, ACS_BLOCK);
mvaddch(3, 2, ACS_BLOCK);
mvaddch(3, 3, ACS_BLOCK);
mvaddch(3, 4, ACS_BLOCK);
mvaddch(3, 5, ACS_BLOCK);
mvaddch(3, 6, ACS_BLOCK);
mvaddch(3, 7, ACS_BLOCK);
mvaddch(3, 8, ACS_BLOCK);
mvaddch(3, 9, ACS_BLOCK);
mvaddch(3, 10, ACS_BLOCK);
mvaddch(3, 11, ACS_BLOCK);
mvaddch(4,2, ACS_BLOCK);
mvaddch(4, 3, ACS_BLOCK);
mvaddch(4, 4, ACS_BLOCK);
mvaddch(5,2, ACS_BLOCK);
mvaddch(5,3, ACS_BLOCK);
mvaddch(5,4, ACS_BLOCK);
mvaddch(6,3, ACS_BLOCK);
mvaddch(6,4, ACS_BLOCK);
mvaddch(7,3, ACS_BLOCK);
mvaddch(7,4, ACS_BLOCK);
mvaddch(8,5, ACS_BLOCK);
mvaddch(8,6, ACS_BLOCK);
mvaddch(9,5, ACS_BLOCK);
mvaddch(9,6,  ACS_BLOCK);
mvaddch(9,7,  ACS_BLOCK);
mvaddch(9,8, ACS_BLOCK);
mvaddch(9,8, ACS_BLOCK);
mvaddch(9,9, ACS_BLOCK);
mvaddch(9,10, ACS_BLOCK);
mvaddch(9,11, ACS_BLOCK);
mvaddch(9,12, ACS_BLOCK);
mvaddch(9,13, ACS_BLOCK);
mvaddch(10,9, ACS_BLOCK);
mvaddch(10,10, ACS_BLOCK);
mvaddch(10,11, ACS_BLOCK);
mvaddch(10,12, ACS_BLOCK);
mvaddch(10,13, ACS_BLOCK);
mvaddch(11,10, ACS_BLOCK);
mvaddch(11,11, ACS_BLOCK);
mvaddch(11,12, ACS_BLOCK);
mvaddch(12,10, ACS_BLOCK);
mvaddch(12,11, ACS_BLOCK);
mvaddch(12,12, ACS_BLOCK);
mvaddch(13,2, ACS_BLOCK);
mvaddch(13,3, ACS_BLOCK);
mvaddch(13,4, ACS_BLOCK);
mvaddch(13,5, ACS_BLOCK);
mvaddch(13,6, ACS_BLOCK);
mvaddch(13,7, ACS_BLOCK);
mvaddch(13,8, ACS_BLOCK);
mvaddch(13,9, ACS_BLOCK);
mvaddch(13,10, ACS_BLOCK);
mvaddch(13,11, ACS_BLOCK);
mvaddch(13,12, ACS_BLOCK);
mvaddch(14,2, ACS_BLOCK);
mvaddch(14,3, ACS_BLOCK);
mvaddch(14,4, ACS_BLOCK);
mvaddch(14,5, ACS_BLOCK);
mvaddch(14,6, ACS_BLOCK);
mvaddch(14,7, ACS_BLOCK);
mvaddch(14,8, ACS_BLOCK);
mvaddch(14,9, ACS_BLOCK);
mvaddch(14,10, ACS_BLOCK);
mvaddch(14,11, ACS_BLOCK);
mvaddch(14,12, ACS_BLOCK);


// N
mvaddch(2,16, ACS_BLOCK);
mvaddch(2,17, ACS_BLOCK);
mvaddch(3,16, ACS_BLOCK);
mvaddch(3,17, ACS_BLOCK);
mvaddch(4,16, ACS_BLOCK);
mvaddch(4,17, ACS_BLOCK);
mvaddch(5,16, ACS_BLOCK);
mvaddch(5,17, ACS_BLOCK);
mvaddch(6,16, ACS_BLOCK);
mvaddch(6,17, ACS_BLOCK);
mvaddch(7,16, ACS_BLOCK);
mvaddch(7,17, ACS_BLOCK);
mvaddch(8,16, ACS_BLOCK);
mvaddch(8,17, ACS_BLOCK);
mvaddch(9,16, ACS_BLOCK);
mvaddch(9,17, ACS_BLOCK);
mvaddch(10,16, ACS_BLOCK);
mvaddch(10,17, ACS_BLOCK);
mvaddch(11,16, ACS_BLOCK);
mvaddch(11,17, ACS_BLOCK);
mvaddch(12,16, ACS_BLOCK);
mvaddch(12,17, ACS_BLOCK);
mvaddch(13,16, ACS_BLOCK);
mvaddch(13,17, ACS_BLOCK);
mvaddch(14,16, ACS_BLOCK);
mvaddch(14,17, ACS_BLOCK);

mvaddch(3,16, ACS_BLOCK);
mvaddch(4,17, ACS_BLOCK);
mvaddch(5,18, ACS_BLOCK);
mvaddch(6,19, ACS_BLOCK);
mvaddch(7,20, ACS_BLOCK);
mvaddch(8,21, ACS_BLOCK);
mvaddch(9,22, ACS_BLOCK);
mvaddch(10,23, ACS_BLOCK);
mvaddch(11,24, ACS_BLOCK);
mvaddch(12,25, ACS_BLOCK);

mvaddch(2,26, ACS_BLOCK);
mvaddch(2,27, ACS_BLOCK);
mvaddch(3,26, ACS_BLOCK);
mvaddch(3,27, ACS_BLOCK);
mvaddch(4,26, ACS_BLOCK);
mvaddch(4,27, ACS_BLOCK);
mvaddch(5,26, ACS_BLOCK);
mvaddch(5,27, ACS_BLOCK);
mvaddch(6,26, ACS_BLOCK);
mvaddch(6,27, ACS_BLOCK);
mvaddch(7,26, ACS_BLOCK);
mvaddch(7,27, ACS_BLOCK);
mvaddch(8,26, ACS_BLOCK);
mvaddch(8,27, ACS_BLOCK);
mvaddch(9,26, ACS_BLOCK);
mvaddch(9,27, ACS_BLOCK);
mvaddch(10,26, ACS_BLOCK);
mvaddch(10,27, ACS_BLOCK);
mvaddch(11,26, ACS_BLOCK);
mvaddch(11,27, ACS_BLOCK);
mvaddch(12,26, ACS_BLOCK);
mvaddch(12,27, ACS_BLOCK);
mvaddch(13,26, ACS_BLOCK);
mvaddch(13,27, ACS_BLOCK);
mvaddch(14,26, ACS_BLOCK);
mvaddch(14,27, ACS_BLOCK);

// A
mvaddch(14,29, ACS_BLOCK);
mvaddch(13,29, ACS_BLOCK);
mvaddch(12,30, ACS_BLOCK);
mvaddch(11,30, ACS_BLOCK);
mvaddch(10,31, ACS_BLOCK);
mvaddch(9,31, ACS_BLOCK);
mvaddch(8,32, ACS_BLOCK);
mvaddch(7,32, ACS_BLOCK);
mvaddch(6,33, ACS_BLOCK);
mvaddch(5,33, ACS_BLOCK);
mvaddch(4,34, ACS_BLOCK);
mvaddch(3,34, ACS_BLOCK);

mvaddch(9,33, ACS_BLOCK);
mvaddch(9,34, ACS_BLOCK);
mvaddch(9,35, ACS_BLOCK);
mvaddch(9,36, ACS_BLOCK);


mvaddch(3,34, ACS_BLOCK);
mvaddch(4,34, ACS_BLOCK);
mvaddch(5,35, ACS_BLOCK);
mvaddch(6,35, ACS_BLOCK);
mvaddch(7,36, ACS_BLOCK);
mvaddch(8,36, ACS_BLOCK);
mvaddch(9,37, ACS_BLOCK);
mvaddch(10,37, ACS_BLOCK);
mvaddch(11,38, ACS_BLOCK);
mvaddch(12,38, ACS_BLOCK);
mvaddch(13,39, ACS_BLOCK);
mvaddch(14,39, ACS_BLOCK);
mvaddch(15,40, ACS_BLOCK);
mvaddch(16,40, ACS_BLOCK);

// K
mvaddch(2,46, ACS_BLOCK);
mvaddch(2,47, ACS_BLOCK);
mvaddch(3,46, ACS_BLOCK);
mvaddch(3,47, ACS_BLOCK);
mvaddch(4,46, ACS_BLOCK);
mvaddch(4,47, ACS_BLOCK);
mvaddch(5,46, ACS_BLOCK);
mvaddch(5,47, ACS_BLOCK);
mvaddch(6,46, ACS_BLOCK);
mvaddch(6,47, ACS_BLOCK);
mvaddch(7,46, ACS_BLOCK);
mvaddch(7,47, ACS_BLOCK);
mvaddch(8,46, ACS_BLOCK);
mvaddch(8,47, ACS_BLOCK);
mvaddch(9,46, ACS_BLOCK);
mvaddch(9,47, ACS_BLOCK);
mvaddch(10,46, ACS_BLOCK);
mvaddch(10,47, ACS_BLOCK);
mvaddch(11,46, ACS_BLOCK);
mvaddch(11,47, ACS_BLOCK);
mvaddch(12,46, ACS_BLOCK);
mvaddch(12,47, ACS_BLOCK);
mvaddch(13,46, ACS_BLOCK);
mvaddch(13,47, ACS_BLOCK);
mvaddch(14,46, ACS_BLOCK);
mvaddch(14,47, ACS_BLOCK);

mvaddch(8,48, ACS_BLOCK);
mvaddch(9,49, ACS_BLOCK);
mvaddch(10,50, ACS_BLOCK);
mvaddch(11,51, ACS_BLOCK);
mvaddch(12,52, ACS_BLOCK);
mvaddch(13,53, ACS_BLOCK);
mvaddch(14,54, ACS_BLOCK);

mvaddch(7,48, ACS_BLOCK);
mvaddch(6,49, ACS_BLOCK);
mvaddch(5,50, ACS_BLOCK);
mvaddch(4,51, ACS_BLOCK);
mvaddch(3,52, ACS_BLOCK);
mvaddch(2,53, ACS_BLOCK);
mvaddch(1,54, ACS_BLOCK);


// E

mvaddch(2,60, ACS_BLOCK);
mvaddch(2,61, ACS_BLOCK);
mvaddch(3,60, ACS_BLOCK);
mvaddch(3,61, ACS_BLOCK);
mvaddch(4,60, ACS_BLOCK);
mvaddch(4,61, ACS_BLOCK);
mvaddch(5,60, ACS_BLOCK);
mvaddch(5,61, ACS_BLOCK);
mvaddch(6,60, ACS_BLOCK);
mvaddch(6,61, ACS_BLOCK);
mvaddch(7,60, ACS_BLOCK);
mvaddch(7,61, ACS_BLOCK);
mvaddch(8,60, ACS_BLOCK);
mvaddch(8,61, ACS_BLOCK);
mvaddch(9,60, ACS_BLOCK);
mvaddch(9,61, ACS_BLOCK);
mvaddch(10,60, ACS_BLOCK);
mvaddch(10,61, ACS_BLOCK);
mvaddch(11,60, ACS_BLOCK);
mvaddch(11,61, ACS_BLOCK);
mvaddch(12,60, ACS_BLOCK);
mvaddch(12,61, ACS_BLOCK);
mvaddch(13,60, ACS_BLOCK);
mvaddch(13,61, ACS_BLOCK);
mvaddch(14,60, ACS_BLOCK);
mvaddch(14,61, ACS_BLOCK);

mvaddch(2,62, ACS_BLOCK);
mvaddch(2,63, ACS_BLOCK);
mvaddch(2,64, ACS_BLOCK);
mvaddch(2,65, ACS_BLOCK);
mvaddch(2,66, ACS_BLOCK);
mvaddch(2,67, ACS_BLOCK);

mvaddch(8,62, ACS_BLOCK);
mvaddch(8,63, ACS_BLOCK);
mvaddch(8,64, ACS_BLOCK);
mvaddch(8,65, ACS_BLOCK);
mvaddch(8,66, ACS_BLOCK);
mvaddch(8,67, ACS_BLOCK);

mvaddch(14,62, ACS_BLOCK);
mvaddch(14,63, ACS_BLOCK);
mvaddch(14,64, ACS_BLOCK);
mvaddch(14,65, ACS_BLOCK);
mvaddch(14,66, ACS_BLOCK);
mvaddch(14,67, ACS_BLOCK);


  int enter = 1;
  while(enter){
    int ch = getch();
    if(ch = KEY_ENTER){
      enter = 0;
    }

  }
  
  timeout(100);// game speed
}

void splash2player(int xmax, int ymax){
	
	start_color();
	
	init_pair(5, COLOR_BLACK, COLOR_YELLOW);
	
	attron(COLOR_PAIR(5));
	
  int x = 0;
  int y = 0;
  // fill in screen
  for(x = 0; x < xmax; x++){
    for(y = 0; y < ymax; y++){
      mvaddch(y, x, ACS_BLOCK);
    }
  }

  
    init_pair(4, COLOR_BLACK, COLOR_GREEN);

    attron(COLOR_PAIR(4));
    
    
    // P
mvaddch(2,16, ACS_BLOCK);
mvaddch(2,17, ACS_BLOCK);
mvaddch(3,16, ACS_BLOCK);
mvaddch(3,17, ACS_BLOCK);
mvaddch(4,16, ACS_BLOCK);
mvaddch(4,17, ACS_BLOCK);
mvaddch(5,16, ACS_BLOCK);
mvaddch(5,17, ACS_BLOCK);
mvaddch(6,16, ACS_BLOCK);
mvaddch(6,17, ACS_BLOCK);
mvaddch(7,16, ACS_BLOCK);
mvaddch(7,17, ACS_BLOCK);
mvaddch(8,16, ACS_BLOCK);
mvaddch(8,17, ACS_BLOCK);
mvaddch(9,16, ACS_BLOCK);
mvaddch(9,17, ACS_BLOCK);
mvaddch(10,16, ACS_BLOCK);
mvaddch(10,17, ACS_BLOCK);
mvaddch(11,16, ACS_BLOCK);
mvaddch(11,17, ACS_BLOCK);
mvaddch(12,16, ACS_BLOCK);
mvaddch(12,17, ACS_BLOCK);
mvaddch(13,16, ACS_BLOCK);
mvaddch(13,17, ACS_BLOCK);
mvaddch(14,16, ACS_BLOCK);
mvaddch(14,17, ACS_BLOCK);

mvaddch(2,18, ACS_BLOCK);
mvaddch(2,19, ACS_BLOCK);
mvaddch(2,20, ACS_BLOCK);
mvaddch(3,21, ACS_BLOCK);
mvaddch(4,22, ACS_BLOCK);
mvaddch(5,23, ACS_BLOCK);
mvaddch(6,22, ACS_BLOCK);
mvaddch(7,21, ACS_BLOCK);
mvaddch(8,18, ACS_BLOCK);
mvaddch(8,19, ACS_BLOCK);
mvaddch(8,20, ACS_BLOCK);

	// V


	mvaddch(4,26, ACS_BLOCK);
	mvaddch(5,26, ACS_BLOCK);
	mvaddch(6,27, ACS_BLOCK);
	mvaddch(7,27, ACS_BLOCK);
	mvaddch(8,28, ACS_BLOCK);
	mvaddch(9,28, ACS_BLOCK);
	mvaddch(10,29, ACS_BLOCK);
	mvaddch(10,29, ACS_BLOCK);
	mvaddch(11,30, ACS_BLOCK);
	
	mvaddch(12,31, ACS_BLOCK);
	
	mvaddch(11,32, ACS_BLOCK);
	mvaddch(10,33, ACS_BLOCK);
	mvaddch(10,33, ACS_BLOCK);
	mvaddch(9,34, ACS_BLOCK);
	mvaddch(8,34, ACS_BLOCK);
	mvaddch(7,35, ACS_BLOCK);
	mvaddch(6,35, ACS_BLOCK);
	mvaddch(5,36, ACS_BLOCK);
	mvaddch(4,36, ACS_BLOCK);


	
	// P
	mvaddch(2,40, ACS_BLOCK);
mvaddch(2,41, ACS_BLOCK);
mvaddch(3,40, ACS_BLOCK);
mvaddch(3,41, ACS_BLOCK);
mvaddch(4,40, ACS_BLOCK);
mvaddch(4,41, ACS_BLOCK);
mvaddch(5,40, ACS_BLOCK);
mvaddch(5,41, ACS_BLOCK);
mvaddch(6,40, ACS_BLOCK);
mvaddch(6,41, ACS_BLOCK);
mvaddch(7,40, ACS_BLOCK);
mvaddch(7,41, ACS_BLOCK);
mvaddch(8,40, ACS_BLOCK);
mvaddch(8,41, ACS_BLOCK);
mvaddch(9,40, ACS_BLOCK);
mvaddch(9,41, ACS_BLOCK);
mvaddch(10,40, ACS_BLOCK);
mvaddch(10,41, ACS_BLOCK);
mvaddch(11,40, ACS_BLOCK);
mvaddch(11,41, ACS_BLOCK);
mvaddch(12,40, ACS_BLOCK);
mvaddch(12,41, ACS_BLOCK);
mvaddch(13,40, ACS_BLOCK);
mvaddch(13,41, ACS_BLOCK);
mvaddch(14,40, ACS_BLOCK);
mvaddch(14,41, ACS_BLOCK);

mvaddch(2,42, ACS_BLOCK);
mvaddch(2,43, ACS_BLOCK);
mvaddch(2,44, ACS_BLOCK);
mvaddch(3,45, ACS_BLOCK);
mvaddch(4,46, ACS_BLOCK);
mvaddch(5,47, ACS_BLOCK);
mvaddch(6,46, ACS_BLOCK);
mvaddch(7,45, ACS_BLOCK);
mvaddch(8,44, ACS_BLOCK);
mvaddch(8,43, ACS_BLOCK);
mvaddch(8,42, ACS_BLOCK);
	
  int enter = 1;
  while(enter){
    int ch = getch();
    if(ch = KEY_ENTER){
      enter = 0;
    }
  }
  timeout(100);// game speed
}

void splashAnaconda(int xmax, int ymax){
	
	timeout(8000); //do not keep waiting for keypress longer than this
	
	start_color();
	
	init_pair(56, COLOR_BLACK, COLOR_MAGENTA);
	init_pair(57, COLOR_BLACK, COLOR_WHITE);
	
	attron(COLOR_PAIR(56));
	
  int x = 0;
  int y = 0;
  // fill in screen
  for(x = 0; x < xmax; x++){
    for(y = 0; y < ymax; y++){
      mvaddch(y, x, ACS_BLOCK);
    }
  }
  
  attron(COLOR_PAIR(57));
  
  // A
mvaddch(14,3, ACS_BLOCK);
mvaddch(13,3, ACS_BLOCK);
mvaddch(12,4, ACS_BLOCK);
mvaddch(11,4, ACS_BLOCK);
mvaddch(10,5, ACS_BLOCK);
mvaddch(9,5, ACS_BLOCK);
mvaddch(8,6, ACS_BLOCK);
mvaddch(7,6, ACS_BLOCK);
mvaddch(6,7, ACS_BLOCK);
mvaddch(5,7, ACS_BLOCK);
mvaddch(4,8, ACS_BLOCK);
mvaddch(3,8, ACS_BLOCK);

mvaddch(9,7, ACS_BLOCK);
mvaddch(9,8, ACS_BLOCK);
mvaddch(9,9, ACS_BLOCK);
mvaddch(9,10, ACS_BLOCK);


mvaddch(3,8, ACS_BLOCK);
mvaddch(4,8, ACS_BLOCK);
mvaddch(5,9, ACS_BLOCK);
mvaddch(6,9, ACS_BLOCK);
mvaddch(7,10, ACS_BLOCK);
mvaddch(8,10, ACS_BLOCK);
mvaddch(9,11, ACS_BLOCK);
mvaddch(10,11, ACS_BLOCK);
mvaddch(11,12, ACS_BLOCK);
mvaddch(12,12, ACS_BLOCK);
mvaddch(13,13, ACS_BLOCK);
mvaddch(14,13, ACS_BLOCK);
mvaddch(15,14, ACS_BLOCK);
mvaddch(16,14, ACS_BLOCK);


  
// N
mvaddch(2,16, ACS_BLOCK);
mvaddch(2,17, ACS_BLOCK);
mvaddch(3,16, ACS_BLOCK);
mvaddch(3,17, ACS_BLOCK);
mvaddch(4,16, ACS_BLOCK);
mvaddch(4,17, ACS_BLOCK);
mvaddch(5,16, ACS_BLOCK);
mvaddch(5,17, ACS_BLOCK);
mvaddch(6,16, ACS_BLOCK);
mvaddch(6,17, ACS_BLOCK);
mvaddch(7,16, ACS_BLOCK);
mvaddch(7,17, ACS_BLOCK);
mvaddch(8,16, ACS_BLOCK);
mvaddch(8,17, ACS_BLOCK);
mvaddch(9,16, ACS_BLOCK);
mvaddch(9,17, ACS_BLOCK);
mvaddch(10,16, ACS_BLOCK);
mvaddch(10,17, ACS_BLOCK);
mvaddch(11,16, ACS_BLOCK);
mvaddch(11,17, ACS_BLOCK);
mvaddch(12,16, ACS_BLOCK);
mvaddch(12,17, ACS_BLOCK);
mvaddch(13,16, ACS_BLOCK);
mvaddch(13,17, ACS_BLOCK);
mvaddch(14,16, ACS_BLOCK);
mvaddch(14,17, ACS_BLOCK);

mvaddch(3,16, ACS_BLOCK);
mvaddch(4,17, ACS_BLOCK);
mvaddch(5,18, ACS_BLOCK);
mvaddch(6,19, ACS_BLOCK);
mvaddch(7,20, ACS_BLOCK);
mvaddch(8,21, ACS_BLOCK);
mvaddch(9,22, ACS_BLOCK);
mvaddch(10,23, ACS_BLOCK);
mvaddch(11,24, ACS_BLOCK);
mvaddch(12,25, ACS_BLOCK);

mvaddch(2,26, ACS_BLOCK);
mvaddch(2,27, ACS_BLOCK);
mvaddch(3,26, ACS_BLOCK);
mvaddch(3,27, ACS_BLOCK);
mvaddch(4,26, ACS_BLOCK);
mvaddch(4,27, ACS_BLOCK);
mvaddch(5,26, ACS_BLOCK);
mvaddch(5,27, ACS_BLOCK);
mvaddch(6,26, ACS_BLOCK);
mvaddch(6,27, ACS_BLOCK);
mvaddch(7,26, ACS_BLOCK);
mvaddch(7,27, ACS_BLOCK);
mvaddch(8,26, ACS_BLOCK);
mvaddch(8,27, ACS_BLOCK);
mvaddch(9,26, ACS_BLOCK);
mvaddch(9,27, ACS_BLOCK);
mvaddch(10,26, ACS_BLOCK);
mvaddch(10,27, ACS_BLOCK);
mvaddch(11,26, ACS_BLOCK);
mvaddch(11,27, ACS_BLOCK);
mvaddch(12,26, ACS_BLOCK);
mvaddch(12,27, ACS_BLOCK);
mvaddch(13,26, ACS_BLOCK);
mvaddch(13,27, ACS_BLOCK);
mvaddch(14,26, ACS_BLOCK);
mvaddch(14,27, ACS_BLOCK);

// A
mvaddch(14,29, ACS_BLOCK);
mvaddch(13,29, ACS_BLOCK);
mvaddch(12,30, ACS_BLOCK);
mvaddch(11,30, ACS_BLOCK);
mvaddch(10,31, ACS_BLOCK);
mvaddch(9,31, ACS_BLOCK);
mvaddch(8,32, ACS_BLOCK);
mvaddch(7,32, ACS_BLOCK);
mvaddch(6,33, ACS_BLOCK);
mvaddch(5,33, ACS_BLOCK);
mvaddch(4,34, ACS_BLOCK);
mvaddch(3,34, ACS_BLOCK);

mvaddch(9,33, ACS_BLOCK);
mvaddch(9,34, ACS_BLOCK);
mvaddch(9,35, ACS_BLOCK);
mvaddch(9,36, ACS_BLOCK);


mvaddch(3,34, ACS_BLOCK);
mvaddch(4,34, ACS_BLOCK);
mvaddch(5,35, ACS_BLOCK);
mvaddch(6,35, ACS_BLOCK);
mvaddch(7,36, ACS_BLOCK);
mvaddch(8,36, ACS_BLOCK);
mvaddch(9,37, ACS_BLOCK);
mvaddch(10,37, ACS_BLOCK);
mvaddch(11,38, ACS_BLOCK);
mvaddch(12,38, ACS_BLOCK);
mvaddch(13,39, ACS_BLOCK);
mvaddch(14,39, ACS_BLOCK);
mvaddch(15,40, ACS_BLOCK);
mvaddch(16,40, ACS_BLOCK);

// C
// back of the c
mvaddch(14,42, ACS_BLOCK);
mvaddch(13,42, ACS_BLOCK);
mvaddch(12,42, ACS_BLOCK);
mvaddch(11,42, ACS_BLOCK);
mvaddch(10,42, ACS_BLOCK);
mvaddch(9,42, ACS_BLOCK);
mvaddch(8,42, ACS_BLOCK);
mvaddch(7,42, ACS_BLOCK);
mvaddch(6,42, ACS_BLOCK);

// top half
mvaddch(5,43, ACS_BLOCK);
mvaddch(5,43, ACS_BLOCK);
mvaddch(4,44, ACS_BLOCK);
mvaddch(4,44, ACS_BLOCK);
mvaddch(3,44, ACS_BLOCK);
mvaddch(3,44, ACS_BLOCK);
mvaddch(4,45, ACS_BLOCK);
mvaddch(4,45, ACS_BLOCK);
mvaddch(5,46, ACS_BLOCK);
mvaddch(5,46, ACS_BLOCK);

//bottom of the c
mvaddch(15,43, ACS_BLOCK);
mvaddch(16,44, ACS_BLOCK);
mvaddch(16,45, ACS_BLOCK);
mvaddch(15,46, ACS_BLOCK);

// o
//left of o 
mvaddch(11,47, ACS_BLOCK);
mvaddch(12,47, ACS_BLOCK);
mvaddch(13,48, ACS_BLOCK);
mvaddch(13,48, ACS_BLOCK);
mvaddch(13,49, ACS_BLOCK);

// right half
mvaddch(13,50, ACS_BLOCK);
mvaddch(12,51, ACS_BLOCK);
mvaddch(11,51, ACS_BLOCK);
mvaddch(10,51, ACS_BLOCK);
mvaddch(10,50, ACS_BLOCK);
mvaddch(9,49, ACS_BLOCK);
mvaddch(9,48, ACS_BLOCK);
mvaddch(9,50, ACS_BLOCK);
mvaddch(10,47, ACS_BLOCK);

// end of c


 
// N
mvaddch(2,53, ACS_BLOCK);

mvaddch(3,53, ACS_BLOCK);

mvaddch(4,53, ACS_BLOCK);

mvaddch(5,53, ACS_BLOCK);
mvaddch(5,53, ACS_BLOCK);
mvaddch(6,53, ACS_BLOCK);
mvaddch(6,53, ACS_BLOCK);
mvaddch(7,53, ACS_BLOCK);
mvaddch(8,53, ACS_BLOCK);
mvaddch(9,53, ACS_BLOCK);
mvaddch(10,53, ACS_BLOCK);
mvaddch(11,53, ACS_BLOCK);
mvaddch(12,53, ACS_BLOCK);
mvaddch(13,53, ACS_BLOCK);
mvaddch(14,53, ACS_BLOCK);

mvaddch(4,54, ACS_BLOCK);
mvaddch(5,54, ACS_BLOCK);
mvaddch(6,55, ACS_BLOCK);
mvaddch(7,55, ACS_BLOCK);
mvaddch(8,56, ACS_BLOCK);
mvaddch(9,56, ACS_BLOCK);
mvaddch(10,57, ACS_BLOCK);
mvaddch(11,57, ACS_BLOCK);

mvaddch(2,58, ACS_BLOCK);
mvaddch(3,58, ACS_BLOCK);
mvaddch(4,58, ACS_BLOCK);
mvaddch(5,58, ACS_BLOCK);
mvaddch(6,58, ACS_BLOCK);
mvaddch(7,58, ACS_BLOCK);
mvaddch(8,58, ACS_BLOCK);
mvaddch(9,58, ACS_BLOCK);
mvaddch(10,58, ACS_BLOCK);
mvaddch(11,58, ACS_BLOCK);
mvaddch(12,58, ACS_BLOCK);
mvaddch(13,58, ACS_BLOCK);
mvaddch(14,58, ACS_BLOCK);

// D
mvaddch(4,60, ACS_BLOCK);
mvaddch(5,60, ACS_BLOCK);
mvaddch(6,60, ACS_BLOCK);
mvaddch(7,60, ACS_BLOCK);
mvaddch(7,60, ACS_BLOCK);
mvaddch(8,60, ACS_BLOCK);
mvaddch(8,60, ACS_BLOCK);
mvaddch(9,60, ACS_BLOCK);
mvaddch(10,60, ACS_BLOCK);
mvaddch(11,60, ACS_BLOCK);
mvaddch(12,60, ACS_BLOCK);
mvaddch(13,60, ACS_BLOCK);
mvaddch(14,60, ACS_BLOCK);
mvaddch(15,60, ACS_BLOCK);
mvaddch(16,60, ACS_BLOCK);

mvaddch(16,61, ACS_BLOCK);
mvaddch(15,62, ACS_BLOCK);
mvaddch(14,63, ACS_BLOCK);
mvaddch(13,63, ACS_BLOCK);
mvaddch(12,64, ACS_BLOCK);
mvaddch(11,64, ACS_BLOCK);
mvaddch(10,65, ACS_BLOCK);

mvaddch(9,65, ACS_BLOCK);
mvaddch(8,64, ACS_BLOCK);
mvaddch(7,63, ACS_BLOCK);
mvaddch(6,63, ACS_BLOCK);
mvaddch(6,62, ACS_BLOCK);
mvaddch(5,62, ACS_BLOCK);
mvaddch(4,61, ACS_BLOCK);
mvaddch(4,60, ACS_BLOCK);


  // A
mvaddch(14,67, ACS_BLOCK);
mvaddch(13,67, ACS_BLOCK);
mvaddch(12,68, ACS_BLOCK);
mvaddch(11,68, ACS_BLOCK);
mvaddch(10,69, ACS_BLOCK);
mvaddch(9,69, ACS_BLOCK);
mvaddch(8,70, ACS_BLOCK);
mvaddch(7,70, ACS_BLOCK);
mvaddch(6,71, ACS_BLOCK);
mvaddch(5,71, ACS_BLOCK);
mvaddch(4,72, ACS_BLOCK);
mvaddch(3,72, ACS_BLOCK);

mvaddch(9,71, ACS_BLOCK);
mvaddch(9,72, ACS_BLOCK);
mvaddch(9,73, ACS_BLOCK);
mvaddch(9,74, ACS_BLOCK);


mvaddch(3,71, ACS_BLOCK);
mvaddch(4,71, ACS_BLOCK);
mvaddch(5,72, ACS_BLOCK);
mvaddch(6,72, ACS_BLOCK);
mvaddch(7,73, ACS_BLOCK);
mvaddch(8,73, ACS_BLOCK);
mvaddch(9,74, ACS_BLOCK);
mvaddch(10,74, ACS_BLOCK);
mvaddch(11,75, ACS_BLOCK);
mvaddch(12,75, ACS_BLOCK);
mvaddch(13,76, ACS_BLOCK);
mvaddch(14,76, ACS_BLOCK);
mvaddch(15,77, ACS_BLOCK);
mvaddch(16,77, ACS_BLOCK);
  
  int enter = 1;
  while(enter){
    int ch = getch();
    if(ch = KEY_ENTER){
      enter = 0;
    }
  }
  timeout(100);// game speed
  
}
	
