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


