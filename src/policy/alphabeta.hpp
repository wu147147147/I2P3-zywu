#pragma once
#include "../state/state.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <utility>
/**
 * @brief Policy class for random policy,
 * your policy class should have get_move method
 */
class Alphabeta{
public:
	static Move get_move(State* state, int depth);
	static int alphabeta(State* state, int, int, int, int);
	
};
