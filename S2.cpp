#include "S2.h"

int death = 0;
bool divided = false;
int choice;
bool done = false;
int large = 300;
int small = 200;

void S2End()
{
	std::cout << "Death Count: " << death << std::endl;
	done = true;
}

void S2Ignore()
{
	std::cout << "You choose to ignore them, thinking they are bluffing.\n" <<
				"However, they are just as stupid as you in this case and bash you over the head.\n"
				"It is only after they remember you are the only one able to fix the boat.\n" <<
				"At least its not your problem now...being dead and all.\n\n";

	death += (large + small + 1);
	S2End();
}

void S2Cry()
{
	std::cout << "You starting sobbing in front of everyone for being so cruel when you only wanted to help.\n" <<
					"They decide it would be better to drown then to owe a life debt to such a wuss.\n" <<
					"As the boats sink, the only sound is your constant wailing.\n\n" <<
					"Way to go, you big baby.\n\n";

	death += (large + small + 1);
	S2End();
}

void S2Kill()
{
	std::cout << "You decided to kill everyone on board the boat.\n" <<
				"You know, for the greater good and all that.\n" <<
				"So after murdering the all the men, women, children, and goldfish\n" <<
				"you whistle a merry tune as you make you want to the larger boat.\n\n";

	death += small;
	small = 0;
}


void S2Revolt()
{
	std::cout << "The people on the smaller boat see you choosing to let them die\n " <<
					"and will not stand for it.\n" <<
					"They threaten to kill you if you do not fix their boat instead.\n\n" <<
					"What do you do?\n" <<
					"1. Ignore them\n" <<
					"2. Break down crying\n" <<
					"3. Kill them all\n\n";


	std::cin >> choice;

	switch (choice)
	{
	case 1:	S2Ignore();
		break;
	case 2:	S2Cry();
		break;
	case 3:	S2Kill();
		break;
	default:
		{
		std::cout << "A WILD KRAKEN HAS APPEARED!\n" <<
						"You briefly wonder as to the programmer's mental state\n" <<
						"before both ships are dragged down into the wet abyss.\n\n";
		death += (large + small + 1);
		S2End();
		}
	}

}




void S2Divide()
{
	divided = true;
	std::cout << "After sailing for awhile, your remaining crew(?) finds two more boats,\n" <<
		"and because pattern recognition is not a strong point of anyone's,\n" <<
		"everyone decides to divide up between the two new boats.\n" <<
		"200 on one, 100 on another.\n" <<
		"Guess what happens.\n\n" <<
		"What do you do?\n" <<
		"1. Fix larger boat\n" <<
		"2. Fix smaller boat\n" <<
		"3. Suicide\n\n" << std::endl;

	std::cin >> choice;

	large = 200;
	small = 100;

	switch(choice)
	{
	case 1: S2FLarge();
		break;
	case 2: S2FSmall();
		break;
	case 3: S2Suicide();
		break;
	default:
		std::cout << "You start wondering where you life went wrong.\n" <<
						"Maybe it was that time you decided boat fixing was a good idea.\n" <<
						"Or maybe that time you climbed your school's computer building in a Batman costume.\n" <<
						"It could even be because you take apart your sandwiches and eat each ingredient separately. You weirdo.\n" <<
						"After a while of these thoughts, you remember the boats are sinking and move to fix one, \n" <<
						"but by this time everyone but you has drowned. So you take the raft and head for land.\n\n" <<
						"Good luck you crazy freak.\n\n";
		death += (small + large);
		S2End();
	}
}


int chance()
{
	int t = rand() % 20;
	return t;
}


void S2FLarge()
{
	if (!done)
	{
		int c;
		std::cout << "You decide to fix the larger boat, dooming " << small << " people.\n\n";

		if (!divided && !done)
		{

			c = chance();

			if (c % 4 == 0)
				S2Revolt();

			if (!done)
			{
				death += small;
				std::cout << "You hate yourself (didn't you already?) for killing so many (is " << death << " a lot?),\n";
				std::cout << "but you know it was for the best...you think...maybe...oh well, screw 'em.\n\n";
	
				c = chance();
	
				if (c % 4 == 0)
				{
					divided = true;
					S2Divide();
				}
				else
				{
					std::cout << "After sailing for a bit longer you realize there is not enough food left.\n" <<
									"The resulting riot leads to all but you dead or dismembered.\n" <<
									"You take the raft and return to land, though the story seems to exclude\n" <<
									"you curled up in the corner.\n" <<
									"VICTORY...I guess.\n\n";
					death += large;
					S2End();
				}
			}
		}
		else
		{
			std::cout << "There is not enough alcohol in the world to help you now.\n" <<
							"You terrible, terrible person.\n\n";
			death += small;
			S2End();
		}
	}
}

void S2FSmall()
{
	std::cout << "You decide to fix the smaller boat, dooming " << large << " people.\n" <<
					"You cringe from the screams as the boat sinks.\n\n\n\n" <<
					"10 YEARS LATER:\n\n" <<
					"Unable to handle the guilt of sending 300 people to their deaths,\n" <<
					"you hang yourself, alone and forgotten.\n\n" <<
					"You monster.\n\n";
	death += (large + 1);
	S2End();
}

void S2Suicide()
{
	std::cout << "Unable to take the burden of deciding who lives and who dies, you jump overboard and drown.\n" <<
					"As you were the only one able to fix the boats, everyone else dies as well.\n\n" <<
					"You selfish bastard.\n\n";
	death += (large + small + 1);
	S2End();
}


void S2Start()
{

	srand(time(NULL));
	std::cout << "Beginnning Scenario 2: Nice Boats\n\n" << std::endl;

	std::cout << "Two boats are sailing across the ocean.\n" <<
					"There are a total of 500 people, 300 on one boat, 200 on the other and yourself.\n" <<
					"The only way to move between the boats is a small raft capable of carrying only one person.\n" <<
					"You are on the less populated boat when boat when they both begin to sink.\n" <<
					"You are the only one capable of fixing them, but only have enough time to repair one.\n\n" <<
					"What do you do?\n" <<
					"1. Fix larger boat\n" <<
					"2. Fix smaller boat\n" <<
					"3. Suicide\n\n" << std::endl;

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
						"He destroys both boats with a massive Browave!\n" << std::endl;
		death += (large + small + 1);
		S2End();


	}

}