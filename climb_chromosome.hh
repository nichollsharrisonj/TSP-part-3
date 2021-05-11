class ClimbChromosome: public Chromosome {
    public:
        virtual Chromosome* clone() const
        {
            return new Chromosome(*this);
        }
        virtual void mutate();

}
