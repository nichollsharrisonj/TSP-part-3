#include "tournament_deme.hh"
ClimbChromosome* TournamentDeme::select_parent()
{
    //Select P parents at random, where P is a constant power of two that you choose
    int parentstochoose = parentschosen_;
    std::uniform_real_distribution<int> dist(0, order_.size()-1);
    std::vector<int> parentsvector; //A vector holding the indices of the parents to choose
    while (parentstochoose > 0){
        parentstochoose -= 1;
        int p = dist(generator_);
        parentsvector.pushback(p);
    //Take consecutive pairs in the set of Parents
    for (int i = 0; i < parentsvector.size(); i = i + 2){ //Iterate through every other index
      //Find max of first parent and parent after it
      if (pop_[i] < pop_[i+1]){
        pop_.erase(i);
      }
      else {
        pop_.erase(i+1);
      }
      //Remove the other parent
    }
}
