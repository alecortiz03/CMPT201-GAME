// COMP 201 - ALEC - ORTIZ - 3114013 - X04L
//--------------------------------------------------------
/// @file levels.c                                        |
/// @brief Main file to run level functions               |
/// @author Alec Ortiz                                    |
/// @date April 7th, 2024                                 |
//--------------------------------------------------------
#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#include <stdbool.h>
#include "gameFunctions.h"
#include "player.h"
#include "levelHelper.h"
//------ GAME_START -----------------------------------------------------------------
int gameStart(WINDOW *mainWin){
	// Turn keypad on
        keypad(mainWin, true);
	// Set int variable choice to the user's choice from the start menu
        int choice = startMenu(mainWin);
	// Return the user's choice
        return choice;
}
//------ LEVEL_ONE ------------------------------------------------------------
int levelOne(WINDOW *mainWin){
	// Set int variable version to 0
        int version = 0;
	// Erase the main window
	werase(mainWin);
	// Put a border around the main window 
        mainBorder(mainWin);
	// Print Title - LEVEL ONE
        printTitle(mainWin, 2, 27, 10);
	// Sleep for 2 seconds
        sleep(2);
        // Print instruction menu before user starts playing
	printIn(mainWin);
        
	//====== PLACE PLAYER =======================================================
	// Place player at (3, 14)
        Player player = createPlayer(mainWin, 3, 14);
	// Set Player pointer - playerOne - to point to new Player structure 
        Player *playerOne = &player;
	// Refresh the main window
        wrefresh(mainWin);
        //===========================================================================
	
	// Print user's reminder of instructions
	inKey(playerOne);
        // Set int variable readKey to 0
	int readKey = 0;

	//====== MAIN INTERACTION ===================================================================================================================
        while(true){
		// If playerOne has obtained all the keys  - Player has completed the tasks in the game
		if( (playerOne->levelOneForestKey + playerOne->levelOneHouseKey + playerOne->levelOneCHouseKey + playerOne->levelOneTentKey) == 4){
		// Set version to 1
                version = 1;
}
		// Print the main image for level one
		printLevelOneMain(mainWin, version);
		// Place player at their current position - BUG FIX for player disapearance 
		placePlayer(mainWin, playerOne, playerOne->pos_x, playerOne->pos_y);
		// Print user's reminder of instructions
		inKey(playerOne);
		// Set readKey to the to player input 
                readKey = wgetch(mainWin);
		// If user presses the right key
                if (readKey == KEY_RIGHT){
			// Move player right
                        playerRight(mainWin, playerOne);
                }
		// If user presses the left key
                if (readKey == KEY_LEFT){
			// Move player left
                        playerLeft(mainWin, playerOne);
                }
		// If user presses the up key
                if (readKey == KEY_UP){
			// Move player up
                        playerUp(mainWin, playerOne);
                }
		// If user presses the down key
                if (readKey == KEY_DOWN){
			// Move user down
                        playerDown(mainWin, playerOne);
                }
		// If player presses p
                if(readKey == 'p'){
			// Display pause window
                        pauseWindow(mainWin);
			// Refresh the main window
                        wrefresh(mainWin);
                }
		// If user presses e - If user attempt to interact
		if(readKey == 'e'){
			// Attempt to enter The Forest level
			enterForest(mainWin, playerOne);
			// Attempt to enter The House level
			enterHouse(mainWin, playerOne);
			// Attempt to enter The Chimney House level
			enterCHouse(mainWin, playerOne);
			// Attempt to enter The Tents level
			enterTent(mainWin, playerOne);
			//====== END GAME ==================================================================
			// If the version of Level One is 1
			if(version == 1){
				// Set bool variable endGame to the check if user is by car the End Game
				bool endGame = carCol(playerOne);
				// If user is by car to End Game
				if(endGame == true){
				// Print the ending game sequence 
				printEndGame(mainWin, playerOne);
				// Break
				break;	
				}
			}
			}
			//====================================================================================
	}
	//=============================================================================================================
	

	// Clear screen
	clear();
	// Delete the main window
	delwin(mainWin);
	// End the main screen
	endwin();
	// Return 0
        return 0;
}                                                     
//------ FOREST_LEVEL --------------------------------------------------------------------------
void forestLevel(WINDOW *mainWin, Player *playerOne){
	// Set int variable to version
	int version;
	// If user has The Forest key
	if (playerOne->levelOneForestKey == 1){
		// Set version to 0
		version = 0;
	}
	// Else
	else{
		// Set version to 1
		version = 1;
	}
	// Erase the main window 
	werase(mainWin);
	// Refresh the main window
      	wrefresh(mainWin);
	// If player has not entered The Forest before
	if(playerOne->forestEncounter == 0){
		// Print Title - The Forest
      		printTitle(mainWin, 3, 25, 10);
		// Put a border around the main window
		mainBorder(mainWin);
		// Sleep for 2 seconds
      		sleep(2);
		// Erase the main window
       		werase(mainWin);
		// Set player - Entered Forest
		playerOne->forestEncounter = 1;
	}
	// Print Forest Level
	printForestLevel(mainWin, version);
	// Save player's old y
	int old_x = playerOne->pos_x;
	// Save player's old y
	int old_y = playerOne->pos_y;
	// Place player on The Forest level
	placePlayer(mainWin, playerOne, 5, 10);
	// Refresh the main window
	wrefresh(mainWin);
	// Print user's reminder of instructions
	inKey(playerOne);
	// Set int variable readKey to 0
        int readKey = 0;

	//====== MAIN INTERACTION =================================================================
        while(true){
		// Print The Forest level
		printForestLevel(mainWin, version);
		// Place player in their current position - BUG FIX for player disapearing
                placePlayer(mainWin, playerOne, playerOne->pos_x, playerOne->pos_y);
		// Print user;s reminder of instructions
		inKey(playerOne);
		// Set readKey to user input
                readKey = wgetch(mainWin);
		// If player presses the right key
                if (readKey == KEY_RIGHT){
			// Move player right
                        playerRight(mainWin, playerOne);
                }
		// If player presses the left key
                if (readKey == KEY_LEFT){
			// Move player left
                        playerLeft(mainWin, playerOne);
                }
		// If player presses the up key
                if (readKey == KEY_UP){
			// Move player up
                        playerUp(mainWin, playerOne);
                }
		// If player presses the down key
                if (readKey == KEY_DOWN){
			// Move player down
                        playerDown(mainWin, playerOne);
                }
		// If player presses p
                if(readKey == 'p'){
			// Display pause window
                        pauseWindow(mainWin);
			// Refresh the main window
                        wrefresh(mainWin);
                }
		// If player presses e - Player attempts to interact
		if(readKey == 'e'){
			// Display The Forest quiz
			forestQuiz(mainWin, playerOne);
			// If player has The Forest key
			if(playerOne->levelOneForestKey == 1){
				// Set version to 0
				version = 0;
			}
			// Set bool variable leave to check if the user is in range to EXIT
			bool leave = exitCol(playerOne);
			// If user is in range to EXIT
			if(leave == true){
				// Break
				break;
			}
		}
        }
	//==============================================================================================================
	

	// Erase the main window
	werase(mainWin);
	// Refresh the main window
	wrefresh(mainWin);
	// Set player back to their old position before entering The Forest Level
	setPlayer(playerOne, old_x, old_y);
	// Return - Return back to the main Level One screen
	return;
}
//------ HOUSE_LEVEL ---------------------------------------------------------------------------------------
void houseLevel(WINDOW *mainWin, Player *playerOne){
	// Set int variable to version
	int version;
	// If player has The House key
	if (playerOne->levelOneHouseKey == 1){
		// Set version to 0
                version = 0;
        }
	// Else
        else{
		// Set version to 1
                version = 1;
        }
	// Erase the main window
	werase(mainWin);
	// If player has not entered The House level before 
	if (playerOne->houseEncounter != 1){
		// Print Title - The House
		printTitle(mainWin, 4, 25, 10);
		// Put a border around the main window
		mainBorder(mainWin);
		// Refresh the main window
		wrefresh(mainWin);
		// Sleep for 2 seconds
		sleep(2);
		// Erase the main window
		werase(mainWin);
		// Set player - Enctounered The House level
		playerOne->houseEncounter = 1;
	}
	// Print user's reminder of instructions
	inKey(playerOne);
	// Set int variable old x to the old x position of the player
	int old_x = playerOne->pos_x;
	// Set int variable old y to the old y position of the player
        int old_y = playerOne->pos_y;
	// Print The House Level
	printHouseLevel(mainWin, version);
	// Place player on The House Level
        placePlayer(mainWin, playerOne, 5, 10);
	// Refresh the main window
        wrefresh(mainWin);
	// Set int variable readKey to 0
	int readKey = 0;

	//====== MAIN INTERACTION ======================================================================
        while(true){
		// Print The House Level
		printHouseLevel(mainWin, version);
		// Place player on their current position - BUG FIX for disapearing player
                placePlayer(mainWin, playerOne, playerOne->pos_x, playerOne->pos_y);
		// Print user's reminder of instructions
                inKey(playerOne);
		// Set readKey to the user's input
                readKey = wgetch(mainWin);
		// If the player presses the right key
                if(readKey == KEY_RIGHT){
			// Move player right
                        playerRight(mainWin, playerOne);
                }
		// If player presses the left key
                if(readKey == KEY_LEFT){
			// Move player left
                        playerLeft(mainWin, playerOne);
                }
		// If player presses the up key
                if(readKey == KEY_UP){
			// Move player up
                        playerUp(mainWin, playerOne);
                }
		// If player presses the down key
                if(readKey == KEY_DOWN){
			// Move player down
                        playerDown(mainWin, playerOne);
                }
		// If player presses p
                if(readKey == 'p'){
			// Display pause window
                        pauseWindow(mainWin);
			// Refresh the main window
                        wrefresh(mainWin);
                }
		// If player presses e - Player attempts to interact
                if(readKey == 'e'){
			// Display The House quiz
			houseQuiz(mainWin, playerOne);
			// If player has The House key
                        if(playerOne->levelOneHouseKey == 1){
				// Set version to 0
                                version = 0;
                        }
			// Set bool variable leave to check if the user is by the EXIT 
                        bool leave = exitCol(playerOne);
			// If user is by the EXIT
                        if(leave == true){
				// Break
                                break;
                        }
                }
        }
	//===========================================================================================================
	

	// Erase the main window
        werase(mainWin);
	// Refresh the main window
        wrefresh(mainWin);
	// Set the player back to their old position
        setPlayer(playerOne, old_x, old_y);
        return;
}
//------ C_HOUSE_LEVEL -----------------------------------------------------------------------------------------------
void cHouseLevel(WINDOW *mainWin, Player *playerOne){
	// Set in variable to version
        int version;
	// If user has The Chimney House key
	if (playerOne->levelOneCHouseKey == 1){
		// Set version to 0
                version = 0;
        }
	// Else 
        else{
		// Set version to 1
                version = 1;
        }
	// Erase the main window
        werase(mainWin);
	// If player has not entered The Chimney House before
        if (playerOne->cHouseEncounter != 1){
		// Print Title - The Chimney House
                printTitle(mainWin, 5, 23, 8);
		// Put a border around the main window
                mainBorder(mainWin);
		// Refresh the main window
                wrefresh(mainWin);
		// Sleep for 2 seconds
                sleep(2);
		// Erase the main window
                werase(mainWin);
		// Set player - Enctounered The Chimney House
                playerOne->cHouseEncounter = 1;
        }
	// Print the user's reminder of the instructions
        inKey(playerOne);
	// Set int variable old x to the player's old x position
        int old_x = playerOne->pos_x;
	// Set int variable old y to the player's old y position
        int old_y = playerOne->pos_y;
	// Print The Chimney House level
        printCHouseLevel(mainWin, version);
	// Place player in The Chimney House level
        placePlayer(mainWin, playerOne, 6, 16);
	// Refresh the main window
        wrefresh(mainWin);
	// Set int variable readKey to 0
        int readKey = 0;

	//====== MAIN INTERACTION ======================================================================================
        while(true){
		// Print The Chimney House level
                printCHouseLevel(mainWin, version);
		// Place player in their current position - BUG FIX for player disapearing 
                placePlayer(mainWin, playerOne, playerOne->pos_x, playerOne->pos_y);
		// Print the user's reminder of the instructions 
                inKey(playerOne);
		// Set readKey to the user's input
                readKey = wgetch(mainWin);
		// If player presses the right key 
                if(readKey == KEY_RIGHT){
			// Move player right 
                        playerRight(mainWin, playerOne);
                }
		// If player presses the left key
                if(readKey == KEY_LEFT){
			// Move player left
                        playerLeft(mainWin, playerOne);
                }
		// If player presses the up key
                if(readKey == KEY_UP){
			// Move player up
                        playerUp(mainWin, playerOne);
                }
		// If player presses the down key
                if(readKey == KEY_DOWN){
			// Move player down
                        playerDown(mainWin, playerOne);
                }
		// If player presses p 
                if(readKey == 'p'){
			// Display pause window
                        pauseWindow(mainWin);
			// Refresh the main window
                        wrefresh(mainWin);
			 }
		// If player presses e - Player attempts to interact
                if(readKey == 'e'){
			// Display The Chimney House quiz
			cHouseQuiz(mainWin, playerOne);
			// If player has The Chimney House Key
                        if(playerOne->levelOneCHouseKey == 1){
				// Set version to 0
                                version = 0;
                        }
			// Set bool variable leave to check if the player is near the EXIT
                        bool leave = exitCol(playerOne);
			// If player is near the EXIT
                        if(leave == true){
				// Break
                                break;
                        }
                }
        }
	//=======================================================================================================
	

	// Erase the main window
        werase(mainWin);
	// Refresh the main window
        wrefresh(mainWin);
	// Set player back to their old position before entering The Chimney House level
        setPlayer(playerOne, old_x, old_y);
	// Return to the main Level One screen
        return;
}
//------ TENT_LEVEL -------------------------------------------------------------------------------------------
void tentLevel(WINDOW *mainWin, Player *playerOne){
	// Set int variable to version
        int version;
	// If player has The Tents level key
        if (playerOne->levelOneTentKey == 1){
		// Set version to 0
                version = 0;
        }
	// Else
        else{
		// Set version to 1
                version = 1;
        }
	// Erase the main window
        werase(mainWin);
	// If player has not entered The Tents level before
        if (playerOne->tentEncounter != 1){
		// Print Title - The Tents
                printTitle(mainWin, 6, 23, 8);
		// Put a border around the main window
                mainBorder(mainWin);
		// Refresh the main window
                wrefresh(mainWin);
		// Sleep for 2 seconds
                sleep(2);
		// Erase the main window 
                werase(mainWin);
		// Set player - Encountered The Tents level
                playerOne->tentEncounter = 1;
        }
	// Print the user's reminder of the instructions
        inKey(playerOne);
	// Set int variable old x to the player's old x value
        int old_x = playerOne->pos_x;
	// Set int variable old y to the player's old y position 
        int old_y = playerOne->pos_y;
	// Print The Tents level
        printTentLevel(mainWin, version);
	// Place player in The Tents level
        placePlayer(mainWin, playerOne, 6, 16);
	// Refresh the main window
        wrefresh(mainWin);
	// Set int variable readKey to 0
        int readKey = 0;

	//====== MAIN INTERACTION ===============================================================
        while(true){
		// Print The Tents level
                printTentLevel(mainWin, version);
		// Place player in their current position - BUG FIX for player disapearing 
                placePlayer(mainWin, playerOne, playerOne->pos_x, playerOne->pos_y);
		// Print the user's reminder for the instructions
                inKey(playerOne);
		// Set readkey to the user's input
                readKey = wgetch(mainWin);
		// If player presses the right key
                if(readKey == KEY_RIGHT){
			// Move player right 
                        playerRight(mainWin, playerOne);
                }
		// If player presses the left key
                if(readKey == KEY_LEFT){
			// Move player left
                        playerLeft(mainWin, playerOne);
                }
		// If player presses the up key
                if(readKey == KEY_UP){
			// Move player right
                        playerUp(mainWin, playerOne);
                }
		// If player presses the down key
                if(readKey == KEY_DOWN){
			// Move player down
		        playerDown(mainWin, playerOne);
                }
		// If player presses p
                if(readKey == 'p'){
			// Display the pause window
                        pauseWindow(mainWin);
			// Refresh the main window
                        wrefresh(mainWin);
                         }
		// If player presses e - Player attempts to interact
                if(readKey == 'e'){
			// Display The Tents quiz
			tentQuiz(mainWin, playerOne);
			// If player has The Tents key
                        if(playerOne->levelOneTentKey == 1){
				// Set version to 0
                                version = 0;
                        }
			// Set bool variable leave to check if the player is near the EXIT
                        bool leave = exitCol(playerOne);
			// If player is near the EXIT
                        if(leave == true){
				// Break
                                break;
                        }
                }
        }
	// Erase the main window
        werase(mainWin);
	// Refresh the main window
        wrefresh(mainWin);
	// Set player back to their old position before they entered The Tents level
        setPlayer(playerOne, old_x, old_y);
	// Return back to level one
        return;
}
//------ FIN --------------------------------------------------
