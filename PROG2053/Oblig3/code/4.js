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