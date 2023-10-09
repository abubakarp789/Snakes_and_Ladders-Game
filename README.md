# Snakes and Ladders Game

This is a simple implementation of the Snakes and Ladders game in C++. The game can be played by two players, and it includes features such as saving and loading game progress. Players take turns rolling a dice and advancing on the game board, encountering snakes and ladders along the way.

## How to Play

1. Run the program.
2. You will be prompted to choose between starting a new game (press 'n' or 'N') or loading a previous game (press 'l' or 'L').
   - If you choose to load a previous game, the saved game state will be loaded.
   - If you choose to start a new game, you will be prompted to enter characters for Player 1 and Player 2.
3. Players take turns rolling a dice by pressing any key.
4. Players advance on the board based on the dice roll.
5. Snakes and ladders are encountered along the way, affecting the player's position.
6. The game continues until one player reaches square 100 and wins.

## Controls

- Press any key to roll the dice when it's your turn.
- Press 's' or 'S' during the game to save the current game state and exit.
- The game can be loaded later by choosing 'load' when starting the program.

## Features

- Players can roll a dice to move on the board.
- Snakes and ladders are implemented.
- The game keeps track of each player's position.
- You can save and load game progress.

## Game Board

The game board is displayed in the console, with numbers representing squares, and snakes ('S') and ladders ('L') affecting the gameplay.

## Game Logic

- Players take turns rolling a dice and move forward on the board.
- If a player rolls a 6, they get another turn (up to three consecutive turns).
- If a player lands on a snake, they move back to a lower square.
- If a player lands on a ladder, they move forward to a higher square.
- The game ends when one player reaches square 100.

## Code Explanation

The code includes functions for moving the cursor on the console, displaying the game board, rolling the dice, handling player scores, and implementing snakes and ladders.

## Enjoy the Game!

Have fun playing Snakes and Ladders! If you encounter any issues or want to make improvements, feel free to modify the code and contribute to the project.
