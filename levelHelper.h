// COMP 201 - ALEC - ORTIZ - 3114013 - X04L
//--------------------------------------------------------
/// @file levelHelper.h                                   |
/// @brief Main file to run helper functions for levels   |
/// @author Alec Ortiz                                    |
/// @date April 7th, 2024                                 |
//--------------------------------------------------------
#include "player.h"
#include <ncurses.h>
#ifndef LEVELHELPER_H
#define LEVELHELPER_H

/// @brief Prints the main instructions for user at the start
/// @param mainWin - WINDOW pointer to print instructions at the start
/// @return VOID
/// @note WINDOW pointer must be pointing to initialized WINDOW
void printIn(WINDOW *mainWin);


/// @brief Prints the first level
/// @param mainWin - WINDOW pointer to print the first level
/// @param Version - version number to be printed
/// @return VOID
/// @note WINDOW pointer must be pointing to initialized WINDOW
/// @note Version must be 0 or 1
void printLevelOneMain(WINDOW *mainWin, int version);



/// @brief Prints the Forest level
/// @param mainWin - WINDOW pointer to print the Forest level
/// @param Version - version number to be printed
/// @return VOID
/// @note WINDOW pointer must be pointing to initialized WINDOW
/// @note Version must be 0 or 1
void printForestLevel(WINDOW *mainWin, int version);


/// @brief Prints the House level
/// @param mainWin - WINDOW pointer to print the House level
/// @param Version - version number to be printed
/// @return VOID
/// @note WINDOW pointer must be pointing to initialized WINDOW
/// @note Version must be 0 or 1
void printHouseLevel(WINDOW *mainWin, int version);



/// @brief Prints the Chimney House level
/// @param mainWin - WINDOW pointer to print the Chimney House level
/// @param Version - version number to be printed
/// @return VOID
/// @note WINDOW pointer must be pointing to initialized WINDOW
/// @note Version must be 0 or 1
void printCHouseLevel(WINDOW *mainWin, int version);



/// @brief Prints the Tent level
/// @param mainWin - WINDOW pointer to print the Tent level
/// @param Version - version number to be printed
/// @return VOID
/// @note WINDOW pointer must be pointing to initialized WINDOW
/// @note Version must be 0 or 1
void printTentLevel(WINDOW *mainWin, int version);




/// @brief Prints the ending game sequence
/// @param mainWin - WINDOW pointer to print the ending level sequence
/// @param playerOne - Player pointer passing the player controlled by the user
/// @return VOID
/// @note WINDOW pointer must be pointing to initialized WINDOW
/// @note Player pointer must be pointing to initialized Player
void printEndGame(WINDOW *mainWin, Player *playerOne);




/// @brief Enables the enter forest sequence
/// @param mainWin - WINDOW pointer to enable enter forest sequence on
/// @param playerOne - Player pointer passing the player controlled by the user
/// @return VOID
/// @note WINDOW pointer must be pointing to initialized WINDOW
/// @note Player pointer must be pointing to initialized Player
void enterForest(WINDOW *mainWin, Player *playerOne);





/// @brief Creates the Forest Quiz
/// @param mainWin - WINDOW pointer to start the quiz on
/// @param playerOne - Player pointer passing the player controlled by the user
/// @return VOID
/// @note WINDOW pointer must be pointing to initialized WINDOW
/// @note Player pointer must be pointing to initialized Player
void forestQuiz(WINDOW *mainWin, Player *playerOne);





/// @brief Enables the enter cHouse sequence
/// @param mainWin - WINDOW pointer to enable enter cHouse sequence on
/// @param playerOne - Player pointer passing the player controlled by the user
/// @return VOID
/// @note WINDOW pointer must be pointing to initialized WINDOW
/// @note Player pointer must be pointing to initialized Player
void enterCHouse(WINDOW *mainWIn, Player *playerOne);





/// @brief Creates the cHouse Quiz
/// @param mainWin - WINDOW pointer to start the quiz on
/// @param playerOne - Player pointer passing the player controlled by the user
/// @return VOID
/// @note WINDOW pointer must be pointing to initialized WINDOW
/// @note Player pointer must be pointing to initialized Player
void cHouseQuiz(WINDOW *mainWin, Player *playerOne);





/// @brief Enables the enter House sequence
/// @param mainWin - WINDOW pointer to enable enter House sequence on
/// @param playerOne - Player pointer passing the player controlled by the user
/// @return VOID
/// @note WINDOW pointer must be pointing to initialized WINDOW
/// @note Player pointer must be pointing to initialized Player
void enterHouse(WINDOW *mainWin, Player *playerOne);





/// @brief Creates the House Quiz
/// @param mainWin - WINDOW pointer to start the quiz on
/// @param playerOne - Player pointer passing the player controlled by the user
/// @return VOID
/// @note WINDOW pointer must be pointing to initialized WINDOW
/// @note Player pointer must be pointing to initialized Player
void houseQuiz(WINDOW *mainWin, Player *playerOne);





/// @brief Enables the enter Tent sequence
/// @param mainWin - WINDOW pointer to enable enter Tent sequence on
/// @param playerOne - Player pointer passing the player controlled by the user
/// @return VOID
/// @note WINDOW pointer must be pointing to initialized WINDOW
/// @note Player pointer must be pointing to initialized Player
void enterTent(WINDOW *mainWin, Player *playerOne);





/// @brief Creates the Tent Quiz
/// @param mainWin - WINDOW pointer to start the quiz on
/// @param playerOne - Player pointer passing the player controlled by the user
/// @return VOID
/// @note WINDOW pointer must be pointing to initialized WINDOW
/// @note Player pointer must be pointing to initialized Player
void tentQuiz(WINDOW *mainWin, Player *playerOne);
#endif /* LEVELHELPER_H */
