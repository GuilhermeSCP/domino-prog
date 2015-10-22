#include <iostream>
#include "Board.h"
#include "Player.h"
#include <vector>
#include <string>
#include "windows.h"

using namespace std;

Board::Board()
{
	players.clear();
}
Board::Board(vector<Player> players1)
{
	players=players1;
}


unsigned int Board::getPontos() const
{
	return 1;
}

unsigned int Board::getNumPlayers() const
{
	return players.size();
}

unsigned int Board::getNumBonesBoard() const
{
	return 1;
}

unsigned int Board::getPontosLeft() const
{	int pointleft= bonesLeft.at(bonesLeft.size()).getValor1();
	return pointleft;
}

unsigned int Board::getPontosRight() const
{	int pointright= bonesRight.at(bonesRight.size()).getValor2();
	return pointright;
}

unsigned int Board::getPontosAbove() const
{	int pointabove= bonesAbove.at(bonesAbove.size()).getValor1();
	return pointabove;
}

unsigned int Board::getPontosBelow() const
{	int pointbelow= bonesBelow.at(bonesBelow.size()).getValor2();
	return pointbelow;
}

unsigned int Board::getBonesLeftSize() const
{	unsigned int tam= bonesLeft.size();
	return tam;
}

unsigned int Board::getBonesRightSize() const
{	unsigned int tam= bonesRight.size();
	return tam;
}

unsigned int Board::getBonesAboveSize() const
{	unsigned int tam= bonesAbove.size();
	return tam;
}

unsigned int Board::getBonesBelowSize() const
{	unsigned int tam= bonesBelow.size();
	return tam;
}

vector <Bone> Board::getBonesLeft() const
{	return bonesLeft;
}

vector <Bone> Board::getBonesRight() const
{	return bonesRight;
}

vector <Bone> Board::getBonesAbove() const
{	return bonesAbove;
}

vector <Bone> Board::getBonesBelow() const
{	return bonesBelow;
}

vector <Bone> Board::getVectorFirstBone() const
{
	return firstBone;
}

Bone Board::getFirstBone()
{
	int indmaior, maior;
	maior = 0;
	vector <Bone> doublebones;
	vector <Bone> bigbone;
	for (int np=0; np<players.size(); np++)
	{
		for (int n=0; n<players.at(np).getBonesHand().size(); n++)
		{
			if (players.at(np).getBonesHand().at(n).getValor1()==players.at(np).getBonesHand().at(n).getValor2())
				doublebones.push_back(players.at(np).getBonesHand().at(n));
		}
	}
	for (int a=0; a<doublebones.size(); a++)
	{
		if (doublebones.at(a).getValor1()>maior)
		{
			maior = doublebones.at(a).getValor1();
			indmaior= a;
		}
		else
		{
			indmaior= a+1;
		}
	}
	if (doublebones.size()!=0)
	{
		for (int b=0; b<doublebones.size(); b++)
		{
			if (doublebones.at(b).getValor1()==maior)
			return doublebones.at(b);
		}
	}
	//---------
	else
	{
		maior = 0;
		indmaior = 0;
		for (int np=0; np<players.size(); np++)
		{
			for (int n=0; n<players.at(np).getBonesHand().size(); n++)
			{
				if ((players.at(np).getBonesHand().at(n).getValor1()+players.at(np).getBonesHand().at(n).getValor2())>maior)
				{
					maior=(players.at(np).getBonesHand().at(n).getValor1()+players.at(np).getBonesHand().at(n).getValor2());
					indmaior=np;
				}
			}
			bigbone.push_back(players.at(np).getBonesHand().at(indmaior));
		}
		maior=0;
		indmaior=0;
		for (int a=0; a<bigbone.size(); a++)
		{
			if ((bigbone.at(a).getValor1()+bigbone.at(a).getValor2())>maior)
			{
				maior = (bigbone.at(a).getValor1()+bigbone.at(a).getValor2());
				indmaior= a;
			}
		}
		return bigbone.at(indmaior);
	}
}

Player Board::getPlayerFirstBone()
{
	int np, i;
	for (np=0; np<players.size(); np++)
	{
		for (i=0; i<players.at(np).getBonesHand().size(); i++)
		{
			if (players.at(np).getBonesHand().at(i).getValor1()==getFirstBone().getValor1()
				&&
				players.at(np).getBonesHand().at(i).getValor2()==getFirstBone().getValor2())
			{
				return players.at(np);
			}

		}
	}
}

void Board::setBonesAbove(Bone bone)
{
	bonesAbove.push_back(bone);
}

void Board::setBonesBelow(Bone bone)
{
	bonesBelow.push_back(bone);
}

void Board::setBonesRight(Bone bone)
{	
	bonesRight.push_back(bone);
}

void Board::setBonesLeft(Bone bone)
{	bonesLeft.push_back(bone);

}

void Board::setVectorFirstBone(Bone bone)
{
	firstBone.push_back(bone);
}


void Board::setPlayersOrder()
{
	int ind;
	vector <Player> newvector;
	ind = 0;
	for (int np=0; np<players.size(); np++)
	{
		if (players.at(np).getName()==getPlayerFirstBone().getName())
		{ 
			ind = np;
		}
	}

	
	for(int a=0; a<players.size();a++)
	{
		if(players.at(a).getName()!=getPlayerFirstBone().getName())
			newvector.push_back(players.at(a));
	}
	newvector.push_back(players.at(ind));
	players=newvector;
}

void Board::fullScreen()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
        SMALL_RECT sr;
        COORD consoleSize;
	consoleSize.X = 170; consoleSize.Y = 62;

        sr.Top=sr.Left=0;
        sr.Right=166; sr.Bottom=59;

        SetConsoleWindowInfo(console, TRUE, &sr);
        SetConsoleScreenBufferSize(console, consoleSize);
}