//`ok`
const containerTxt = document.getElementById("container-txt");
const btncolor = document.getElementById("btn-color");
const btnBorde = document.getElementById("btn-borde");
const btnSombra = document.getElementById("btn-sombra");
const btnTamaño = document.getElementById("btn-tamaño");

let a = 1, b = 0, c = 1;
// let tamaños = [["200px", "160px"] , ["250px", "180px"] , ["300px", "200px"]];

btncolor.addEventListener("input", ()=>{
    console.log("color");
    let color = btncolor.value;
    containerTxt.style.backgroundColor = color;
});

btnBorde.addEventListener("click", ()=>{
    console.log("borde");
    a++;
    switch(a) {
        case 1 : containerTxt.style.borderStyle = "solid";
        break;
        case 2 : containerTxt.style.borderStyle = "dotted";
        break;
        case 3 : 
            containerTxt.style.borderStyle = "none";
            a=0;
        break;
    }
});

btnSombra.addEventListener("click", ()=>{
    console.log("sombra");
    if (b == 0){
        containerTxt.style.webkitBoxShadow = "0px 0px 23px 15px rgba(0,0,0,0.5)";
        containerTxt.style.mozBoxShadow = "0px 0px 23px 15px rgba(0,0,0,0.5)";
        containerTxt.style.mozBoxShadow = "0px 0px 23px 15px rgba(0,0,0,0.5)";
        containerTxt.style.boxShadow = "0px 0px 23px 15px rgba(0,0,0,0.5)";
        b++;
    } else if (b == 1){
        containerTxt.style.boxShadow = "none";
        b=0;
    }
});

btnTamaño.addEventListener("click", ()=>{
    console.log("tamaño");
    c++;
    if (c == 1){
        containerTxt.style.width = "200px";
        containerTxt.style.height = "160px";
    } else if (c == 2){
        containerTxt.style.width = "250px";
        containerTxt.style.height = "180px";
    } else if (c == 3){
        containerTxt.style.width = "300px";
        containerTxt.style.height = "200px";
        c=0;
    }
});
