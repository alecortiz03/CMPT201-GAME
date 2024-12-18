//COMP 201 - ALEC - ORIZ - 3114013 - X04L
//--------------------------------------------------------
/// @file gameFunctions.h                                 |
/// @brief Main file to run main game functions           |
/// @author Alec Ortiz                                    |
/// @date April 7th, 2024                                 |
//--------------------------------------------------------
//------ LIBRARIES ---------------------------------------
#include <stdlib.h>
#include "player.h"
//------ INCLUSION GUARDS --------------------------------
#ifndef GAMEFUNCTIONS_H
#define GAMEFUNCTIONS_H


/// @brief Initializes the start menu to prompt the user to  START or QUIT the game
/// @param mainWin - WINDOW pointer to initialize start menu on
/// @return 0 if function returns correctly 
/// @note WINDOW pointer must be pointing to initialized WINDOW 
int startMenu(WINDOW *mainWin);


/// @brief Initializes colors
/// @param VOID
/// @return VOID
void colorPal(void);


/// @brief Creates a box border aronud a window
/// @param mainWin - WINDOW pointer passing WINDOW to print border onto
/// @return VOID 
/// @note WINDOW pointer must be pointing to initialized WINDOW 
void mainBorder(WINDOW *mainWin);


/// @brief Prints a specific Title from a list of titles
/// @param mainWin - WINDOW pointer passing WINDOW to print Title on
/// @param titleNum - Title number to be printed
/// @param x - x position to start Title print
/// @param y - y positino to start Title print
/// @return VOID
/// @note WINDOW pointer must be pointing to initialized WINDOW
/// @note Title number MUST be in the list of titles (can be updated)
/// @note x and y must be within screen size and account for title size
void printTitle(WINDOW *mainWin, int titleNum, int x, int y);


/// @brief Prints a specific asset from a list of assets
/// @param mainWin - WINDOW pointer passing WINDOW to print asset onto
/// @param asset - asset number to be printed
/// @param x - x position to start printing asset
/// @param y - y position to start printing asset
/// @return VOID
/// @note WINDOW pointer must be pointing to initialized WINDOW
/// @note Asset number MUST be in the list of assets (can be updated)
/// @note x and y must be within screen size and account for asset size
void printAsset(WINDOW *mainWIn, int asset, int x, int y);


/// @brief Creates a pause window
/// @param mainWin - WINDOW pointer passing WINDOW to pause window onto
/// @return VOID
/// @note WINDOW pointer must be pointing to initialized WINDOW
void pauseWindow(WINDOW *mainWin);


/// @brief Creates a window to ask the user if they want to enter the forest section 
/// @param mainWin - WINDOW pointer passing WINDOW to print forest window onto
/// @return 0 if the user chooses YES and 1 if the user chosoes NO 
/// @note WINDOW pointer must be pointing to initialized WINDOW
int forestWindow(WINDOW *mainWin);


/// @brief Creates The Forest quiz window to start The Forest quiz
/// @param mainWin - WINDOW pointer passing WINDOW to print quiz onto
/// @param playerOne - Player pointer passing the player used in game
/// @return 0 - 2 Depending on the user's answer
/// @note WINDOW pointer must be pointing to initialized WINDOW
/// @note Player pointer must be pointing to initialized Player
int forestQuizWindow(WINDOW *mainWin, Player *playerOne);


/// @brief Creates a window to ask the user if they want to enter the Chimney House section 
/// @param mainWin - WINDOW pointer passing WINDOW to print window onto
/// @return 0 if the user chooses YES and 1 if the user chooses NO
/// @note WINDOW pointer must be pointing to initialized WINDOW
int cHouseWindow(WINDOW *mainWin);


/// @brief Creates the Chimney House quiz window to start the Chimney House quiz
/// @param mainWin - WINDOW pointer passing WINDOW to print quiz onto
/// @param playerOne - Player pointer passing the player used in game
/// @return 0 - 2 Depending on the user's answer
/// @note WINDOW pointer must be pointing to initialized WINDOW
/// @note Player pointer must be pointing to initialized Player
int cHouseQuizWindow(WINDOW *mainWin, Player *playerOne);


/// @brief Creates a window to ask the user if they want to enter the House section
/// @param mainWin - WINDOW pointer passing WINDOW to print window onto
/// @return 0 if the user chooses YES and 1 if the user chooses NO
/// @note WINDOW pointer must be pointing to initialized WINDOW
int HouseWindow(WINDOW *mainWin);


/// @brief Creates the House quiz window to start the House quiz
/// @param mainWin - WINDOW pointer passing WINDOW to print quiz onto
/// @param playerOne - Player pointer passing the player used in game
/// @return 0 - 2 Depending on the user's answer
/// @note WINDOW pointer must be pointing to initialized WINDOW
/// @note Player pointer must be pointing to initialized Player
int houseQuizWindow(WINDOW *mainWin, Player *playerOne);


/// @brief Creates a window to ask the user if they want to enter the Tents section
/// @param mainWin - WINDOW pointer passing WINDOW to print window onto
/// @return 0 if the user chooses YES and 1 if the user chooses NO
/// @note WINDOW pointer must be pointing to initialized WINDOW
int tentWindow(WINDOW *mainWin);


/// @brief Creates the Tents quiz window to start the House quiz
/// @param mainWin - WINDOW pointer passing WINDOW to print quiz onto
/// @param playerOne - Player pointer passing the player used in game
/// @return 0 - 2 Depending on the user's answer
/// @note WINDOW pointer must be pointing to initialized WINDOW
/// @note Player pointer must be pointing to initialized Player
int tentQuizWindow(WINDOW *mainWin, Player *playerOne);


/// @brief Key/Instructions to remind the player how to play the game
/// @param playerOne - Player pointer passing the player used in game
/// @return VOID
/// @note Player pointer must be pointing to initialized Player
void inKey(Player *playerOne);
#endif /* GAMEFUNCTIONS_H */
