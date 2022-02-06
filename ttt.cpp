/**
 * @file ttt.cpp
 * @author Martin Czarnecki
 * @brief Simple Tic-Tac-Toe Game
 * @version 0.1
 * @date 2022-02-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>

void printGameRules(){
	std::cout << "-============== Tic-Tac-Toe ==============-" << std::endl;
	std::cout << "When it's your turn, enter the \n" 
				 "location of the box you want to \n" 
				 "select! \n";
	std::cout << "Valid Moves, with corresponding \n"
				 "squares: \n"
				 "1 2 3 \n"
				 "4 5 6 \n"
				 "7 8 9 \n";
	std::cout << "Game will end only if there is a \n"
				 "winner. \n";
}

int getValidMove(char game[3][3]){
	int userLocation;
	while(true){
		std::cout << "Enter Valid Loction: ";
		std::cin >> userLocation;
		if(1 <= userLocation && userLocation <= 9){
			if(userLocation > 6 && game[2][userLocation - 7] == '*')
				return userLocation;
			else if(userLocation > 3 && game[1][userLocation - 4] == '*')
				return userLocation;
			else if(game[0][userLocation - 1] == '*')
				return userLocation;
		}
	}
	return -1;
}

void printGame(char arr[3][3]){
	std::cout << "=================================\n";
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++)
			std::cout << arr[i][j] << " ";
		std::cout << '\n';
	}
}

bool isWinner(char game[3][3]){
	for(int i = 0; i < 3; i++){
		if(game[i][0] != '*' && game[i][0] == game[i][1] && game[i][0] == game[i][2])
			return true;
		if(game[0][i] != '*' && game[0][i] == game[1][i] && game[0][i] == game[2][i])
			return true;
	}
	if(game[0][0] != '*' && game[0][0] == game[1][1] && game[0][0] == game[2][2])
		return true;
	if(game[0][2] != '*' && game[0][2] == game[1][1] && game[0][2] == game[2][0])
		return true;

	return false;
}

int main(){
	bool isGameRunning = true;
	char player = 'X';
	int playerMove, 
		movesTracker = 0;

	char gameBoard[3][3] = {
		{'*', '*', '*'},
		{'*', '*', '*'},
		{'*', '*', '*'}
	};
	
	printGameRules();
	printGame(gameBoard);

	while(isGameRunning && movesTracker < 9){
		std::cout << "It is player " << player << "\'s turn. \n";
		playerMove = getValidMove(gameBoard);

		if(playerMove > 6)
			gameBoard[2][playerMove - 7] = player;
		else if(playerMove > 3)
			gameBoard[1][playerMove - 4] = player;
		else
			gameBoard[0][playerMove - 1] = player;

		printGame(gameBoard);
		if(isWinner(gameBoard)){
			isGameRunning = !isGameRunning;
			std::cout << "Player " << player << " has won.\n";
		}
		player = player == 'X' ? 'O' : 'X';
		movesTracker++;
	}
	if(!isWinner(gameBoard))
		std::cout << "Game Ended With a Tie.";
	std::cout << "=================================";
	return 0;
}	