function main(){
    /*
    Ask the user to enter the current outdoor temperature in degrees and check whether it is hotter
    than, colder than, or exactly equal to a perfect target temperature value set in your code.
    Output the result to the user.
    */
    const targetTemperature = 25; //Temperature we check against

    const wrapper = document.createElement("div");
    document.body.appendChild(wrapper);

    //text header
    const header = document.createElement("div");
    header.innerHTML = "Enter a temperature and guess whether it is higher or lower than my code";
    wrapper.appendChild(header);

    //message whether temp is exact, lower or higher than code
    const checkMessage = document.createElement("div");

    //input temperature
    const input = document.createElement("input");
    input.type = "number";
    input.min = "-100";
    input.max = "100";
    input.value = "20";
    input.addEventListener("click",function(){
        checkMessage.innerHTML = ""; // clears message when adjusting temp;
    })
    wrapper.appendChild(input);


    //submit button
    const checkBTN = document.createElement("button");
    checkBTN.innerHTML = "Guess Temperature";
    checkBTN.addEventListener("click",function(){
        if(input.value < targetTemperature){
            //lower
            checkMessage.innerHTML = "Too cold!";
            checkMessage.style.color = "blue";
        }
        else if(input.value == targetTemperature){
            //exact match
            checkMessage.innerHTML = "Exact match. Comfy temp :)";
            checkMessage.style.color = "green";
        }
        else if(input.value > targetTemperature){
            //too hot
            checkMessage.innerHTML = "Too hot!";
            checkMessage.style.color = "red";
        }
    });
    wrapper.appendChild(checkBTN);

    //applies check message lower cause i dont want to use ID and yet want to keep text below other UI elements
    wrapper.appendChild(checkMessage);
}
