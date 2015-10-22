#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include <string>
#include "Player.h"
#include "Bone.h"
#include "Boneyard.h"

using namespace std;

class Board{

private:

	vector <Bone> firstBone; //vector com a primeira peça a ser jogada
	vector <Bone> bonesAbove;
	vector <Bone> bonesBelow;
	vector <Bone> bonesLeft;
	vector <Bone> bonesRight;

public:

	Board();
	Board(vector<Player>);
	vector <Player> players;

	//get methods
	unsigned int getPontos() const;	
	unsigned int getNumPlayers() const;
	unsigned int getNumBonesBoard() const;
	unsigned int getPontosLeft() const;
	unsigned int getPontosRight() const;
	unsigned int getPontosAbove() const;
	unsigned int getPontosBelow() const;
	unsigned int getBonesLeftSize() const;
	unsigned int getBonesRightSize() const;
	unsigned int getBonesAboveSize() const;
	unsigned int getBonesBelowSize() const;
	vector <Bone> getBonesLeft() const;
	vector <Bone> getBonesRight() const;
	vector <Bone> getBonesAbove() const;
	vector <Bone> getBonesBelow() const;
	vector <Bone> getVectorFirstBone() const; //devolve o vector firstBone
	Bone getFirstBone();//indica a primeira peça a ser jogada
	Player getPlayerFirstBone();//indica o jogador que tem q jogar a primeira peça
	
	//set methods
	void setBonesAbove(Bone bone);
	void setBonesBelow(Bone bone);
	void setBonesRight(Bone bone);
	void setBonesLeft(Bone bone);
	void setVectorFirstBone(Bone bone);
	void setPlayersOrder();//altera a ordem dos jogadores no vector para definir a ordem de jogo
	
	void fullScreen(); 
};
#endif