//Zack Hill
//Lab 7 Out
//Flag Game

#include "graph1.h"
#include "menu.h"
#include "configuration.h"
#include <iostream>
#include <string>


using namespace std;

Menu::Menu()
{
	choices = NULL;
	selection = 0;
}


Menu::~Menu()
{
	delete[] choices;
}

//copy constructor
Menu::Menu(const Menu& menu)
{ 
    // Copy configuration
    this->setConfig(menu.config);
    
    // Copy selection
    this->selection = menu.selection;
    
    // Copy contents of this menu's choices to the new choices array 
    choices = new string [config.getNoChoices()];
    for (int i = 0; i < config.getNoChoices(); i++)
    {
        this->choices[i] = menu.choices[i];
    }
}


//Sets config datafield
void Menu::setConfig(Configuration config)
{
    this->config.setNoQuestions(config.getNoQuestions());
    this->config.setNoFlagNames(config.getNoFlagNames());
    this->config.setNoChoices(config.getNoChoices());
    
    for (int i = 0; i < config.getNoFlagNames(); i++)
    {
        this->config.setFlagNameAt(config.getFlagNameAt(i),i);
    }
    
    this->choices = new string[config.getNoChoices()];
    for (int i = 0; i < config.getNoChoices(); i++)
    {
        this->setChoice(i, config.getFlagNameAt(i));  // Initialize each choice string
    }
}


//Sets selection data field from user input
void Menu::setSelection(int selection) 
{
    this->selection = selection;
}


//Sets the value within the choices array   
void Menu::setChoice(int index, string flag_name)
{
    this->choices[index] = flag_name;
}


string Menu::getChoice(int index)
{
    return choices[index];
}


int Menu::getSelection()
{
    return selection;
}


Configuration Menu::getConfig()
{
    return config;
}


int Menu::displayMenu()
{
    int i;
    int yVal = 235;
    int size = this->config.getNoChoices();
      
    gout << setPos(200, 220) << "Choose from the following: " << endg;

    for (i = 0; i < size; i++)
    {
        int boxes = drawRect(200, yVal, 300, 15);
        setColor(boxes, 100, 100, 100);
        gout << setPos(200, yVal+11) << i + 1 << ". " << getChoice(i) << endg;
        yVal += 20;
    }

    gout << setPos(200, yVal + 10) << "Enter your choice on the console" << endg;

    cout << "Enter your answer: ";
    cin >> selection;

    return selection;
}

//Displays the flag within the graphics window.
void Menu::displayFlag(string flag_name)
{
    displayBMP(flag_name + ".bmp", 200, 50);
}

