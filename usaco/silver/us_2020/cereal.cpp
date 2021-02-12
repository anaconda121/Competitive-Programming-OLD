/*
LOGIC
Simulating this cereal grabbing would be O(N^2), too slow
Instead, we can "simulate" the grabbing from the back in O(N) time

Sample Case:
Cow 4 will get cereal #1
Cow 3 first priority is #1, but since the normal simulation will start from Cow 1, Cow 4 will get kicked out
We now go to Cow 4's second priority is #2, Cow 4 will now get cereal #2
Cow 2's first priority is #1, so it will kick out Cow 3
Cow 3's second priority is #2, so it will Cow 4
Cow 1's first priority is #1, so it will kick out Cow 2
Cow 2's second priority is #2, so it will check out Cow 3

1 2 3 4
1 2 _ _
*/
