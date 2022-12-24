# Bonus Challenge:
*Every program must be able to read, use and write text files*

## Task 1:
Create a program that would reverse an array, without using another array

## Task 2:
Given a size *n* array. Products that cost less than the average should have their price increased by *p* percent. Create a program that would return the average of the newly raised product prices

## Task 3:
Given an array of the average temperature of each month, create a program that would show how many times the temperature average was above positive, but less than *t0*

## Task 4:
Given an integer array (size is to be determined by you), create a program that would show how many times there was a double sign number that started with 3 

## Task 5:
Given an array of integers, containing the average atmospheric pressure of an entire year, create a program that would show how many days had a pressure higher than *p1*, but lower than *p2*

## Task 6:
Given an array of integers and the array size *n*, create a program that would write "YES" if the array is symmetrical, and "NO" if it is not

*Example:*
| in.txt | out.txt | 
| ------ | ------- |
| 8<br>5 8 4 6 9 4 5 6 | NO |
| 10<br>6 7 1 5 9 9 5 1 7 6 | YES |
| 9<br>6 4 8 1 2 1 8 4 6 | YES |

## Task 7:
Given a 1-dimentional array, which has *n* numbers, create a program that would find the only 2 numbers that repeat, and would show their indecies, as well as the number that was repeated

*Example:*
| in.txt | out.txt | Explanation |
| ------ | ------- | ----------- |
| 20<br>19 7 2 6 90 1 4580 32 5 0 654<br>25 4 62 120 65 -4 0 87 -84 | 9 17 0 | The numbers at indecies 9 and 17 are identical (0) |

## Task 8:
Create a program to remove all suplicate values from an *n* sized array

*Example:*
| in.txt | out.txt |
| ------ | ------- |
| 8<br>5 8 4 8 9 4 5 6 | 5 8 4 |

## Task 9:
Create a program to remove all elements from an array, who's indecies are odd.
*(The task is worded weirdly, you have to output the deleted elements)*

*Example:*
| in.txt | out.txt |
| ------ | ------- |
| 8<br>50 80 40 80 90 40 50 60 | 50 40 90 50 |

## Task 10:
An *n* sized array is sorted largest to smallest, each element is random. Create a program that would remove every element smaller than *p*

*Example:*
| in.txt | out.txt |
| ------ | ------- |
| 12 195<br>208 205 205 201 198 192<br>190 186 170 169 169 166| 208 205 205 201 198 |

## Task 11:
A class has *n* students. Their heights, which are sorted tallest to shortest, are in *class.txt*. There are *k* new freshmen. Their heights are in *freshmen.txt*. Create a program, which would read the class heights into an array, insert the freshmen heights (without disruption the sort) and write them to *new.txt*.

*Example:*
| class.txt | freshmen.txt | new.txt |
| ------ | ------- | ------ |
| 12<br>208 205 205 201 198 192<br>190 186 170 169 169 166 | 3<br>203 195 186 | 15<br>208 205 205 203 201 198 195<br>192 190 186 186 170 169 169 166 |

## Task 12:
A group of *n* figure skating judges judge each performer on their technique and style. The ratings are a 6-point scale. The lowest and highest rating of each category are removed. Create a program to calculate a performers average rating.

*Example:*
| in.txt | out.txt |
| ------ | ------- |
| 7<br>5 3<br>6 5<br>6 5<br>6 4<br>5 5<br>6 5<br>6 6<br> | 5.8<br>4.8 |

## Task 13:
You are given an array of *k* = 2<sup>N</sup> number of team tournament results. Each array line contains 2 values - the team number and the points scored. The tournament system is structured, such that, no 2 teams can score an identical number of points. Create a program that would create the next round of competing teams. The team results must be displayed in descending order.

*(Example given is poor, it does not specify if the given array is in descending order. I will assume that it is not)*

*Example:*
| in.txt | out.txt |
| ------ | ------- |
| 8<br>2 75<br>8 60<br>1 57<br>14 51<br>6 48<br>5 36<br>7 35<br>3 31 | 4<br>2 75<br>8 60<br>1 57<br>14 51<br>|

