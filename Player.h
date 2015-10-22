#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "Bone.h"
#include <vector>
#include <string>

class Player{

private:
	static unsigned int numPlayers; //n�mero total de jogadores
	unsigned int ID; //ID do jogador
	string name; //nome do jogador
	vector <Bone> bonesHand; //as pe�as que o jogador possui

public:
	//construtores
	Player(string playerName);

	//get methods
	unsigned int getID() const;
	string getName() const;
	vector <Bone> getBonesHand() const;
	unsigned int getNumBonesHand() const;
	
	bool hasBonesHand() const;
	
	//set methods
	void setID(unsigned int playerID);
	void setName (string playerName);
	void setBonesHand (const vector <Bone> &bonesTakenByPlayer);

	void addBoneToHand (Bone); //tirar uma pe�a do monte
	void playBone(unsigned int BoneID); //colocar uma pe�a no tabuleiro
};
#endif