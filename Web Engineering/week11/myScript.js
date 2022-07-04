var DYNO_PRICE = 5;
var ANDROID_PRICE = 5000;
var LAMP_PRICE = 10;
var DRAGON_PRICE = 10000

const formatter = new Intl.NumberFormat('en-US', {
  style: 'currency',
  currency: 'USD',
  minimumFractionDigits: 2
})

function display_total() {
    var dyno = parseInt(document.getElementById("item_0").value);
    var android = parseInt(document.getElementById("item_1").value);
    var lamp = parseInt(document.getElementById("item_2").value);
    var dragon = parseInt(document.getElementById("item_3").value);
    document.getElementById("dyno_total").innerHTML = formatter.format(dyno * DYNO_PRICE);
    document.getElementById("android_total").innerHTML = formatter.format(android * ANDROID_PRICE);
    document.getElementById("lamp_total").innerHTML = formatter.format(lamp * LAMP_PRICE);
    document.getElementById("dragon_total").innerHTML = formatter.format(dragon * DRAGON_PRICE);
    document.getElementById("total").innerHTML = formatter.format((dyno * DYNO_PRICE) + (android * ANDROID_PRICE) + (lamp * LAMP_PRICE) + (dragon * DRAGON_PRICE));
}

function calculate_total() {
    var dyno = parseInt(document.getElementById("item_0").value);
    var android = parseInt(document.getElementById("item_1").value);
    var lamp = parseInt(document.getElementById("item_2").value);
    var dragon = parseInt(document.getElementById("item_3").value);
    var total_dyno = dyno * DYNO_PRICE;
    var total_android = android * ANDROID_PRICE;
    var total_lamp = lamp * LAMP_PRICE;
    var total_dragon = dragon * DRAGON_PRICE;
    var total = total_dyno + total_android + total_lamp + total_dragon;
    console.log(dyno);
    document.getElementById("num_dyno").value = dyno;
    document.getElementById("num_android").value = android
    document.getElementById("num_lamp").value = lamp;
    document.getElementById("num_dragon").value = dragon;
    document.getElementById("total_dyno").value = formatter.format(total_dyno);
    document.getElementById("total_android").value = formatter.format(total_android);
    document.getElementById("total_lamp").value = formatter.format(total_lamp);
    document.getElementById("total_dragon").value = formatter.format(total_dragon);
    document.getElementById("total_price").value = formatter.format(total);
    return total;
}

function validate_phone() {
    var phone = document.getElementById("phone").value;
    var correct_phone;
    var phone_pattern = /[0-9]{3}-[0-9]{3}-[0-9]{4}/;
    var result = phone_pattern.test(phone);
    console.log(result);
    if(result == false) {
        document.getElementById("number_message").innerHTML = "Must be in this format: ###-###-####";
    } else {
        document.getElementById("number_message").innerHTML = "";
        correct_phone = phone;
        console.log(correct_phone)
    }
    return correct_phone;
}

function validate_card() {
    var cc = document.getElementById("credit_card").value;
    var correct_card;
    var card_pattern = /[0-9\s]{16}/;
    var result = card_pattern.test(cc);
    console.log(result);
    if(result == false) {
        document.getElementById("card_message").innerHTML = "Must have 16 digits to be valid";
    } else {
        document.getElementById("card_message").innerHTML = "";
        correct_card = cc;
        console.log(correct_card)
    }
    return correct_phone;
}

function validate_exp() {
    var exp = document.getElementById("exp_date").value;
    var correct_exp;
    var exp_pattern = /((0[1-9])|10|11|12)\/20[2-9][0-9]/;
    var result = exp_pattern.test(exp);
    console.log(result);
    if(result == false) {
        document.getElementById("exp_message").innerHTML = "Must be a valid month and year greater than 2020 in this format: ##/####";
    } else {
        document.getElementById("exp_message").innerHTML = "";
        correct_exp = exp;
        console.log(correct_exp)
    }
    return correct_exp
}