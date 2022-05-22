
function formvalidation() {
    if (validate_userid(5, 12)) {
        if (validate_passid(7, 12)) {
            if (all_alphabets()) {
                if (alpha_numeric()) {
                    if (select_country()) {
                        if (all_numeric()) {
                            if (email_validate()) {
                                if (check_language()) {
                                    sex_validate()
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}

function validate_userid(min, max) {
    var uid = document.registration.userid;
    var uid_len = uid.value.length;
    if (uid_len == 0 || uid_len > max || uid_len < min) {
        alert('incorrect length');
        uid.focus();
        return false;
    }
    return true;
}

function validate_passid(min, max) {
    var pid = document.registration.passid;
    var pid_len = pid.value.length;
    if (pid_len == 0 || pid_len > max || pid_len < min) {
        alert('incorrect length');
        pid.focus();
        return false;
    }
    return true;
}

function all_alphabets() {
    var usern = document.registration.username;
    var alphabets = /^[A-Za-z]+$/;
    if (usern.value.match(alphabets)) {
        return true;
    } else {
        alert('must be alphabets only');
        usern.focus();
        return false;
    }
}

function alpha_numeric() {
    var addr = document.registration.address;
    var alphabets = /^[0-9a-zA-Z]+$/;
    if (addr.value.match(alphabets)) {
        return true;
    } else {
        alert('either alphabets or numbers');
        addr.focus();
        return false;
    }
}

function select_country() {
    var usercountry = document.registration.country;
    if (usercountry.value == 'Default') {
        alert('select a country');
        usercountry.focus();
        return false;
    }
    return true;
}

function all_numeric() {
    var uzip = document.registration.zip;
    var characters = /^[0-9]+$/;
    if (uzip.value.match(characters)) {
        return true;
    } else {
        alert("must be numbers only");
        uzip.focus();
        return false;
    }
}

function email_validate() {
    var uemail = document.registration.email;
    var format = /^\w+([\.-]?\w+)@\w+([\.-]?\w+)(\.\w{2,3})+$/;
    if (uemail.value.match(format)) {
        return true;
    } else {
        alert('email format incorrect');
        uemail.focus();
        return false;
    }
}

function check_language() {
    var english = document.registration.eng;
    var nonenglish = document.registration.noneng;
    x = 0;
    if (english.checked) {
        x++;
    }
    if (nonenglish.checked) {
        x++;
    }
    if (x == 0) {
        alert('select a language');
        return false;
    }
    return true;
}

function sex_validate() {
    var male = document.registration.msex;
    var female = document.registration.fsex;
    x = 0;
    if (male.checked) {
        x++;
    }
    if (female.checked) {
        x++;
    }
    if (x == 0) {
        alert('select a sex');
        return false;
    } else {
        alert('form successfully submitted');
        window.location.reload();
    }
}