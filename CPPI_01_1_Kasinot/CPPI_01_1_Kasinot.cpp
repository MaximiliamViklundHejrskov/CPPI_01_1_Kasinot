#include <iostream>
#include <random>
#include <cstring>

std::random_device seed;
std::mt19937 engine(seed());
std::uniform_int_distribution<int> dist_1_6(1, 6);
std::uniform_int_distribution<int> dist_1_4(1, 4);
int die1;
int die2;

char userInput;
int guess;

char winList[5] =
{
	0,
	0,
	0,
	0,
	0
};

int winningsNumberGame = 0;
int winningsOddsAndEvens = 0;
int winningsDuckGame = 0;
int money = 1000;
int bet;


void AddToWinList(char winOrLose)
{
	for (int i = 4; i > 0; i--)
	{
		winList[i] = winList[i - 1];
	}
	winList[0] = winOrLose;
}

void PrintWinList()
{
	std::cout << "Last 5 Games\n\n";
	for (int i = 0; i < 5; i++)
	{
		std::cout << i + 1 << ") ";
		switch (winList[i])
		{
		case '1':
			std::cout << " Win\n";
			break;

		case '2':
			std::cout << " Loss\n";
			break;

		default:
			std::cout << "\n";
			break;
		}
	}
	system("pause");
	system("cls");
}

bool CheckWinnings(int winnings)
{
	int maxWinnings = 500;
	int loses = (-500);
	if (winnings >= maxWinnings)
	{
		std::cout << "You've been winning a bit too much here, play something else.\n*Security escorts you from the table*\n";
		return false;
	}
	else if (winnings <= loses)
	{
		std::cout << "Only loser is the quiter, isn't it so?\n";
		return true;
	}
	else
	{
		std::cout << "You got this champ\n";
		return true;
	}
}


void DuckGame()
{
	int amountOfDucks;

	bool duckGame = true;
	bool duckGameMenu = true;
	bool playingDuckGame = false;

	while (duckGame && CheckWinnings(winningsDuckGame))
	{
		system("cls");
		while (duckGameMenu && CheckWinnings(winningsDuckGame))
		{
			system("pause");
			system("cls");
			userInput = 'x';
			if (money == 0) {
				std::cout << "Money: " << money << "kr\nYou have no money left and get thrown out by security.\n";
				system("pause");
				system("cls");
				duckGame = false;
				duckGameMenu = false;
				userInput = 'c';
			}

			while (std::cin.fail() || userInput != 'a' && userInput != 'b' && userInput != 'c' && money != 0)
			{
				std::cout << "Money: " << money << "kr\nWelcome to THE DUCK GAME!!\na) Play\nb) Rules\nc) Exit to main menu\n";
				std::cin >> userInput;

				std::cin.clear();
				std::cin.ignore(100, '\n');
				system("cls");
			}

			switch (userInput)
			{
			case 'a':
				playingDuckGame = true;
				duckGameMenu = false;
				break;

			case 'b':
				system("cls");
				std::cout << "RULES\nIn The Duck Game you will guess how many ducks are in this bag.\nThere can be anywhere between 1 and 4 ducks in the bag.\nIf you guess correctly you win 4 times your bet!!\n";
				system("pause");
				system("cls");
				break;

			case 'c':
				duckGame = false;
				duckGameMenu = false;
				break;
			}
		}

		while (playingDuckGame)
		{
			while (std::cin.fail() || bet < 1 || bet > money)
			{
				std::cout << "Money: " << money << "kr\nFirst place your bet.\n";
				std::cin >> bet;
				std::cin.clear();
				std::cin.ignore(100, '\n');
				system("cls");
			}
			if (bet == money)
			{
				std::cout << "ALL IN!!\n";
			}
			std::cout << "Your bet: " << bet << "kr\n";
			system("pause");
			system("cls");

			std::cout << "Let's Play!!\nPlease enter a number between 1 and 4.\n";
			std::cin >> guess;
			system("cls");


			while (std::cin.fail() || guess < 1 || guess > 4)
			{
				std::cin.clear();
				std::cin.ignore(100, '\n');
				std::cout << "Invalid input\nPlease enter a number between 2 and 12.\n";
				std::cin >> guess;
				system("cls");
			}

			amountOfDucks = dist_1_4(engine);

			std::cout << "You guessed that there are " << guess << " ducks!!\n";
			system("pause");
			system("cls");
			std::cout << "You guessed that there are " << guess << " ducks!!\n";
			std::cout << "There are...\n";
			system("pause");
			system("cls");
			std::cout << "You guessed that there are " << guess << " ducks!!\n";
			std::cout << "There are...\n";
			for (int i = 0; i < amountOfDucks; i++)
			{
				std::cout << R"(
	    _
	.__(.)<
	 \___))";
			}
			std::cout << "\n" << amountOfDucks << " ducks!!!";
			system("pause");
			system("cls");

			if (guess == amountOfDucks)
			{
				money = money + (bet * 4);
				winningsDuckGame = winningsDuckGame + (bet * 4);
				AddToWinList('1');
				std::cout << "Money: " << money << "kr\nCongratulations, you won " << (bet * 4) << "kr!!\n";
			}
			else
			{
				money -= bet;
				winningsDuckGame -= bet;
				AddToWinList('2');
				std::cout << "Money: " << money << "kr\nSorry, you lost " << bet << "kr\n";
			}
			std::cout << "\n\n";
			PrintWinList();
			bet = 0;
			playingDuckGame = false;
			duckGameMenu = true;
		}
	}
}

