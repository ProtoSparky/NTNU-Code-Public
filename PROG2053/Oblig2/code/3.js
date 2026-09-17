function main(){
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

}


