function enviar(){
    let form = document.forms["myForm"];

    let nombre = form.nombre.value;

    let telefono = form.telefono.value;
    
    let email = form.email.value;

    let sabor = form.sabor.value;

    let recipiente = form.recipiente.value;

    let extra = document.getElementsByName("extras");
    
    let info = 'El cliente ' + nombre + ', telefono:' + telefono + ', email:' + email + ', eligió un helado de sabor ' + sabor + ' en un recipiente de ' + recipiente + ' con un extra de ';

    for (let i=0; i < extra.length; i++ ){
        const extras = extra[i];
        if (extras.checked){
            info += extras.value + " ";
        }
    }

    console.log(info);

}