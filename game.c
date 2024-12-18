// COMP 201 - ALEC - ORTIZ - X04L - 3114013
//--------------------------------------------------------
/// @file game.c                                          |
/// @brief Main file to run the main process of the game  |
/// @author Alec Ortiz                                    |
/// @date April 7th, 2024                                 |
//--------------------------------------------------------
//------ LIBRARIES ---------------------------------------  
#include <stdio.h>
#include <ncurses.h>
#include "gameFunctions.h"
#include "levels.h"
//------ MACROS ------------------------------------------ 
#define THIRD 52
#define TWO_THIRD 104
//------ MAIN FUNCTINO ----------------------------------
int main(void){
	// Intialize screen, ensure input characters are not recorded, and erase the cursor
	initscr(); noecho(); cbreak(); curs_set(0);
	// Create a window pointer, pointing to a new window termed mainWin
	WINDOW *mainWin = newwin(30, 80, 0, 0);
	// Refresh the new screen
	refresh();
	// Initialize colors with colorPal function
	colorPal();
	// Int variable termed level to hold the user's choice from the game start menu
	int level = gameStart(mainWin);
	//======= SWITCH CASE ======================================
	switch(level){
		// Case 1 - User pressed quit
		case 1:
			// Delete the new window created
			delwin(mainWin);
			// End the main screen
			endwin();
			// Break from switch case
			break;
		// Case 0 - User presses start
		case 0:
			// Start level one
			levelOne(mainWin);
			// Delete the new created window
			delwin(mainWin);
			// Break from switch case
			break;
	}
	//=========================================================
	// Return successful
	return 0;
}
//------ FIN ---------------------------------------------------------------------------

























