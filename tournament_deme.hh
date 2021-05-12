#include "cities.hh"
#include "deme.hh"
#include "climb_chromosome.hh"
#include <vector>

#pragma once

class TournamentDeme: public Deme {
    public:
      TournamentDeme(const Cities* cities_ptr, unsigned pop_size, double mut_rate)
      : Deme(cities_ptr, pop_size, mut_rate)
      {}
    protected:
        virtual ClimbChromosome* select_parent();
    private:
        const int parentschosen_ = 32;
};
