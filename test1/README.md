****test1****

Write an algorithm to solve the following problem and pass the test.

**Problem Description**

You are given an integer array nums. Based on this array, Player 1 and Player 2 have designed a game. Player 1 and Player 2 take turns to play their rounds, with Player 1 going first. Initially, both players start with a score of 0. Each turn, a player takes a number from either end of the array (i.e., nums[0] or nums[nums.length - 1]), and the number taken is removed from the array (reducing the array length by 1). The chosen number is added to their score. The game ends when there are no more numbers left in the array to take. Return true if Player 1 can be the winner. If both players end up with the same score, Player 1 is still considered the winner of the game, so return true. You may assume that each player plays to maximize their score.

**Input Format**

The first line contains an integer N representing the length of the array.
The second line contains N integers, separated by spaces.

**Output Format**

Whether Player 1 can be a winner. Output true if they can, otherwise output false.
