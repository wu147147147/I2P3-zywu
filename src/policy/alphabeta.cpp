#include <cstdlib>

#include "../state/state.hpp"
#include "./alphabeta.hpp"
#include <climits>


 /// @brief 
 /// @param state 
 /// @param depth 
 /// @return 
 int me;
 Move Alphabeta::get_move(State* state, int depth){

    if (!state->legal_actions.size())
        state->get_legal_actions();
    Move ans;
    int value = INT_MIN;
    int temp;
    me = state->player;
    for (auto actions : state->legal_actions) {
        if (value < (temp = alphabeta(state->next_state(actions), depth, INT_MIN, INT_MAX, 1 - me))) {
            value = temp;
            ans = actions;
        }

    }
    
    return ans;
}

int Alphabeta::alphabeta(State* state, int depth, int alpha,int beta, int maximizingPlayer) {
   
    if(depth==0) return  (maximizingPlayer == me)?state->evaluate():-state->evaluate();
    state->get_legal_actions();
    if (state->legal_actions.empty()) {
        return (maximizingPlayer == me)?state->evaluate():-state->evaluate();
    }
    int value;
    if (maximizingPlayer == me) {
        value = INT_MIN;
        for (auto next : state->legal_actions) {
            value = std::max(value,alphabeta(state->next_state(next), depth - 1, alpha, beta, 1- maximizingPlayer));
            alpha = std::max(alpha, value);
            if(beta<=alpha) break;
        }
        return value;
    }
    else {
        value = INT_MAX;
        for (auto next : state->legal_actions) {
            value = std::min(value,alphabeta(state->next_state(next), depth - 1, alpha, beta, 1 - maximizingPlayer));
            beta = std::min(beta, value);
            if(beta<=alpha) break;
        }
        return value;
    }
}