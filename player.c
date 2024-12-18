// COMP 201 - ALEC - ORTIZ - 3114013 - X04L
//--------------------------------------------------------
/// @file player.c                                        |
/// @brief Main file to run player functions              |
/// @author Alec Ortiz                                    |
/// @date April 7th, 2024                                 |
//--------------------------------------------------------
//------ LIBRARIES --------------------------
#include "player.h"
#include "gameFunctions.h"
#include <ncurses.h>
#include <stdio.h>
#include <stdbool.h>
//-------------------------------------------

//------ CREATE_PLAYER ----------------------
Player createPlayer(WINDOW *mainWin, int x, int y){
	// Intilize player object type
	Player player;
	// Set main x coordinate to where user wants to place player
	player.pos_x = x;
	// Set main y coordinate to where user wants to place player
	player.pos_y = y;
	
	//====== HEAD ================
	// Set x and y for head
	player.head.pos_x = x;
	player.head.pos_y = y - 1;
	// Set head segment to O
	player.head.seg = 'O';
	//============================
	
	//====== RIGHT ARM ===========
	// Set x and y for right arm
	player.rArm.pos_x = x + 1;
	player.rArm.pos_y = y;
	// Set right arm segment to '\'
	player.rArm.seg = '\\';
	//============================
	
	//====== LEFT ARM ============
	// Set x and y for left arm
	player.lArm.pos_x = x - 1;
	player.lArm.pos_y = y;
	// Set left arm segment to /
	player.lArm.seg = '/';
	//=============================
	
	//====== BODY =================
	// Set x and y for the body
	player.body.pos_x = x;
	player.body.pos_y = y;
	// Set the body segment to |
	player.body.seg = '|';
	//=============================
	
	//====== RIGHT LEG ============
	// Set x and y for right leg
	player.rLeg.pos_x = x + 1;
	player.rLeg.pos_y = y + 1;
	// Set right leg segment to '\'
	player.rLeg.seg = '\\';
	//=============================
	
	//====== LEFT LEG =============
	// Set x and y for left leg
	player.lLeg.pos_x = x - 1;
	player.lLeg.pos_y = y + 1;
	// Set left leg segment to /
	player.lLeg.seg = '/';
	//=============================
	
	// Display the head
	mvwaddch(mainWin, player.head.pos_y, player.head.pos_x, player.head.seg);
	// Display the body
	mvwaddch(mainWin, player.body.pos_y, player.body.pos_x, player.body.seg);
	// Display the right arm
	mvwaddch(mainWin, player.rArm.pos_y, player.rArm.pos_x, player.rArm.seg);
	// Display the left arm
	mvwaddch(mainWin, player.lArm.pos_y, player.lArm.pos_x, player.lArm.seg);
	// Display the left leg
	mvwaddch(mainWin, player.lLeg.pos_y, player.lLeg.pos_x, player.lLeg.seg);
	// Display the right leg
	mvwaddch(mainWin, player.rLeg.pos_y, player.rLeg.pos_x, player.rLeg.seg);
	// Set Forest key to 0
	player.levelOneForestKey = 0;
	// Set Forest Encounter to 0
	player.forestEncounter = 0;	
	// Set House key to 0
	player.levelOneHouseKey = 0;
	// Set House Enctouner to 0
	player.houseEncounter = 0;
	// Set Chimney House key to 0
	player.levelOneCHouseKey = 0;
	// Set Chimney House Encounter to 0
	player.cHouseEncounter = 0;
	// Set Tents key to 0
	player.levelOneTentKey = 0;
	// Set TentsEncounter to 0
	player.tentEncounter = 0;	
	// Return player
	return player;
}
//------ PLAYER_RIGHT ---------------------------------------------------------------------
void playerRight(WINDOW *mainWin, Player *playerOne){
	//====== IF PLAYER AREA TO THE RIGHT IS CLEAR =======================================================
	// If the area to the right of the right arm, head, and right leg are clear (collision to the right) 
	if ( (mvwinch(mainWin, playerOne->rArm.pos_y, playerOne->rArm.pos_x + 1) == ' ') &&\
		       	(mvwinch(mainWin, playerOne->head.pos_y, playerOne->head.pos_x + 1) == ' ') &&\
		       	(mvwinch(mainWin, playerOne->rLeg.pos_y, playerOne->rLeg.pos_x + 1) == ' ')){
	//====================================================================================================
		
		//====== CLEAR PLAYER =============================================
		// Clear the head
		mvwaddch(mainWin, playerOne->head.pos_y, playerOne->head.pos_x, ' ');
		// Clear the body
		mvwaddch(mainWin, playerOne->body.pos_y, playerOne->body.pos_x, ' ');
		// Clear the right arm
		mvwaddch(mainWin, playerOne->rArm.pos_y, playerOne->rArm.pos_x, ' ');
		// Clear the left arm
		mvwaddch(mainWin, playerOne->lArm.pos_y, playerOne->lArm.pos_x, ' ');
		// Clear the right leg
		mvwaddch(mainWin, playerOne->rLeg.pos_y, playerOne->rLeg.pos_x, ' ');
		// Clear the left leg
		mvwaddch(mainWin, playerOne->lLeg.pos_y, playerOne->lLeg.pos_x, ' ');
		//=================================================================
		
		// Refresh the main window
		wrefresh(mainWin);
		
		//====== PLACE PLAYER =================================================================
		// Place the head to the right position
		mvwaddch(mainWin, playerOne->head.pos_y, playerOne->head.pos_x + 1, playerOne->head.seg);
		// Place the body to the right position
                mvwaddch(mainWin, playerOne->body.pos_y, playerOne->body.pos_x + 1, playerOne->body.seg);
		// PLace the right arm to the right position 
                mvwaddch(mainWin, playerOne->rArm.pos_y, playerOne->rArm.pos_x + 1, playerOne->rArm.seg);
		// Place the left arm to the right position
                mvwaddch(mainWin, playerOne->lArm.pos_y, playerOne->lArm.pos_x + 1, playerOne->lArm.seg);
		// Place the right leg to the right position
                mvwaddch(mainWin, playerOne->rLeg.pos_y, playerOne->rLeg.pos_x + 1, playerOne->rLeg.seg);
		// Place the left leg to the right position 
                mvwaddch(mainWin, playerOne->lLeg.pos_y, playerOne->lLeg.pos_x + 1, playerOne->lLeg.seg);
		// Refresh the main window
		wrefresh(mainWin); 
		// Increment the x position of the head segment 
		playerOne->head.pos_x += 1;
		// Increment the x position of the body segment 
		playerOne->body.pos_x +=1;
		// Increment the x position of the right arm segment 
		playerOne->rArm.pos_x +=1;
		// Increment the x position of the left arm segment 
		playerOne->lArm.pos_x +=1;
		// Increment the x position of the right leg segment 
		playerOne->rLeg.pos_x += 1;
		// Increment the x position of the left leg position
		playerOne->lLeg.pos_x +=1;
		// Increment the main position 
		playerOne->pos_x += 1;
		//===============================================================================================
	}
	// Return
	return;
}
//------ PLAYER_LEFT -------------------------------
void playerLeft(WINDOW *mainWin, Player *playerOne){
	//====== IF PLAYER AREA TO THE LEFT IS CLEAR =====================================================
        // If the area to the left of the left arm, head, and left leg are clear (collision to the left)
        if ( (mvwinch(mainWin, playerOne->lArm.pos_y, playerOne->lArm.pos_x - 1) == ' ') &&\
		       	(mvwinch(mainWin, playerOne->head.pos_y, playerOne->head.pos_x - 1) == ' ') &&\
		       	(mvwinch(mainWin, playerOne->lLeg.pos_y, playerOne->lLeg.pos_x - 1) == ' ')){
	//================================================================================================
                
		//====== CLEAR PLAYER =================================================
		// Clear the head 
		mvwaddch(mainWin, playerOne->head.pos_y, playerOne->head.pos_x, ' ');
		// Clear the body
                mvwaddch(mainWin, playerOne->body.pos_y, playerOne->body.pos_x, ' ');
		// Clear the right arm
                mvwaddch(mainWin, playerOne->rArm.pos_y, playerOne->rArm.pos_x, ' ');
		// Clear the left arm
                mvwaddch(mainWin, playerOne->lArm.pos_y, playerOne->lArm.pos_x, ' ');
		// Clear the right leg
                mvwaddch(mainWin, playerOne->rLeg.pos_y, playerOne->rLeg.pos_x, ' ');
		// Clear the left leg
                mvwaddch(mainWin, playerOne->lLeg.pos_y, playerOne->lLeg.pos_x, ' ');
		//===================================================================
                
		// Refresh the main window
		wrefresh(mainWin);

		//====== PLACE PLAYER =================================================================
		// Place the head to the left position 
                mvwaddch(mainWin, playerOne->head.pos_y, playerOne->head.pos_x - 1, playerOne->head.seg);
		// Place the body the to the left position 
                mvwaddch(mainWin, playerOne->body.pos_y, playerOne->body.pos_x - 1, playerOne->body.seg);
		// Place the right arm to the left poisiton 
                mvwaddch(mainWin, playerOne->rArm.pos_y, playerOne->rArm.pos_x - 1, playerOne->rArm.seg);
		// Place the left arm to the left position 
                mvwaddch(mainWin, playerOne->lArm.pos_y, playerOne->lArm.pos_x - 1, playerOne->lArm.seg);
		// Place the right leg to the left position 
                mvwaddch(mainWin, playerOne->rLeg.pos_y, playerOne->rLeg.pos_x - 1, playerOne->rLeg.seg);
		// Place the left leg to the left position 
                mvwaddch(mainWin, playerOne->lLeg.pos_y, playerOne->lLeg.pos_x - 1, playerOne->lLeg.seg);
		// Refresh the main window
                wrefresh(mainWin);
		// Decrement x position of head
                playerOne->head.pos_x -= 1;
		// Decrement x position of body
                playerOne->body.pos_x -=1;
		// Decrement x position of right arm
                playerOne->rArm.pos_x -=1;
		// Decrement x position of left arm
                playerOne->lArm.pos_x -=1;
		// Decrement x position of right leg
                playerOne->rLeg.pos_x -= 1;
		// Decrement the x position of the left leg
                playerOne->lLeg.pos_x -=1;
		// Decrement the main position
                playerOne->pos_x -= 1;
		//===========================================================================================
        }
	// Return
        return;
}
//------ PLAYER_UP ---------------------------------------------
void playerUp(WINDOW *mainWin, Player *playerOne){
	//====== IF PLAYER AREA UP IS CLEAR ================================================================
        // If the area up of the right arm, head, and left arm are clear (collision upwards)
        if ( (mvwinch(mainWin, playerOne->rArm.pos_y - 1, playerOne->rArm.pos_x) == ' ') &&\
		       	(mvwinch(mainWin, playerOne->head.pos_y - 1, playerOne->head.pos_x) == ' ') &&\
		       	(mvwinch(mainWin, playerOne->lArm.pos_y - 1, playerOne->lArm.pos_x) == ' ')){
	//==================================================================================================
                
		//====== CLEAR PLAYER =================================================
		// Clear the head
		mvwaddch(mainWin, playerOne->head.pos_y, playerOne->head.pos_x, ' ');
		// Clear the body
                mvwaddch(mainWin, playerOne->body.pos_y, playerOne->body.pos_x, ' ');
		// Clear the right arm
                mvwaddch(mainWin, playerOne->rArm.pos_y, playerOne->rArm.pos_x, ' ');
		// Clear the left arm
                mvwaddch(mainWin, playerOne->lArm.pos_y, playerOne->lArm.pos_x, ' ');
		// Clear the right leg
                mvwaddch(mainWin, playerOne->rLeg.pos_y, playerOne->rLeg.pos_x, ' ');
		// Clear the left leg
                mvwaddch(mainWin, playerOne->lLeg.pos_y, playerOne->lLeg.pos_x, ' ');
		//=====================================================================
                
		// Refresh the main window 
		wrefresh(mainWin);
                
		//====== PLACE PLAYER ==========================================================================
		// Place the head to the upwards position 
		mvwaddch(mainWin, playerOne->head.pos_y - 1, playerOne->head.pos_x, playerOne->head.seg);
		// Place the body to the upwards position 
                mvwaddch(mainWin, playerOne->body.pos_y - 1, playerOne->body.pos_x, playerOne->body.seg);
		// Place the right arm to the upwards position
                mvwaddch(mainWin, playerOne->rArm.pos_y - 1, playerOne->rArm.pos_x, playerOne->rArm.seg);
		// Place the left arm to the upwards position 
                mvwaddch(mainWin, playerOne->lArm.pos_y - 1, playerOne->lArm.pos_x, playerOne->lArm.seg);
		// Place the right leg to the upwards position 
                mvwaddch(mainWin, playerOne->rLeg.pos_y - 1, playerOne->rLeg.pos_x, playerOne->rLeg.seg);
		// Place the left leg to the upwards position 
                mvwaddch(mainWin, playerOne->lLeg.pos_y - 1, playerOne->lLeg.pos_x, playerOne->lLeg.seg);
		// Refresh the main window
                wrefresh(mainWin);
		// Decrement y position of head
                playerOne->head.pos_y -= 1;
		// Decrement y position of body
                playerOne->body.pos_y -=1;
		// Decrmeent y position of right arm
                playerOne->rArm.pos_y -=1;
		// Decrement y position of left arm 
                playerOne->lArm.pos_y -=1;
		// Decrement y position of right leg
                playerOne->rLeg.pos_y -= 1;
		// Decrement y position of left leg
                playerOne->lLeg.pos_y -=1;
		// Decrement main y position
                playerOne->pos_y -= 1;
		//===============================================================================================
        }
	// Return
        return;
}
//------ PLAYER_DOWN --------------------------
void playerDown(WINDOW *mainWin, Player *playerOne){
	//====== IF PLAYER AREA DOWN IS CLEAR ================================================================
        // If the area down of the right leg and left leg are clear (collision downwards)
        if ( (mvwinch(mainWin, playerOne->rLeg.pos_y + 1, playerOne->rLeg.pos_x) == ' ') &&\
		       	(mvwinch(mainWin, playerOne->lLeg.pos_y + 1, playerOne->lLeg.pos_x) == ' ')){
	//====================================================================================================
                
		//====== CLEAR PLAYER =================================================
		// Clear the head
		mvwaddch(mainWin, playerOne->head.pos_y, playerOne->head.pos_x, ' ');
		// Clear the body
                mvwaddch(mainWin, playerOne->body.pos_y, playerOne->body.pos_x, ' ');
		// Clear the right arm
                mvwaddch(mainWin, playerOne->rArm.pos_y, playerOne->rArm.pos_x, ' ');
		// Clear the left arm
                mvwaddch(mainWin, playerOne->lArm.pos_y, playerOne->lArm.pos_x, ' ');
		// Clear the right leg
                mvwaddch(mainWin, playerOne->rLeg.pos_y, playerOne->rLeg.pos_x, ' ');
		// Clear the left leg
                mvwaddch(mainWin, playerOne->lLeg.pos_y, playerOne->lLeg.pos_x, ' ');
		//=====================================================================
                
		// Refresh the main window
		wrefresh(mainWin);
                
		//====== PLACE PLAYER ======================================================================
		// Place the head to the downwards position
		mvwaddch(mainWin, playerOne->head.pos_y + 1, playerOne->head.pos_x, playerOne->head.seg);
		// Place the body to the downwards position
                mvwaddch(mainWin, playerOne->body.pos_y + 1, playerOne->body.pos_x, playerOne->body.seg);
		// Place the right arm to the downwards position
                mvwaddch(mainWin, playerOne->rArm.pos_y + 1, playerOne->rArm.pos_x, playerOne->rArm.seg);
		// Place the left arm to the downards position
                mvwaddch(mainWin, playerOne->lArm.pos_y + 1, playerOne->lArm.pos_x, playerOne->lArm.seg);
		// Place the right leg to the downwards position
                mvwaddch(mainWin, playerOne->rLeg.pos_y + 1, playerOne->rLeg.pos_x, playerOne->rLeg.seg);
		// Place the left leg to the downwards position
                mvwaddch(mainWin, playerOne->lLeg.pos_y + 1, playerOne->lLeg.pos_x, playerOne->lLeg.seg);
		// Refresh the main window
                wrefresh(mainWin);
		// Increment the y position of the head
                playerOne->head.pos_y += 1;
		// Increment the y position of the body
                playerOne->body.pos_y +=1;
		// Increment the y position of the right arm
                playerOne->rArm.pos_y +=1;
		// Increment the y position of the left arm
                playerOne->lArm.pos_y +=1;
		// Increment the y poistion of the right leg
                playerOne->rLeg.pos_y += 1;
		// Increment the y position of the left leg
                playerOne->lLeg.pos_y +=1;
		// Increment the main y position
                playerOne->pos_y += 1;
        }
	// Return
        return;
}
//------ PLACE_PLAYER --------------------------------------------------------
void placePlayer(WINDOW *mainWin, Player *playerOne, int x, int y){
	//====== CLEAR PLAYER =================================================
       	// Clear the head
      	mvwaddch(mainWin, playerOne->head.pos_y, playerOne->head.pos_x, ' ');
     	// Clear the body
    	mvwaddch(mainWin, playerOne->body.pos_y, playerOne->body.pos_x, ' ');
     	// Clear the right arm
    	mvwaddch(mainWin, playerOne->rArm.pos_y, playerOne->rArm.pos_x, ' ');
     	// Clear the left arm
       	mvwaddch(mainWin, playerOne->lArm.pos_y, playerOne->lArm.pos_x, ' ');
      	// Clear the right leg
      	mvwaddch(mainWin, playerOne->rLeg.pos_y, playerOne->rLeg.pos_x, ' ');
      	// Clear the left leg
    	mvwaddch(mainWin, playerOne->lLeg.pos_y, playerOne->lLeg.pos_x, ' ');
      	//=====================================================================

     	// Refresh the main window
       	wrefresh(mainWin);
	//====== PLACE PLAYER ======================================================================
      	// Place the head at new position
      	mvwaddch(mainWin, (y - 1), x, playerOne->head.seg);
      	// Place the body at the new position
       	mvwaddch(mainWin, y, x, playerOne->body.seg);
      	// Place the right arm at the new position
     	mvwaddch(mainWin, y, (x + 1), playerOne->rArm.seg);
     	// Place the left arm at the new position
      	mvwaddch(mainWin, y, (x - 1), playerOne->lArm.seg);
      	// Place the right leg at the new position
     	mvwaddch(mainWin, (y + 1), (x + 1), playerOne->rLeg.seg);
      	// Place the left leg at the new position
     	mvwaddch(mainWin, (y + 1), (x - 1), playerOne->lLeg.seg);
    	// Refresh the main window
       	wrefresh(mainWin);
     	// Set new position of the head
      	playerOne->head.pos_y = y - 1; playerOne->head.pos_x = x;
     	// Set new position of the body
    	playerOne->body.pos_y = y; playerOne->body.pos_x = x;
     	// Set new position of the right arm 
     	playerOne->rArm.pos_y = y; playerOne->rArm.pos_x = x + 1;
   	// Set new position of the left arm
     	playerOne->lArm.pos_y = y; playerOne->lArm.pos_x = x - 1;
      	// Set new position of the right leg
    	playerOne->rLeg.pos_y = y + 1; playerOne->rLeg.pos_x = x + 1;
      	// Set new position of the left leg
    	playerOne->lLeg.pos_y = y + 1; playerOne->lLeg.pos_x = x - 1;
       	// Set main position
      	playerOne->pos_y = y; playerOne->pos_x = x;
	// Return
	return;
}
//------ SET_PLAYER ----------------------------------------------------------
void setPlayer(Player *playerOne, int x, int y){
	// Set new position of the head
        playerOne->head.pos_y = y - 1; playerOne->head.pos_x = x;
        // Set new position of the body
        playerOne->body.pos_y = y; playerOne->body.pos_x = x;
        // Set new position of the right arm
        playerOne->rArm.pos_y = y; playerOne->rArm.pos_x = x + 1;
        // Set new position of the left arm
        playerOne->lArm.pos_y = y; playerOne->lArm.pos_x = x - 1;
        // Set new position of the right leg
        playerOne->rLeg.pos_y = y + 1; playerOne->rLeg.pos_x = x + 1;
        // Set new position of the left leg
        playerOne->lLeg.pos_y = y + 1; playerOne->lLeg.pos_x = x - 1;
        // Set new main position
        playerOne->pos_y = y; playerOne->pos_x = x;
	// Return
	return;
}
//------ FOREST_COL ----------------------------------------------------------
bool forestCol(Player *playerOne){
	// If player is within the forest's lower bounds
	if( (playerOne->pos_y == 8) && (playerOne->pos_x <= 13)){
		// Return true
		return true;
	}
	// If the player is within the forest's right bounds
	if( (playerOne->lArm.pos_y <= 7) && (playerOne->lArm.pos_x <= 13) ){
		// Return true
		return true;
	}
	// Return false
	return false;
}
//------ FOREST_KEY_COL ------------------------------------------------------
bool forestKeyCol(Player *playerOne){
	// If player is within the bounds of the forest key
	if( (playerOne->pos_y >= 23 ) && (playerOne->pos_x >= 66)){
		// Return true
                return true;
        }
	// Return false
        return false;
}
//------ C_HOUSE_COL ---------------------------------------------------------
bool cHouseCol(Player *playerOne){
	// If player is within the lower bounds of the Chimney House
	if( (playerOne->pos_y == 8) && (playerOne->pos_x >= 63)){
		// Return true
                return true;
        }
	// If the player is within the left bounds of the Chimney House
        if( (playerOne->rArm.pos_y <= 7) && (playerOne->rArm.pos_x >= 60) ){
		// Return true
                return true;
        }
	// Return false
        return false;
}
//------ HOUSE_COL ---------------------------------------------------------
bool houseCol(Player *playerOne){
	// If the player is within upper bounds of the house 
        if( (playerOne->pos_y == 22) && (playerOne->pos_x <= 16)){
		// Return true
                return true;
        }
	// If the player is within the right bounds of the house
        if( (playerOne->lArm.pos_y >= 24) && (playerOne->lArm.pos_x <= 18) ){
		// Return true
                return true;
        }
	// Return false
        return false;
}
//------ HOUSE_KEY_COL ------------------------------------------------------
bool houseKeyCol(Player *playerOne){
	// If player is within bounds of the house key
        if( (playerOne->pos_y >= 1 ) && (playerOne->pos_x >= 71)){
		// Return true
                return true;
        }
	// Return false
        return false;
}
//------ C_HOUSE_KEY_COL ------------------------------------------------------
bool cHouseKeyCol(Player *playerOne){
	// If player is within bounds of the chimney house key
        if( (playerOne->pos_y >= 13 ) && (playerOne->pos_x >= 38) && (playerOne->pos_y <= 16) && (playerOne->pos_x <= 42)){
		// Return true
                return true;
        }
	// Return false
        return false;
}
//------ TENT_COL ---------------------------------------------------------
bool tentCol(Player *playerOne){
	// If player is within the upper bounds of the tents
        if( (playerOne->pos_y == 18) && (playerOne->pos_x >= 60)){
		// Return true
                return true;
        }
	// If player is within the right bounds of the tents
        if( (playerOne->rArm.pos_y >= 20) && (playerOne->rArm.pos_x >= 59) ){
		// Return true
                return true;
        }
	// Return false
        return false;
}
//------ TENT_KEY_COL ------------------------------------------------------
bool tentKeyCol(Player *playerOne){
	// If player is within bounds of the tent key
        if( (playerOne->pos_y >= 24 ) && (playerOne->pos_x >= 1) && (playerOne->pos_y <= 26) && (playerOne->pos_x <= 5)){
		// Return true
                return true;
        }
	// Return false
        return false;
}
//------ EXIT_COL ---------------------------------------------------------
bool exitCol(Player *playerOne){
	// If player is within upper bounds of the EXIT
        if( (playerOne->pos_y >= 12) && (playerOne->pos_x == 4)){
		// Return true
                return true;
        }
	// If player is within lower bounds of the EXIT 
        if( (playerOne->pos_y <= 19) && (playerOne->pos_x == 4) ){
		// Return true
		return true;
	}
	// Return false
        return false;
}
//------ CAR_COL ---------------------------------------------------------
bool carCol(Player *playerOne){
	// If player is within bounds of the car
	if( (playerOne->pos_x >= 55) && (playerOne->pos_x <= 71) && (playerOne->pos_y >= 10) && (playerOne->pos_y <= 17) ){
		// Return true
		return true;
	}
	// Return false
        return false;
}
//------ FIN -----------------------------------------------------------------------------------
