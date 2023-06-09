//Zack Hill
//Lab 7 Out
//Flag Game

#include "graph1.h"
#include "game.h"
#include <iostream>
#include <string>


using namespace std;


int main()
{
	char again = 'n';

	do
	{
		string names[] = { "Afghanistan", "Albania", "Algeria", "American_Samoa", "Andorra", "Angola", "Anguilla",
			"Antigua_and_Barbuda", "Argentina","Armenia", "Aruba","Australia", "Austria","Azerbaijan",
			"Bahamas", "Bahrain", "Bangladesh", "Barbados", "Belarus", "Belgium", "Belize", "Benin",
			"Bermuda", "Bhutan", "Bolivia", "Bosnia", "Botswana", "Brazil", "British_Virgin_Islands",
			"Brunei", "Bulgaria", "Burkina_Faso", "Burundi", "Cambodia", "Cameroon", "Canada", "Cape_Verde","Cayman_Islands", "Central_African_Republic", "Chad", "Chile", "China","Christmas_Island",
			"Colombia","Comoros","Cook_Islands","Costa_Rica","Croatia","Cuba","Cyprus","Cyprus_Northern",
			"Czech_Republic","Cte_dIvoire","Democratic_Republic_of_the_Congo","Denmark","Djibouti","Dominica",
			"Dominican_Republic","Ecuador","Egypt","El_Salvador","Equatorial_Guinea","Eritrea","Estonia",
			"Ethiopia","Falkland_Islands","Faroe_Islands","Fiji","Finland","France","French_Polynesia",
			"Gabon","Gambia","Georgia","Germany","Ghana","Gibraltar","Greece","Greenland","Grenada",
			"Guam","Guatemala","Guinea","Guinea_Bissau","Guyana","Haiti","Honduras","Hong_Kong","Hungary",
			"Iceland", "India","Indonesia","Iran","Iraq", "Ireland","Israel","Italy","Jamaica","Japan",
			"Jordan", "Kazakhstan","Kenya","Kiribati","Kuwait","Kyrgyzstan","Laos","Latvia","Lebanon",
			"Lesotho","Liberia","Libya","Liechtenstein","Lithuania","Luxembourg","Macao","Macedonia",
			"Madagascar","Malawi","Malaysia","Maldives","Mali","Malta","Marshall_Islands","Martinique",
			"Mauritania","Mauritius","Mexico","Micronesia","Moldova","Monaco","Mongolia","Montserrat",
			"Morocco","Mozambique","Myanmar","Namibia","Nauru","Nepal","Netherlands","Netherlands_Antilles",
			"New_Zealand", "Nicaragua","Niger","Nigeria","Niue","Norfolk_Island","North_Korea","Norway",
			"Oman","Pakistan","Palau","Panama","Papua_New_Guinea","Paraguay","Peru","Philippines",
			"Pitcairn_Islands","Poland","Portugal","Puerto_Rico","Qatar","Republic_of_the_Congo","Romania",
			"Russian_Federation","Rwanda","Saint_Kitts_and_Nevis","Saint_Lucia","Saint_Pierre","Saint_Vicent_and_the_Grenadines",
			"Samoa","San_Marino","Sao_Tom�_and_Prncipe","Saudi_Arabia","Senegal","Serbia_and_Montenegro",
			"Seychelles", "Sierra_Leone", "Singapore","Slovakia","Slovenia","Soloman_Islands","Somalia",
			"South_Africa","South_Georgia","South_Korea","Soviet_Union","Spain","Sri_Lanka","Sudan","Suriname",
			"Swaziland","Sweden","Switzerland","Syria", "Taiwan","Tajikistan","Tanzania","Thailand",
			"Tibet", "Timor-Leste", "Togo","Tonga","Trinidad_and_Tobago","Tunisia", "Turkey","Turkmenistan",
			"Turks_and_Caicos_Islands", "Tuvalu","UAE","Uganda","Ukraine","United_Kingdom","United_States_of_America",
			"Uruguay","US_Virgin_Islands","Uzbekistan","Vanuatu","Vatican_City","Venezuela","Vietnam",
			"Wallis_and_Futuna","Yemen","Zambia","Zimbabwe" };

	

		Configuration config(names, 224);

		double noQuestions = 0.0;
		int noChoices = 0;
		int answer = 0;
		double result = 0.0;
		double numCorrect = 0.0;
		
		cout << "This quiz is on current and historic flags from around the world.\n";
		cout << "Enter # of questions for the quiz: (3 to 20) ";

		cin >> noQuestions;
		config.setNoQuestions(noQuestions);


		cout << "\nEnter # of choices per question: (2 to 6) ";
		cin >> noChoices;
		config.setNoChoices(noChoices);

		displayGraphics();

		Menu menu;
		menu.setConfig(config);

		Game game;
		game.setMenu(menu);
		numCorrect = game.play();

		//get the average score
		result = (numCorrect / noQuestions) * 100;


		gout << setPos(200, 220) << "Quiz Over" << endg;
		gout << setPos(200, 240) << "Your Percentage: " << result << endg;

		cout << "Would you like to take the quiz again? (y/n)";
		cin >> again;

		if (again == 'y' || again == 'Y')
		{
			clearGraphics(); //clear graphics
			system("cls"); //clear console
		}

		
	} while (again == 'y' || again == 'Y');

	clearGraphics();

	
}
