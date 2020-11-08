# Television Sets

## Problem Description

Dr. Vishnu is opening a new world class hospital in a small town designed to be the first preference of the patients in the city. Hospital has N rooms of two types -with TV and without TV- and two daily rates:R1 for rooms with TV and R2 for rooms without TV.

However, from his experience, Dr. Vishnu knows that the number of patients is not constant throughout the year, instead it follows a pattern. The number of patients on any given day of they year is given by the following formula

>(6 - M)^2 + |D - 15|

where M is the number of the month, from 1 to 12, and D is the number of the day, from 1 to 31.

Assuming all patients prefer a room without a TV as they are cheaper, but will opt for a room with a TV if there is no other room available, the Hospital has a revenue target R for its first year of operation. Given this target, and the values N, R1, and R2, you need to identify the number of TVs needed by the Hospital so that it meets the yearly revenue target. Assume the Hospital opens on every day, starting on January 1st, and the year is a non-leap year.

## Constraints

* Hospital opens on the 1st of January in an ordinary year
* 5 <= N <= 100
* 500 <= R1, R2 <= 5000
* 0 <= R <= 90000000

## Input

First line provides an integer N, denoting the number of rooms

Second line provides two integers, R1 and R2, denoting the rates of rooms with TV and rooms without TV, respectively

Third line provides the revenue target R

## Output

Minimum number of TVs the hospital needs to buy in order to meet the yearly revenue target, or the number of rooms N in case it cannot meet the yearly revenue target

## Timeout

1 second

## Examples

### Input

20
1500 1000
7000000

### Output

14

### Explanation

After installing 14 TVs in 14 of the 20 rooms, the hospital is able to meet the revenue target. With less TVs, it gets short of R in this case.

### Input

10
1000 1500
10000000

### Output

10

### Explanation

In this case, the hospital is not able to meet the revenue target and so the output is the number of rooms, N
