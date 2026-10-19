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