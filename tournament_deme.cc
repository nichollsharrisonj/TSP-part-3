#include "tournament_deme.hh"

ClimbChromosome* TournamentDeme::select_parent()
{
    //Select P parents at random, where P is a constant power of two that you choose
    int parentstochoose = parentschosen_;
    std::uniform_real_distribution<> dist(0, pop_.size()-1);
    std::vector<int> parentsvector; //A vector holding the indices of the parents to choose
    while (parentstochoose > 0){
        parentstochoose -= 1;
        int p = dist(generator_);
        parentsvector.push_back(p);
      }
    //Take consecutive pairs in the set of Parents
    while (parentsvector.size() > 1){
      for (unsigned long i = 0; i < parentsvector.size(); i++){ //Iterate through every index, after one is deleted
        //Find max of first parent and parent after it
        if (pop_[parentsvector[i]]->get_fitness() < pop_[parentsvector[i+1]]->get_fitness()){
          parentsvector.erase(parentsvector.begin() + i);
        }
        else {
          parentsvector.erase(parentsvector.begin() + i+1);
        }
        //Remove the other parent
      }
    }
    return pop_[parentsvector[0]];
}
