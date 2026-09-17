/*
Rewrite the following constructor function as a JavaScript class and ensure that the method
    describe is properly implemented as part of the class definition.
    Use different variable names if needed.
*/

/*
function Food(name, cooktime) {
    this.name = name;
    this.cooktime = cooktime;
}
Food.prototype.describe = function() {
    console.log(
        `${this.name} is delicious and will take ${this.cooktime} to
    finish cooking.`
    );
};



    const food1 = new Food('Pizza', '15 min');
    food1.describe(); // Expected output: "Pizza is delicious and will take 15 min to finish cooking."
*/


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

function main(){
    const food1 = new Food('Pizza', '15 min');
    food1.describe();
}