### Traveling Salesperson Part 3

#### Harrison Nicholls and Lucas Hamilton

##### Building our project
- Run `make` in our repository to compile our project
##### Override Mutation
- The overwritten mutation method uses local hill climbing to find improved Chromosomes
- first it picks a point at random using a generator
  - using this point, it checks if a switch between the selected city and the city before or after it changes the fitness of the chromosome
  - if either of the changes are helpful (ie a higher fitness), this version of the chromosome is saved
  - if the changes are not helpful, no changes are made to the chromosome
- this is all done inside of `ClimbChromosome` which inherits from `Chromosome`
  - this means everything about `ClimbChromosome` and `Chromosome` is the same except for the overwritten mutation method


##### Override Selection to use Tournament Selection
- To select the random parents, we used a vector called `parentsvector`, which stores the indices of the parents.
  - we used `std::uniform_real_distribution` to generate random indices within the range of the size of the population.
- We compared the pairs of parents by iterating through the parentsvector, deleting the less fit of each pair of parents.


##### Data Collection
- All of the data sets were made using a population size of `10,000` and a mutation rate of 10%
