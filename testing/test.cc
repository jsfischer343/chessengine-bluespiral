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
#include "../src/global.hh"
#include "../src/position.hh"
#include "../src/positiontree.hh"
#include "../src/uci.hh"
#include "../src/cli.hh"

int main()
{
    PositionTree* positionTree = new PositionTree("4k3/3p4/8/8/8/8/3P4/2K5 w - - 0 1",1);
    positionTree->printPositionTree();
    positionTree->expandNextBestBranchDeep();
    printf("~~~~~~~~~~~~~~\n");
    positionTree->printPositionTree();
    positionTree->expandNextBestBranchDeep();
    printf("~~~~~~~~~~~~~~\n");
    positionTree->printPositionTree();
    positionTree->expandNextBestBranchDeep();
    printf("~~~~~~~~~~~~~~\n");
    positionTree->printPositionTree();
    positionTree->expandNextBestBranchDeep();
    printf("~~~~~~~~~~~~~~\n");
    positionTree->printPositionTree();
    delete positionTree;
	return 0;
}
