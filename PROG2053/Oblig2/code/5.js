
function main(){
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

    /* could also do this, but i think its less clean
    promise
    .then((message)=>{
        console.log(message);
        document.body.innerHTML = bookClass.description; //write to html
    })
    .catch((error)=>{
        console.log(error);
    })
    */
}