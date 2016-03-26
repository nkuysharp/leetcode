# description

Given an unsorted array of integers, find the length of LIS(longest increasing subsequence).

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?


# algorithm

Let S = x[1], x[2], ..., x[n]

we maintain a table T which initially has T[1] = x[1]. Then as j proceeds from 2 until n, we insert x[j] into
T as follows:

Assuming T[k] is the last element of T. We compare x[j] with T[k], if x[j] > T[k], we set T[k+1]=x[j]. Otherwise we
find the least index m >=1 such that x[j]<=T[m] and we set T[m] = x[j].

After all elements of S have been processed, the length of T is the length of LIS. 

# prove

我们来证明这个命题：
当处理完 x[1],x[2],...x[j] 的时候
T[k] 是 { x[1], x[2], ..., x[j] } 中长度为k 的所有LIS中，最小的结尾元素。

用科学证明法。
j = 1 的时候, T[1] = x[1], 不言自明。

假定T[k]对 {x[1], ..., x[j]} 都成立。

处理到 x[j+1] 时，分两种情况：

1. x[j+1] > T[k]；此时LIS 的长度为k, 说明x[j+1] 构成了第一个长度为k+1的LIS的结尾元素。
2. T[m-1]< x[j+1] <= T[m], (1<= m<= k)；T[m-1]说明存在一个长度是m-1的LIS, 用这个LIS 加上 x[j+1]，可以构成一个长度是m的LIS, 且它的尾元素<T[m]. 那么算法把T[m]更新为x[j+1]。

可见算法能够维持命题的一致性。


# references
Michael L. Fredman.On computing the length of longest increasing subsequences.1975


