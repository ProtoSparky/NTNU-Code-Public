function main(){
    const textString = "hello world";
    formatText(textString, toSecret);
}

function formatText(str, callback){
    console.log(callback(str));
}
function toShouting(str){
    return str.toUpperCase() + "!";
}
function toSecret(str){
    //replaces all vowels (A,E,I,O,U) with asterisks
    const strArray = str.split(""); 
    for(let i = 0; i < strArray.length; i++){
        if(
            (strArray[i].toUpperCase() == "A") ||
            (strArray[i].toUpperCase() == "E") ||
            (strArray[i].toUpperCase() == "I") ||
            (strArray[i].toUpperCase() == "O") ||
            (strArray[i].toUpperCase() == "U")
        ){
            strArray[i] = "*";            
        }
    }
    return strArray.join(""); 
}