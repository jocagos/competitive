# Philaland Coin

## Problem Description

The problem solvers have found a new island for coding and named it as Philaland.

These smart people were given a task to make purchase of the items at the island easier by distributing various coins with different value.

Manish has come up with a solution that, if we make the coins categories starting from $1 till the maximum price of the item present on the Island, then we can purchase any item easily. He added the following example to prove his point.

Let's suppose the maximum price of an item is $5, then we can make coins with denominations {$1, $2, $3, $4, $5} to purchase any item ranging from $1 till $5.

Now, Manisha being a keen observer suggested that we could actually minimize the number of coins required and gave the following distribution: {$1, $2, $3}. According to him, any item can be purchased one time ranging from $1 to $5. Everyone was impressed with both solutions.

Your task is to help Manisha come up with the minimum number of different denominations for any arbitrary maximum price in Philaland.

## Constraints

* 1 <= T <= 100
* 1 <= N <= 5000

## Input

First line contains an integer T denoting the number of test cases

Next T lines contain an integer N denoting the maximum price of an item in Philaland

## Output

For each test case, print a single line denoting the minimum number of different coin denominations required for every price from 1 to N

## Timeout

1 second

## Examples

### Input

2
10
5

### Output

4
3

### Explanation

* For the first test case, N = 10, according to Manish we can distribute the coins in {$1, $2, $3, $4}. But also in {$1, $2, $3, $5}. Hence, as both sets have the same number of denominations, the answer is 4.

* For the second test case, N = 5, according to Manish we can distribute the coins in {$1, $2, $3}, but also in {$1, $2, $4}. Hence, as both sets have the same number of denominations, the answer is 3.
