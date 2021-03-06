# Amazon Coding Challenge
### Bright Network Internship, June 2022
## Overview 
Implement Amazon’s pathfinding algorithm for Amazon’s self-driving delivery vehicles. The self-driving vehicle will need to create a path on a 2D-grid that contains a starting point (x,y), a delivery point (x,y) and a number of obstacles. Your vehicle can navigate to any of the adjacent squares (even diagonally), as long as the squares are inbound and do not contain an obstacle.

## General Notes: 
You can use any language and ideally the output is to a command line.
<p align="center">
  <img src="image.JPG" width="650" height="350" />
</p>

## Phase 1:
Implement a 10x10 grid that contains a starting point on (0,0), the delivery point on (9,9) and the following obstacles on (9,7) (8,7) (6,7) (6,8).

Algorithm should calculate a valid path avoiding the obstacles and reaching the delivery point.

Solution should print the path in the format of:

[(x1,y2), (x2,y2), ...] and also the number of steps.

## Phase 2:
Add an additional 20 randomly placed obstacles and print their location using the format [(x1,y1), (x2,y2), ...]. The obstacles should not overlap the existing ones and should not be placed on the start and delivery points.

Algorithm should calculate a valid path avoiding the obstacles and reaching the delivery point.

Solution should print the path in the format of:

[(x1,y2), (x2,y2), ...]

## Bonus:
In the event that your vehicle is unable to reach its destination, the algorithm should print "Unable to reach delivery point" and identify which obstacles to be removed in order for the vehicle to reach its destination.

The algorithm should suggest the least amount of obstacles using the format [(x1,y1), (x2,y2), ...] in order for your vehicle to reach the destination.

## References
Basic BFS Search between two nodes: https://www.geeksforgeeks.org/shortest-distance-two-cells-matrix-grid/

Why BFS: https://stackoverflow.com/questions/54063691/whats-the-best-pathfinding-algorithm-in-complexity

Queue STL: https://www.programiz.com/cpp-programming/queue

rand() in C++: https://cplusplus.com/reference/cstdlib/srand/

Random number not random using rand(): https://stackoverflow.com/questions/28656004/c-random-doesnt-workreturns-same-value-always#:~:text=The%20rand()%20function%20does,that%20sequence%20using%20srand()%20

srand() in C++: https://cplusplus.com/reference/cstdlib/rand/
