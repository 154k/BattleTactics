#pragma once
#include <random>

class Dice
{
public:
	int Roll(int n = 1)
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