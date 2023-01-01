# ModernBurnHandSimulator

A simulator that calculates the percentage of keepable hands with Modern Burn, as well as how likely you are to flood with said keeps. This is done from the statistical point of view, namely, the code runs through X number of initial draws and evaluates them as keeps/mulls based on a set of rules. Currently, the number of repetitions is adjustable through the `config.ini` file.

To run, as of right now, simply run `make build` followed by `make run`. 
