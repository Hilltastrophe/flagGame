//Zack Hill
//Lab 7 Out
//Flag Game


#include "graph1.h"
#include "menu.h"
#include "game.h"
#include <iostream>
#include <string>
#include <ctime>


using namespace std;
Configuration config;
Menu menu;

Game::Game()
{
	no_correct = 0;
}

//set menu data field
void Game::setMenu(Menu menu)
{
	// Copy the configuration from the menu passed as argument to the menu object in Game
	Configuration config = menu.getConfig();
	this->menu.setConfig(config);

	// Copy the choices from the menu passed as argument to the menu object in Game
	for (int i = 0; i < config.getNoChoices(); i++) 
	{
		string choice = menu.getChoice(i);
		this->menu.setChoice(i, choice);
	}

	// Copy the selection from the menu passed as argument to the menu object in Game
	int selection = menu.getSelection();
	this->menu.setSelection(selection);
}

void setNoCorrect(int no_correct)
{
	no_correct;
}

void setQuestionNo(int question_no)
{
	question_no;
}

void setCorrectAnswer(int* correct_answer)
{
	correct_answer;
}


Menu Game::getMenu()
{
	return menu;
}


int Game::getNoCorrect()
{
	return this->no_correct;
}


int Game::play()
{
	int questions = 0;
	int correct = 0;

	do {


		//get random number for the correct flag
		srand(time(nullptr));
		int correctFlag = rand() % 224;
		int* correctAnswer = new int(correctFlag); //pointer for correct answer

		//variables
		int i = 0;
		int j = 0;
		int answer = 0;
		int randomNum = 0;
		int size = this->menu.getConfig().getNoChoices();
		int* randomChoice = new int[size]; //create the choice array holder
		int* checkArray = new int[size]; //create an array to check against holder
		string* choices = new string[size]; //create the final choices array


		for (int i = 0; i < size; i++)
		{

			// Generate a random number between 0 and 223
			randomNum = rand() % 224;

			// Check if the number already exists in the array
			for (int j = 0; j < i; j++)
			{
				while (checkArray[j] == randomNum || checkArray[j] == correctFlag)
				{
					// If the number is a duplicate, generate a new random number and check again
					randomNum = rand() % 224;
					j = -1; // Start from the beginning of the array
				}
			}

			// Add the non-duplicate number to the placeholder array
			randomChoice[i] = randomNum;

			//assign the name of the flag to the final array
			choices[i] = this->menu.getConfig().getFlagNameAt(randomChoice[i]);
			menu.setChoice(i, choices[i]); //set the choice array
		}

		//get the name of the correct flag
		string flagName = this->menu.getConfig().getFlagNameAt(correctFlag);

		//generate a number within the # of choices
		randomNum = rand() % size;
		choices[randomNum] = flagName; //assign the correct flag to that position


		menu.setChoice(randomNum, choices[randomNum]); //set the correct answer to choice array

		//Keep track of # of questions
		gout << setPos(200, 30) << "Question #" << questions + 1 << endg;
		questions += 1;

		menu.displayFlag(flagName);
		answer = menu.displayMenu();
		


		int yValue = 235 + (size * 20);
		int eraser = drawRect(200, yValue, 300, 20);
		setColor(eraser, 0, 0, 0);

		if (answer == randomNum + 1) //check if answer is = to position of the correct answer
		{
			
			gout << setPos(200, yValue) << endg;
			gout << setPos(200, yValue + 11) << "Correct!" << endg;
			correct += 1;
			setQuestionNo(questions);
			setNoCorrect(correct);
		}
		else
		{
			gout << setPos(200, yValue) << endg;
			gout << setPos(200, yValue + 11) << "Nope, the answer is " << menu.getConfig().getFlagNameAt(correctFlag) << "! " << endg;
			setQuestionNo(questions);
		}

		Sleep(5000);
		clearGraphics();



		delete[] randomChoice;
		delete[] checkArray;
		delete[] choices;
		delete correctAnswer;
		randomChoice = NULL;
		checkArray = NULL;
		choices = NULL;
		correctAnswer = NULL;

	} while (questions < menu.getConfig().getNoQuestions());


	return correct;
}
	

