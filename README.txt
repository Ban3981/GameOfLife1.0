-This is famous game of English mathematician John Conway.
-It simulates development of one population.
-Life-space is a matrix of cells,and torus topology is used(first and last column are neighbours,first and last row are neighbours,all cells in cornes are also neighbours).
-Every cell can be empty or populated with exactly one alive individual.-
-Every cell has 8 neighbour cells
-Individuals are neighbours if they live in neighbour cells.
-The following rules are applied:
1-birth rule: a new individual is born in an empty cell if it has exactly three neighbors individuals
2-rule of survival: an individual survives if it has two or three neighboring individuals
3-rule of immobility: an individual spends its entire life in the same cell;
4-rule of dying: an individual dies if it has more than three neighboring individuals (due to overpopulation) or less than two neighboring individuals (due to loneliness);
5-the application of rules to a cell or unit does not affect the application of rules to adjacent ones cells and individuals,
all rules are applied simultaneously for all individuals and cells of one configuration and as a result give a new generation
-You can generate some random configuration,or enter some generation in input file from where it will be read;after this you choose how many generatons will be calculate;at end,
these generations are written in output file.