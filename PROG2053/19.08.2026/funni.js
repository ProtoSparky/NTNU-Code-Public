function main (){
    //setInterval(setColor,10);
    spawnPattern();

    document.addEventListener('mousemove', function(event) {
    sync2mouse(event.clientX, event.clientY); setColor();
});
}
function setColor(){
    let r = 0;
    let g = 0;
    let b = 0;
    let css = "";
    r = RandomRangedIntiger(0,255);
    g = RandomRangedIntiger(0,255);
    b = RandomRangedIntiger(0,255);

    str = "rgb(" + r + "," + g +"," +b + ")";

    //console.log(str);
    document.body.style.backgroundColor  =str;
}

function RandomRangedIntiger(min, max) {
  return Math.floor(Math.random() * (max - min + 1)) + min;
}

function sync2mouse(x, y){
    const position = document.getElementById("sex");
    position.style.top = y + "px";
    position.style.left = x + "px";
    console.log(x);

}

function spawnPattern(){
    const boxSize = {
        "w":40,
        "h":40
    };

    const box = document.createElement("div");
    box.style.position = "absolute";
    box.style.top = 0;
    box.style.left = 0;
    box.style.width = boxSize.w;
    box.style.height = boxSize.h;

    for(let pxW = 0; pxW < boxSize.w; pxW ++){

        for(let pxH = 0; pxH < boxSize.h; pxH ++){

            const pixel = document.createElement("div");
            pixel.style.position = "absolute";
            pixel.style.top = pxH;
            pixel.style.left = pxW;
            pixel.style.width = 1;
            pixel.style.height = 1;
            pixel.style.zIndex = "999";
           

            if((pxW + pxH) % 2 ){
                pixel.style.backgroundColor = "black";
            }

            box.appendChild(pixel);
            
        }

    }
    document.body.appendChild(box);
}