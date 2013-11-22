#include "S2.h"

int death = 0;
bool divided = false;
int choice;
bool done = false;
int large = 300;
int small = 200;

//final function for accumulator output
void S2End()
{
	std::cout << "Death Count: " << death << std::endl;
	done = true;
}
//function for ignore option
void S2Ignore()
{
	std::cout << "You choose to ignore them, thinking they are bluffing.\n" <<
				"However, they are just as stupid as you in this case and bash you over the head.\n"
				"It is only after they remember you are the only one able to fix the boat.\n" <<
				"At least its not your problem now...being dead and all.\n\n";

	death += (large + small + 1); //add to death total
	S2End(); //jump to end
}

//function for cry option
void S2Cry()
{
	std::cout << "You starting sobbing in front of everyone for being so cruel when you only wanted to help.\n" <<
					"They decide it would be better to drown then to owe a life debt to such a wuss.\n" <<
					"As the boats sink, the only sound is your constant wailing.\n\n" <<
					"Way to go, you big baby.\n\n";

	death += (large + small + 1);
	S2End();
}

//function for kill option
void S2Kill()
{
	std::cout << "You decided to kill everyone on board the boat.\n" <<
				"You know, for the greater good and all that.\n" <<
				"So after murdering the all the men, women, children, and goldfish\n" <<
				"you whistle a merry tune as you make you want to the larger boat.\n\n";

	death += small;
	small = 0;
}

//function for revolt random event
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
	case 1:	S2Ignore(); //jump to ignore
		break;
	case 2:	S2Cry(); //jump to cry
		break;
	case 3:	S2Kill(); //jump to kill
		break;
	default: //if no defined option is chosen
		{
		std::cout << "A WILD KRAKEN HAS APPEARED!\n" <<
						"You briefly wonder as to the programmer's mental state\n" <<
						"before both ships are dragged down into the wet abyss.\n\n";
		death += (large + small + 1);
		S2End();
		}
	}

}



