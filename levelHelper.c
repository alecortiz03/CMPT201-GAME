// COMP 201 - ALEC - ORTIZ - 3114013 - X04L
//--------------------------------------------------------
/// @file levelHelper.c                                   |
/// @brief Main file to run helper functions for levels   |
/// @author Alec Ortiz                                    |
/// @date April 7th, 2024                                 |
//--------------------------------------------------------
#include <ncurses.h>
#include <unistd.h>
#include "levels.h"
#include "player.h"
#include "gameFunctions.h"


//------ PRINT_IN -------------------------------------------------------------------------------------------------------
void printIn(WINDOW *mainWin){
	// Erase main window
	werase(mainWin);
	// Put a border around the main window 
	mainBorder(mainWin);
	// Set int variable readKey to 0
	int readKey = 0;
	// While readKey is not equal to enter - User has not pressed enter
	while(readKey != '\n'){
		//====== INSTRUCTIONS ===================================================================
		// Turn on red
		wattron(mainWin, COLOR_PAIR(3));
		mvwprintw(mainWin, 3, 3, "Hello there fellow camper.");
		mvwprintw(mainWin, 4, 3, "It seems you've finally woken up.");
		mvwprintw(mainWin, 5, 3, "I understand that you may be confused but fear no more.");
		mvwprintw(mainWin, 6, 3, "By my gacrious hand, I am allowing YOU to escape");
		// Turn off red
		wattroff(mainWin, COLOR_PAIR(3));
		mvwprintw(mainWin, 10, 3, "Here are MY rules:");
		mvwprintw(mainWin, 11, 3, "-------------------");
		mvwprintw(mainWin, 12, 3, "All interactions are completed using '");
		// Turn on green
		wattron(mainWin, COLOR_PAIR(1));
		// Turn on bold
		wattron(mainWin, A_BOLD);
		mvwprintw(mainWin, 12, 41, "e");
		// Turn off bold
		wattroff(mainWin, A_BOLD);
		// Turn off green
		wattroff(mainWin, COLOR_PAIR(1));
		mvwprintw(mainWin, 12, 42, "'");
		mvwprintw(mainWin, 13, 3, "Enter all sections by getting close to the area and pressing '");
		// Turn on green
		wattron(mainWin, COLOR_PAIR(1));
		// Turn on bold
                wattron(mainWin, A_BOLD);
		mvwprintw(mainWin, 13, 65, "e");
		// Turn off bold
		wattroff(mainWin, A_BOLD);
		// Turn off green
                wattroff(mainWin, COLOR_PAIR(1));
		mvwprintw(mainWin, 13, 66, "'");
		mvwprintw(mainWin, 14, 3, "Level One has 4 sections and Level Two has 5.");
		mvwprintw(mainWin, 15, 3, "Go into each section and interact with the yellow '!'");
		// Turn on yellow
		wattron(mainWin, COLOR_PAIR(5));
		// Turn on bold
                wattron(mainWin, A_BOLD);
		mvwprintw(mainWin, 15, 54, "!");
		// Turn off bold
		wattroff(mainWin, A_BOLD);
		// Turn off yellow
                wattroff(mainWin, COLOR_PAIR(5));
		mvwprintw(mainWin, 15, 55, "'");
		mvwprintw(mainWin, 16, 3, "Answer each quiz correctly and be granted a key");
		mvwprintw(mainWin, 17, 3, "Interact with '");
		// Turn on red
		wattron(mainWin, COLOR_PAIR(3));
		// Turn on bold
                wattron(mainWin, A_BOLD);
		mvwprintw(mainWin, 17, 18, "EXIT");
		// Turn off bold
		wattroff(mainWin, A_BOLD);
		// Turn off red
                wattroff(mainWin, COLOR_PAIR(3));
		mvwprintw(mainWin, 17, 22, "' to exit each section.");
		mvwprintw(mainWin, 18, 3, "After collecting all keys, a car should show up for you escape");
		mvwprintw(mainWin, 19, 3, "Press '");
		// Turn on green
		wattron(mainWin, COLOR_PAIR(1));
		// Turn on bold
                wattron(mainWin, A_BOLD);
		mvwprintw(mainWin, 19, 10, "e");
		// Turn off bold
		wattroff(mainWin, A_BOLD);
		// Turn off green
                wattroff(mainWin, COLOR_PAIR(1));
		mvwprintw(mainWin, 19, 11, "' by the car to finish the level....");
		mvwprintw(mainWin, 20, 3, "IF YOU CAN ESCAPE......");
		// Turn off blink
		wattron(mainWin, A_BLINK);
		mvwprintw(mainWin ,26, 3, "[PRESS ENTER TO CONTINUE]");
		// Turn off blink
		wattroff(mainWin, A_BLINK);
		// Refresh main window
		wrefresh(mainWin);
		// Set readKey to the user's input
		readKey = wgetch(mainWin); 
	}
	// Erase the main window
	werase(mainWin);
	// Return
	return;
}
//------ PRINT_LEVEL_ONE_MAIN -----------------------------------------------------------------
void printLevelOneMain(WINDOW *mainWin, int version){
//====== MAIN SCENE =========================================================
        // Put a border on the main window
        mainBorder(mainWin);
	// Refresh the main window
        wrefresh(mainWin);

        // Chimney House #1
        printAsset(mainWin, 3, 63, 1);
        printAsset(mainWin, 6, 61, 5);
	// Refresh main window
        wrefresh(mainWin);
        //============================

	//Basic House #2
        printAsset(mainWin, 4, 1, 24);
        printAsset(mainWin, 6, 15, 27);
	// Refresh main window
        wrefresh(mainWin);
        //=============================
	
	// Campfire/Tent Area
        printAsset(mainWin, 7,72, 25);
        printAsset(mainWin, 9, 68, 20);
        printAsset(mainWin, 9, 60, 24);
	// Refresh main window
        wrefresh(mainWin);
	//==============================        

	// Forrest Area
        printAsset(mainWin, 1, 2, 1);
	// Refresh main window
        wrefresh(mainWin);
	//============================
	
        // Lake Area
        printAsset(mainWin, 8, 33, 10);
	// Refresh main window
        wrefresh(mainWin);
	//=============================
	
	// If the version is set to 1
	if(version == 1){
		// Print the car
		printAsset(mainWin, 12, 57, 12);
	}
        //===========================================================================
}
//------ PRINT_FOREST_LEVEL ----------------------------------------------------------------------------
void printForestLevel(WINDOW *mainWin, int version){
	// Put a border on the main window
	mainBorder(mainWin);
	
	// Print grass
	printAsset(mainWin, 10, 50, 20);
	printAsset(mainWin, 10, 30, 7);
	printAsset(mainWin, 10, 65, 2);
	//=============================
	
	// Print trees
	printAsset(mainWin, 1, 60, 10);
	printAsset(mainWin, 1, 5, 22);
	printAsset(mainWin, 1, 5, 1);
	//==============================
	
	// Print lake
	printAsset(mainWin, 8, 18, 16);
	//=============================
	
	// Print EXIT
	printAsset(mainWin, 11, 2, 14); 
	//==============================
	
	// If version is set to 1
	if(version == 1){
		// Turn on yellow
		wattron(mainWin, COLOR_PAIR(5));	
		mvwprintw(mainWin, 25, 68, "!");
		// Turn off yellow
		wattroff(mainWin, COLOR_PAIR(5));
	}
	// Else
	else{
		mvwprintw(mainWin, 25, 68, "!");
	}
	// Return
	return;
}
//------ PRINT_HOUSE_LEVEL ----------------------------------------------------------------------------
void printHouseLevel(WINDOW *mainWin, int version){
	// Put border on main window
        mainBorder(mainWin);
	// Print EXIT 
        printAsset(mainWin, 11 ,2, 14);
	//====== ROOMS =============================
	wmove(mainWin, 6, 1);
	whline(mainWin, '-', 13);
	wmove(mainWin, 5, 14);
	wvline(mainWin, '|', 2);
	wmove(mainWin, 1, 14);
	wvline(mainWin, '|', 1);
	wmove(mainWin, 1, 57);
	wvline(mainWin, '|', 10);
	wmove(mainWin, 11, 76);
	whline(mainWin, '-', 3);
	wmove(mainWin, 11, 57);
	whline(mainWin, '-', 4);
	wmove(mainWin, 20, 1);
	whline(mainWin, '-', 8);
	wmove(mainWin, 20, 14);
	whline(mainWin, '-', 5);
	wmove(mainWin, 20, 19);
	wvline(mainWin, '|', 9);
	wmove(mainWin, 20, 19);
	whline(mainWin, '-', 10);
	wmove(mainWin, 20, 35);
	whline(mainWin, '-', 20);
	wmove(mainWin, 20, 55);
	wvline(mainWin, '|', 9);
	wmove(mainWin, 20, 55);
	whline(mainWin, '-', 15);
	//=========================================

	// If version is set to 1
        if(version == 1){
		// Turn yellow on
                wattron(mainWin, COLOR_PAIR(5));
                mvwprintw(mainWin, 3, 73, "!");
		// Turn yellow off
                wattroff(mainWin, COLOR_PAIR(5));
        }
	// Else
        else{
                mvwprintw(mainWin, 3, 73, "!");
        }
	// Return
        return;
}
//------ PRINT_CHOUSE_LEVEL ------------------------------
void printCHouseLevel(WINDOW *mainWin, int version){
	// Put a border on the main window
        mainBorder(mainWin);
	// Print EXIT 
        printAsset(mainWin, 11 ,2, 14);
	//====== ROOMS ==================================
	wmove(mainWin, 1, 26);
	wvline(mainWin, '|', 10);
	wmove(mainWin, 10, 1);
	whline(mainWin, '-', 10);
	wmove(mainWin, 10, 16);
	whline(mainWin, '-', 21);
	wmove(mainWin, 1, 52);
	wvline(mainWin, '|', 10);
	wmove(mainWin, 10, 42);
	whline(mainWin, '-', 21);
	wmove(mainWin, 10, 68);
	whline(mainWin, '-', 11);
	wmove(mainWin, 19, 26);
	wvline(mainWin, '|', 10);
	wmove(mainWin, 19, 52);
	wvline(mainWin, '|', 10);
	wmove(mainWin, 19, 1);
	whline(mainWin, '-', 10);
	wmove(mainWin, 19, 16);
	whline(mainWin, '-', 21);
	wmove(mainWin, 19, 42);
	whline(mainWin, '-', 21);
	wmove(mainWin, 19, 68);
	whline(mainWin, '-', 11);
	// Print firepit
	printAsset(mainWin, 7, 75, 14);
	wmove(mainWin, 17, 75);
	whline(mainWin, '-', 3);
	wmove(mainWin, 13, 75);
	whline(mainWin, '-', 3);
	//================================================
	
	// If version is set to 1
	if(version == 1){
		// Turn yellow on
                wattron(mainWin, COLOR_PAIR(5));
                mvwprintw(mainWin, 15, 40, "!");
		// Turn yellow off
                wattroff(mainWin, COLOR_PAIR(5));
        }
	// Else
        else{
                mvwprintw(mainWin, 15, 40, "!");
        }
	// Return
        return;
}
//------ PRINT_TENT_LEVEL ------------------------------
void printTentLevel(WINDOW *mainWin, int version){
        // Put a border on the main window
        mainBorder(mainWin);
        // Print EXIT
        printAsset(mainWin, 11 ,2, 14);
        // Print firepit
        printAsset(mainWin, 7, 39, 14);
        // Print tents
        printAsset(mainWin, 9, 5, 4);
        printAsset(mainWin, 9, 68, 4);
        printAsset(mainWin, 9, 65, 25);
        //=============================

        // Print Grass
        printAsset(mainWin, 10, 10, 20);
        printAsset(mainWin, 10, 35, 7);
        printAsset(mainWin, 10, 60, 15);
        //==============================

        // Print Trees
        printAsset(mainWin, 1, 54, 1);
        printAsset(mainWin, 1, 13, 1);
        printAsset(mainWin, 1, 43, 20);
        //=============================

        // If version is set to 1
        if(version == 1){
                // Turn yellow on
                wattron(mainWin, COLOR_PAIR(5));
                mvwprintw(mainWin, 25, 3, "!");
                // Turn yellow off
                wattroff(mainWin, COLOR_PAIR(5));
        }
        // Else
        else{
                mvwprintw(mainWin, 25, 3, "!");
        }
        // Return
        return;
}
//------ PRINT_END_GAME -----------------------------------------------------------------------------------------------
void printEndGame(WINDOW *mainWin, Player *playerOne){
        // Place player off the screen
        placePlayer(mainWin, playerOne, 50, 50);
        // Print level version 0
        printLevelOneMain(mainWin, 0);
        //====== MOVE CAR ===========================
        printAsset(mainWin, 13, 57, 12);
        printAsset(mainWin, 12, 58, 12);
        // Sleep
        sleep(1);
        wrefresh(mainWin);
        printLevelOneMain(mainWin, 0);
        printAsset(mainWin, 13, 58, 12);
        printAsset(mainWin, 12, 62, 12);
        // Sleep
        sleep(1);
        wrefresh(mainWin);
        printLevelOneMain(mainWin, 0);
        printAsset(mainWin, 13, 62, 12);
        printAsset(mainWin, 12, 66, 12);
        // Sleep
        sleep(2);
        wrefresh(mainWin);
        printLevelOneMain(mainWin, 0);
        printAsset(mainWin, 13, 66, 12);
        mainBorder(mainWin);
        // Sleep
        sleep(1);
        //==============================================
        // Refresh the main window
        wrefresh(mainWin);
        // Erase the main window
        werase(mainWin);
        // Print level one complete
        printTitle(mainWin, 7, 15, 10);
        // Put a border on the main window
        mainBorder(mainWin);
        // Sleep for 5 seconds
        sleep(5);
        // Erase main window
	werase(mainWin);
        // Refresh main window
        wrefresh(mainWin);
        // Return
        return;
}
//------ ENTER_FOREST ----------------------------------------------------------------------------------
void enterForest(WINDOW *mainWin, Player *playerOne){
	// Bool variable forest set to the colision check for the forest section
        bool forest = forestCol(playerOne);
	// Int variable set to forest choice
	int forestChoice;
	// If forest colision is equal to true
        if(forest == true){
		// Set forest choice to the choice of the forest window
                forestChoice = forestWindow(mainWin);
		// If the user chooses YES
		if( forestChoice == 0){
			// Initilize the forest level
                	forestLevel(mainWin, playerOne);
		}
	}
	// Return
        return;
}
//------ FOREST_QUIZ -----------------------------------------------------------------------------------
void forestQuiz(WINDOW *mainWin, Player *playerOne){
	// Bool variable forest set to the colision check for the key in the forest
	bool forest = forestKeyCol(playerOne);
	// If forest key colision is equal to true
	if(forest == true){
		// Erase the main window 
		werase(mainWin);
		// Initialize the forest quiz 
		forestQuizWindow(mainWin, playerOne);
	}
	// Return
	return;
}
//------ ENTER_C_HOUSE ----------------------------------------------------------------------------------
void enterCHouse(WINDOW *mainWin, Player *playerOne){
	// Bool variable cHouse set to the colision check to enter the cHouse
        bool cHouse = cHouseCol(playerOne);
	// Int variable set to cHouseChoice
	int cHouseChoice;
	// If cHouse colision check is true
        if(cHouse == true){
		// Set cHouseChoice to the choice to enter the cHouse
                cHouseChoice = cHouseWindow(mainWin);
		// If the user answers YES to enter the cHouse
                if(cHouseChoice == 0){
			// Initialize the cHouse level
			cHouseLevel(mainWin, playerOne);
                        // Refresh the main window
                        wrefresh(mainWin);
                }
        }
	// Return
        return;
}
//------ C_HOUSE_QUIZ -----------------------------------------------------------------------------------
void cHouseQuiz(WINDOW *mainWin, Player *playerOne){
	// Bool variable cHouse set to the colision check for the key of the cHouse
        bool cHouse = cHouseKeyCol(playerOne);
	// If the key colision is true
        if(cHouse == true){
		// Erase the main window
                werase(mainWin);
		// Initialize the cHouse quiz
                cHouseQuizWindow(mainWin, playerOne);
        }
	// Return
        return;
}
//------ ENTER_HOUSE ----------------------------------------------------------------------------------
void enterHouse(WINDOW *mainWin, Player *playerOne){
	// Bool variable House set to the colision check for the House
        bool House = houseCol(playerOne);
	// If the House colision is true
        if(House == true){
		// Set int variable to the user's choice to enter the house level
                int HouseChoice = HouseWindow(mainWin);
		// If user answers YES
                if(HouseChoice != 1){
                        // Refresh main window
                        wrefresh(mainWin);
			// Inittialize the House level
			houseLevel(mainWin, playerOne);
                }
        }
	// Return
        return;
}
//------ HOUSE_QUIZ -----------------------------------------------------------------------------------
void houseQuiz(WINDOW *mainWin, Player *playerOne){
	// Bool variable House set to the colision check for the key of the House
        bool house = houseKeyCol(playerOne);
	// If the key colision is true
        if(house == true){
		// Erase the main window
                werase(mainWin);
		// Intialize the house quiz
                houseQuizWindow(mainWin, playerOne);
        }
	// Return
        return;
}
//------ ENTER_TENT ----------------------------------------------------------------------------------
void enterTent(WINDOW *mainWin, Player *playerOne){
	// Bool variable tent set to the colision check for the tent
        bool Tent = tentCol(playerOne);
	// If the tent colision is true
        if(Tent == true){
		// Set int variable tent choice to the user's choice to enter the tents
                int tentChoice = tentWindow(mainWin);
		// If the user wants to enter the tents
                if(tentChoice != 1){
                        // Initialize the tent level
			tentLevel(mainWin, playerOne);
			// Refresh the main window
                        wrefresh(mainWin);
                }
        }
	// Return
        return;
}
//------ TENT_QUIZ -----------------------------------------------------------------------------------
void tentQuiz(WINDOW *mainWin, Player *playerOne){
	// Bool variable tent set to the colision check for the tent key 
        bool tent = tentKeyCol(playerOne);
	// If the key colision is true
        if(tent == true){
		// Erase the main window
                werase(mainWin);
		// Initialize the tent quiz
                tentQuizWindow(mainWin, playerOne);
        }
	// Return
        return;
}
//------ FIN ----------------------------------------------------------------------------------
