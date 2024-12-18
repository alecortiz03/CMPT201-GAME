// COMP 201 - ALEC - ORTIZ - 3114013 - X04L
//--------------------------------------------------------
/// @file levels.h                                        |
/// @brief Main file to run main level functions          |
/// @author Alec Ortiz                                    |
/// @date April 7th, 2024                                 |
//--------------------------------------------------------
#include "player.h"
#ifndef LEVELS_H
#define LEVELS_H



/// @brief Starts the game's keypad and starts the start game sequence
/// @param mainWin - WINDOW pointer to pass window game is started on
/// @retrun 0 if the function returns correctly
/// @note Wdinow pointer needs to be created and pointing to a window
int gameStart(WINDOW *mainWindow);





/// @brief Starts the first level's sequence, allowing the player to move
/// @param mainWin - WINDOW pointer to window to start Level One on
/// @return 0 if the function returns correclty
/// @note WINDOW pointer must be pointing to initialized WINDOW
int levelOne(WINDOW *mainWin);





/// @brief Starts the Forest level's sequence, allowing the player to move
/// @param mainWin - WINDOW pointer to window to start The Forest Level on
/// @param playerOne - Player pointer to pass player onto The Forest level
/// @return VOID 
/// @note WINDOW pointer must be pointing to initialized WINDOW
/// @note Player pointer must be pointing to initialized Player
void forestLevel(WINDOW *mainWin, Player *playerOne);





/// @brief Starts the House level's sequence, allowing the player to move
/// @param mainWin - WINDOW pointer to start The House level on
/// @param playerOne - Player pointer to pass player onto The House level
/// @return VOID
/// @note WINDOW pointer must be pointing to initialized WINDOW
/// @note Player pointer must be pointing to initialized Player
void houseLevel(WINDOW *mainWin, Player *playerOne);





/// @brief Starts the Chimney House level's sequence, allowing the player to move
/// @param mainWin - WINDOW pointer to start The Chimney House level on
/// @param playerOne - Player pointer to pass player onto The Chimney House level
/// @return VOID
/// @note WINDOW pointer must be pointing to initialized WINDOW
/// @note Player pointer must be pointing to initialized Player
void cHouseLevel(WINDOW *mainWin, Player *playerOne);





/// @brief Starts the Tents level's sequence, allowing the player to move
/// @param mainWin - WINDOW pointer to start The Tents level on
/// @param playerOne - Player pointer to pass player onto The Tents level
/// @return VOID
/// @note WINDOW pointer must be pointing to initialized WINDOW
/// @note Player pointer must be pointing to initialized Player
void tentLevel(WINDOW *mainWin, Player *playerOne);
#endif /* LEVELS_H*/
