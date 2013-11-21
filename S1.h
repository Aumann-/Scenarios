#include <iostream>



void S1Sniper()
{
	std::cout << "The sniper is unable to obtain a clear shot " <<
				"and the terrorist has lost his patience.\n" <<
				"The bombs have detonated\n" <<
				"Death Count: 4,000" << std::endl;

}

void S1Rush()
{
	std::cout << "You and a small group of 10 others rush the building but are unable to stop the terrorist " <<
				"before he detonates the bombs.\n" <<
				"You and your group are caught in the explosion.\n" <<
				"Death Count: 4,011" << std::endl;

}

void S1Destroy()
{
	std::cout << "You make the decision to destroy the building the terrorist is in.\n" <<
					"The 1,000 people inside die along with him in order to save everyone else.\n" <<
					"Death Count: 1,000\n" <<
					"Terrorist killed, situation clear." << std::endl;

}


void S1Give()
{
	std::cout << "You give into the terrorist's demands, including the execution of the chosen person.\n" <<
					"Unfortunately, the terrorist refuses to disarm the bombs and detonates them.\n" <<
					"Death Count: 4,001" << std::endl;

}


void S1Kill()
{
	std::cout << "How do you wish to kill?\n" <<
					"1. Sniper\n" <<
					"2. Rush the building\n" <<
					"3. Destroy the building\n" << std::endl;

	int ch;

	std::cin >> ch;

	switch(ch)
	{

	case 1:	S1Sniper();
		break;
	case 2:	S1Rush();
		break;
	case 3:	S1Destroy();
		break;
	default:
		std::cout << "The terrorist leans on the window to see what you are doing.\n" <<
			"Due to faulty construction, the frame gives way and the terrorist plummets to his death.\n" <<
			"Death Count: 0\n" <<
			"Terrorist killed, situation clear" << std::endl;
	}

}


void S1Pass()
{
	std::cout << "You allow someone else to make the decision for you.\n" <<
					"However, they are also unable to make a decision in time and the terrorist is angered.\n" <<
					"The bombs have detonated\n" <<
					"Death Count: 4,000" << std::endl;

}


void S1Fourth()
{
	std::cout << "You rage at the programming for this crappy scenario before turning your sidearm on yourself.\n" <<
					"The terrorist, seeing your action, is shocked at your choice.\n" <<
					"His hesitation gives the sniper the opportunity to take him out without issue.\n" <<
					"Death Count: 1" << std::endl;
}


void S1Start()
{
	std::cout << "Beginning Scneario 1: Terrorist Threat " << std::endl << std::endl;

	std::cout << "A terrorist has planted bombs at various locations around the city.\n" <<
					"He has barricaded himself inside a skyscraper containing 1,000 civilians.\n" <<
					"The estimated loss of life if all bombs detonate is ~4,000 people. \n" <<
					"This includes the people in the building with the terrorist.\n" <<
					"The terrorist has made multiple demands, including the death of a government official.\n\n" <<
					"What do you do?\n" <<
					"1. Give into the demands.\n" <<
					"2. Kill the terrorist.\n" <<
					"3. Let someone else choose.\n" <<
					"4. Take a fourth option." << std::endl;


	int S1choice;

	std::cin >> S1choice;

	switch (S1choice)
	{

		case 1:	S1Give();
			break;
		case 2:	S1Kill();
			break;
		case 3: S1Pass();
			break;
		case 4: S1Fourth();
			break;
		default:
			std::cout << "Your inability to make a decision has angered the terrorist.\n" <<
				"Death Count: 4,000" << std::endl;

	}



}