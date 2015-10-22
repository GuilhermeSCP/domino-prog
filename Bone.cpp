#include <iostream>
#include "Bone.h"
#include <string>
#include <vector>


unsigned int Bone::numBones=0;

Bone::Bone(unsigned int boneValor1, unsigned int boneValor2)
{
	numBones++;
	ID=numBones;
	valor1=boneValor1;
	valor2=boneValor2;	
}

unsigned int Bone::getID() const
{
	return ID;
}

unsigned int Bone::getValor1() const
{
	return valor1;
}

unsigned int Bone::getValor2() const
{
	return valor2;
}

void Bone::setID(unsigned int BoneID)
{
	ID = BoneID;
}

void Bone::setValor1(unsigned int boneValor1)
{
	valor1 = boneValor1;
}

void Bone::setValor2(unsigned int boneValor2)
{
	valor2 = boneValor2;
}

void Bone::setNumBones(unsigned int num)
{
	numBones=num;
}
void Bone::Rolate()
{
	int tmp;
	tmp=valor2;
	valor2=valor1;
	valor1=tmp;
}