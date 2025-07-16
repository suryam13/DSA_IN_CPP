/*
SHORTEST PATH INTUTIONS :

-> If the graph is weighted or the cost of moving from one place to another takes uniform time then apply simple bfs which uses visited array and queue
Because in such a case all the edges are uniform and bfs gives us the chance to move to nearest edge first,so we will take that and mark it as visited and consider that path was the minimalist


->If the graph is weighted and has different weights all across so in such a condition we have to be greedy so we will apply dijkstra's algo, here normal bfs + visited will not work because suppose if i go from a vertex A to another vertex B so here i would be marking B as visited but the cost of coming was 3 and surely i had another path from A to C to B which had total cost 2 but since now B is marked i wont be able to go to B via C in the next iteration and end up losing the minimum cost.
NOTE : BFS + Visited qont work in dijkstra's logic if we implement with queue wihtout visisted vector then even that would yield the right answer but would be suffering with some extra steps or iterations.

Dijkstra's has two variations either it can be applied on matrix or either on regular graph with adjacency list.







*/