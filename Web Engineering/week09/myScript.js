function renderHTML(data) {
    var htmlString = "<pre>";
    for (i = 0; i < data.length; i++) {
        htmlString += data[i];
    }
    htmlString += "<pre>"
    return htmlString;
}

function canadaPop() {
    req=new XMLHttpRequest();
    req.onreadystatechange=function() {
    if (req.readyState==4 && req.status==200) {
        country = req.responseText;
        htmlCountry = renderHTML(country);
        document.getElementById("div1").innerHTML=htmlCountry;
    }
    } // end of onreadstatechange function
    req.open("GET","canada.txt",true);
    req.send();
} // end of canadaPop()

function mexicoPop() {
    req=new XMLHttpRequest();
    req.onreadystatechange=function() {
    if (req.readyState==4 && req.status==200) {
        country = req.responseText;
        htmlCountry = renderHTML(country);
        document.getElementById("div1").innerHTML=htmlCountry;
    }
    } // end of onreadstatechange function
    req.open("GET","mexico.txt",true);
    req.send();
} // end of mexicoPop()

function russiaPop() {
    req=new XMLHttpRequest();
    req.onreadystatechange=function() {
    if (req.readyState==4 && req.status==200) {
        country = req.responseText;
        htmlCountry = renderHTML(country);
        document.getElementById("div1").innerHTML=htmlCountry;
    }
    } // end of onreadstatechange function
    req.open("GET","russia.txt",true);
    req.send();
} // end of russiaPop()

function usaPop() {
    req=new XMLHttpRequest();
    req.onreadystatechange=function() {
    if (req.readyState==4 && req.status==200) {
        country = req.responseText;
        htmlCountry = renderHTML(country);
        document.getElementById("div1").innerHTML=htmlCountry;
    }
    } // end of onreadstatechange function
    req.open("GET","usa.txt",true);
    req.send();
} // end of usaPop()


