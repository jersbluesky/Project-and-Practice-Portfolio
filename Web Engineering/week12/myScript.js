function create_jQuery() {
    startCity = document.getElementById("startCity").value;
    startState = document.getElementById("startState").value;
    endCity = document.getElementById("endCity").value;
    endState = document.getElementById("endState").value;
    jQueryString = "/cgi-bin/cs213/mileageAjaxJSON?startCity=" + startCity + "&endCity=" + endCity + "&startState=" + startState + "&endState=" + endState
    console.log(jQueryString);
    return jQueryString;
}
    
function loadDoc() {
    jQueryString = create_jQuery();
    const xhr = new XMLHttpRequest();
    xhr.onload = function() {
        if (this.status === 200) {
            try {
            const resObj = JSON.parse(this.responseText);
            output_results(resObj);
            
            } catch (e) {
                document.getElementById("div2").innerHTML = "There is an issue with the requested file. Contact your site administrator.";
            }
        }
        else {
            document.getElementById("div2").innerHTML = "File doesn't exist, or it was entered incorrectly. Try again!";
        }

    }

    xhr.open('GET', jQueryString, true);
    xhr.send();
}
function output_results(resObj) {
    var table = "<table><tr><th>Starting Location</th><th>Ending Location</th><th>Miles</th><th>Modes of Travel<th></tr>";
    console.log(resObj);
    tLength = resObj.trip.tmode.length;
    console.log(tLength);
    trip_mode = "";
    for (i=0; i < tLength; i++) {
        trip_mode += resObj.trip.tmode[i] + " ";
    }
    table += "<tr>";
    table += "<td>" + resObj.trip.startcity + " " + resObj.trip.startstate + "</td>";
    table += "<td>" + resObj.trip.endcity + " " + resObj.trip.endstate +  "</td>";
    table += "<td>" + resObj.trip.miles + "</td>";
    table += "<td>" + trip_mode + "</td>";
    table += "</tr>";
    console.log(table);
    document.getElementById("results").innerHTML = table;
    console.log(resObj);
}
