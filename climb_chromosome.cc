#include "climb_chromosome.hh"
#include <algorithm>
#include <cassert>


ClimbChromosome::mutate(){
   //evaluate fitness
   double fitness;
   fitness = get_fitness();
   //pick a random point and swap with n-1
   std::uniform_int_distribution<int> dist(0, order_.size() - 1);
   int p = dist(generator_);
   if (p == 0){
       int swapindex = order_.size() - 1;
   }
   else {
       int swapindex = p - 1;
   }
   std::swap(order_[p], order_[swapindex];
   //swap with n + 1
   if (p == order_.size() - 1){
       int swapindex = 0;
   }
   else {
       int swapindex = p + 1;
   }
   std::swap(order_[p], order_[swapindex];

   //figure out which produced the fittest, and choose it as the resulting chromosome
}
