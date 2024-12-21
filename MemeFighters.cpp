#include "MemeFighters.h"
#include <iostream>


MemeFrog::MemeFrog(const std::string name)
	:
	MemeFighter(name, 110, 18, 8),
	oldName(name)
{
	std::cout << GetName() << " enters the ring!\n";
}

std::string MemeFrog::GetOldName() const
{
	return oldName;
}

bool MemeFrog::SpecialAttack(MemeFighter& other)
{
	if (Roll() > 5 && !super)
	{
		name = "Super " + name;
		hp += 15;
		power += 5;
		speed += 3;
		super = true;
		std::cout << GetOldName() << " went Super mode!\n";
		return true;
	}
	return false;
}

void MemeFrog::Tick()
{
	if (super)
	{
		int damage = 3;
		hp -= damage;
		superTurns += 1;
		std::cout << GetName() << " lost " << damage << " hp from Super mode usage!\n";
	}

	if (superTurns == 3)
	{
		super = false;
		superTurns = 0;
		name = GetOldName();
		power -= 3;
		std::cout << GetOldName() << " is no longer in Super Mode, take this chance!\n";
	}

	MemeFighter::Tick();
}

MemeFrog::~MemeFrog()
{
	std::cout << "MemeFrog left the ring!\n";
}
	

MemeStoner::MemeStoner(const std::string name)
	:
	MemeFighter(name, 250, 12, 3)
{
	std::cout << GetName() << " enters the ring!\n";
}

bool MemeStoner::SpecialAttack(MemeFighter& other)
{
	if (Roll() > 4)
	{
		int damage = 20 + Roll(3);
		DealDamage(other, damage);
		std::cout << GetName() << " performed a Special Attack on " << other.GetName() << " dealing " << damage << " damage!\n";
		return true;
	}
	return false;
}

MemeStoner::~MemeStoner()
{
	std::cout << "MemeStoner left the ring!\n";
}