//function for divide random event
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

	//change current values to new values
	large = 200;
	small = 100;

	switch(choice)
	{
	case 1: S2FLarge(); //jump to fix large
		break;
	case 2: S2FSmall(); //jump to fix small
		break;
	case 3: S2Suicide(); //jump to suicide
		break;
	default:
		{
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
}

//function to generate random number
int chance()
{
	int t = rand() % 20;
	return t;
}

//function for fix large
void S2FLarge()
{
	if (!done) //check end flag
	{
		int c;
		std::cout << "You decide to fix the larger boat, dooming " << small << " people.\n\n";

		if (!divided) //check divide flag
		{

			c = chance();

			if (c % 4 == 0)
				S2Revolt(); //jump to revolt

			if (!done)
			{
				death += small;
				std::cout << "You hate yourself (didn't you already?) for killing so many (is " << death << " a lot?),\n";
				std::cout << "but you know it was for the best...you think...maybe...oh well, screw 'em.\n\n";
	
				c = chance();
	
				if (c % 4 == 0)
				{
					divided = true;
					S2Divide();//jump to divide
				}
				else //if divide random event does not happen
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
		else //if already divided
		{
			std::cout << "There is not enough alcohol in the world to help you now.\n" <<
							"You terrible, terrible person.\n\n";
			death += small;
			S2End();
		}
	}
}

//function for fix small
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

//function for suicide
void S2Suicide()
{
	if (!divided) //if first is first option chosen
	{
	std::cout << "Unable to take the burden of deciding who lives and who dies, you jump overboard and drown.\n" <<
					"As you were the only one able to fix the boats, everyone else dies as well.\n\n" <<
					"You selfish bastard.\n\n";
	death += (large + small + 1);
	S2End();
	}

	else //if already divided
	{
		std::cout << "After killing so many people, now you decide to quit?\n" <<
					"Are you serious?\n" <<
					"Well I won't let you. In fact, let's play a different game." << std::endl;
		S2BadEnd();
	}
}

//beginning function
void S2Start()
{
	//seed random generator
	srand(time(NULL));
	std::cout << "Beginnning Scenario 2: Nice Boats\n\n" << std::endl;
	//scenario description
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
	case 1: S2FLarge();//jump to fix large
		break;
	case 2: S2FSmall();//jump to fix small
		break;
	case 3: S2Suicide();//jump to suicide
		break;
	case 10: S2Divide(); //jump to divide (for debug)
		break;
	default://if no defined option is chosen
		std::cout << "Your hesitation has angered Broseidon, Lord of the Brocean!\n" <<
						"He destroys both boats with a massive Browave!\n" << std::endl;
		death += (large + small + 1);
		S2End();


	}

}

//bad end function. ONly possible to reach by choosing suicide option after divide
void S2BadEnd()
{
	std::cout << "\n\n\n\n\nYou find yourself in a room.\n\n" <<
				"What do you do?\n" <<
				"1. Look around\n" <<
				"2. Scream\n" <<
				"3. Beg for mercy\n\n";

	std::cin >> choice;

	switch (choice)
	{
	case 1:
		{
			std::cout << "You decide to look around\n" <<
						"Well you could do that, but I've decided to remove your eyes.\n\n" <<
						"..........................................\n\n" <<
						"Ah, let's just take your entire head, shall we.\n" <<
						"\n\nYOU ARE DEAD\n\n";
			done = true;
			return;
		}

	case 2:
		{
			std::cout << "You scream and scream until your throat is raw.\n" <<
						"Too bad no one can hear you.\n" <<
						"You are going to stay here, screaming, for the rest of your miserable life.\n" <<
						"Have fun. HAHAHAHAHAHAHAHAHAHAHA\n\n" <<
						"YOU ARE DEAD\n\n";
			done = true;
			return;
		}

	case 3:
		{
			std::cout << "You decide to beg for your life.\n" <<
							"But, I thought you wanted to die?\n" <<
							"Afterall, the only way to get to this path was to choose Suicide.\n" <<
							"Did you change your mind?\n" <<
							"Well we can't have that, now can we?\n" <<
							"You have to keep to your word.\n" <<
							"If you really want out though, there is a quick way.\n" <<
							"There is a button in front of you, push it.\n\n";
			S2Button();
			break;

		}

	default:
		{
			std::cout << "Try to follow instructions please\n";
			S2BadEnd(); //recall bad end
			break;
		}

	}

}

//function for pressing button. reachable by choosing option three in bad end function
void S2Button()
{
	std::cout << "1. Push the button\n" <<
					"2. Push the button\n" <<
					"3. Push the button\n";

	std::cin >> choice;

	switch (choice)
	{
	case 1:
		{
		std::cout << "Unfortunately, this button is picky.\n" <<
					"How about you try again.\n\n";
		S2Button();
		break;
		}
	case 2:
		{
		std::cout << "AHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH!!!\n" <<
						"Oops, wrong button, lets try again without the tiny bees\n\n";
		S2Button();
		break;
		}
	case 3:
		{
		std::cout << "\n\n*Drip* *Drip* *Drip*\n\n" <<
					"Now isn't that better?\n" <<
					"You didn't need those pesky legs anyway.\n" <<
					"Just look at how much weight you've lost.\n" <<
					"Now just quietly bleed to death, would you?\n\n" <<
					"YOU ARE DEAD\n\n";

		done = true;
		return;
		}
	default:
		{
		std::cout << "You decide not to press the button.\n" <<
						"Since you dislike pressing buttons so much\n" <<
						"I'll simply remove your ability to do so.\n" <<
						"What good are arms anyway?\n" <<
						"Oh, stop screaming. That was a different option.\n" <<
						"If you wanted to do that you should have picked it instead.\n" <<
						"See ya, stumpy.\n\n" <<
						"YOU ARE DEAD\n\n";

		done = true;
		return;
		}
	}

}