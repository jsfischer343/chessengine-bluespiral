/*
	Bluespiral, a simple open source chess engine
	Copyright (C) 2025 John Fischer

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include <iostream>
#include <chrono>
#include "global.hh"
#include "position.hh"
#include "positiontree.hh"
#include "uci.hh"
#include "cli.hh"


void printWelcomeText()
{
	std::cout << "Bluespiral Chess Engine, Version " << GLOBAL_BLUESPIRAL_VERSION << ", 2025, " << "\n";
	std::cout << GLOBAL_LICENSE_STATEMENT << std::endl;
	return;
}

int main()
{
	//debug
	// PositionTree* debugPT = new PositionTree("6k1/8/4q3/8/1Q6/8/8/5K2 w - - 0 1",1);
 //    for(int i=0;i<15;i++)
 //    {
 //        debugPT->printPositionTree(3);
 //        debugPT->printTreeInfo();
 //        if(!debugPT->expandNextCheckDeep())
 //        {
 //            debugPT->expandNextBestBranchDeep();
 //        }
 //    }
 //    debugPT->printPositionTree(3);
 //    debugPT->printTreeInfo();
    // Position* debugPosition = debugPT->getCurrentPosition();
    // debugPosition->printBoard();
    // debugPosition->printInfo();
    // debugPosition->printInstantEvalBreakdown();

	printWelcomeText();
	std::string userInput;
	CLI bluespiralCLI;
	do {
		getline(std::cin, userInput);
		bluespiralCLI.parseCommand(userInput);
	} while(userInput!="exit" && userInput!="quit");
	return 0;
}
