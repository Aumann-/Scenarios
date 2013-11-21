#include "S2.h"

int death = 0;
bool divided = false;
int choice;

void S2Revolt()
{
	std::cout << " " << std::endl;


}




void S2Divide()
{
	std::cout << "After saling for awhile, your remain crew(?) finds two more boats,\n" <<
		"and because pattern recognition is not a strong point of anyone's,\n" <<
		"everyone decides to divide up between the two new boats.\n" <<
		"200 on one, 100 on another.\n" <<
		"Guess what happens.\n" <<
		"What do you do?\n" <<
		"1. Fix larger boat\n" <<
		"2. Fix smaller boat\n" <<
		"3. Suicide" << std::endl;

	std::cin >> choice;

	switch(choice)
	{
	case 1: 
		break;
	case 2: S2FSmall(150);
		break;
	case 3: S2Suicide();
		break;
	default:
		std::cout << "Your hesitation has angered Broseidon, Lord of the Brocean!\n" <<
						"He destroys both boats with a massive Browave!" << std::endl;
		death += 501;
		break;
	}
}


int chance()
{
	int t = rand() % 20;
	return t;
}


void S2FLarge(int small)
{
	int c;
	std::cout << "You decide to fix the larger boat, dooming " << small << " people.\n";


	c = chance();

	if (c % 4 == 0)
		S2Revolt();





	if (!divided)
	{
		std::cout << "You hate yourself for killing so many (is " << small << " a lot?),\n";
		std::cout << "but you know it was for the best...you think...maybe...oh well, screw 'em.\n";
	
		c = chance();
	
		if (c % 4 == 0)
		{
			divided = true;
			S2Divide();
		}
		else
			c = 0;

	}
	else
	{

	}
}

void S2FSmall(int big)
{
	std::cout << "You decide to fix the smaller boat, dooming " << big << " people.\n" <<
					"You cringe from the screams as the boat sinks.\n\n\n\n" <<
					"10 YEARS LATER:\n\n" <<
					"Unable to handle the guilt of sending 300 people to their deaths,\n" <<
					"you hang yourself, alone and forgotten.\n" <<
					"You monster.\n";
	death += 301;
}

void S2Suicide()
{
	std::cout << "Unable to take the burden of deciding who lives and who dies, you jump overboard and drown.\n" <<
					"As you were the only one able to fix the boats, everyone else dies as well.\n" <<
					"You selfish bastard.\n";
	death += 501;
}


void S2Start()
{

	srand(time(NULL));
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

	std::cin >> choice;

	switch(choice)
	{
	case 1: S2FLarge(200);
		break;
	case 2: S2FSmall(300);
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