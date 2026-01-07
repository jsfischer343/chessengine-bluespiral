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
    std::chrono::time_point<std::chrono::steady_clock> treeGenStartTime;
    std::chrono::milliseconds duration;
    PositionTree* positionTree;
    bool tempBool;

    positionTree = new PositionTree("1kq5/p1p4p/1pn5/4r3/7P/1P1Q4/PBP5/1K5R w - - 0 1",1);
    treeGenStartTime = std::chrono::steady_clock::now();
    while(positionTree->expandNextBestBranchDeep());
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - treeGenStartTime);
    std::cout << "Tree Gen using expandNextBestBranchDeep() " << duration.count() << " ms\n";
    delete positionTree;

    positionTree = new PositionTree("1kq5/p1p4p/1pn5/4r3/7P/1P1Q4/PBP5/1K5R w - - 0 1",1);
    treeGenStartTime = std::chrono::steady_clock::now();
    while(positionTree->expandNextBestBranchWide());
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - treeGenStartTime);
    std::cout << "Tree Gen using expandNextBestBranchWide() " << duration.count() << " ms\n";
    delete positionTree;

    // positionTree = new PositionTree("1kq5/p1p4p/1pn5/4r3/7P/1P1Q4/PBP5/1K5R w - - 0 1",1);
    // treeGenStartTime = std::chrono::steady_clock::now();
    // while(positionTree->expandNextBestBranchRecursiveAvgDeep());
    // duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - treeGenStartTime);
    // std::cout << "Tree Gen using expandNextBestBranchRecursiveAvgDeep() " << duration.count() << " ms\n";
    // delete positionTree;

    positionTree = new PositionTree("1kq5/p1p4p/1pn5/4r3/7P/1P1Q4/PBP5/1K5R w - - 0 1",1);
    treeGenStartTime = std::chrono::steady_clock::now();
    tempBool = true;
    while(tempBool)
    {
        if(!positionTree->expandNextCheckDeep())
        {
            tempBool = positionTree->expandNextBestBranchDeep();
        }
    }
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - treeGenStartTime);
    std::cout << "Tree Gen using expandNextCheckDeep() " << duration.count() << " ms\n";
    delete positionTree;

    positionTree = new PositionTree("1kq5/p1p4p/1pn5/4r3/7P/1P1Q4/PBP5/1K5R w - - 0 1",1);
    treeGenStartTime = std::chrono::steady_clock::now();
    tempBool = true;
    while(tempBool)
    {
        if(!positionTree->expandNextCheckWide())
        {
            tempBool = positionTree->expandNextBestBranchWide();
        }
    }
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - treeGenStartTime);
    std::cout << "Tree Gen using expandNextCheckWide() " << duration.count() << " ms\n";
    delete positionTree;

    positionTree = new PositionTree("1kq5/p1p4p/1pn5/4r3/7P/1P1Q4/PBP5/1K5R w - - 0 1",1);
    treeGenStartTime = std::chrono::steady_clock::now();
    tempBool = true;
    while(tempBool)
    {
        if(!positionTree->expandNextCaptureDeep())
        {
            tempBool = positionTree->expandNextBestBranchDeep();
        }
    }
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - treeGenStartTime);
    std::cout << "Tree Gen using expandNextCaptureDeep() " << duration.count() << " ms\n";
    delete positionTree;

    positionTree = new PositionTree("1kq5/p1p4p/1pn5/4r3/7P/1P1Q4/PBP5/1K5R w - - 0 1",1);
    treeGenStartTime = std::chrono::steady_clock::now();
    tempBool = true;
    while(tempBool)
    {
        if(!positionTree->expandNextCaptureWide())
        {
            tempBool = positionTree->expandNextBestBranchWide();
        }
    }
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - treeGenStartTime);
    std::cout << "Tree Gen using expandNextCaptureWide() " << duration.count() << " ms\n";
    delete positionTree;
	return 0;
}
