
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


# Q2
## 1
*Convert the string ‘I am writing in Javascript!’ into an array*
```
    const string = "I am writing in Javascript!";
    let array = string.split("");
    //or just treat the string as an array
    //  and for example use string[0]
    //  which would return "I"
    console.log(array);
```
You can use the split feature on strings to explicitly split at nothing to separate each char into a char array, or just treat the string as an array and access the values that way.
I suppose using split would reduce the amount of errors if a var got assigned something else than a string, but the other method should work as well.

## 2
### A
*Suppose this string was already stored as an array. How would you convert it back into a*
*single string?*
```
const stringArray = [
    "I",
    " ",
    "a",
    "m",
    " ",
    "w",
    "r",
    "i",
    "t",
    "i",
    "n",
    "g",
    " ",
    "i",
    "n",
    " ",
    "J",
    "a",
    "v",
    "a",
    "s",
    "c",
    "r",
    "i",
    "p",
    "t",
    "!"
];

let string = stringArray.join("")
console.log(string); 
```
you could probably do the same using a for loop but js has a built in function for joining strings or arrays at something, and in this case its at nothing, so each letter or space gets joined after each other.

### B
*Rewrite the following constructor function as a JavaScript class and ensure that the method*
*describe is properly implemented as part of the class definition.*

```
class Food{
    constructor(name, cooktime){
        this.name = name;
        this.cooktime = cooktime;
    }
    describe(){
        console.log(
            `${this.name} is delicious and will take ${this.cooktime} to finish cooking.`
        );
    }
}


const food1 = new Food('Pizza', '15 min');
food1.describe();
```

# Q3 
```
const student = {
    name:"Sparky",
    age:21, 
    course:"Digsec", 
    greet:function(){
        return `Hello, I am ${this.name}`;
    }
}
let body = document.body;

const greetName  = document.createElement("div");
greetName.innerHTML = student.greet();
body.appendChild(greetName); 

//Create a string variable and use string methods to display different versions of the text:
const string = student.greet();

//toUpperCase
const stringUpper = document.createElement("div");
stringUpper.innerHTML = string.toUpperCase();
body.appendChild(stringUpper);

//length
const stringLength = document.createElement("div");
stringLength.innerHTML = string.length;
body.appendChild(stringLength);

//pop
const stringPop = document.createElement("div");
stringPop.innerHTML = string.split("").pop(); // i assume this is what you expect when asking for me to use .pop()
body.appendChild(stringPop); 

//replace
const stringReplace = document.createElement("div");
stringReplace.innerHTML = string.replace("Hello", "Goodbye");
body.appendChild(stringReplace)
```

# Q4

```
/*
Ask the user to enter the current outdoor temperature in degrees and check whether it is hotter
than, colder than, or exactly equal to a perfect target temperature value set in your code.
Output the result to the user.
*/
const targetTemperature = 25; //Temperature we check against

const wrapper = document.createElement("div");
document.body.appendChild(wrapper);

//text header
const header = document.createElement("div");
header.innerHTML = "Enter a temperature and guess whether it is higher or lower than my code";
wrapper.appendChild(header);

//message whether temp is exact, lower or higher than code
const checkMessage = document.createElement("div");

//input temperature
const input = document.createElement("input");
input.type = "number";
input.min = "-100";
input.max = "100";
input.value = "20";
input.addEventListener("click",function(){
    checkMessage.innerHTML = ""; // clears message when adjusting temp;
})
wrapper.appendChild(input);


//submit button
const checkBTN = document.createElement("button");
checkBTN.innerHTML = "Guess Temperature";
checkBTN.addEventListener("click",function(){
    if(input.value < targetTemperature){
        //lower
        checkMessage.innerHTML = "Too cold!";
        checkMessage.style.color = "blue";
    }
    else if(input.value == targetTemperature){
        //exact match
        checkMessage.innerHTML = "Exact match. Comfy temp :)";
        checkMessage.style.color = "green";
    }
    else if(input.value > targetTemperature){
        //too hot
        checkMessage.innerHTML = "Too hot!";
        checkMessage.style.color = "red";
    }
});
wrapper.appendChild(checkBTN);

//applies check message lower cause i dont want to use ID and yet want to keep text below other UI elements
wrapper.appendChild(checkMessage);
```

# Q5
```
class Book{
    constructor(name,author,ISBN){
        this.name = name;
        this.author = author;
        this.ISBN = ISBN;
    }
    get description(){
        return `This book is called ${this.name} by ${this.author} and has ${this.ISBN}`;
    }
    set nameChange(name){
        this.name = name;
    }
}

//we create a new book
const bookClass = new Book(
    "The Hunger Games",
    "Suzanne Collins",
    "978-0-439-02352-8"

);


//actuaally we want to change the name of the book
bookClass.nameChange= "The Hungrier Games";


const promise = new Promise((resolve, reject)=>{
    setTimeout(()=>{
        resolve("Data loaded successfully");
    },3000);
});

promise.then((message)=>{
    console.log(message);
    document.body.innerHTML = bookClass.description; //write to html
})
promise.catch((error)=>{
    console.log(error);
})
```

# Q6
## 1
*Represent the full DOM tree for this HTML, showing the hierarchy of elements and
text/comment nodes.*

Given that the question is super vague, I'll make a diagram of the DOM tree. 




# Q7

```
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8">
        <meta name="viewport"
        content="width=device-width, initial-scale=1.0">
        <title>Course Registration</title>
    </head>
    <body>
        <h1>Course Registration</h1>
        <label for="course">Enter a course name:</label>
        <input type="text" id="course">
        <button id="register-button">Register</button>
        <p id="message"></p>
        <script>
            //create listener for when person clicks on button
            document.getElementById("register-button").addEventListener("click",function(){
                registerCourse();
            }); 

            function registerCourse(){
                const inputData = document.getElementById("course").value;
                const messageBanner = document.getElementById("message");

                if(inputData == ""){messageBanner.innerHTML = "Please enter a course name.";}
                else{messageBanner.innerHTML = `You are registered for ${inputData}.`;}
            }
        </script>
    </body>
</html>
```

## What the click event does
It runs a specific function or code when the user clicks the element it is attached to
## What the registerCourse() function does.
It gets the data from the input field, checks whether its empty, and writes a message based on its state. 
## Why addEventListener() is used.
Creates the event for the click of the button, and appends it to the button element. 
