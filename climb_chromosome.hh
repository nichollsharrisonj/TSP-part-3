#include "chromosome.hh"

#pragma once

class ClimbChromosome: public Chromosome {
    public:
        virtual Chromosome* clone() const
        {
            return new ClimbChromosome(*this);
        }
        virtual void mutate();


        virtual std::pair<ClimbChromosome*, ClimbChromosome*>
        recombine(const ClimbChromosome* other);
        
        ClimbChromosome(const Cities *);
};
