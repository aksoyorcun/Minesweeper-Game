# Minesweeper Game
This is a simple implementation of the Minesweeper game in C programming language. The game is played on a 10x10 grid, and the objective is to uncover all the cells that do not contain mines without triggering a mine.

## How to Play
1. The game starts by initializing the game grid, placing mines randomly, and calculating the numbers in each cell based on the neighboring mines.

2. The game will display an initial empty grid with coordinates labeled on the top and left sides.

3. You can choose to either place a flag or select a cell by entering the column and row coordinates.

4. To place a flag, enter 1 when prompted and provide the coordinates of the cell. Flags are used to mark cells that you think contain mines.

5. To select a cell, enter 0 when prompted and provide the coordinates of the cell. If the selected cell contains a mine, the game will end and display the game over message along with the final grid. Otherwise, the selected cell and its neighboring cells will be uncovered. If the selected cell has no neighboring mines, adjacent cells will be automatically uncovered recursively.

6. The game continues until either all the cells without mines are uncovered, resulting in a win, or a cell containing a mine is uncovered, resulting in a loss.

7. After the game ends, the total time taken to complete the game will be displayed.

## Code Explanation
 The code is divided into several functions to perform different tasks:

- **initializeGame:** Initializes the game grid, setting all cells to zero and flags to zero.

- **placeMines:** Randomly places mines in the grid based on the MINES constant.

- **calculateNumbers:** Calculates the numbers in each cell based on the neighboring mines.

- **printTable:** Prints the game grid on the console, including flagged cells and numbers.

- **placeFlag:** Handles the logic for placing flags on cells.

- **selectedCell:** Handles the logic for selecting a cell and recursively uncovering adjacent cells.

- **gameOverTable:** Prints the final game grid when the game is over, revealing all mines and flagged cells.

- **main:** The main function that runs the game. It initializes the game, starts the timer, and handles the player's input until the game ends.

## Compilation and Execution
To compile and run the code, follow these steps:

1. Save the code in a file with a .c extension (e.g., minesweeper.c).

2. Open a terminal or command prompt and navigate to the directory where the file is saved.

3. Use a C compiler to compile the code. For example, using gcc:

```
gcc minesweeper.c -o minesweeper
```
4. Run the compiled executable:
```
./minesweeper
```


5. Follow the prompts in the console to play the game.

**Note:** This code assumes you have a C compiler installed on your system.

**Enjoy playing Minesweeper!**

## OUTPUT
![image](https://github.com/aksoyorcun/Minesweeper-Game/assets/136446246/d04b66bd-a6e2-4989-965b-1331814a8a01)
