#ifndef BONEYARD_H
#define BONEYARD_H

#include <iostream>
#include <vector>
#include <string>
#include "Bone.h"


using namespace std;

class Boneyard{

private:
	unsigned int numBones;
	vector <Bone> bones;

public:
	Boneyard();

	unsigned int getSizeBoneyard();
	vector <Bone> getBoneyard();
	Bone loseBone();
};
#endif