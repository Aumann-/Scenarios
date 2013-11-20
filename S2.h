#include <iostream>

int death = 0;


void S2FLarge()
{

}

void S2FSmall()
{

}

void S2Suicide()
{

}


void S2Start()
{
	std::cout << "Beginnning Scenario 2: Nice Boats\n" << std::endl;

	std::cout << "Two boats are sailing across the ocean.\n" <<
					"There are a total of 500 people, 300 on one boat, 200 on the other and yourself.\n" <<
					"The only way to move between the boats is a small raft capable of carrying only one person.\n" <<
					"You are on the less populated boat when boat when they both begin to sink.\n" <<
					"You are the only one capable of fixing them, but only have enough time to repair one.\n" <<
					"What do you do?\n" <<
					"1. Fix larger boat\n" <<
					"2. Fix smaller boat\n" <<
					"3. Suicide" << std::endl;

	int choice;

	std::cin >> choice;

	switch(choice)
	{
	case 1: S2FLarge();
		break;
	case 2: S2FSmall();
		break;
	case 3: S2Suicide();
		break;
	default:
		std::cout << "Your hesitation has angered Broseidon, Lord of the Brocean!\n" <<
						"He destroys both boats with a massive Browave!" << std::endl;
		death += 501;
		break;


	}

	std::cout << "Death Count: " << death << std::endl;

}