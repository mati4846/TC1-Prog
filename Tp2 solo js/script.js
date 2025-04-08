//`ok`
const contenedor = document.getElementById("container");

const materias = [
    {materia : "Programacion", nota : 10},
    {materia : "Fisica", nota : 3},
    {materia : "Quimica", nota : 4},
    {materia : "Analisis Matematico", nota : 4},
    {materia : "Base de datos", nota : 1},
    {materia : "Ingles", nota : 0}
];

const buscarNota = (id)=>{
    return new Promise((resolve, reject)=> {
        if (materias[id]==undefined) reject("No se encontro la materia");
        else setTimeout(()=>{resolve(materias[id])},Math.random()*500);
    })
}

const obtenerNota = async ()=>{
    let materiaa = [];
    for (i in materias) {
        materiaa[i] =  await buscarNota(i);
        contenedor.innerHTML += `
        <div class="container-materia">
        <h3>${materiaa[i].materia}</h3>
        <h2>${materiaa[i].nota}</h2>
        </div>
        `
    }
}

obtenerNota()
