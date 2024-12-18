// COMP 201 - ALEC - ORTIZ - X04L - 3114013
//--------------------------------------------------------
/// @file gameFunctions.c                                 |
/// @brief Main file to run main game functions           |
/// @author Alec Ortiz                                    |
/// @date April 7th, 2024                                 |
//-------------------------------------------------------- 
//------ LIBRARIES ---------------------------------------
#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#include <stdbool.h>
#include "gameFunctions.h"
#include "player.h"

//------ START_MENU ----------------------------------------------------------------
int startMenu(WINDOW *mainWin){
	// Initialize border
	mainBorder(mainWin);
	// Print Title - Campfire Escape
	printTitle(mainWin, 1, 20, 7);
	// Turn on red
	wattron(mainWin, COLOR_PAIR(3));
	mvwprintw(mainWin, 17, 31, "Enter if you dare!");
	// Turn off red
	wattroff(mainWin, COLOR_PAIR(3));
	// Set char variable choices, to two strings - START and QUIT 
        char choices[][6] = {"START", "QUIT"};
	// Set int variable highlight to 0
        int highlight = 0;
	// Set int variable index to 22
        int index = 22;
	// Set int variable readKey to equal 0
        int readKey = 0;
	// While the user has not pressed enter - User has not made a choice
        while(readKey != '\n'){
		// For int i is less than 2 - the amount of choices for the user
		for(int i = 0; i < 2; i++){
			// If i is euqal to highlight
                        if( i == highlight){
				// Turn on green backgroud and black foreground - Color pair 2
                                wattron(mainWin, COLOR_PAIR(2));
                        }
			// Print i of choices - print START and QUIT
                        mvwprintw(mainWin, 23, index, choices[i]);
			// Refresh the window
                        wrefresh(mainWin);
			// Turn off color pair 2
                        wattroff(mainWin, COLOR_PAIR(2));
			// Increment index by 30 so START and QUIT are spaced out
                        index += 30;
                }
		// Set the index back to 22
                index = 22;
		// Refresh the window
                wrefresh(mainWin);
		// Grab the users input and set it to readKey
                readKey = wgetch(mainWin);
		// If user presses the left key and they are not on START
                if( (readKey == KEY_LEFT) && (highlight != 0)){
			// Decrement highlight
                        highlight--;
                }
		// Else if the user presses the right key and they are not on QUIT
                else if( (readKey == KEY_RIGHT) && (highlight != 1)){
			// Increment highlight
                        highlight++;
                }
        }
	// Return the user's choice - Return highlight
	return highlight;
}
//------ COLOR_PAL ------------------------------------------------------------
void colorPal(void){
	// Intilize colors	
	start_color();
	// Initialize green
        init_pair(1, COLOR_GREEN, COLOR_BLACK);
	// Initialize the reverse of color green
        init_pair(2, COLOR_BLACK, COLOR_GREEN);
	// Initialize red
        init_pair(3, COLOR_RED, COLOR_BLACK);
	// Initialize blue
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	// Initilize yellow
	init_pair(5, COLOR_YELLOW, COLOR_BLACK);
	// Return
	return;
}
//------ MAIN_BOARDER ---------------------------------------------------------
void mainBorder(WINDOW *mainWin){
	// Set char variable x to - for horizontal border and y to | for vertical border
	char x = '-', y = '|';
	// Box the main window 
        box(mainWin, y, x);
	// Refresh main window
        wrefresh(mainWin);
	// Return
	return;
}
//------ PRINT TITLE ----------------------------------------------------------
void printTitle(WINDOW *mainWin, int titleNum, int x, int y){
	//====== SWITCH CASE ==============================================================================
	switch(titleNum){
		// Case 1 - Game Title - Campfire Escape
		case 1:
			// Turn on red
                        wattron(mainWin, COLOR_PAIR(3));
                        mvwprintw(mainWin, y, x, " ___   _   __  __ ___ ___ ___ ___ ___  ");
                        mvwprintw(mainWin, (1 + y), x, " / __| /_\\ |  \\/  | _ \\ __|_ _| _ \\ __|");
                        mvwprintw(mainWin, (2 + y), x, "| (__ / _ \\| |\\/| |  _/ _| | ||   / _| ");
                        mvwprintw(mainWin, (3 + y), x, " \\___/_/_\\_\\_|  |_|_| |_| |___|_|_\\___|");
                        mvwprintw(mainWin, (4 + y), x, "      | __/ __|/ __| /_\\ | _ \\ __|     ");
                        mvwprintw(mainWin, (5 + y), x, "      | _|\\__ \\ (__ / _ \\|  _/ _|      ");
                        mvwprintw(mainWin, (6 + y), x, "      |___|___/\\___/_/ \\_\\_| |___|     ");
			// Refresh main window
                        wrefresh(mainWin);
			// Turn off red
                        wattroff(mainWin, COLOR_PAIR(3));
			// Break
                        break;
		// Case 2 - Level One Title
		case 2:
			// Turn on red
			wattron(mainWin, COLOR_PAIR(3));
			mvwprintw(mainWin, y, x, " _    _____   _____ _    ");
        		mvwprintw(mainWin, (1 + y), x, "| |  | __\\ \\ / / __| |   ");
        		mvwprintw(mainWin, (2 + y), x, "| |__| _| \\ V /| _|| |__ ");
        		mvwprintw(mainWin, (3 + y), x, "|____|___| \\_/_|___|____|");
        		mvwprintw(mainWin, (4 + y), x, "     / _ \\| \\| | __|     ");
        		mvwprintw(mainWin, (5 + y), x, "    | (_) | .` | _|      ");
			mvwprintw(mainWin, (6 + y), x, "     \\___/|_|\\_|___|     ");
			// Refresh main window
        		wrefresh(mainWin);
			// Turn off red
			wattroff(mainWin, COLOR_PAIR(3));
			// Break
			break;
		// Case 3 - Game Title - The Forest
		case 3:
			// Turn on red
                        wattron(mainWin, COLOR_PAIR(3));
                        mvwprintw(mainWin, y, x, " _____ _   _ _____                 ");
                        mvwprintw(mainWin, (1 + y), x, "|_   _| | | | ____|                ");
                        mvwprintw(mainWin, (2 + y), x, "  | | | |_| |  _|                  ");
                        mvwprintw(mainWin, (3 + y), x, "  | | |  _  | |___                 ");
                        mvwprintw(mainWin, (4 + y), x, " _|_|_|_|_|_|_____|____ ____ _____ ");
                        mvwprintw(mainWin, (5 + y), x, "|  ___/ _ \\|  _ \\| ____/ ___|_   _|");
                        mvwprintw(mainWin, (6 + y), x, "| |_ | | | | |_) |  _| \\___ \\ | |  ");
			mvwprintw(mainWin, (7 + y), x, "|  _|| |_| |  _ <| |___ ___) || |  ");
			mvwprintw(mainWin, (8 + y), x, "|_|   \\___/|_| \\_\\_____|____/ |_|  ");
			// Refresh main window
                        wrefresh(mainWin);
			// Turn off red
                        wattroff(mainWin, COLOR_PAIR(3));
			// Break
                        break;
		// Case 4 - Game Title - The House
		case 4:
			// Turn on red
                        wattron(mainWin, COLOR_PAIR(3));
                        mvwprintw(mainWin, y, x, " _____ _   _ _____             ");
                        mvwprintw(mainWin, (1 + y), x, "|_   _| | | | ____|            ");
                        mvwprintw(mainWin, (2 + y), x, "  | | | |_| |  _|              ");
                        mvwprintw(mainWin, (3 + y), x, "  | | |  _  | |___             ");
                        mvwprintw(mainWin, (4 + y), x, " _|_|_|_|_|_|_____|____  _____ ");
                        mvwprintw(mainWin, (5 + y), x, "| | | |/ _ \\| | | / ___|| ____|");
                        mvwprintw(mainWin, (6 + y), x, "| |_| | | | | | | \\___ \\|  _|  ");
                        mvwprintw(mainWin, (7 + y), x, "|  _  | |_| | |_| |___) | |___ ");
                        mvwprintw(mainWin, (8 + y), x, "|_| |_|\\___/ \\___/|____/|_____|");
			// Refresh main window
                        wrefresh(mainWin);
			// Turn off red
                        wattroff(mainWin, COLOR_PAIR(3));
			// Break
                        break;
		// Case 5 - Game Title - The Chimney House
		case 5:
			// Turn on red
                        wattron(mainWin, COLOR_PAIR(3));
                        mvwprintw(mainWin, y, x, " _____ _   _ _____                      ");
                        mvwprintw(mainWin, (1 + y), x, "|_   _| | | | ____|                     ");
                        mvwprintw(mainWin, (2 + y), x, "  | | | |_| |  _|                       ");
                        mvwprintw(mainWin, (3 + y), x, "  | | |  _  | |___                      ");
                        mvwprintw(mainWin, (4 + y), x, "  |_|_|_| |_|_____|__ _   _ _______   __");
                        mvwprintw(mainWin, (5 + y), x, " / ___| | | (_)  \\/  | \\ | | ____\\ \\ / /");
                        mvwprintw(mainWin, (6 + y), x, "| |   | |_| | | |\\/| |  \\| |  _|  \\ V / ");
                        mvwprintw(mainWin, (7 + y), x, "| |___|  _  | | |  | | |\\  | |___  | |  ");
                        mvwprintw(mainWin, (8 + y), x, " \\____|_|_|_|_|_|_ |_|_| \\_|_____| |_|  ");
			mvwprintw(mainWin, (9 + y), x, "| | | |/ _ \\| | | / ___|| ____|         ");
                        mvwprintw(mainWin, (10 + y), x, "| |_| | | | | | | \\___ \\|  _|           ");
                        mvwprintw(mainWin, (11 + y), x, "|  _  | |_| | |_| |___) | |___          ");
                        mvwprintw(mainWin, (12 + y), x, "|_| |_|\\___/ \\___/|____/|_____|         ");
			// Refresh main window
                        wrefresh(mainWin);
			// Turn off red
                        wattroff(mainWin, COLOR_PAIR(3));
			// Break
                        break;
		// Case 6 - Game Title - The Tents 
		case 6:
			// Turn on red
                        wattron(mainWin, COLOR_PAIR(3));
                        mvwprintw(mainWin, y, x, " _____ _   _ _____             ");
                        mvwprintw(mainWin, (1 + y), x, "|_   _| | | | ____|            ");
                        mvwprintw(mainWin, (2 + y), x, "  | | | |_| |  _|              ");
                        mvwprintw(mainWin, (3 + y), x, "  | | |  _  | |___             ");
                        mvwprintw(mainWin, (4 + y), x, " _|_|_|_|_|_|_____|_____ ____  ");
                        mvwprintw(mainWin, (5 + y), x, "|_   _| ____| \\ | |_   _/ ___| ");
                        mvwprintw(mainWin, (6 + y), x, "  | | |  _| |  \\| | | | \\___ \\ ");
                        mvwprintw(mainWin, (7 + y), x, "  | | | |___| |\\  | | |  ___) |");
                        mvwprintw(mainWin, (8 + y), x, "  |_| |_____|_| \\_| |_| |____/ ");
			// Refresh main window
                        wrefresh(mainWin);
			// Turn off red
                        wattroff(mainWin, COLOR_PAIR(3));
			// Break
                        break;
		// Case 7 - Game Title - Level One Complete
		case 7:
			// Turn on green
                        wattron(mainWin, COLOR_PAIR(1));
                        mvwprintw(mainWin, y, x, " _     _______     _______ _        ___  _   _ _____ ");
                        mvwprintw(mainWin, (1 + y), x, "| |   | ____\\ \\   / / ____| |      / _ \\| \\ | | ____|");
                        mvwprintw(mainWin, (2 + y), x, "| |   |  _|  \\ \\ / /|  _| | |     | | | |  \\| |  _|  ");
                        mvwprintw(mainWin, (3 + y), x, "| |___| |___  \\ V / | |___| |___  | |_| | |\\  | |___ ");
                        mvwprintw(mainWin, (4 + y), x, "|_____|_____|_ \\_/ _|_____|_____|__\\___/|_|_\\_|_____|");
                        mvwprintw(mainWin, (5 + y), x, " / ___/ _ \\|  \\/  |  _ \\| |   | ____|_   _| ____|    ");
			mvwprintw(mainWin, (6 + y), x, "| |  | | | | |\\/| | |_) | |   |  _|   | | |  _|      ");
			mvwprintw(mainWin, (7 + y), x, "| |__| |_| | |  | |  __/| |___| |___  | | | |___     ");
			mvwprintw(mainWin, (8 + y), x, " \\____\\___/|_|  |_|_|   |_____|_____| |_| |_____|    ");
			// Refresh main window
                        wrefresh(mainWin);
			// Turn off green
                        wattroff(mainWin, COLOR_PAIR(1));
			// Break
                        break;
	}
	//======================================================================================================================
	// Return
	return;
}
//------ PRINT_ASSET ---------------------------------------------------------
void printAsset(WINDOW *mainWin, int asset, int x, int y){
	//====== SWITCH CASE ===============================================================================
	switch(asset){
		// Case 1 - Tree
		case 1:
			// Turn on green
			wattron(mainWin, COLOR_PAIR(1));
			mvwprintw(mainWin, y, x, "    ^^    ");
			mvwprintw(mainWin, (y + 1), x, "   ()()   ");
			mvwprintw(mainWin, (y + 2), x, "  (()())  ");
			mvwprintw(mainWin, (y + 3), x, " ((()())) ");
			mvwprintw(mainWin, (y + 4), x, "(((()())))");
			// Turn off green
			wattroff(mainWin, COLOR_PAIR(1));
			mvwprintw(mainWin, (y + 5), x, "   |  |   ");
			// Break
			break;
		// Case 3 - Chimney House Left
		case 3:

			mvwprintw(mainWin, y, x, "        ____   ");
                        mvwprintw(mainWin, (y + 1), x, "  ______|  |_  ");
                        mvwprintw(mainWin, (y + 2), x, " / ##   |  |/\\ ");
                        mvwprintw(mainWin, (y + 3), x, "/__________/__\\");
                        mvwprintw(mainWin, (y + 4), x, "|   ____## |  |");
                        mvwprintw(mainWin, (y + 5), x, "|___|__|___|__|");
			// Break
			break;
		// Case 4 - House Right
		case 4:
			mvwprintw(mainWin, y, x, "   _________  ");
                        mvwprintw(mainWin, (y + 1), x, " /\\         \\ ");
                        mvwprintw(mainWin, (y + 2), x, "/__\\_________\\");
                        mvwprintw(mainWin, (y + 3), x, "|  |##____## |");
                        mvwprintw(mainWin, (y + 4), x, "|__|__|__|___|");
			// Break
			break;
		// Case 6 - Bush
		case 6:
			// Turn on green
			wattron(mainWin, COLOR_PAIR(1));
			mvwprintw(mainWin, y, x, "##");
                        mvwprintw(mainWin, (y + 1), x, "##");
			// Turn off green
			wattroff(mainWin, COLOR_PAIR(1));
			// Break
			break;
		// Case 7 - Firepit
		case 7:
			// Turn on red
			wattron(mainWin, COLOR_PAIR(3));
			mvwprintw(mainWin, y, x, "  )");
                        mvwprintw(mainWin, (y + 1), x, " ( ");
			// Turn off red
			wattroff(mainWin, COLOR_PAIR(3));
                        mvwprintw(mainWin, (y + 2), x, "/|\\");
			// Break
			break;
		// Case 8 - Lake
		case 8:
			// Turn on blue
			wattron(mainWin, COLOR_PAIR(4));
			mvwprintw(mainWin, y, x, "      ~~~      ");
                        mvwprintw(mainWin, (y + 1), x, "  ~~~~~~~~~~~  ");
                        mvwprintw(mainWin, (y + 2), x, " ~~~~~~~~~~~~~ ");
                        mvwprintw(mainWin, (y + 3), x, "~~~~~~~~~~~~~~~");
                        mvwprintw(mainWin, (y + 4), x, "~~~~~~~~~~~~~~~");
                        mvwprintw(mainWin, (y + 5), x, " ~~~~~~~~~~~~~ ");
			mvwprintw(mainWin, (y + 6), x, "   ~~~~~~~~~   ");
                        mvwprintw(mainWin, (y + 7), x, "      ~~~      ");
			// Turn off blue
			wattroff(mainWin, COLOR_PAIR(4));
			// Break
			break;
		// Case 9 - Tent
		case 9:
			mvwprintw(mainWin, y, x, "   |   ");
                        mvwprintw(mainWin, (y + 1), x, "  /X\\  ");
                        mvwprintw(mainWin, (y + 2), x, "_/_|_\\_");
			// Break
			break;
		// Case 10 - Grass
		case 10:
			// Turn on green
			wattron(mainWin, COLOR_PAIR(1));
			mvwprintw(mainWin, y, x, "      ^^^");
                        mvwprintw(mainWin, (y + 1), x, "   ^^^^^^");
                        mvwprintw(mainWin, (y + 2), x, "^^^^^^^^^");
                        mvwprintw(mainWin, (y + 3), x, "^^^^^^^  ");
                        mvwprintw(mainWin, (y + 4), x, "    ^^^  ");
			// Turn off green
                        wattroff(mainWin, COLOR_PAIR(1));
			// Break
                        break;
		// Case 11 - EXIT 
		case 11:
			// Turn on red
			wattron(mainWin, COLOR_PAIR(3));
			mvwprintw(mainWin, y, x, "E");
			mvwprintw(mainWin, (y + 1), x, "X");
			mvwprintw(mainWin, (y + 2), x, "I");
			mvwprintw(mainWin, (y + 3), x, "T");
			// Turn off red
			wattroff(mainWin, COLOR_PAIR(3));
			// Break
			break;
		// Case 12 - Car
		case 12:
			// Turn on blue
                        wattron(mainWin, COLOR_PAIR(4));
                        mvwprintw(mainWin, y, x, "  ______     ");
                        mvwprintw(mainWin, (y + 1), x, " /|_||_\\`.__ ");
                        mvwprintw(mainWin, (y + 2), x, "(   _    _ _\\");
			// Turn off blue
			wattroff(mainWin, COLOR_PAIR(4));
                        mvwprintw(mainWin, (y + 3), x, "=`-(_)--(_)-'");
			// Break
                        break;
		// Case 13 - Empty Car
		case 13:
                        mvwprintw(mainWin, y, x, "	           ");
                        mvwprintw(mainWin, (y + 1), x, "	           ");
                        mvwprintw(mainWin, (y + 2), x, "	           ");
                        mvwprintw(mainWin, (y + 3), x, "	           ");
			// Break
                        break;
	}
	//================================================================================================================
	// Return
	return;
}
//------ PAUSE_WINDOW ---------------------------------------
void pauseWindow(WINDOW *mainWin){
	// Set int variable readKey to 0
	int readKey = 0;
	// Set char variables choices to RESUME and QUIT 
        char choices[][10] = {"RESUME", "QUIT"};
	// Set int variable highlight to 0
        int highlight = 0;
	// Create a window pointing to a new window - pause window
        WINDOW *pauseWin = newwin(10, 30, 9, 26);
	// Turn keypad on 
	keypad(pauseWin, true);
	// Refresh screen
        refresh();
	// Print pause title
	mvwprintw(pauseWin, 1, 13, "PAUSE\n"); 
	// Refresh pause window	
       	wrefresh(pauseWin);
	// Box pause window
      	box(pauseWin, '|', '-');
	// Refresh pause window
      	wrefresh(pauseWin);
	// Set int variable index to 4
	int index = 4;
	// While readKey is not equal to enter - While user has not made a choice
	while(readKey != '\n'){
		// For int i is less than 2 - For i is less than the choices
		for(int i = 0; i < 2; i++){
			// If i is equal to highlight
                        if( i == highlight){
				// Turn inverse of green on
                                wattron(pauseWin, COLOR_PAIR(2));
                        }
                        mvwprintw(pauseWin, 5, index, choices[i]);
			// Refresh the pause window
                        wrefresh(pauseWin);
			// Turn inverse of green off
                        wattroff(pauseWin, COLOR_PAIR(2));
			// Increment index by 18 - Correct spacing for choices
                        index += 18;
                }
		// Set index back to 4
                index = 4;
		// Refresh the pause window
                wrefresh(pauseWin);
		// Grab user's input
                readKey = wgetch(pauseWin);
		// If the user presses the left key and they are not on RESUME
                if( (readKey == KEY_LEFT) && (highlight != 0)){
			// Decrement highlight
                        highlight--;
                }
		// Else if user presses the right key and they are not on quit
                else if( (readKey == KEY_RIGHT) && (highlight != 1)){
			// Inrement highlight
                        highlight++;
	}
	}
	// If user made a choice and it was quit
	if((readKey == '\n') && (highlight == 1)){
		// Clear the screen
		clear();
		// Refresh the screen
		refresh();
		// Delete the pause window
		delwin(pauseWin);
		// End the Screen
		endwin();
		// Exit the program - SUCCESSFUL
		exit(0);
	}
	// Erase the pause window
	werase(pauseWin);
	// Refresh the pause window
	wrefresh(pauseWin);
	// Delete the pause window
	delwin(pauseWin);
	// Refresh the screen
	refresh();
	// Return
	return;
}
//------ FOREST_MENU ----------------------------------------------------------
int forestWindow(WINDOW *mainWin){
	// Set int variable readKey to 0
        int readKey = 0;
	// Set char variable choices to YES and NO
        char choices[][10] = {"YES", "NO"};
	// Set in variable highlight to 0
        int highlight = 0;
	// Create a new window pointer and set it to a new window termed forest window
        WINDOW *forestWin = newwin(10, 30, 9, 26);
	// Turn the keypad on
        keypad(forestWin, true);
	// Refresh the screen
        refresh();
        mvwprintw(forestWin, 1, 6, "DO YOU WANT TO ENTER\n");
	mvwprintw(forestWin, 2, 10 ,"THE FOREST?");
	// Refresh the forest window
        wrefresh(forestWin);
	// Box the forest window
        box(forestWin, '|', '-');
	// Refresh the forest window
        wrefresh(forestWin);
	// Set int variable index to 6
        int index = 6;
	// While readKey is not equal to enter - While the user has not made a choice
        while(readKey != '\n'){
		// For int i is less than 2 - For i is less than the amount of choices
                for(int i = 0; i < 2; i++){
			// If i is equal to highlight
                        if( i == highlight){
				// Turn on the inverse of green
                                wattron(forestWin, COLOR_PAIR(2));
                        }
                        mvwprintw(forestWin, 5, index, choices[i]);
			// Refresh the forest window
                        wrefresh(forestWin);
			// Turn off the inverse of green
                        wattroff(forestWin, COLOR_PAIR(2));
			// Increment the index by 16 - Correct spacing
                        index += 16;
                }
		// Set index back to 6
                index = 6;
		// Refresh the forest window
                wrefresh(forestWin);
		// Set readKey to the user's input - Grab the user's input
                readKey = wgetch(forestWin);
		// If the user presses the left key and they are not at YES
                if( (readKey == KEY_LEFT) && (highlight != 0)){
			// Decrement highlight
                        highlight--;
                }
		// Else if the usernpresses the right key and they are not at NO
                else if( (readKey == KEY_RIGHT) && (highlight != 1)){
			// Increment highlight
                        highlight++;
        }
        }
	// Erase the forest window
        werase(forestWin);
	// Refresh the forest window
        wrefresh(forestWin);
	// Delete the forest window
        delwin(forestWin);
	// Refresh the screen
        refresh();
	// Return user choice
        return highlight;
}
//------ FOREST_QUIZ_WINDOW ----------------------------------------------------
int forestQuizWindow(WINDOW *mainWin, Player *playerOne){
	// Set int variable readKey to 0
	int readKey = 0;
	// Set char variable choices to BELGIUM, PARIS, NEVERLAND
        char choices[][12] = {"- BELGIUM", "- PARIS", "- NEVERLAND"};
	// Set int variable highlight to 0 
        int highlight = 0;
	// Turn the keypad on
        keypad(mainWin, true);
	// Refresh the screen
        refresh();
        mvwprintw(mainWin, 3, 23, "WHAT IS THE CAPITAL OF FRANCE?\n");
	// Refresh the main window
        wrefresh(mainWin);
	// Box the main window
        box(mainWin, '|', '-');
	// Refresh the main window
        wrefresh(mainWin);
	// Set int variable index to 5
        int index = 5;
	// While readKey is not equal to enter - While user has not made a choice
        while(readKey != '\n'){
		// For int variable i is less than 3 - For i is less choices
                for(int i = 0; i < 3; i++){
			// If i is equal to highlight
                        if( i == highlight){
				// Turn on the inverse of green
                                wattron(mainWin, COLOR_PAIR(2));
                        }
                        mvwprintw(mainWin, index + i, 28, choices[i]);
			// Refresh the main window
                        wrefresh(mainWin);
			// Turn off the inverse of green
                        wattroff(mainWin, COLOR_PAIR(2));
                }
		// Set index back to 5
                index = 5;
		// Refresh the main window
                wrefresh(mainWin);
		// Set readKey to the user's input
                readKey = wgetch(mainWin);
		// If user presses the up key and they are not at the first choice 
                if((readKey == KEY_UP) && (highlight > 0)){
			// Decrement highlight
                        highlight--;
                }
		// Else if user presses the down key and they are not at the last choice
                else if( (readKey == KEY_DOWN) && (highlight < 2)){
			// Increment highlight
                        highlight++;
        }
        }
	// If user's choice is not equal to the second option
	if( highlight != 1 ){
			// Erase the main window
			werase(mainWin);
			// Refresh the main window
			wrefresh(mainWin);
			// Put a border around the main window
			mainBorder(mainWin);
			// Turn on red
			wattron(mainWin, COLOR_PAIR(3));
                        mvwprintw(mainWin, 15, 30, "SORRY WRONG ANSWER!!");
			// Turn off red
			wattroff(mainWin, COLOR_PAIR(3));
			// Refresh the main window
			wrefresh(mainWin);
			// Sleep for 2 seconds
			sleep(2);
                }
	// Else
	else{
		// Erase the main window
		werase(mainWin);
		// Refresh the main window
              	wrefresh(mainWin);
		// Put a border around the main window
             	mainBorder(mainWin);
		// Turn on green
            	wattron(mainWin, COLOR_PAIR(1));
             	mvwprintw(mainWin, 15, 30, "CORRECT ANSWER!!");
		// Turn off green
             	wattroff(mainWin, COLOR_PAIR(1));
		// Set forest key to 1 - User has the correct answer and can grab the key
		playerOne->levelOneForestKey = 1;
		// Refresh the main window
             	wrefresh(mainWin);
		// Sleep for 2 seonds
            	sleep(2);
	}
	// Erase the main window
        werase(mainWin);
	// Refresh the main window
        wrefresh(mainWin);
	// Refresh the screen
        refresh();
	// Return the user's choice
        return highlight;
}
//------ C_HOUSE_WINDOW ----------------------------------------------------------
int cHouseWindow(WINDOW *mainWin){
	// Set int variable readKey to 0
        int readKey = 0;
	// Set char varaible choices to YES and NO
        char choices[][10] = {"YES", "NO"};
	// Set int variable highlight to 0
        int highlight = 0;
	// Set new window pointer to a new window termed C house window
        WINDOW *cHouseWin = newwin(10, 30, 9, 26);
	// Turn the keypad on
        keypad(cHouseWin, true);
	// Refresh the screen
        refresh();
        mvwprintw(cHouseWin, 1, 6, "DO YOU WANT TO ENTER\n");
        mvwprintw(cHouseWin, 2, 6,"THE CHIMNEY HOUSE?");
	// Refresh the C house window
        wrefresh(cHouseWin);
	// Put a box around the C house window
        box(cHouseWin, '|', '-');
	// Refresh the C house window
        wrefresh(cHouseWin);
	// Set int variable index to 6
        int index = 6;
	// While readKey is not equal to enter - User has not made a choice
        while(readKey != '\n'){
		// For i is less than 2 - For i is less than choices
                for(int i = 0; i < 2; i++){
			// If i is equal to highlight
                        if( i == highlight){
				// Turn on the inverse of green
                                wattron(cHouseWin, COLOR_PAIR(2));
                        }
                        mvwprintw(cHouseWin, 5, index, choices[i]);
			// Refresh the C house window
                        wrefresh(cHouseWin);
			// Turn off the inverse of green
                        wattroff(cHouseWin, COLOR_PAIR(2));
			// Increment the index by 16 - Correct spacing
                        index += 16;
                }
		// Set index back to 6
                index = 6;
		// Refresh the C house window
                wrefresh(cHouseWin);
		// Set readKey to the user's choice
                readKey = wgetch(cHouseWin);
		// If the user presses the left keyand they are not at YES
                if( (readKey == KEY_LEFT) && (highlight != 0)){
			// Decrement highlight
                        highlight--;
                }
		// Else if user presses the right key and they are not at NO
                else if( (readKey == KEY_RIGHT) && (highlight != 1)){
			// Increment highlight
                        highlight++;
        }
        }
	// Erase C house window
        werase(cHouseWin);
	// Refresh C house window
        wrefresh(cHouseWin);
	// Delete C house window
        delwin(cHouseWin);
	// Refresh the main screen
        refresh();
	// Return the user's choice
        return highlight;
}
//------ C_HOUSE_QUIZ_WINDOW ---------------------------------------------------------------------------
int cHouseQuizWindow(WINDOW *mainWin, Player *playerOne){
	// Set int variable readKey to 0
        int readKey = 0;
	// Set char varaible choices to MARS, VENUS, and JUPITER
        char choices[][11] = {"- MARS", "- VENUS", "- JUPITER"};
	// Set int variable highlight to 0
        int highlight = 0;
	// Turn keypad on
        keypad(mainWin, true);
	// Refresh the screen
        refresh();
        mvwprintw(mainWin, 3, 23, "WHICH PLANET IS KNOWN AS THE RED PLANET?\n");
	// Refresh the main window
        wrefresh(mainWin);
	// Box the main window
        box(mainWin, '|', '-');
	// Refresh the main window
        wrefresh(mainWin);
	// Set int variable index to 5
        int index = 5;
	// While readKey is not equal to enter - While user has not made a choice
        while(readKey != '\n'){
		// For int variable i is less than 3 - For i is less than choices
                for(int i = 0; i < 3; i++){
			// If i is equal to highlight
                        if( i == highlight){
				// Turn on the inverse of green
                                wattron(mainWin, COLOR_PAIR(2));
                        }
                        mvwprintw(mainWin, index + i, 28, choices[i]);
			// Refresh main window
                        wrefresh(mainWin);
			// Turn off the inverse of green
                        wattroff(mainWin, COLOR_PAIR(2));
                }
		// Set index back to 5
                index = 5;
		// Refresh the main window
                wrefresh(mainWin);
		// Set readKey to the user's input
                readKey = wgetch(mainWin);
		// If user presses the up key and they are not at the first choice
                if( (readKey == KEY_UP) && (highlight > 0)){
			// Decrement highlight
                        highlight--;
                }
		// Else if user presses the down key and they are not at the last choice
                else if( (readKey == KEY_DOWN) && (highlight < 2)){
			// Increment highlight
                        highlight++;
        }
        }
	// If highlight is not equal to the first choice
        if( highlight != 0 ){
			// Erase the main window
                        werase(mainWin);
			// Refresh the main window
                        wrefresh(mainWin);
			// Put a border around the main window
                        mainBorder(mainWin);
			// Refresh the main window
                        wrefresh(mainWin);
			// Turn on red
                        wattron(mainWin, COLOR_PAIR(3));
                        mvwprintw(mainWin, 15, 30, "SORRY WRONG ANSWER!!");
			// Turn off red
                        wattroff(mainWin, COLOR_PAIR(3));
			// Refresh the main window
			wrefresh(mainWin);
			// Sleep for 2 seconds
                        sleep(2);
                }
	// Else
        else{
		// Erase the main window
                werase(mainWin);
		// Refresh the main window
                wrefresh(mainWin);
		// Put a border around the main window
                mainBorder(mainWin);
		// Turn on green
                wattron(mainWin, COLOR_PAIR(1));
                mvwprintw(mainWin, 15, 30, "CORRECT ANSWER!!");
		// Turn off green
                wattroff(mainWin, COLOR_PAIR(1));
		// Set C house key to 1 - User can grab the C house key
                playerOne->levelOneCHouseKey = 1;
		// Refresh the main window
                wrefresh(mainWin);
		// Sleep for 2 seconds
                sleep(2);
        }
	// Erase the main window
        werase(mainWin);
	// Refresh the main window
        wrefresh(mainWin);
	// Refresh the screen
        refresh();
	// Return the user's choice
        return highlight;
}
//------ HOUSE_WINDOW ----------------------------------------------------------
int HouseWindow(WINDOW *mainWin){
	// Set int variable readKey to 0
        int readKey = 0;
	// Set char variable choices to YES and NO
        char choices[][10] = {"YES", "NO"};
	// Set int variable highlight to 0
        int highlight = 0;
	// Create a new window pointer pointing to House window
        WINDOW *HouseWin = newwin(10, 30, 9, 26);
	// Turn the keypad on
        keypad(HouseWin, true);
	// Refresh the screen 
        refresh();
        mvwprintw(HouseWin, 1, 6, "DO YOU WANT TO ENTER\n");
        mvwprintw(HouseWin, 2, 10 ,"THE HOUSE?");
	// Refresh the House window
        wrefresh(HouseWin);
	// Box the House window
        box(HouseWin, '|', '-');
	// Refresh the House window
        wrefresh(HouseWin);
	// Set int variable index to 6 
        int index = 6;
	// While readKey is not equal to enter - While the user has not made a choice 
        while(readKey != '\n'){
		// For int variable i is less than 0 - For i is less than choices
                for(int i = 0; i < 2; i++){
			// If i is equal to highlight
                        if( i == highlight){
				// Turn on the inverse of green
                                wattron(HouseWin, COLOR_PAIR(2));
                        }
                        mvwprintw(HouseWin, 5, index, choices[i]);
			// Refresh the House window
                        wrefresh(HouseWin);
			// Turn off the inverse of green
                        wattroff(HouseWin, COLOR_PAIR(2));
			// Increment index by 16 - Correct spacing 
                        index += 16;
                }
		// Set index back to 6
                index = 6;
		// Refresh the House window
                wrefresh(HouseWin);
		// Set readKey to the user's input
                readKey = wgetch(HouseWin);
		// If the user presses the left key and they are not at YES
                if( (readKey == KEY_LEFT) && (highlight != 0)){
			// Decrement highlight
                        highlight--;
                }
		// Else if the user preses the right key and they are not at NO
                else if( (readKey == KEY_RIGHT) && (highlight != 1)){
			// Increment highlight
                        highlight++;
        }
        }
	// Erase the House window 
        werase(HouseWin);
	// Refresh the House window 
        wrefresh(HouseWin);
	// Delete the House window
        delwin(HouseWin);
	// Refresh the screen
        refresh();
	// Return the user's choice
	return highlight;
}
//------ HOUSE_QUIZ_WINDOW ----------------------------------------------------
int houseQuizWindow(WINDOW *mainWin, Player *playerOne){
	// Set int variable readKey to 0
        int readKey = 0;
	// Set char variable chioces to WATER, C02, and H20
        char choices[][8] = {"- WATER", "- C02", "- H20"};
	// Set int variable highlight to 0 
        int highlight = 0;
	// Turn keypad on
        keypad(mainWin, true);
	// Refresh the screen
        refresh();
        mvwprintw(mainWin, 3, 23, "WHAT IS THE CHEMICAL NAME FOR WATER?\n");
	// Refresh the main window
        wrefresh(mainWin);
	// Box the main window
        box(mainWin, '|', '-');
	// Refresh the main window
        wrefresh(mainWin);
	// Set int variable index to 5
        int index = 5;
	// While readKey it not equal to enter - While user has not made a choice 
        while(readKey != '\n'){
		// For int variable i is less than 3 - For i is less than choices
                for(int i = 0; i < 3; i++){
			// If i is equal to highlight
                        if( i == highlight){
				// Turn on the inverse of green
                                wattron(mainWin, COLOR_PAIR(2));
                        }
                        mvwprintw(mainWin, index + i, 28, choices[i]);
			// Refresh the main window 
                        wrefresh(mainWin);
			// Turn off the inverse of green
                        wattroff(mainWin, COLOR_PAIR(2));
                }
		// Set index back to 5
                index = 5;
		// Refresh the main window
                wrefresh(mainWin);
		// Set readKey to the user's choice
                readKey = wgetch(mainWin);
		// If user presses the up key and they are not at the first choice
                if( (readKey == KEY_UP) && (highlight > 0)){
			// Decrement highlight
                        highlight--;
                }
		// Else if user presses the down key and they are not at last choice
                else if( (readKey == KEY_DOWN) && (highlight < 2)){
			// Increment highlight
                        highlight++;

        }
        }
	// If highlight is not equal to the last choice
        if( highlight != 2 ){
			// Erase the main window
                        werase(mainWin);
			// Refresh the main window
                        wrefresh(mainWin);
			// Put a border around the main window 
                        mainBorder(mainWin);
			// Refresh the main window
			wrefresh(mainWin);
			// Turn on red
                        wattron(mainWin, COLOR_PAIR(3));
                        mvwprintw(mainWin, 15, 30, "SORRY WRONG ANSWER!!");
			// Turn off red
                        wattroff(mainWin, COLOR_PAIR(3));
			// Refresh the main window
                        wrefresh(mainWin);
			// Sleep for 2 seconds 
                        sleep(2);
                }
	// Else
        else{
		// Erase the main window 
                werase(mainWin);
		// Refresh the main window
                wrefresh(mainWin);
		// Put a border around the main window
                mainBorder(mainWin);
		// Turn on green
                wattron(mainWin, COLOR_PAIR(1));
                mvwprintw(mainWin, 15, 30, "CORRECT ANSWER!!");
		// Turn off green
                wattroff(mainWin, COLOR_PAIR(1));
		// Set House Key to 1 - User can grab House Key
                playerOne->levelOneHouseKey = 1;
		// Refresh the main window
                wrefresh(mainWin);
		// Sleep for 2 seconds 
                sleep(2);
        }
	// Erase the main window 
        werase(mainWin);
	// Refresh the main window
        wrefresh(mainWin);
	// Refresh the screen
        refresh();
	// Return the user's choice
        return highlight;
}
//------ TENT_WINDOW ----------------------------------------------------------
int tentWindow(WINDOW *mainWin){ 
	// Set int variable readKey to 0
        int readKey = 0;
	// Set char variable choices to YES and NO 
        char choices[][10] = {"YES", "NO"};
	// Set int variable highlight to 0
        int highlight = 0;
	// Create a new window pointer and set it to tent window 
        WINDOW *tentWin = newwin(10, 30, 9, 26);
	// Turn the keypad on 
        keypad(tentWin, true);
	// Refres the screen
        refresh();
        mvwprintw(tentWin, 1, 6, "DO YOU WANT TO ENTER\n");
        mvwprintw(tentWin, 2, 10 ,"THE TENTS?");
	// Refresh the tent window
        wrefresh(tentWin);
	// Box the tent window 
        box(tentWin, '|', '-');
	// Refresh the tent window
        wrefresh(tentWin);
	// Set int variable index to 6
        int index = 6;
	// While readKey is not equal to enter - While user has not made a choice
        while(readKey != '\n'){
		// For int variable i is less than 2 - For i is less than choices 
                for(int i = 0; i < 2; i++){
			// If i is equal to highlight
                        if( i == highlight){
				// Turn the inverse of green on
                                wattron(tentWin, COLOR_PAIR(2));
                        }
                        mvwprintw(tentWin, 5, index, choices[i]);
			// Refresh the tent window 
                        wrefresh(tentWin);
			// Turn off the inverse of green
                        wattroff(tentWin, COLOR_PAIR(2));
			// Increment index by 16 - Correct spacing 
                        index += 16;
                }
		// Set index back to 6
                index = 6;
		// Refresh the tent window 
                wrefresh(tentWin);
		// Set readKey to the user's choice
                readKey = wgetch(tentWin);
		// If the user presses the left key and they are not at YES
                if( (readKey == KEY_LEFT) && (highlight != 0)){
			// Decrement highlight
                        highlight--;
                }
		// Else if the user presses the righ tkey and they are not at NO
                else if( (readKey == KEY_RIGHT) && (highlight != 1)){
			// Increment highlight
                        highlight++;
        }
        }
	// Erase the tent window
        werase(tentWin);
	// Refresh the tent window
        wrefresh(tentWin);
	// Delete the tent window
        delwin(tentWin);
	// Refresh the screen
        refresh();
	// Return the user's choice
	return highlight;
}
//------ TENT_QUIZ_WINDOW -------------------------------------------------
int tentQuizWindow(WINDOW *mainWin, Player *playerOne){
	// Set int variable readKey to 0
        int readKey = 0;
	// Set char variable choices to ALDOUS HUXLEY, ERNEST HEMINGWAY, and GEORGE ORWELL
        char choices[][20] = {"- ALDOUS HUXLEY", "- ERNEST HEMINGWAY", "- GEORGE ORWELL"};
	// Set int variable highlight to 0
        int highlight = 0;
	// Turn keypad on
        keypad(mainWin, true);
	// Refresh the screen
        refresh();
        mvwprintw(mainWin, 3, 23, "WHO WROTE THE NOVEL '1984'?\n");
	// Refresh the main window 
        wrefresh(mainWin);
	// Box the main window
        box(mainWin, '|', '-');
	// Refresh the main window 
        wrefresh(mainWin);
	// Set int variable index to 5
        int index = 5;
	// While readKey is not equal to enter - While the user has not made a choice 
        while(readKey != '\n'){
		// For int variable i is less than 3 - For i is less than choices 
                for(int i = 0; i < 3; i++){
			// If i is equal to highlight
                        if( i == highlight){
				// Turn on the inverse of green
                                wattron(mainWin, COLOR_PAIR(2));
                        }
                        mvwprintw(mainWin, index + i, 28, choices[i]);
			// Refresh the main window 
                        wrefresh(mainWin);
			// Turn off the inverse of green
                        wattroff(mainWin, COLOR_PAIR(2));
                }
		// Set index to 5
                index = 5;
		// Refresh the main window 
                wrefresh(mainWin);
		// Set readKey to the user's input
                readKey = wgetch(mainWin);
		// If the user presses the up key and they are not at the first choice
                if( (readKey == KEY_UP) && (highlight > 0)){
			// Decrement highlight 
                        highlight--;
                }
		// Else if the user presses the down key and they are not at the last choice
                else if( (readKey == KEY_DOWN) && (highlight < 2)){
			// Increment highlight 
                        highlight++;
        }
        }
	// If highlight is not equal to the last choice 
        if( highlight != 2 ){
			// Erase the main window 
                        werase(mainWin);
			// Refresh the main window 
                        wrefresh(mainWin);
			// Put a border around the main window 
                        mainBorder(mainWin);
			// Refresh the main window 
                        wrefresh(mainWin);
			// Turn on red
                        wattron(mainWin, COLOR_PAIR(3));
                        mvwprintw(mainWin, 15, 30, "SORRY WRONG ANSWER!!");
			// Turn off red
                        wattroff(mainWin, COLOR_PAIR(3));
			// Refresh the main window 
			wrefresh(mainWin);
			// Sleep for 2 seconds 
                        sleep(2);
                }
	// Else 
        else{
		// Erase the main window 
                werase(mainWin);
		// Refresh the main window 
                wrefresh(mainWin);
		// Put a border around the main window 
                mainBorder(mainWin);
		// Turn on green
                wattron(mainWin, COLOR_PAIR(1));
                mvwprintw(mainWin, 15, 30, "CORRECT ANSWER!!");
		// Turn off green
                wattroff(mainWin, COLOR_PAIR(1));
		// Set tent key to 1 - User can grab the tent key
                playerOne->levelOneTentKey = 1;
		// Refresh the main window 
                wrefresh(mainWin);
		// Sleep for 2 seconds 
                sleep(2);
        }
	// Erase the main window 
        werase(mainWin);
	// Refresh the main window 
        wrefresh(mainWin);
	// Refresh the screen
        refresh();
	// Return the user's choice 
        return highlight;
}
//------ IN_KEY -----------------------------------------------------------
void inKey(Player *playerOne){
	// Print player reminder of controls
	mvwprintw(stdscr, 1, 81, "PLAYER KEY");
	mvwprintw(stdscr, 2, 81, "-----------");
	// Arrow keys - Move Player
	mvwprintw(stdscr, 3, 81, "Move player - Arrow Keys");
	// Interaction occur with e
	mvwprintw(stdscr, 4, 81, "Interact - 'e'");
	// Turn on yellow
	wattron(stdscr, COLOR_PAIR(5));
	mvwprintw(stdscr, 5, 81, "!");
	// Turn off yellow
	wattroff(stdscr, COLOR_PAIR(5));
	mvwprintw(stdscr, 5, 82, " - Interact with this to find the key!");
	// Forest key
	mvwprintw(stdscr, 6, 81, "Forest Key = %d", playerOne->levelOneForestKey);
	// House key
	mvwprintw(stdscr, 7, 81, "House Key = %d", playerOne->levelOneHouseKey);
	// Chimney House key
	mvwprintw(stdscr, 8, 81, "Chimney House Key = %d", playerOne->levelOneCHouseKey);
	// Tent key
	mvwprintw(stdscr, 9, 81, "Tent Key = %d", playerOne->levelOneTentKey);
	// Int variable set to the sum of the keys the player has
	int keySum = playerOne->levelOneForestKey + playerOne->levelOneHouseKey + playerOne->levelOneCHouseKey + playerOne->levelOneTentKey;
	// Int variable keys left set to 4 minus the sum of the keys
	int keysLeft = 4 - keySum;
	mvwprintw(stdscr, 10, 81, "Amout of keys left: %d", keysLeft);
	// Refresh the standard screen
	wrefresh(stdscr);
	// Return
	return;
}
//------ FIN --------------------------------------------------------------------------------------------------------
