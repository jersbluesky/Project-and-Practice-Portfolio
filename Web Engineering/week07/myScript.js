const formatter = new Intl.NumberFormat('en-US', {
  style: 'currency',
  currency: 'USD',
  minimumFractionDigits: 2
})


function calculatePayment() {
    let p = parseFloat(document.getElementById("principal").value);
    let a = parseFloat(document.getElementById("apr").value);
    let y = parseFloat(document.getElementById("yrs").value);    
    let a1 = a / 100;
    let r = a1 / 12;
    let n = 12 * y;
    let mp = (p * r) / (1 - (1 + r) **-n);
    let mpFormatted = formatter.format(mp)

    document.getElementById('outputDiv1').innerHTML = mpFormatted;
}

function resetForm() {
    document.getElementById("loanCalculator").reset();
}

