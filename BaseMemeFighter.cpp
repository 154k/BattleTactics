#include "BaseMemeFighter.h"
#include <iostream>

MemeFighter::MemeFighter(const std::string& name, int hp, int power, int speed)
	:
	name(name),
	hp(hp),
	power(power),
	speed(speed){}

int MemeFighter::Roll(int n)
{
	return d6.Roll(n);
}

std::string MemeFighter::GetName() const
{
	return name;
}

int MemeFighter::GetInitiative()
{
	return speed * Roll(2);
}

void MemeFighter::Attack(MemeFighter& other)
{
	if (IsAlive() && other.IsAlive())
	{
		int damage = power + Roll(2);
		DealDamage(other, damage);
		std::cout << GetName() << " attacked " << other.GetName() << " and did " << damage << " damage!\n";
	}
}

void MemeFighter::DealDamage(MemeFighter& other, int damage) const
{
	other.hp -= damage;
}

bool MemeFighter::IsAlive() const
{
	return hp > 0;
}

void MemeFighter::Tick()
{
	if (IsAlive())
	{
		int heal = Roll(1);
		hp += heal;
		std::cout << GetName() << " recovered " << heal << " hp.\n";
	}
	else if (alive)
	{
		alive = false;
		std::cout << GetName() << " has died!\n";
	}
}