static void NumberGame()
{
	int sum;
	bool numbers = true;
	bool numbersMenu = true;
	bool playingNumbers = false;

	while (numbers && CheckWinnings(winningsNumberGame))
	{
		system("cls");
		while (numbersMenu && CheckWinnings(winningsNumberGame))
		{
			system("pause");
			system("cls");
			userInput = 'x';
			if (money == 0) {
				std::cout << "Money: " << money << "kr\nYou have no money left and get thrown out by security.\n";
				system("pause");
				system("cls");
				numbers = false;
				numbersMenu = false;
				userInput = 'c';
			}

			while (std::cin.fail() || userInput != 'a' && userInput != 'b' && userInput != 'c' && money != 0)
			{
				std::cout << "Money: " << money << "kr\nWelcome to the Number Game!\na) Play\nb) Rules\nc) Exit to main menu\n";
				std::cin >> userInput;

				std::cin.clear();
				std::cin.ignore(100, '\n');
				system("cls");
			}

			switch (userInput)
			{
			case 'a':
				playingNumbers = true;
				numbersMenu = false;
				break;

			case 'b':
				system("cls");
				std::cout << "RULES\nIn the number game you'll place a bet and then guess what the sum of our two die will be.\nIf you guess correctly, you win triple your bet!\n";
				system("pause");
				system("cls");
				break;

			case 'c':
				numbers = false;
				numbersMenu = false;
				break;
			}
		}

		while (playingNumbers)
		{
			while (std::cin.fail() || bet < 1 || bet > money)
			{
				std::cout << "Money: "<<money<<"kr\nFirst place your bet.\n";
				std::cin >> bet;
				std::cin.clear();
				std::cin.ignore(100, '\n');
				system("cls");
			}
			if (bet == money) 
			{
				std::cout << "ALL IN!!\n";
			}
			std::cout << "Your bet: " << bet << "kr\n";
			system("pause");
			system("cls");

			std::cout << "Let's Play!!\nPlease enter a number between 2 and 12.\n";
			std::cin >> guess;
			system("cls");


			while (std::cin.fail() || guess < 2 || guess > 12)
			{
				std::cin.clear();
				std::cin.ignore(100, '\n');
				std::cout << "Invalid input\nPlease enter a number between 2 and 12.\n";
				std::cin >> guess;
				system("cls");
			}


			die1 = dist_1_6(engine);
			die2 = dist_1_6(engine);
			sum = die1 + die2;

			std::cout << "You guessed " << guess << "\n";
			system("pause");
			std::cout << "The first die shows " << die1 << "!\n";
			system("pause");
			system("cls");
			std::cout << "You guessed " << guess << "\n";
			std::cout << "The first die shows " << die1 << "!\n";
			std::cout<<"The second die shows " << die2 << "!\n";
			system("pause");
			system("cls");
			std::cout << "You guessed " << guess << "\n";
			std::cout << "The first die shows " << die1 << "!\n";
			std::cout<<"The second die shows " << die2 << "!\n";
			std::cout << "The sum of the two die is " << sum << "\n\n";
			system("pause");
			system("cls");
			if (guess == sum)
			{
				money = money + (bet * 3);
				winningsNumberGame = winningsNumberGame + (bet * 3);
				AddToWinList('1');
				std::cout << "Money: " << money << "kr\nCongratulations, you won " << (bet * 2) << "kr!!\n";
			}
			else
			{
				money -= bet;
				winningsNumberGame -= bet;
				AddToWinList('2');
				std::cout << "Money: " << money << "kr\nSorry, you lost " << bet << "kr\n";
			}
			std::cout << "\n\n";
			PrintWinList();
			bet = 0;
			playingNumbers = false;
			numbersMenu = true;
		}
	}
}

