//Zack Hill
//Lab 7 Out
//Flag Game

#include "graph1.h"
#include "configuration.h"
#include <iostream>
#include <string>


Configuration::Configuration()
{
	noChoices = 4;
	noQuestions = 10;
	noFlagNames = 224;
    flagNames = new string [noFlagNames];  //flagNames is dynamically allocated to have 224 elements

}

//takes the array of value and dynamically allocates the array flagNames 
Configuration::Configuration(string* value, int noFlagNames)
{
    flagNames = new string[noFlagNames];

for (int i = 0; i < noFlagNames; i++) 
    {
        this->flagNames[i] = value[i];
    }

    this->noFlagNames = noFlagNames;
}

Configuration::~Configuration()
{
	delete[] flagNames;
    flagNames = NULL;
}


//copy constructor
Configuration::Configuration(const Configuration& config)
{
    
    this->noChoices = config.noChoices;
    this->noQuestions = config.noQuestions;
    this->noFlagNames = config.noFlagNames;

   
    this->flagNames = new string[config.noFlagNames];
    
    for (int i = 0; i < config.noFlagNames; i++) 
    {
        flagNames[i] = config.flagNames[i];
    }

}


//Returns false if no_choices is out of range.
//Clips the value to 2 or 6 if no_choices is out of range.
bool Configuration::setNoChoices(int no_choices)
{
    bool valid = false;
  
    if (no_choices < 2)
    {
        this->noChoices = 2;
    }
    else if (no_choices > 6)
    {
        this->noChoices = 6;
    }
    else
    {
        this->noChoices = no_choices;
        valid = true;
    }

    return valid;
}


//Returns false if no_questions is out of range.
//Clips the value to 3 or 20 if no_questions is out of range.
bool Configuration::setNoQuestions(int no_questions)
{
    bool valid = false;
    
    if (no_questions < 3)
    {
        this->noQuestions = 3;
    }
    else if (no_questions > 20)
    {
        this->noQuestions = 20;
    }
    else
    {
        this->noQuestions = no_questions;
        valid = true;
    }

    return valid;
}

void Configuration::setFlagNameAt(string flagName, int position)
{
    /*
    Sets the element within the flagNames array of strings at the subscript 
    indicated by position with the value indicated by flagName.
    */

    if (position >= 0 && position <= noFlagNames)
    {
        this->flagNames[position] = flagName;
    }    
}

string* Configuration::getAllFlagNames()
{
    return flagNames;
}

// Clips the value to 5 or 224 if noFlagNames is out of range.
void Configuration::setNoFlagNames(int noFlagNames)
{
    if (noFlagNames < 5)
    {
        this->noFlagNames = 5;
    }
    else if (noFlagNames > 224)
    {
        this->noFlagNames = 224;
    }
    else
    {
        this->noFlagNames = noFlagNames;
    }
}

//Returns the flagName(i.e., country) at the subscript indicated by index.
string Configuration::getFlagNameAt(int index)
{
    return flagNames[index];
}


int Configuration::getNoChoices()
{
    return noChoices;
}


int Configuration::getNoQuestions()
{
    return noQuestions;
}


int Configuration::getNoFlagNames()
{
    return noFlagNames;
}




