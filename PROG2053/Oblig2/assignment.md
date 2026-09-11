# Q1
## 1
*What will be the final value of **total** after the code executes?*

First we calculate the modulo for the whole loop 

| number | modulo |
| ------ | ------ |
| 3      | 1      |
| 4      | 0      |
| 5      | 1      |
| 6      | 0      |
| 7      | 1      |
| 8      | 0      |
We invert it because the code checks it against 0 instead of 1, and then do the rest of the calculations.

| run | calculation | total (current run) |
| --- | ----------- | ------------------- |
| 3   | 5 * 3       | 15                  |
| 4   | 15 + 4      | 19                  |
| 5   | 19 * 5      | 95                  |
| 6   | 95 + 6      | 101                 |
| 7   | 101 * 7     | 707                 |
| 8   | 707 + 8     | 715                 |
The total is 715 at the end of the loop. 

## 2
*What is the purpose of the condition j % 2 === 0 in this code?*

This condition runs the modulo of j and 2 to see whether j is divisible by 2, and then checks whether the answer is 0 or not. The triple equals check for not just the value but also the type, which is redundant in this case, but i suppose it helps with safer code. 
## 3 
*Rewrite the same logic using a while loop instead of a for loop.*

This is an example for how it can be done

```
let total = 5;
let j = 3;
while(j <= 8){
    if (j % 2 === 0) {
        total += j;
    }
    else {
        total *= j;
    }
    j ++ ; //increment j as this is no longer a for loop
}
```

## 4
*Explain in your own words how operators (+, *, %) are used in this example.*
`+` in our case is used with the equal symbol to increment total by j
`*` in our case is used with the equal symbol to multiply total by j
`%` in our case is used to run the modulo operation on j to see if it is divisible by 2
