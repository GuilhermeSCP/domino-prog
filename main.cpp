#include <iostream>

#include <string>
#include <vector>

#include "Bone.h"
#include "Player.h"
#include "Board.h"
#include "Boneyard.h"

using namespace std;


int main ()
{	
	Board tabuleiro;
	tabuleiro.fullScreen();
	int num;
	cout << "Bem-Vindo ao Jogo de Domino\n" << endl;
	cout << "Direitos Reservados por Daniel Teixeira e Luis Guilherme Martins\n" << endl;
	cout << "Recomenda-se a maximização da janela para um maior disfrutar do jogo...\n\n\n";
	cout << "\nQuantos jogadores vao jogar?\n";
	cin >> num;
	if (num>=5 || num<=1)
	{
		cout << "O numero de jogadores tem de ser entre 2 e 4" << endl;
		cout << "\nQuantos jogadores vao jogar?\n";
		cin >> num;
	for (int i=0; i<num ;i++)
	{
		string nome;
		cout << "\nQual o nome do jogador "<< i + 1 <<"?\n";
		cin >> nome;
		Player player1(nome);
		tabuleiro.players.push_back(player1);
	}}
	else
	{
		for (int i=0; i<num ;i++)
	{
		string nome;
		cout << "\nQual o nome do jogador "<< i + 1 <<"?\n";
		cin >> nome;
		Player player1(nome);
		tabuleiro.players.push_back(player1);
	}
	}
	
	Boneyard monte;
	

	for (int np=0;np<num; np++) //adiciona peças às mãos de todos os jogadores
	{for (int i=0;i<7;i++)
		{
			tabuleiro.players.at(np).addBoneToHand(monte.loseBone());
		}
	
	}

	cout << "VAMOS COMECAR!!!!!!!!\n";
	system("pause");
	system ("cls");
	cout << "||=================================================================||\n";
	cout << "||DOMINO - Direitos Reservados por Daniel Teixeira e Luis Guilherme||\n";
	cout << "||=================================================================||\n\n";
	cout << "||=========================||\n";
	cout << "||Existem ";
	cout.width(2);
	cout << left << monte.getSizeBoneyard();	
	cout << " pecas no monte"<< "||\n";
	cout << "||=========================||\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

	cout << "A primeira peca a ser jogada sera |" << tabuleiro.getFirstBone().getValor1() << "|" << tabuleiro.getFirstBone().getValor2() << "|\n";
	cout << "Como e o jogador " << tabuleiro.getPlayerFirstBone().getName() << " que tem a peca, sera ele o primeiro a jogar!\n";
	tabuleiro.setPlayersOrder();//altera a ordem do vector players de acordo com a ordem com que os jogadores jogam
	tabuleiro.setVectorFirstBone(tabuleiro.getFirstBone());
	
	for (int np=0; np<tabuleiro.players.size();np++) //Joga a primeira peça
	{
		if (tabuleiro.players.at(np).getName()==tabuleiro.getPlayerFirstBone().getName())
		{
			tabuleiro.players.at(np).playBone(tabuleiro.getFirstBone().getID());
		}
	}

	system ("pause");
	system ("cls");
	int op;
	for (int j=0; j<28 ; j++)//ciclo do jogo
	{
		int op, lado;
		for (int np=0; np<tabuleiro.players.size() ; np++)
		{
			//como a primeira peça já foi jogada esta condição impede q o primeiro jogador jogue outra vez
			if (j==0 && tabuleiro.players.at(np).getName()==tabuleiro.getPlayerFirstBone().getName())
			{
				system ("cls");
			}
			else
			{
			cout << "||=================================================================||\n";
			cout << "||DOMINO - Direitos Reservados por Daniel Teixeira e Luis Guilherme||\n";
			cout << "||=================================================================||\n\n";
			cout << "||=========================||\n";
			cout << "||Existem ";
			cout.width(2);
			cout << left << monte.getSizeBoneyard();
			cout << " pecas no monte"<< "||\n";
			cout << "||=========================||\n\n\n\n\n\n\n\n";
			
			//tabuleiro de jogo
			if (tabuleiro.getBonesRightSize()==0 && tabuleiro.getBonesLeftSize()==0)
			{
				cout << "-\n";
				cout << tabuleiro.getVectorFirstBone().at(0).getValor1();
				cout << endl;
				cout << "-\n";
				cout << tabuleiro.getVectorFirstBone().at(0).getValor2();
				cout << endl;
				cout << "-\n";
			}
			if (tabuleiro.getBonesLeftSize()==0 && tabuleiro.getBonesRightSize()!=0)
			{
				cout << "-\n";
				cout << tabuleiro.getVectorFirstBone().at(0).getValor1();
				cout << endl;
				cout << "-";
				cout << "(...)";
				cout << "|" ;
				cout << tabuleiro.getBonesRight().at(tabuleiro.getBonesRightSize()-1).getValor1();
				cout << "|";
				cout << tabuleiro.getBonesRight().at(tabuleiro.getBonesRightSize()-1).getValor2();
				cout << "|";
				cout << endl;
				cout << tabuleiro.getVectorFirstBone().at(0).getValor1();
				cout << endl;
				cout << "-\n";
			}
			if (tabuleiro.getBonesLeftSize()!=0 && tabuleiro.getBonesRightSize()==0)
			{
				cout << "          ";
				cout << "-\n";
				cout << "          ";
				cout << tabuleiro.getVectorFirstBone().at(0).getValor1();
				cout << endl;
				cout << "|" ;
				cout << tabuleiro.getBonesLeft().at(tabuleiro.getBonesLeftSize()-1).getValor1();
				cout << "|";
				cout << tabuleiro.getBonesLeft().at(tabuleiro.getBonesLeftSize()-1).getValor2();
				cout << "|";
				cout << "(...)";
				cout << "-";
				cout << endl;
				cout << "          ";
				cout << tabuleiro.getVectorFirstBone().at(0).getValor1();
				cout << endl;
				cout << "          ";
				cout << "-\n";
			}
			if (tabuleiro.getBonesLeftSize()!=0 && tabuleiro.getBonesRightSize()!=0)
			{
				cout << "          ";
				cout << "-\n";
				cout << "          ";
				cout << tabuleiro.getVectorFirstBone().at(0).getValor1();
				cout << endl;
				cout << "|" ;
				cout << tabuleiro.getBonesLeft().at(tabuleiro.getBonesLeftSize()-1).getValor1();
				cout << "|";
				cout << tabuleiro.getBonesLeft().at(tabuleiro.getBonesLeftSize()-1).getValor2();
				cout << "|";
				cout << "(...)";
				cout << "-";
				cout << "(...)";
				cout << "|" ;
				cout << tabuleiro.getBonesRight().at(tabuleiro.getBonesRightSize()-1).getValor1();
				cout << "|";
				cout << tabuleiro.getBonesRight().at(tabuleiro.getBonesRightSize()-1).getValor2();
				cout << "|";
				cout << endl;
				cout << "          ";
				cout << tabuleiro.getVectorFirstBone().at(0).getValor1();
				cout << endl;
				cout << "          ";
				cout << "-\n";
			}
			//tabuleiro de jogo

			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\nE a vez do " << tabuleiro.players.at(np).getName() << " jogar...\n";
			for (int n = 0; n<tabuleiro.players.at(np).getBonesHand().size(); n++)
			{
				cout << " (" << n << ")" << " |" << tabuleiro.players.at(np).getBonesHand().at(n).getValor1() << "|";
				cout << tabuleiro.players.at(np).getBonesHand().at(n).getValor2() << "|";
			}
			cout << " (30) Tirar peca do monte";
			cout << endl;
			cout << "Escolhe a tua peca:";
			cin >> op;
			if (op ==30)
			{
				tabuleiro.players.at(np).addBoneToHand(monte.loseBone());
			}
			else
			{
				cout << endl;
				cout << "Escolhe o lado:\n";
				cout << "1 - Direito\n";
				cout << "2 - Esquerdo\n";
				cout << "3 - Cima\n";
				cout << "4 - Baixo\n";
				cout << "\nLado: ";
				cin >> lado;
				{
					if (lado==1) //Joga peças à direita
					{
						if (tabuleiro.getBonesRightSize()==0)
						{
							if (tabuleiro.getVectorFirstBone().at(0).getValor2()!=tabuleiro.players.at(np).getBonesHand().at(op).getValor1()
							&&
							tabuleiro.getVectorFirstBone().at(0).getValor2()!=tabuleiro.players.at(np).getBonesHand().at(op).getValor2())
							{
								cout << "Não pode jogar essa peca...";
								np=np-1;
							}
							if (tabuleiro.getVectorFirstBone().at(0).getValor2()!=tabuleiro.players.at(np).getBonesHand().at(op).getValor1())
							{
								Bone peca=tabuleiro.players.at(np).getBonesHand().at(op);

								peca.Rolate();
								tabuleiro.setBonesRight(peca);

							}
							if (tabuleiro.getVectorFirstBone().at(0).getValor2()==tabuleiro.players.at(np).getBonesHand().at(op).getValor1())
							{
								tabuleiro.setBonesRight(tabuleiro.players.at(np).getBonesHand().at(op));
							}
						}
						else
						{
							if (tabuleiro.getBonesRight().at(tabuleiro.getBonesRightSize()-1).getValor2()!=tabuleiro.players.at(np).getBonesHand().at(op).getValor1()
								&&
								tabuleiro.getBonesRight().at(tabuleiro.getBonesRightSize()-1).getValor2()!=tabuleiro.players.at(np).getBonesHand().at(op).getValor2())
							{
								cout << "Não pode jogar essa peca...";
								np=np-1;
							}
							if (tabuleiro.getBonesRight().at(tabuleiro.getBonesRightSize()-1).getValor2()!=tabuleiro.players.at(np).getBonesHand().at(op).getValor1())
							{
								Bone peca=tabuleiro.players.at(np).getBonesHand().at(op);

								peca.Rolate();
								tabuleiro.setBonesRight(peca);
							}
							if (tabuleiro.getBonesRight().at(tabuleiro.getBonesRightSize()-1).getValor2()==tabuleiro.players.at(np).getBonesHand().at(op).getValor1())
							{
								tabuleiro.setBonesRight(tabuleiro.players.at(np).getBonesHand().at(op));
							}
						}
					}
					if (lado==2)//Joga peças à esquerda
					{
						if (tabuleiro.getBonesLeftSize()==0)
						{
							if (tabuleiro.getVectorFirstBone().at(0).getValor1()!=tabuleiro.players.at(np).getBonesHand().at(op).getValor2()
								&&
								tabuleiro.getVectorFirstBone().at(0).getValor1()!=tabuleiro.players.at(np).getBonesHand().at(op).getValor1())
							{
								cout << "Não pode jogar essa peca...";
								np = np-1;
							}
							if (tabuleiro.getVectorFirstBone().at(0).getValor1()!=tabuleiro.players.at(np).getBonesHand().at(op).getValor2())
							{
								Bone peca=tabuleiro.players.at(np).getBonesHand().at(op);

								peca.Rolate();
								tabuleiro.setBonesLeft(peca);
							}
							if (tabuleiro.getVectorFirstBone().at(0).getValor1()==tabuleiro.players.at(np).getBonesHand().at(op).getValor2())
							{
								tabuleiro.setBonesLeft(tabuleiro.players.at(np).getBonesHand().at(op));
							}
						}
						else
						{
							if (tabuleiro.getBonesLeft().at(tabuleiro.getBonesLeftSize()-1).getValor1()!=tabuleiro.players.at(np).getBonesHand().at(op).getValor2()
								&&
								tabuleiro.getBonesRight().at(tabuleiro.getBonesLeftSize()-1).getValor1()!=tabuleiro.players.at(np).getBonesHand().at(op).getValor1())
							{
								cout << "Não pode jogar essa peca...";
								np = np-1;
							}
							if (tabuleiro.getBonesLeft().at(tabuleiro.getBonesLeftSize()-1).getValor1()!=tabuleiro.players.at(np).getBonesHand().at(op).getValor2())
							{
								Bone peca=tabuleiro.players.at(np).getBonesHand().at(op);

								peca.Rolate();
								tabuleiro.setBonesLeft(peca);
							}
							if (tabuleiro.getBonesLeft().at(tabuleiro.getBonesLeftSize()-1).getValor1()==tabuleiro.players.at(np).getBonesHand().at(op).getValor2())
							{
								tabuleiro.setBonesLeft(tabuleiro.players.at(np).getBonesHand().at(op));
							}
						}
					}
					if (lado==3)//Joga peças em cima
					{
						tabuleiro.setBonesAbove(tabuleiro.players.at(np).getBonesHand().at(op));
					}
					if (lado==4)//Joga peças em baixo
					{
						tabuleiro.setBonesBelow(tabuleiro.players.at(np).getBonesHand().at(op));
					}
				}
				tabuleiro.players.at(np).playBone(tabuleiro.players.at(np).getBonesHand().at(op).getID());//retira a peça da mão do jogador
			}

			//termina o jogo quando um jogador fica sem peças e não há peças no monte
			if (tabuleiro.players.at(np).getBonesHand().size()==0 && monte.getSizeBoneyard()==0)
			{
				cout << "\nO jogador " << tabuleiro.players.at(np).getName() << "ficou sem pecas!\n";
				cout << "O jogo acabou!!!";
				system ("pause");
				system ("cls");
				cout << "FIM DO JOGO!!!!!!!!";
				return 0;
			}
			//quando um jogador fica sem peças e há peças no monte esta condição faz com que o jogador tira uma peça do monte
			if (tabuleiro.players.at(np).getBonesHand().size()==0 && monte.getSizeBoneyard()!=0)
			{
				tabuleiro.players.at(np).addBoneToHand(monte.loseBone());
				system ("cls");
			}

			else
			{
				system ("cls");
			}
		}
		}
	}	
	return 0;
}
