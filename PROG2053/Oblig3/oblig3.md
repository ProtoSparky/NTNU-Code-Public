# 1 


```
function main(){
    const textString = "hello world";
    formatText(textString, toSecret);
}

function formatText(str, callback){
    console.log(callback(str));
}
function toShouting(str){
    return str.toUpperCase() + "!";
}
function toSecret(str){
    //replaces all vowels (A,E,I,O,U) with asterisks
    const strArray = str.split(""); 
    for(let i = 0; i < strArray.length; i++){
        if(
            (strArray[i].toUpperCase() == "A") ||
            (strArray[i].toUpperCase() == "E") ||
            (strArray[i].toUpperCase() == "I") ||
            (strArray[i].toUpperCase() == "O") ||
            (strArray[i].toUpperCase() == "U")
        ){
            strArray[i] = "*";            
        }
    }
    return strArray.join(""); 
}
```

# 2
```
function main(){
    const number = randomNum(10); //generates random number 0-10
    randomFunction(number, hiddenMath); 
}

function randomFunction(num, callback){
    let call = callback(num);

    console.log("The random number is: " + num);
    console.log("result: " + call.num); 
    console.log("The random number is: " + num);
    console.log("result: " + call.even); 
}
function hiddenMath(num){
    let isEvenStr = "odd";
    if(num %2 == 0){
        isEvenStr = "even";
    }
    
    //sends out multiple vars
    return {
        num:num * 2,
        "even":isEvenStr
    };
}

function randomNum(max){
    return Math.floor(Math.random() * max);
}

```

# 3
```
function main(){
    sendCampaign("Atumn Sale",generateRaport); 
}

function sendCampaign(campaignName,callback){
    console.log(`Initiating transmission sequence for ${campaignName}...`); 
    //3s timeout
    setTimeout(()=>{
        console.log("Emails delivered successfully to subscribers!"); 
        callback(); ///runs callback
    },3000)  

}
function generateRaport(){
    console.log("Performance analytics report compiled and updated on dashboard.");
}
```

# 4
```
function main(){
    calculateFactorial(5,displayResult); 
}

function calculateFactorial(number, callback){
    let result = 1;
    console.log(`Initiating factorial calculation for ${number}...`);
    setTimeout(()=>{
        //calculate factorial
        for(let i = 1; i <= number; i++){
            result = result * i; 
        }
        console.log("Calculation complete!"); 
        callback(result); 
    },1500) //1.5s delay
}

function displayResult(result){
    console.log(`The final computed result is: ${result}`);
}
```

# 5
```
function main(){
    const diceRoll = new Promise((resolve, reject)=>{
        const number = Math.floor(Math.random() * 6);
        if(number >3){
            resolve("High roll, You win!");
        }
        else if(number <=3){
            reject("Low roll! You lose"); 
        }
        
    });
    diceRoll.then(result =>{
        console.log(result); 
    })
    diceRoll.catch(error =>{
        console.log(error);
    })
    diceRoll.finally(()=>{
        console.log("Game Completed"); 
    })
    
}
```

# 6
```
function main(){
    const validateCoupon = new Promise((resolve, reject)=>{
        const shoppingCart = {
            couponCode:"SAVE15",
            codeExpired:false,
            basePrice:200
        }
        const correctCoupon = "SAVE15";

        if(shoppingCart.couponCode != "SAVE15"){
            //wrong coupon
            reject("Invalid coupon code!"); 
        }

        if(shoppingCart.couponCode == correctCoupon && shoppingCart.codeExpired){
            //correct coupon, code expired
            reject("Coupon code expired!"); 
        }

        if(shoppingCart.couponCode == correctCoupon && !shoppingCart.codeExpired){
            //correct coupon, not expired
            const savedPrice = shoppingCart.basePrice * 0.15;
            resolve(`Success! Saved $${savedPrice}. Your adjusted checkout total is $${shoppingCart.basePrice - savedPrice}`); 
        }
    });

    validateCoupon.then(result=>{
        console.log(result);
    });
    validateCoupon.catch(error=>{
        console.log(error);
    });
    validateCoupon.finally(()=>{
        console.log("Session sync complete.");
    })
}
```

