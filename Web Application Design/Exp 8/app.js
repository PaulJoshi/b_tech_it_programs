function validation() {
    const form = document.querySelector('#form');
    const user = document.getElementById('user');
    const pass = document.getElementById('pass');
    const user_name = document.getElementById('uname');
    const address = document.getElementById('address');
    const zip = document.getElementById('zip');
    const gender = document.getElementById('gender');
    const lan = document.getElementById('eng');
    const checkboxes = form.querySelectorAll('input[type=checkbox]');
    const checkboxLength = checkboxes.length;
    const firstCheckbox = checkboxLength > 0 ? checkboxes[0] : null;
    const alpha = /^[a-zA-Z]+$/;
    const numeric = /^[0-9]+$/;

    //User ID
    if(user.value == "") {
        document.getElementById('user_id').innerHTML = "User Id Cannot be Empty";
        return false;
    }

    if( (user.value.length < 5) || (user.value.length > 12) ) {
        document.getElementById('user_id').innerHTML = "User Id should be between 5 & 12";
        return false;
    }

    // Address
    if(pass.value == "") {
        document.getElementById('pass_error').innerHTML = "Password Cannot be Empty";
        return false;
    }

    if( (pass.value.length < 7) || (pass.value.length > 12) ) {
        document.getElementById('pass_error').innerHTML = "Password should be between 7 & 12";
        return false;
    }

    //Name
    if(user_name.value == "") {
        document.getElementById('name_error').innerHTML = "Name Cannot be Empty";
        return false;
    }

    if(!user_name.value.match(alpha)) {
        document.getElementById('name_error').innerHTML = "Only Alphabets allowed";
        return false;
    }

    //Address
    if(address.value == "") {
        document.getElementById('address_error').innerHTML = "Address Cannot be Empty";
        return false;
    }

    //Zip
    if(zip.value == "") {
        document.getElementById('zip_error').innerHTML = "Zip Cannot be Empty";
        return false;
    }

    if(!zip.value.match(numeric)) {
        document.getElementById('zip_error').innerHTML = "Only Numbers allowed";
        return false;
    }

    //gender
    if(gender.value == ""){
        checked = document.querySelector("input[type=radio]:checked").length;

        if(!checked) {
            document.getElementById('gender_error').innerHTML = " Please Select a Gender";
            return false;
        }
      }
    

    //language
    const result = Validatelan()  
    if(result == false)
    {
        return false;
    }
    else {
        return true;
    }
    
}

function Validatelan()  
{  
    var checkboxes = document.getElementsByName("language");  
    var numberOfCheckedItems = 0;  
    for(var i = 0; i < checkboxes.length; i++)  
    {  
        if(checkboxes[i].checked)  
            numberOfCheckedItems++;  
    } 
    console.log(numberOfCheckedItems); 
    if(numberOfCheckedItems == 0)  
    {  
        document.getElementById('lan_error').innerHTML = " (Please Select a Language)";
        return false;  
    }  
}
