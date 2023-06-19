#pragma once
#include "../state/state.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <utility>

/// @brief 


/**
 * @brief Policy class for random policy,
 * your policy class should have get_move method
 */

class Minimax{
public:
	
	static Move get_move(State* state, int depth);
	static int minimax(State* state, int, int);
	
};
