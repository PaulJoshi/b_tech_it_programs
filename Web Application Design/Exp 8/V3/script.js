function validation() {

    //check userid
    var userid = document.form.user.value;
    if (userid.length == 0 || userid.length < 5 || userid.length > 12) {
        alert("User ID should not be empty and should be min of 5 characters and max of 12 characters only");
        return false;
    }

    //check password
    var password = document.form.pass.value;
    if (password.length == 0 || password.length < 7 || password.length > 12) {
        alert("Password should not be empty and  be min of 7 characters and max of 12 characters only");
        return false;
    }
    
    //check username
    var uname = document.form.uname;
    var letter = /^[A-Za-z]+$/;
    if (!uname.value.match(letter)) {
        alert("Name must contain alphabets only!!");
        return false;
    }
    
    //check address
    var addr = document.form.address;
    var letterNumber = /^[0-9a-zA-Z ]+$/;
    if (!addr.value.match(letterNumber)) {
        alert("Address must contain alphabets and numbers only!!");
        return false;
    }
    
    //check country
    var count = document.form.country;
    if (count.value == "Default") {
        alert("Select any country!!");
        return false;
    }
    
    //check zipcode
    var zipcode = document.form.zip;
    var number = /^[0-9]+$/;
    if (!zipcode.value.match(number)) {
        alert("Only numbers are allowed!!");
        return false;
    }
    
    //check email
    var em = document.form.email;
    var mailform = /^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$/;
    if (!em.value.match(mailform)) {
        alert("Enter a valid email id!!");
        return false;
    }
    
    //check gender
    if ((form.sex[0].checked == false) && (form.sex[1].checked == false)) {
        alert("Select either male or female!!");
        return false;
    }
    
    //check language
    var eng = document.form.englang;
    var noneng = document.form.nonenglang;
    if (!eng.checked && !noneng.checked) {
        alert("Select any language!!");
        return false;
    }

    else {
        alert("Submit Successful");
        return false;
    }
}
