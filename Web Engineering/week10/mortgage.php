<?php 
   $p = $_GET['principal'];
   $a = $_GET['apr'];
   $y = $_GET['yrs'];   
   $a1 = $a / 100;
   $r = $a1 / 12;
   $n = 12 * $y;
   $mp = ($p * $r) / (1 - (1 + $r) **-$n);
  ?> 


<!DOCTYPE HTML>
<html lang="en-us">
<head>
</head>
<body>
<h1>Monthly Payment Calculator</h1>
<?php
  setlocale(LC_MONETARY, 'en_US');
  echo "Loan Amount: $p <br /> <br />";
  echo "APR: $a <br /> <br />";
  echo "Loan Term (in years): $y  <br /> <br />"; 
  echo "The monthly payment is: ";
  echo money_format('%i', $mp) . "\n";
  ?>
</body>
</html>




<!-- 
function calculatePayment() {

    let mpFormatted = formatter.format(mp)
    document.getElementById('outputDiv1').innerHTML = mpFormatted;
} -->


