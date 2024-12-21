#pragma once
#include "BaseMemeFighter.h"
#include <string>

class MemeFrog : public MemeFighter
{
public:
	MemeFrog(const std::string name);
	std::string GetOldName() const;
	bool SpecialAttack(MemeFighter& other) override;
	void Tick() override;

private:
	std::string oldName;
	bool super = false;
	int superTurns = 0;
};

class MemeStoner : public MemeFighter
{
public:
	MemeStoner(const std::string name);
	bool SpecialAttack(MemeFighter& other) override;
};