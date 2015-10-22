#ifndef BONE_H
#define BONE_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Bone{

private:
	static unsigned int numBones;
	unsigned int ID;
	unsigned int valor1;
	unsigned int valor2;

public:
	//construtores
	Bone(unsigned int boneValor1, unsigned int boneValor2);


	//get methods
	unsigned int getID() const;
	unsigned int getValor1() const;
	unsigned int getValor2() const;

	//set methods
	void setID(unsigned int boneID);
	void setValor1(unsigned int boneValor1);
	void setValor2(unsigned int boneValor2);
	void setNumBones(unsigned int num);
	void Rolate();
};
#endif