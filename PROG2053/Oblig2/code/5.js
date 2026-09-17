/*
TODO. NOT FINISHED
*/

function main(){
    class Book{
        constructor(name,author,ISBN){
            this.name = name;
            this.author = author;
            this.ISBN = ISBN;
        }
        get descriotion(){
            return `This book is called ${this.name} by ${this.author} and has ${this.ISBN}`;
        }
        set nameChange(name){
            this.name = name;
        }
    }

    const promise = new Promise(function(resolve, reject){
        promise.then(function(value){

        });
    });

    setTimeout(function(){
        

    },3000); //yes we are wasting time, but this assignment expects it for some reason

}