# 7
```
function main(){
    processItem("Laptop"); 
}
async function checkStockLevel(){
    return 45;
}
async function isWarehouseOpen(){
    return true;
}
async function processItem(itemName){
    if(! await isWarehouseOpen()){
        console.log("Warehosue closed. Aborting!!");
    }
    else{
        console.log("Warehouse open.");
        console.log(`${await checkStockLevel() + 10} item/s in stock for ${itemName}`); 
    }
}
```

# 8 
```
function main(){
    applyUpgrade("Premium-User-Alpha", 4); 
}
async function getLoyaltyDiscount(yearsActive){
    if(yearsActive > 2){
        return 15;
    }
    else{
        return 0;
    }
}
async function applyUpgrade(accountName, yearsActive){
    console.log(`Starting upgrade process for ${accountName}...`); 
    const customerDiscount = await getLoyaltyDiscount(yearsActive);
    const baseCharge = 50;
    console.log(`Account ${accountName}'s processed. Final balance due: $${baseCharge - customerDiscount}`);
}
```

# 9
```
function main(){
    getBookingInfo();
}
function getBookingInfo(){
    const url = "https://travel.com?price=1000&day=Wednesday";
    const getRequests = url.split("?")[1].split("&")
    for(let i = 0; i < getRequests.length; i++){
        let currentValue = getRequests[i].split("=");
        console.log("Key:" + currentValue[0]);
        console.log("Value:"+currentValue[1]); 
    }


}
```

# 10
```
function main(){
    const formBody = document.createElement("form");
    formBody.action = "./filter.php";
    formBody.method = "GET";
    document.body.appendChild(formBody);

    const textInput = document.createElement("input");
    textInput.type ="text"; 
    textInput.name = "genere";
    textInput.defaultValue = "action";
    formBody.appendChild(textInput); 

    const numericInput = document.createElement("input");
    numericInput.type = "number";
    numericInput.name = "year";
    numericInput.defaultValue = "2025";
    formBody.appendChild(numericInput); 

    const submitBTN = document.createElement("input");
    submitBTN.type = "submit";
    submitBTN.value = "Filter movies";
    formBody.appendChild(submitBTN); 
}

//url looks like this after clicking submit
//http://localhost/NTNU-Code/PROG2053/Oblig3/filter.php?genere=action&year=2025
```
# 11
```
function main(){
    getFlightInfo(); 
}
function getFlightInfo(){
    const urlString = "https://fly.com?name=norwegian&passenger=60";
    URLSearchParams(urlString.split("?")[1].split("&"));
}
function URLSearchParams(string){
    for(let i = 0; i < string.length; i++){
        let currentValue = string[i].split("=");
        console.log("Key:" + currentValue[0]);
        console.log("Value:"+currentValue[1]); 
    }
}
```

# 12
im not fully sure what is wanted here. The raw post data would be `product_id=883&qty=2`

# 13
this could be done better so each segment loads one after the other, but this proof of concept code does work as well.
```
//this is code for nodejs
const fileName = "./students.txt";
const fs = require('fs');

//A
const names = "Alice\nBob\nCharlie";
fs.writeFile(fileName,names, err=>{
    if(err){
        console.error(`Failed to write file ${fileName}`);
    }
    else{
        console.info("A. File created successfully"); 
    }
});


//B
fs.readFile(fileName, "utf8", (err,data)=>{
    if(err){
        console.log("error");
    }
    else{
        console.log("B. Current roster contents:");
        console.log(data); 
    }
});

//C
const newStudents = "\nDavid";
fs.writeFile(fileName, newStudents, {flag:'a+'}, err =>{
    if(err){
        console.error("Failed to save file"); 
    }
    else{
        console.info("C. Records appended successfully");
    }
});

//making sure everything is done processing before checking the file again
setTimeout(()=>{
    //D
    fs.readFile(fileName, "utf8", (err,data)=>{
        if(err){
            console.log("error");
        }
        else{            
            if(data == names+newStudents){
                console.info("D. The file exists"); 
            }
            else{
                console.error("The file does not exist.");
            }
        }
    });

},1000)

setTimeout(()=>{
    //E
    fs.rename("./oldstudents.txt",fileName,(err)=>{
        if(err){
            console.error("Cannot copy oldstudents.txt into students.txt"); //will probably fail cause this file never exitsts
        }
        else{
            console.info("E. File renamed successfully."); 
        }
    });
},2000);



```