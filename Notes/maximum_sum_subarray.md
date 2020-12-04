# Maximum Sum in a subarray.

so I have created solution for max-subarray problem mutlitple times.

See there are five files

1. max\_subarray\_again.cpp
2. max\_subarray\_take1.cpp
3. max\_subarray\_take2\_recursive.cpp
4. max\_subarray\_copy.cpp
5. maximum_subarray.cpp

so out of these five ones, the first one is the most recent and has

    Time Complexity: O(n)
    Space Complexity: O(1)

the first one is a very simple algorithm and follows this ideology-

    It keeps storing the value in curr and if it overtakes the value of max, max becomes equal to it.
    If any point of time curr becomes negative, it means that there is no use of continue.
    The previous subarray will always constitute a negative value for upcoming subarrays.
    So we make curr = 0, in that case.

The second file is similar to the first one. the only difference is that it also prints the index correspind to that sub array.

The third file is a recursive take on subarray. It is very similar to how merge algorithm works.

The fourth file I guess is I copied from someone profile on GeeksForGeeks.

The fifth file contains the code as I thought should be while learning the algorithm first time from CORS book.
