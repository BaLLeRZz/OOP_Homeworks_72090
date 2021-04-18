#include"Player.h"
int main()
{
	// Player 1:
	String player1Name = "Ivan";
	String c1 = "Pochvam", c2 = "Da Begam", c3 = "Bate", c4 = "Istinska", c5 = "Mashina";
	Deck<Water> waterDeck;
	Water card1(c1, 12, 33), card2(c2, 16, 21), card3(c3, 10, 15);
	waterDeck.addCard(card1);
	waterDeck += card2;
	waterDeck = waterDeck + card3;
	Deck<Fire> fireDeck;
	Fire card4(c4, 15, 22), card5(c5, 69, 30);
	fireDeck.addCard(card4);
	fireDeck.addCard(card5);
	Player<Water, Fire> player1(player1Name, 0, 0, waterDeck, fireDeck);

	//Player 2:
	String player2Name = "Georgi";
	String k1 = "Bat Gergi", k2 = "Zadushaam sa", k3 = "Vsichko", k4 = "Stava", k5 = "Paprikash";
	Deck<Earth> earthDeck;
	Earth karta1(k1, 18, 26), karta2(k2, 9, 14);
	earthDeck += karta1;
	earthDeck.addCard(karta2);
	Deck<Wind> windDeck;
	Wind karta3(k3, 20, 8), karta4(k4, 19, 15), karta5(k5, 30, 11);
	windDeck += karta3;
	windDeck.addCard(karta4);
	windDeck = windDeck + karta5;
	Player<Earth, Wind> player2(player2Name, 0, 0, earthDeck, windDeck);

	//Game:
	srand(time(NULL));
	std::ifstream loadData("Stats.txt");
	if (loadData.is_open())
	{
		player1.loadPlayer(loadData);
		player2.loadPlayer(loadData);
	}
	else
		std::cout << "File didn't open!" << std::endl;
	loadData.close();
	std::cout << "Player 1:" << std::endl << player1;
	std::cout << std::endl;
	std::cout << "Player 2:" << std::endl << player2;
	std::cout << "Game Begins:" << std::endl;
	size_t wins1, losses1, wins2, losses2, points1 = 0, points2 = 0;
	size_t sPower1, sPower2, bPower1, bPower2, cType1, cType2;
	wins1 = player1.getWins();
	losses1 = player1.getLosses();
	wins2 = player2.getWins();
	losses2 = player2.getLosses();
	for (size_t i = 1; points1 < 5 && points2 < 5; i++)
	{
		std::cout << "---------------Round " << i << "---------------" << std::endl << std::endl;
		std::cout << player1.getPlayerName() << "'s Card:" << std::endl;
		if (rand() % 2)
		{
			sPower1 = waterDeck[0].getStartPower();
			bPower1 = waterDeck[0].getBonusPower();
			cType1 = waterDeck[0].getType();
			std::cout << player1.drawCardDeck1() << std::endl << "Current points: " << points1 << std::endl;
		}
		else
		{
			sPower1 = fireDeck[0].getStartPower();
			bPower1 = fireDeck[0].getBonusPower();
			cType1 = fireDeck[0].getType();
			std::cout << player1.drawCardDeck2() << std::endl << "Current points: " << points1 << std::endl;
		}
		std::cout << std::endl << "~~~" << std::endl <<std::endl;
		std::cout << player2.getPlayerName() << "'s Card:" << std::endl;
		if (rand() % 2)
		{
			sPower2 = earthDeck[0].getStartPower();
			bPower2 = earthDeck[0].getBonusPower();
			cType2 = earthDeck[0].getType();
			std::cout << player2.drawCardDeck1() << std::endl << "Current points: " << points2 << std::endl;
		}
		else
		{
			sPower2 = windDeck[0].getStartPower();
			bPower2 = windDeck[0].getBonusPower();
			cType2 = windDeck[0].getType();
			std::cout << player2.drawCardDeck2() << std::endl << "Current points: " << points2 << std::endl;
		}
		std::cout << std::endl;
		if ((cType1 == 2 && cType2 == 4) || (cType1 == 1 && cType2 == 2) || (cType1 == 3 && cType2 == 1) || (cType1 == 4 && cType2 == 3))
		{
			if (sPower1 + bPower1 > sPower2)
			{
				std::cout << "Winner of the round is " << player1.getPlayerName() << std::endl;
				points1++;
				continue;
			}
			else
			{
				std::cout << "Winner of the round is " << player2.getPlayerName() << std::endl;
				points2++;
				continue;
			}
		}
		else
		{
			if (sPower1 > sPower2)
			{
				std::cout << "Winner of the round is " << player1.getPlayerName() << std::endl;
				points1++;
				continue;
			}
			if (sPower1 < sPower2)
			{
				std::cout << "Winner of the round is " << player2.getPlayerName() << std::endl;
				points2++;
				continue;
			}
		}
		if ((cType1 == 4 && cType2 == 2) || (cType1 == 2 && cType2 == 1) || (cType1 == 1 && cType2 == 3) || (cType1 == 3 && cType2 == 4))
		{
			if (sPower2 + bPower2 > sPower1)
			{
				std::cout << "Winner of the round is " << player1.getPlayerName() << std::endl;
				points1++;
			}
			else
			{
				std::cout << "Winner of the round is " << player2.getPlayerName() << std::endl;
				points2++;
			}
		}
		else
		{
			if (sPower1 > sPower2)
			{
				std::cout << "Winner of the round is " << player1.getPlayerName() << std::endl;
				points1++;
			}
			else
			{
				std::cout << "Winner of the round is " << player2.getPlayerName() << std::endl;
				points2++;
			}
		}
	}
	std::cout << "---------------Game Over---------------" << std::endl;
	if (points1 > points2)
	{
		std::cout << "Winner of the game is " << player1.getPlayerName() << std::endl;
		player1.setWins(++wins1);
		player2.setLosses(++losses2);
	}
	else
	{
		std::cout << "Winner of the game is " << player2.getPlayerName() << std::endl;
		player2.setWins(++wins2);
		player1.setLosses(++losses1);
	}
	std::ofstream saveData("Stats.txt");
	if (saveData.is_open())
	{
		player1.savePlayer(saveData);
		std::cout << std::endl << std::endl;
		player2.savePlayer(saveData);
	}
	else
		std::cout << "File didn't open!" << std::endl;
	saveData.close();
	return 0;
}