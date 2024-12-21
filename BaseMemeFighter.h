#pragma once
#include <string>
#include <random>

class MemeFighter
{
protected:
	class Dice
	{
	public:
		int Roll(int n)
		{
			int total = 0;
			for (int i = 0; i < n; i++)
			{
				total += dDist(rng);
			}
			return total;
		}

	private:
		std::random_device rd;
		std::mt19937 rng{ rd() };
		std::uniform_int_distribution<int> dDist{ 1, 6 };
	};

protected:
	MemeFighter(const std::string& name, int hp, int power, int speed);
	int Roll(int n = 1);

public:
	std::string GetName() const;
	int GetInitiative();
	void Attack(MemeFighter& other);
	virtual bool SpecialAttack(MemeFighter& other) = 0;
	void DealDamage(MemeFighter& other, int damage) const;
	bool IsAlive() const;
	virtual void Tick();

protected:
	std::string name;
	int hp;
	int power;
	int speed;
	bool alive = true;
	Dice d6;

};