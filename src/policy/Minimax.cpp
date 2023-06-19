#include <cstdlib>
#include "../state/state.hpp"
#include "./Minimax.hpp"
#include <climits>

int true_player;

Move Minimax::get_move(State* state, int depth) {
    if (!state->legal_actions.size())
        state->get_legal_actions();
    Move ans;
    int value = INT_MIN;
    int temp;
    true_player = state->player;
    for (auto action : state->legal_actions) {
        if (value < (temp = minimax(state->next_state(action), depth, 1 - true_player))) {
            value = temp;
            ans = action;
        }
    }
    return ans;
}

int Minimax::minimax(State* state, int depth, int maximizingPlayer) {
    if (depth == 0) {
        return (state->player==true_player) ?state->evaluate():-state->evaluate();
    }
    state->get_legal_actions();
    if (state->legal_actions.empty()) {
        return (state->player==true_player) ?state->evaluate():-state->evaluate();
    }
    int value;
    if (maximizingPlayer == true_player) {
        value = INT_MIN;
        for (auto next : state->legal_actions) {
            value = std::max(value, minimax(state->next_state(next), depth - 1, 1 - maximizingPlayer));
        }
        return value;
    } else {
        value = INT_MAX;
        for (auto next : state->legal_actions) {
            value = std::min(value, minimax(state->next_state(next), depth - 1, 1 - maximizingPlayer));
        }
        return value;
    }
}
