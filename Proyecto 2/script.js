//`ok`
const respuesta = document.getElementById("answer");
const imagenes = document.getElementById("container-img");
const myPoints = document.getElementById("my-points");
const pcPoints = document.getElementById("pc-points");

let resultado = "", mispuntos = 0, pcPuntos = 0;
const opciones = ["piedra", "papel", "tijera"];

respuesta.innerHTML = "Elije piedra papel o tijera";
myPoints.innerHTML = 0;
pcPoints.innerHTML = 0;

imagenes.addEventListener("click", (evt)=>{
    let pc = Math.floor(Math.random() * 3);
    let eleccion = parseInt(evt.target.id);
    console.log(eleccion);
    if (eleccion == pc) resultado = "es un empate";
    else if (eleccion == 0 && pc == 1 || eleccion == 1 && pc == 2 || eleccion == 2 && pc == 0){
        resultado = "ganó la computadora";
        pcPuntos ++;
    } else if ((eleccion == 0 && pc == 2) || (eleccion == 1 && pc == 0) || (eleccion == 2 && pc == 1)){
        resultado = "ganaste tú";
        mispuntos ++;
    }
    if (opciones[eleccion] != undefined){
        myPoints.innerHTML = mispuntos;
        pcPoints.innerHTML = pcPuntos;
        respuesta.innerHTML = `Elijiste ${opciones[eleccion]} y la computadora ${opciones[pc]}, ${resultado}.`;
    }
});
