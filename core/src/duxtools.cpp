#include <iostream>
#include <ctime>
#include "objects/dict.h"

int main() {

	std::cout << "Hello World!" << std::endl;

	clock_t begin = clock();
	dux::Dict dict;
	for (uint i = 0; i < 200000; i++) {
		dict.add(std::string("name")+std::to_string(i), std::string("name")+std::to_string(i));
		dict.add(std::string("namea")+std::to_string(i), i);
		dict.add(std::string("name_name")+std::to_string(i), (i%2) ? true : false);
		std::cout << dict.get<std::string>(std::string("name")+std::to_string(i)) << std::endl;
		dict.get<int>(std::string("namea")+std::to_string(i));
		dict.get<bool>(std::string("name_name")+std::to_string(i));
	}
	
	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

	std::cout << "dux::Dict: " << elapsed_secs << std::endl;

	clock_t begin1 = clock();
	std::map<std::string, std::string> _map;
	std::map<std::string, int> _map1;
	std::map<std::string, bool> _map2;
	for (uint i = 0; i < 200000; i++) {
		_map[std::string("name")+std::to_string(i)] = std::string("name")+std::to_string(i);
		_map1[std::string("namea")+std::to_string(i)] = i;
		_map2[std::string("name_name")+std::to_string(i)] = (i%2) ? true : false;
		_map[std::string("name")+std::to_string(i)];
		_map1[std::string("namea")+std::to_string(i)];
		_map2[std::string("name_name")+std::to_string(i)];
	}
	clock_t end1 = clock();
	double elapsed_secs1 = double(end1 - begin1) / CLOCKS_PER_SEC;

	std::cout << "std::map: " << elapsed_secs1 << std::endl;
	
}
