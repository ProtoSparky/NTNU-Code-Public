function main(){
    
    const formBody = document.createElement("form");
    formBody.action = "./checkout.php";
    formBody.method = "POST";
    document.body.appendChild(formBody);

    const textInput = document.createElement("input");
    textInput.type ="number"; 
    textInput.name = "product_id";
    textInput.defaultValue = "883";
    formBody.appendChild(textInput); 

    const numericInput = document.createElement("input");
    numericInput.type = "number";
    numericInput.name = "qty";
    numericInput.defaultValue = "2";
    formBody.appendChild(numericInput); 

    const submitBTN = document.createElement("input");
    submitBTN.type = "submit";
    submitBTN.value = "Filter movies";
    formBody.appendChild(submitBTN);   

    //raw data is product_id=883&qty=2
}