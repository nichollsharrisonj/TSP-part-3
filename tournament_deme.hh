class TournamentDeme: public Deme {
    public:
    protected:
        virtual ClimbChromosome* select_parent();
    private:
        int parentschosen_ = 8;
}
