#pragma once
#include <string>
#include "Weapon.h"
#include "Dice.h"
#include "Attribute.h"



class MemeFighter
{
protected:
	MemeFighter(const std::string& name, int hp, int power, int speed, Weapon* pWeapon);
	int Roll(int n = 1) const;

public:
	std::string GetName() const;
	int GetInitiative();
	void Attack(MemeFighter& other);
	virtual bool SpecialAttack(MemeFighter& other) = 0;
	void DealDamage(MemeFighter& other, int damage);
	void StealWeapon(MemeFighter& other);
	bool IsAlive() const;
	bool HasWeapon() const;
	virtual void Tick();
	virtual ~MemeFighter();

protected:
	std::string name;
	Attribute attr;
	bool alive = true;
	Weapon* pWeapon = nullptr;
	mutable Dice d6;
};