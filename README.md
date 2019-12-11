# snakegame

The code builds upon the code created by Julian Evans from this repository: https://github.com/jvns/snake 
I have used the same license as her, MIT license. 

Features added include:

- Showing the score at middle top of screen

- PVP : eat a pvp bonus and a 2nd snake appears which can be controlled with WASD 

- Fireblocks : eat a fireblock power up and you can shoot a fireblock which will eat food in its path
  ( Enter for playerA, Space for playerB )
  
- Anaconda power up : transform into a monster snake which guzzles food easily

- Maze in the centre

- Splash screens for the start of the game, for when PvP bonus is eaten, for when Anaconda bonus is eaten

NOTES FOR DEVELOPERS:
- The way I went about doing these features, apart from the coordinates method, was to add variables to the PointList struct, some for snakes, some for fireblocks, some for anaconda, the PointList struct is in backend.h
For example when a snake eats a fireblock the hasFireblock variable in the snake head PointList gets set to 1, when the user presses the special key the fireblock is fired from the snake so Fireblock variable independentOfSnake is set to 1, while the snake's hasFireblock is set back to 0. 
 - I also changed the way that the snake is moved by dominoing the coords of each part to the next part of the snake, then updating the first part, the head, with the new coordinates of the next move point. 
 - I changed the way food is eaten and a new one created, instead of freeing an item and creating a new one, I just changed the         coordinates of the existing food item when it is eaten, simulating it being removed and a new one made. 
 - For Anacondas I decided to keep the existing snakes points and just show additional blocks around it, this requires starting from the snake head block and then changing to the surrounding points to display blocks there too. This also meant that when eating food, I need to do extra checks for the snake head point and all surrounding points, which was a bit of a headache. It might have been better to make the anaconda actually have more blocks in the head rather than simulating it, but this is the way I did it. For example things like list_contains for anaconda needed a new function dedicated to anaconda checks. 
 - For fireblocks I created new functions similar to the move_snake but for fireblocks. As they span a few points I did these a similar way to Anacondas which is to move the centre block and simulate the surrounding blocks. I also have these moving double speed, which is done by calling move on them twice for every one of move_snake. 
