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