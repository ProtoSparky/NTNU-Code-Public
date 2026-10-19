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
