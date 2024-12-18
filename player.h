// COMP 201 - ALEC - ORTIZ - 3114013 - X04L
//--------------------------------------------------------
/// @file player.h                                        |
/// @brief Main file to hold all player functions         |
/// @author Alec Ortiz                                    |
/// @date April 7th, 2024                                 |
//--------------------------------------------------------
#include <ncurses.h>
#include <stdbool.h>
#ifndef PLAYER_H
#define PLAYER_H



/// @struct Part
/// @brief Structure to hold the player character's body Part
typedef struct{
	int pos_x; /**< x coordinate for body part */
	int pos_y; /**< y coordinate for body part */
	char seg; /**< Character representing body part */
}Part;



/// @struct Player
/// @brief Player structure to hold Player body Part structures, keys, and map encounters
typedef struct{
	//====== BODY PARTS ===============================
	int pos_x; /**< Main x coordinate for player */
	int pos_y; /**< Main y coordinate for player */
	Part head; /**< Part structure for head */
	Part rArm; /**< Part structure for the right arm */
	Part lArm; /**< Part structure for the left arm */
	Part body; /**< Part structure for the body */
	Part rLeg; /**< Part structure for the right leg */
	Part lLeg; /**< Part structure for the left leg */
	// ====== KEYS/ENCOUNTERS ==========================
	// The Forest
	int levelOneForestKey; /**< Key obtained from The Forest level */
	int forestEncounter; /**< Player encounter check for The Forest level */
	// The House
	int levelOneHouseKey; /**< Key obtained from The House level */
	int houseEncounter; /**< Player encounter check for The House level */
	// The Chimney House
	int levelOneCHouseKey; /**< Key obtained from The Chimney House level */
	int cHouseEncounter; /**< Player encounter check for The Chimney House level */
	// The Tents
	int levelOneTentKey; /**< Key obtained from The Tents level */
	int tentEncounter; /**< Player encounter check for The Tents level */
	//==================================================
}Player;



/// @brief Creates Player structure at position (x, y)
/// @param mainWin - WINDOW pointer pointing to window to place Player onto
/// @param x - x position to place Player onto
/// @param y - y posittoin to place Player onto
/// @retrun New created Player structure
/// @note Window pointer needs to be created and pointing to a window
/// @note x and y coordinates need to be within screen bounds
Player createPlayer(WINDOW *mainWin, int x, int y);


/// @brief Moves player right
/// @param mainWin - WINDOW pointer pointing to window to move Player on
/// @param playerOne - Player pointer pointing to player to be moved
/// @retrun VOID
/// @note Window pointer needs to be created and pointing to a window
/// @note Player pointer need to be created and pointing to a Player
void playerRight(WINDOW *mainWin, Player *playerOne);



/// @brief Moves player left
/// @param mainWin - WINDOW pointer pointing to window to move Player on
/// @param playerOne - Player pointer pointing to player to be moved
/// @retrun VOID
/// @note Window pointer needs to be created and pointing to a window
/// @note Player pointer need to be created and pointing to a Player
void playerLeft(WINDOW *mainWin, Player *playerOne);



/// @brief Moves player up
/// @param mainWin - WINDOW pointer pointing to window to move Player on
/// @param playerOne - Player pointer pointing to player to be moved
/// @retrun VOID
/// @note Window pointer needs to be created and pointing to a window
/// @note Player pointer need to be created and pointing to a Player
void playerUp(WINDOW *mainWin, Player *playerOne);



/// @brief Moves player down
/// @param mainWin - WINDOW pointer pointing to window to move Player on
/// @param playerOne - Player pointer pointing to player to be moved
/// @retrun VOID
/// @note Window pointer needs to be created and pointing to a window
/// @note Player pointer need to be created and pointing to a Player
void playerDown(WINDOW *mainWin, Player *playerOne);



/// @brief Sets and prints player in set (x, y) position
/// @param mainWin - WINDOW pointer pointing to window to place Player on
/// @param playerOne - Player pointer pointing to Player to be placed
/// @param x - x coordinate to place Player at
/// @param y - y coordinate to place Player at
/// @retrun VOID
/// @note Window pointer needs to be created and pointing to a window
/// @note Player pointer need to be created and pointing to a Player
void placePlayer(WINDOW *mainWin, Player *playerOne, int x, int y);



/// @brief Sets Player coordinates to (x, y) 
/// @param playerOne - Player pointer pointing to Player to set new x and y coorindates for
/// @param x - new x coordinate
/// @param y - new y coordinate
/// @retrun VOID
/// @note Player pointer need to be created and pointing to a Player
void setPlayer(Player *playerOne, int x, int y);



/// @brief Checks colision for Player in The Forest
/// @param playerOne - Player pointer pointing to Player to check colsion on
/// @retrun True if Player is within bounds, False all else
/// @note Player pointer need to be created and pointing to a Player
bool forestCol(Player *playerOne);



/// @brief Checks colision for The Forest Key and the Player
/// @param playerOne - Player pointer pointing to Player to check colsion on
/// @retrun True if Player is within bounds, False all else
/// @note Player pointer need to be created and pointing to a Player
bool forestKeyCol(Player *playerOne);



/// @brief Checks colision for Player in The Chimney House
/// @param playerOne - Player pointer pointing to Player to check colsion on
/// @retrun True if Player is within bounds, False all else
/// @note Player pointer need to be created and pointing to a Player
bool cHouseCol(Player *playerOne);



/// @brief Checks colision for the Player in The House
/// @param playerOne - Player pointer pointing to Player to check colsion on
/// @retrun True if Player is within bounds, False all else
/// @note Player pointer need to be created and pointing to a Player
bool houseCol(Player *playerOne);



/// @brief Checks colision for The House Key and the Player
/// @param playerOne - Player pointer pointing to Player to check colsion on
/// @retrun True if Player is within bounds, False all else
/// @note Player pointer need to be created and pointing to a Player
bool houseKeyCol(Player *playerOne);



/// @brief Checks colision for The Chimney House Key and the Player
/// @param playerOne - Player pointer pointing to Player to check colsion on
/// @retrun True if Player is within bounds, False all else
/// @note Player pointer need to be created and pointing to a Player
bool cHouseKeyCol(Player *playerOne);



/// @brief Checks colision for the Player in The Tents
/// @param playerOne - Player pointer pointing to Player to check colsion on
/// @retrun True if Player is within bounds, False all else
/// @note Player pointer need to be created and pointing to a Player
bool tentCol(Player *playerOne);



/// @brief Checks colision for The Tents Key and the Player
/// @param playerOne - Player pointer pointing to Player to check colsion on
/// @retrun True if Player is within bounds, False all else
/// @note Player pointer need to be created and pointing to a Player
bool tentKeyCol(Player *playerOne);



/// @brief Checks colision for the Player by the EXIT
/// @param playerOne - Player pointer pointing to Player to check colsion on
/// @retrun True if Player is within bounds, False all else
/// @note Player pointer need to be created and pointing to a Player
bool exitCol(Player *playerOne);



/// @brief Checks colision for the Player by the car
/// @param playerOne - Player pointer pointing to Player to check colsion on
/// @retrun True if Player is within bounds, False all else
/// @note Player pointer need to be created and pointing to a Player
bool carCol(Player *playerOne);
#endif /* PLAYER_H */ 
