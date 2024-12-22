#include "BaseMemeFighter.h"
#include <iostream>

MemeFighter::MemeFighter(const std::string& name, int hp, int power, int speed, Weapon* pWeapon)
	:
	name(name),
	attr{hp, power, speed},
	pWeapon(pWeapon){}

int MemeFighter::Roll(int n) const
{
	return d6.Roll(n);
}

std::string MemeFighter::GetName() const
{
	return name;
}

int MemeFighter::GetInitiative()
{
	return attr.speed * Roll(2);
}

void MemeFighter::Attack(MemeFighter& other)
{
	if (IsAlive() && other.IsAlive())
	{
		int damage = attr.power + Roll(2);
		DealDamage(other, damage);
		std::cout << GetName() << " attacked " << other.GetName() << " with a " << pWeapon->GetName() << " and did " << damage << " damage!\n";

		if (!other.IsAlive() && other.HasWeapon())
		{
			if (other.pWeapon->GetRank() > pWeapon->GetRank())
			{
				StealWeapon(other);
			}
		}
	}
}

void MemeFighter::DealDamage(MemeFighter& other, int damage)
{
	other.attr.hp -= damage;
}

void MemeFighter::StealWeapon(MemeFighter& other)
{
	Weapon* storedWeapon = other.pWeapon->CopyWeapon();
	delete pWeapon;
	pWeapon = storedWeapon;
	delete other.pWeapon;
	other.pWeapon = nullptr;
	std::cout << GetName() << " has killed " << other.GetName() << " and stole his weapon!\n";
}

bool MemeFighter::IsAlive() const
{
	return attr.hp > 0;
}

bool MemeFighter::HasWeapon() const
{
	return pWeapon != nullptr;
}

void MemeFighter::Tick()
{
	if (IsAlive())
	{
		int heal = Roll(1);
		attr.hp += heal;
		std::cout << GetName() << " recovered " << heal << " hp.\n";
	}
	else if (alive)
	{
		alive = false;
		std::cout << GetName() << " has died!\n";
	}
}

MemeFighter::~MemeFighter()
{
	delete pWeapon;
	pWeapon = nullptr;
}
