***test2***

***problem describe***

Xiao, a hamster, is an ordinary student at Wuhan Hamster University (WHU). Although currently serving as the controller of the new student race at WHU, Xiao, steady as an old dog, has run off to the neighboring Wuhan University to climb Luojiashan Mountain. 

After overcoming numerous difficulties, Xiao finally reaches the top of Luojiashan Mountain and now needs to find a way down. There are n footholds on the slope down the mountain, connected by m downhill paths, with the 1st foothold definitely being the mountaintop. Xiao will certainly take the downhill paths when descending, and it's obvious that only taking downhill paths won't lead to a loop. The scenery on Luojiashan is picturesque, even the paths down have their unique beauty. Each foothold has its own aesthetic value, but since some footholds might be dangerous (like encountering a snake), this aesthetic value could also be negative. Xiao wishes to find a downhill path starting from the top that maximizes the sum of aesthetic values of all the points passed (including the mountaintop). Note that Xiao doesn't necessarily need to reach the mountain's base. If Xiao decides not to enjoy the scenery any further, it will directly call wk for a ride down the mountain.

***Input***

The first line includes two integers n and m, representing the number of footholds and the number of mountain slopes respectively.
(1≤n≤105,1≤m≤105).
The second line includes n integers (a1, a2, ... an), representing the aesthetic values of each point.
(-109≤ai≤109, (1≤i≤n)).
The next m lines, each with two integers a, b; (1≤i≤m,1≤a, b≤n) represent a downhill path from a to b.

***Output***

Output an integer representing the maximum sum of point values.

***Example***

【Sample Input】

5 4

1 2 3 4 5

1 3

3 4

4 2

2 5

【Sample Output】

15

【Sample Explanation】

For the sample, the answer is the sequence 1->3->4->2->5, outputting 1+2+3+4+5=15.
