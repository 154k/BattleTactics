#pragma once
#include <string>
#include "BaseMemeFighter.h"
#include "Dice.h"
#include "Attribute.h"

class Weapon
{
protected:
	Weapon(const std::string& name, int rank)
		:
		name(name),
		rank(rank){}
	
public:
	Weapon(const Weapon* pWeapon)
		:
		name(pWeapon->name),
		rank(pWeapon->rank){}
	virtual int GetWeaponDamage(const Attribute& attr, Dice& d6) const = 0;
	int GetRank() const
	{
		return rank;
	}
	std::string GetName() const
	{
		return name;
	}
	virtual Weapon* CopyWeapon() const = 0;

protected:
	std::string name;
	int rank;
};

class Knife : public Weapon
{
public:
	Knife()
		:
		Weapon("Knife", 2){}
	Weapon* CopyWeapon() const override
	{
		return new Knife(*this);
	}
	int GetWeaponDamage(const Attribute& attr, Dice& d6) const override
	{
		return (attr.speed * 4) + d6.Roll(2);
	}

};

class Fist : public Weapon
{
public:
	Fist()
		:
		Weapon("Fist", 0) {}
	Weapon* CopyWeapon() const override
	{
		return new Fist(*this);
	}
	int GetWeaponDamage(const Attribute& attr, Dice& d6) const override
	{
		return attr.power + d6.Roll(3);
	}

};

class Bat : public Weapon
{
public:
	Bat()
		:
		Weapon("Bat", 1) {}
	Weapon* CopyWeapon() const override
	{
		return new Bat(*this);
	}
	int GetWeaponDamage(const Attribute& attr, Dice& d6) const override
	{
		return (attr.power * 2) + d6.Roll(3);
	}

};