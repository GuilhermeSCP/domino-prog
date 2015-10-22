#include <iostream>
#include "Player.h"
#include <vector>
#include <string>

using namespace std;

unsigned int Player::numPlayers=0;

Player::Player(string playerName)
{
	numPlayers++;
	ID=numPlayers;
	name=playerName;
}

unsigned int Player::getID() const
{
	return ID;
}

string Player::getName() const
{
	return name;
}

vector <Bone> Player::getBonesHand() const
{
	return bonesHand;
}

unsigned int Player::getNumBonesHand() const
{
	return bonesHand.size();
}

bool Player::hasBonesHand() const
{
	if (bonesHand.size() ==0)
		return false;
	else
		return true;
}

void Player::setID(unsigned int playerID)
{
	ID = playerID;
}

void Player::setName(string playerName)
{
	name= playerName;
}

void Player::setBonesHand(const vector <Bone> &bonesTakenByPlayer)
{
	bonesHand=bonesTakenByPlayer;
}

void Player::addBoneToHand(Bone peca)
{	
	bonesHand.push_back(peca);
}

void Player::playBone(unsigned int BoneID)
{
	for(int n=0; n<bonesHand.size(); n++)
	{if (bonesHand.at(n).getID()==BoneID)
		{
			bonesHand.erase(bonesHand.begin()+n);
		}
	}
}