static void OddsAndEvens()
{
	bool oddsAndEvens = true;
	bool menuOddsAndEvens = true;
	bool playingOddsAndEvens = false;
	char choiceOddsOrEvens[6];

	bool WonToMuch = CheckWinnings(winningsOddsAndEvens);
	while (oddsAndEvens && WonToMuch)
	{
		system("cls");
		while(menuOddsAndEvens)
		{
			system("pause");
			system("cls");
			userInput = 'x';
			if (money == 0) {
				std::cout << "Money: " << money << "kr\nYou have no money left and get thrown out by security.\n";
				system("pause");
				system("cls");
				oddsAndEvens = false;
				menuOddsAndEvens = false;
				userInput = 'c';
			}

			while (std::cin.fail() || userInput != 'a' && userInput != 'b' && userInput != 'c')
			{
				std::cout << "Money: " << money << "kr\nWelcome to Odds & Evens!\na) Play\nb) Rules\nc) Exit to main menu\n";
				std::cin >> userInput;

				std::cin.clear();
				std::cin.ignore(100, '\n');
				system("cls");
			}

			switch (userInput)
			{
			case 'a':
				playingOddsAndEvens = true;
				menuOddsAndEvens = false;
				break;

			case 'b':
				system("cls");
				std::cout << "RULES\nIn Odds & Evens you will predict whether our dice will show odds or evens.\nIf you guess correctly on both die you win double your bet!!\n";
				system("pause");
				system("cls");
				break;

			case 'c':
				oddsAndEvens = false;
				menuOddsAndEvens = false;
				break;
			}
		}

		while(playingOddsAndEvens)
		{
			std::cout << "Money: " << money << "kr\nFirst place your bet.\n";
			std::cin >> bet;
			while (std::cin.fail() || bet < 1 || bet > money)
			{
				std::cout << "Incorrect amount or input\nPlease enter a number between 1 and " << money << ".\n";
				std::cin >> bet;
				std::cin.clear();
				std::cin.ignore(100, '\n');
				system("cls");
			}
			if (bet == money)
			{
				std::cout << "ALL IN!!\n";
			}
			std::cout << "Your bet: " << bet << "kr\n";
			system("pause");
			system("cls");


			userInput = 'x';
			while (std::cin.fail() || userInput != 'a' && userInput != 'b')
			{
				std::cout << "Lets START!!\nWhich do you pick?\na) Odds\nb) Evens\n";
				std::cin >> userInput;

				std::cin.clear();
				std::cin.ignore(100, '\n');
				system("cls");
			}

			if(userInput == 'a')
			{
				strncpy_s(choiceOddsOrEvens, "Odds", 4);
				//choiceOddsOrEvens = "Odds";
			}
			else
			{
				strncpy_s(choiceOddsOrEvens, "Evens", 5);
				//choiceOddsOrEvens = "Evens";
			}

			die1 = dist_1_6(engine);
			die2 = dist_1_6(engine);

			std::cout << "You chose " << choiceOddsOrEvens << "\n";
			system("pause");
			system("cls");
			std::cout << "You chose " << choiceOddsOrEvens << "\n";
			std::cout << "First die shows " << die1 << "\n";
			system("pause");
			system("cls");
			std::cout << "You chose " << choiceOddsOrEvens << "\n";
			std::cout << "First die shows " << die1 << "\n";
			std::cout << "Second die shows " << die2 << "\n";
			system("pause");
			system("cls");

			if (strcmp(choiceOddsOrEvens, "Evens") == 0 && (die1 & 1) == 0 && (die2 & 1) == 0)
			{
				money = money + (bet * 2);
				AddToWinList('1');
				std::cout << "Money: " << money << "kr\nCongratulations, you won " << (bet * 2) << "kr!!\n";
			}
			else if (strcmp(choiceOddsOrEvens, "Odds") == 0 && (die1 & 1) != 0 && (die2 & 1) != 0)
			{
				money = money + (bet * 2);
				winningsOddsAndEvens = winningsOddsAndEvens+ (bet * 2);
				AddToWinList('1');
				std::cout << "Money: " << money << "kr\nCongratulations, you won " << (bet * 2) << "kr!!\n";
			}
			else
			{
				money -= bet;
				winningsOddsAndEvens -= bet;
				AddToWinList('2');
				std::cout << "Money: " << money << "kr\nSorry, you lost " << bet << "kr\n";
			}
			std::cout << "\n\n";
			PrintWinList();
			bet = 0;
			playingOddsAndEvens = false;
			menuOddsAndEvens = true;
		}
	}
}


static int Menu()
{
	userInput = 'x';
	while (std::cin.fail() || userInput != 'a' && userInput != 'b' && userInput != 'c' && userInput != 'd' && userInput != 'e')
	{
		std::cout << "Welcome to the Casino Maxima!\n" << "Money: " << money << "kr\n\na) Play the Number Game\nb) Play Odds or Evens\nc) Play THE DUCK GAME!!\nd) Show Win or Loss from last 5 Games\ne) Exit the casino\n";
		std::cin >> userInput;

		std::cin.clear();
		std::cin.ignore(100, '\n');
		system("cls");
		
	}

	switch (userInput)
	{
	case 'a':
		return 0;
		break;

	case 'b':
		return 1;
		break;

	case 'c':
		return 2;
		break;

	case 'd':
		return 3;
		break;

	case 'e':
		return 4;
		break;
	}
	return 10;
}

int main()
{
	bool playing = true;
	while(playing)
	{
		int switcher = Menu();
		switch (switcher)
		{
		case 0:
			NumberGame();
			break;

		case 1:
			OddsAndEvens();
			break;

		case 2:
			DuckGame();
			break;

		case 3:
			system("cls");
			PrintWinList();
			break;

		case 4:
			playing = false;
			break;
		}
	}
}
