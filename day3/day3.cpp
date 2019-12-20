// AdventOfCode_Day3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <algorithm>
#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <sstream>
#include <utility>
#include <vector>

void increment(char dir, int* x, int* y) {
	if (dir == 'R') {
		int v = *x + 1;
		*x = v;
	}
	else if (dir == 'L') {
		int v = *x -1;
		*x = v;
	}
	else if (dir == 'U') {
		int v = *y + 1;
		*y = v;
	}
	else if (dir == 'D') {
		int v = *y - 1;
		*y = v;
	}
}


void stringToPoints(std::string& line, std::vector < std::pair<int, int>>& points)
{
	line.erase(std::remove_if(line.begin(), line .end(), isspace), line.end());
	std::stringstream l1(line);
	


	std::string point;
	int x = 0;
	int y = 0;
	while (std::getline(l1, point, ',')) {
		char dir = point[0];
		int val = atoi(point.substr(1, point.size()).c_str());

		for (int i = 0; i < val; i++) {
			increment(dir, &x, &y);
			points.push_back(std::make_pair(x, y));
		}
	}


}

struct Printer {
	
	std::ostream& o;
	Printer(std::ostream& o) : o(o) {}
	void operator()(std::pair<int, int>& i) {
		o << "(" << i.first << "," << i.second << ")";
	}

};


std::pair<std::string, std::string> lines(std::istream& file) {

	std::string l1, l2;
	
	std::getline(file, l1);
	std::getline(file, l2);

	return std::make_pair(l1, l2);
}

int cost(const std::pair<int, int>& v, std::vector<std::pair<int, int>>& vec)
{
	auto pos = std::find(vec.begin(), vec.end(), v);
	if (pos != vec.end()) {


		return std::distance(vec.begin(), pos);
	}
	else {
		return INT_MAX;
	}
	
}

int main()
{
	
	std::ifstream file("input.txt");
	std::pair<std::string, std::string> p = lines(file);

	std::string line1 = "R75,D30,R83,U83,L12,D49,R71,U7,L72";
	std::string line2 = "U62, R66, U55, R34,D71,R55,D58,R83";
	int expected = 159;

	//std::string line1 = "R8,U5,L5,D3";
	//std::string line2 = "U7,R6,D4,L4";

	//std::string line1 = "R98,U47,R26,D63,R33,U87,L62,D20,R33,U53,R51";
	//std::string line2 = "U98,R91,D20,R16,D67,R40,U7,R15,U6,R7";
	//int expected = 135

	



	std::vector<std::pair<int, int>> lineOnePoints = { std::make_pair(0,0) };
	std::vector<std::pair<int, int>> lineTwoPoints = { std::make_pair(0,0) };
	std::vector<std::pair<int, int>> matches = {};

	stringToPoints(p.first, lineOnePoints);
	stringToPoints(p.second, lineTwoPoints);


//	std::for_each(lineOnePoints.begin(), lineOnePoints.end(), Printer(std::cout));

	std::vector<std::pair<int, int>> lineOnePointsSorted;
	std::copy(lineOnePoints.begin(), lineOnePoints.end(), std::back_inserter(lineOnePointsSorted));


	std::vector<std::pair<int, int>> lineTwoPointsSorted;
	std::copy(lineTwoPoints.begin(), lineTwoPoints.end(), std::back_inserter(lineTwoPointsSorted));


	std::sort(lineOnePointsSorted.begin(), lineOnePointsSorted.end());
	std::sort(lineTwoPointsSorted.begin(), lineTwoPointsSorted.end());

	std::set_intersection(std::begin(lineOnePointsSorted), std::end(lineOnePointsSorted)
		, std::begin(lineTwoPointsSorted), std::end(lineTwoPointsSorted)
		, std::back_inserter(matches));

	int min_dist_val = INT_MAX;
	int min_cost = INT_MAX;
	std::cout << "matches = " << matches.size() << "\n";

	for (auto& x : matches) {
	//	Printer p(std::cout);
	//	p(x);
		if (x.first == 0 && x.second == 0) {

		}
		else {

			int cost_ = cost(x, lineOnePoints) + cost(x, lineTwoPoints);
			if (cost_ < min_cost) {
				min_cost = cost_;
			}
			std::cout << cost_ << "\n";

			int man_dist = std::abs(x.first) + std::abs(x.second);
			if (man_dist < min_dist_val) {
				min_dist_val = man_dist;
			}
		}
	}
	
	std::cout << "\nDist = " << min_dist_val << "\n";
	std::cout << "Cost = " << min_cost << "\n";


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
