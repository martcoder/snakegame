#include <stdio.h>
#include "backend.h"

PointList* create_maze(int xmax, int ymax){
  
  // Left wall of maze
  PointList* maze = create_cell(xmax/2 - 5, ymax/2 - 5);
  PointList* maze2 = create_cell(xmax/2 - 5, ymax/2 - 4);
  maze->next = maze2;

  PointList* maze3 = create_cell(xmax/2 - 5, ymax/2 - 4);
  maze2->next = maze3;

  PointList* maze4 = create_cell(xmax/2 - 5, ymax/2 - 3);
  maze3->next = maze4;

  PointList* maze5 = create_cell(xmax/2 - 5, ymax/2 - 2);
  maze4->next = maze5;
  PointList* maze6 = create_cell(xmax/2 - 5, ymax/2 - 1);
  maze5->next = maze6;
  PointList* maze7 = create_cell(xmax/2 - 5, ymax/2 - 0);
  maze6->next = maze7;
  PointList* maze8 = create_cell(xmax/2 - 5, ymax/2 + 1);
  maze7->next = maze8;
  PointList* maze9 = create_cell(xmax/2 - 5, ymax/2 + 2);
  maze8->next = maze9;
  PointList* maze10 = create_cell(xmax/2 - 5, ymax/2 + 3);
  maze9->next = maze10;
  PointList* maze11 = create_cell(xmax/2 - 5, ymax/2 + 4);
  maze10->next = maze11;
  PointList* maze12 = create_cell(xmax/2 - 5, ymax/2 + 5);
  maze11->next = maze12;
  PointList* maze13 = create_cell(xmax/2 - 5, ymax/2 + 6);
  maze12->next = maze13;
  PointList* maze14 = create_cell(xmax/2 - 5, ymax/2 + 7);
  maze13->next = maze14;
  
  PointList* maze14a = create_cell(xmax/2 - 5, ymax/2 + 8);
  maze14->next = maze14a;
  PointList* maze14b = create_cell(xmax/2 - 5, ymax/2 + 9);
  maze14a->next = maze14b;
  PointList* maze14c = create_cell(xmax/2 - 5, ymax/2 + 10);
  maze14b->next = maze14c;
  PointList* maze14d = create_cell(xmax/2 - 5, ymax/2 + 11);
  maze14c->next = maze14d;
  // end of left maze wall
  
  //lowest wall
  PointList* maze140 = create_cell(xmax/2 - 5, ymax/2 + 11);
  maze14d->next = maze140;
  PointList* maze141 = create_cell(xmax/2 - 4, ymax/2 + 11);
  maze140->next = maze141;
  PointList* maze142 = create_cell(xmax/2 - 3, ymax/2 + 11);
  maze141->next = maze142;
  PointList* maze143 = create_cell(xmax/2 - 2, ymax/2 + 11);
  maze142->next = maze143;
  PointList* maze144 = create_cell(xmax/2 - 1, ymax/2 + 11);
  maze143->next = maze144;
  PointList* maze145 = create_cell(xmax/2 - 0, ymax/2 + 11);
  maze144->next = maze145;
  PointList* maze146 = create_cell(xmax/2 + 1, ymax/2 + 11);
  maze145->next = maze146;
  PointList* maze147 = create_cell(xmax/2 + 2, ymax/2 + 11);
  maze146->next = maze147;

  // Entrance of maze 
  PointList* maze15 = create_cell(xmax/2 - 4, ymax/2 - 3);
  maze147->next = maze15;
  PointList* maze16 = create_cell(xmax/2 - 4, ymax/2 + 7);
  maze15->next = maze16;

  // Top section of maze
  PointList* maze17 = create_cell(xmax/2 - 1, ymax/2 - 5);
  maze16->next = maze17;
  PointList* maze18 = create_cell(xmax/2 - 0, ymax/2 - 5);
  maze17->next = maze18;
  PointList* maze19 = create_cell(xmax/2 +1, ymax/2 - 5);
  maze18->next = maze19;
  PointList* maze20 = create_cell(xmax/2 +2, ymax/2 - 5);
  maze19->next = maze20;
  PointList* maze20a = create_cell(xmax/2 +3, ymax/2 - 5);
  maze20->next = maze20a;
  PointList* maze20b = create_cell(xmax/2 +4, ymax/2 - 5);
  maze20a->next = maze20b;
  PointList* maze20c = create_cell(xmax/2 +5, ymax/2 - 5);
  maze20b->next = maze20c;

  // Maze right-wall
  PointList* maze21 = create_cell(xmax/2 + 5, ymax/2 - 5);
  maze20c->next = maze21;
  PointList* maze22 = create_cell(xmax/2 + 5, ymax/2 - 4);
  maze21->next = maze22;
  PointList* maze23 = create_cell(xmax/2 + 5, ymax/2 - 3);
  maze22->next = maze23;
  PointList* maze24 = create_cell(xmax/2 + 5, ymax/2 - 2);
  maze23->next = maze24;
  PointList* maze25 = create_cell(xmax/2 + 5, ymax/2 - 1);
  maze24->next = maze25;
  PointList* maze26 = create_cell(xmax/2 + 5, ymax/2 - 0);
  maze25->next = maze26;
  PointList* maze27 = create_cell(xmax/2 + 5, ymax/2 + 1);
  maze26->next = maze27;
  PointList* maze28 = create_cell(xmax/2 + 5, ymax/2 + 2);
  maze27->next = maze28;
  PointList* maze29 = create_cell(xmax/2 + 5, ymax/2 + 3);
  maze28->next = maze29;
  PointList* maze30 = create_cell(xmax/2 + 5, ymax/2 + 4);
  maze29->next = maze30;
  PointList* maze31 = create_cell(xmax/2 + 5, ymax/2 + 5);
  maze30->next = maze31;
  PointList* maze32 = create_cell(xmax/2 + 5, ymax/2 + 6);
  maze31->next = maze32;
  PointList* maze33 = create_cell(xmax/2 + 5, ymax/2 + 7);
  maze32->next = maze33;
  
  PointList* maze33a = create_cell(xmax/2 + 5, ymax/2 + 8);
  maze33->next = maze33a;
  PointList* maze33b = create_cell(xmax/2 + 5, ymax/2 + 9);
  maze33a->next = maze33b;
  PointList* maze33c = create_cell(xmax/2 + 5, ymax/2 + 10);
  maze33b->next = maze33c;
  // end of right-hand maze wall

  // Start of inner left wall
  PointList* maze34 = create_cell(xmax/2 - 2, ymax/2 - 0);
  maze33c->next = maze34;
  PointList* maze34a = create_cell(xmax/2 - 2, ymax/2 + 1);
  maze34->next = maze34a;
  PointList* maze34g = create_cell(xmax/2 - 2, ymax/2 + 2);
  maze34a->next = maze34g;
  
  PointList* maze34h = create_cell(xmax/2 - 2, ymax/2 - 1);
  maze34g->next = maze34h;
  PointList* maze35 = create_cell(xmax/2 - 1, ymax/2 + -1);
  maze34h->next = maze35;
  PointList* maze36 = create_cell(xmax/2 - 0, ymax/2 + -1);
  maze35->next = maze36;
  PointList* maze37 = create_cell(xmax/2 + 1, ymax/2 + -1);
  maze36->next = maze37;
  PointList* maze38 = create_cell(xmax/2 - 2, ymax/2 + 3);
  maze37->next = maze38;
  PointList* maze39 = create_cell(xmax/2 - 2, ymax/2 + 4);
  maze38->next = maze39;
  PointList* maze40 = create_cell(xmax/2 - 2, ymax/2 + 5);
  maze39->next = maze40;
  // end of inner left wall

  // Start of bottom section
  PointList* maze41 = create_cell(xmax/2 - 4, ymax/2 + 7);
  maze40->next = maze41;
  PointList* maze42 = create_cell(xmax/2 - 3, ymax/2 + 7);
  maze41->next = maze42;
  PointList* maze43 = create_cell(xmax/2 - 2, ymax/2 + 7);
  maze42->next = maze43;
  PointList* maze44 = create_cell(xmax/2 - 1, ymax/2 + 7);
  maze43->next = maze44;
  PointList* maze45 = create_cell(xmax/2 - 0, ymax/2 + 7);
  maze44->next = maze45;

PointList* maze45a = create_cell(xmax/2 +1, ymax/2 + 7);
  maze45->next = maze45a;
PointList* maze45b = create_cell(xmax/2 +2, ymax/2 + 7);
  maze45a->next = maze45b;
/*ointList* maze45c = create_cell(xmax/2 +3, ymax/2 + 7);
  maze45b->next = maze45c;*/
/*PointList* maze45d = create_cell(xmax/2 +4, ymax/2 + 7);
  maze45c->next = maze45d;*/
  // End of bottom section 

  // Start of inner top section 
  PointList* maze46 = create_cell(xmax/2 - 3, ymax/2 - 3);
  maze45b->next = maze46;
  PointList* maze47 = create_cell(xmax/2 - 2, ymax/2 - 3);
  maze46->next = maze47;
  PointList* maze47a = create_cell(xmax/2 - 1, ymax/2 - 3);
  maze47->next = maze47a;
  PointList* maze47b = create_cell(xmax/2 - 0, ymax/2 - 3);
  maze47a->next = maze47b;
PointList* maze47c = create_cell(xmax/2 +1, ymax/2 - 3);
  maze47b->next = maze47c;
  PointList* maze48 = create_cell(xmax/2 + 2, ymax/2 - 3);
  maze47c->next = maze48;
  
  PointList* maze48a = create_cell(xmax/2 + 3, ymax/2 - 1);
  maze48->next = maze48a;
  PointList* maze48b = create_cell(xmax/2 + 4, ymax/2 - 1);
  maze48a->next = maze48b;
  // End of inner top section 

  // Start of inner right wall 
  PointList* maze49 = create_cell(xmax/2 -1, ymax/2 - 3);
  maze48b->next = maze49;
  PointList* maze50 = create_cell(xmax/2 +2, ymax/2 - 1);
  maze49->next = maze50;
  /*PointList* maze51 = create_cell(xmax/2 +2, ymax/2 - 0);
  maze48->next = maze51;*/
  PointList* maze52 = create_cell(xmax/2 +2, ymax/2 + 1);
  maze50->next = maze52;
  PointList* maze53 = create_cell(xmax/2 +2, ymax/2 + 2);
  maze52->next = maze53;
  PointList* maze54 = create_cell(xmax/2 +2, ymax/2 + 3);
  maze53->next = maze54;
  PointList* maze55 = create_cell(xmax/2 +2, ymax/2 + 4);
  maze54->next = maze55;
  // End of inner right wall


  // Start of inner bottom wall
  PointList* maze56a = create_cell(xmax/2 +2, ymax/2 + 5);
  maze55->next = maze56a;
  PointList* maze56 = create_cell(xmax/2 +1, ymax/2 + 5);
  maze56a->next = maze56;
  PointList* maze57 = create_cell(xmax/2 +1, ymax/2 +6);
  maze56->next = maze57;
  /*PointList* maze58 = create_cell(xmax/2 - 1, ymax/2 + 5);
  maze57->next = maze58;
  PointList* maze59 = create_cell(xmax/2 - 0, ymax/2 + 5);
  maze58->next = maze59;
*/

  // Start of inner lower bottom wall
  PointList* maze58 = create_cell(xmax/2 + 4, ymax/2 + 9);
  maze57->next = maze58;
  PointList* maze59 = create_cell(xmax/2 + 3, ymax/2 + 9);
  maze58->next = maze59;
  PointList* maze60 = create_cell(xmax/2 + 2, ymax/2 + 9);
  maze59->next = maze60;
  PointList* maze61 = create_cell(xmax/2 + 1, ymax/2 + 9);
  maze60->next = maze61;
  PointList* maze62 = create_cell(xmax/2 + 0, ymax/2 + 9);
  maze61->next = maze62;
  PointList* maze63 = create_cell(xmax/2 - 1, ymax/2 + 9);
  maze62->next = maze63;
  PointList* maze64 = create_cell(xmax/2 - 2, ymax/2 + 9);
  maze63->next = maze64;


  //mazeLAST->next = NULL;
  //maze58->next = NULL;

  return maze;

}
