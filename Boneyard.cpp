#include <iostream>
#include "boneyard.h"
#include <ctime>
#include <vector>
#include <string>
using namespace std;

Boneyard::Boneyard()
{
	for (int i = 0; i <= 6 ; i++)
		for (int j = i; j <= 6; j++)
		{
			Bone bone (i,j);
			bones.push_back (bone);
		}
}

unsigned int Boneyard::getSizeBoneyard()
{
	return bones.size();
}

int randomBetween(int n1, int n2)
{
	int u;
	srand((unsigned) time(NULL));


	u= n1 + rand() % (n2 - n1 + 1);
	return u;
}
Bone Boneyard::loseBone()
{
	int n= bones.size();
	int rand = randomBetween(0, n-1);

	Bone peca = bones[rand];
	
	vector<Bone> vec; 
	for(int i=0; i<n; i++)
	{
		if (i != rand)
		{
			vec.push_back(bones[i]);
			
		}
	}
	bones=vec;
	numBones--;
	return peca;

}

vector <Bone> Boneyard::getBoneyard()
{
	return bones;
}