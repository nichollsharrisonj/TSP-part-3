#include "climb_chromosome.hh"
#include <algorithm>
#include <cassert>

ClimbChromosome::ClimbChromosome(const Cities *){
}
void ClimbChromosome::mutate(){
   //evaluate fitness
   double fitness;
   fitness = get_fitness();
   int best = 0;
   //pick a random point and swap with n-1
   std::uniform_int_distribution<int> dist(0, order_.size() - 1);
   int p = dist(generator_);

   int firstswapindex = p - 1;
   if (p == 0){
       firstswapindex = order_.size() - 1;
   }
   /*
   else {
       int firstswapindex = p - 1;
   }
   */

   //int firstswapindex = (p - 1) % order_.size();     //this gets the p - 1 term and will wraparound if p = 0
   std::swap(order_[p], order_[firstswapindex]);
   if (get_fitness() < fitness){
     best = 1;                                   //save that there's an improvement
     fitness = get_fitness();
   }
   std::swap(order_[p], order_[firstswapindex]);     //switch the cities back so we have an "unchanged" copy still
   //swap with n + 1
   /*
   if (p == order_.size() - 1){
       int swapindex = 0;
   }
   else {
       int swapindex = p + 1;
   }
   */
   int secondswapindex = (p + 1) % order_.size();
   std::swap(order_[p], order_[secondswapindex]);
   if (get_fitness() > fitness){
     std::swap(order_[p], order_[secondswapindex]);     //this last switch is NOT the best, reverse it
    if (best){
      std::swap(order_[p], order_[firstswapindex]);      //first switch was good, go back to that
    }
    }
   //figure out which produced the fittest, and choose it as the resulting chromosome
}
