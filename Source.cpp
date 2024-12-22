#include <conio.h>
#include <iostream>
#include "MemeFighters.h"
#include "Weapon.h"
#include <cstdlib>

void Fight(MemeFighter& f1, MemeFighter& f2)
{
	auto* p1 = &f1;
	auto* p2 = &f2;

	if (p1->GetInitiative() < p2->GetInitiative())
	{
		std::swap(p1, p2);
	}

	if (!p1->SpecialAttack(*p2))
	{
		p1->Attack(*p2);
	}
	if (!p2->SpecialAttack(*p1))
	{
		p2->Attack(*p1);
	}
}

int main()
{
	std::vector<MemeFighter*> team1 = {
		new MemeFrog("Dank Boi", new Bat),
		new MemeStoner("Illuminarti", new Fist),
		new MemeFrog("Scumbag Steve", new Knife)};

	std::vector<MemeFighter*> team2 = {
		new MemeFrog("Doritos", new Knife),
		new MemeStoner("Bloody Mary", new Knife),
		new MemeFrog("Donald Trump", new Fist)};

	std::cout << "\n=============== BATTLE START! ==================\n\n";

	auto alivePred = [](const MemeFighter* fighter) {return fighter->IsAlive();};

	while (
		std::any_of(team1.begin(), team1.end(), alivePred) &&
		std::any_of(team2.begin(), team2.end(), alivePred))
	{
		std::random_shuffle(team1.begin(), team1.end());
		std::partition(team1.begin(), team1.end(), alivePred);
		std::random_shuffle(team2.begin(), team2.end());
		std::partition(team2.begin(), team2.end(), alivePred);

		for (size_t i = 0; i < team1.size(); i++)
		{
			Fight(*team1[i], *team2[i]);
		}
		

		std::cout << "\n\n\n";
		
		for (size_t i = 0; i < team1.size(); i++)
		{
			team1[i]->Tick();
			team2[i]->Tick();
		}

		std::cout << "\n================================================\n\n";
		_getch();
		system("cls");
	}

	if (std::any_of(team1.begin(), team1.end(), alivePred))
	{
		std::cout << "Team 1 won!\n\n";
	}
	else
	{
		std::cout << "Team 2 won!\n\n";
	}

	for (int i = 0; i < team1.size(); i++)
	{
		delete team1[i];
		delete team2[i];
	}

	while (!_kbhit());
	return 0;
}