//`ok`
const dado = document.getElementById("dado");
const btn = document.getElementById("btn");

btn.addEventListener("click", ()=>{
    let num = Math.floor(Math.random()* 6);
    let html = ``
    console.log(num);
    for (let i = 0; i <= num; i++) {
        html += `
        <div class="punto"></div>
        `
    }
    dado.innerHTML = html;
});
