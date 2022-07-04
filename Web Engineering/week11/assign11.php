<?php 
   $name = $_GET['first_name'] . " " . $_GET['last_name'];
   $address = $_GET['address'];
   $phone = $_GET['phone'];
   $num_dyno = $_GET['num_dyno'];
   $num_android = $_GET['num_android'];
   $num_lamp = $_GET['num_lamp'];
   $num_dragon = $_GET['num_dragon'];
   $total_dyno = $_GET['total_dyno'];
   $total_android = $_GET['total_android'];
   $total_lamp = $_GET['total_lamp'];
   $total_dragon = $_GET['total_dragon'];
   $total_cost = $_GET['total_price'];
   $card = $_GET['card'];
   $exp_date = $_GET['exp_date'];
   $dyno_string = "";
   $android_string = "";
   $lamp_string = "";
   $dragon_string = "";

    if ($num_dyno != 0) {
       $dyno_string = $num_dyno . " Dyno Pee Item(s) at " . $total_dyno . "<br /><br />";    
    }
    if ($num_android != 0) {
        $android_string = $num_android . " Phineas Android(s) at " . $total_android . "<br /><br />";    
    }
    if ($num_lamp != 0) {
        $lamp_string = $num_lamp . " Broken Lamp(s) at " . $total_lamp . "<br /><br />";    
    }
    if ($num_dragon != 0) {
        $dragon_string = $num_dragon . " Gary Busey Dragon(s) at " . $total_dragon . "<br /><br />";    
    }

  ?> 


<!DOCTYPE HTML>
<html lang="en-us">
<head>
</head>
<body>
    <h1>Purchase Confirmation Page</h1>
    <form class="d-flex flex-column align-items-start" action="assign11_a.php" method="GET">
        <?php
        echo "Name: $name <br /> <br />";
        echo "Address: $address <br /> <br/>";
        echo "Phone Number: $phone <br /> <br/>";
        echo "$dyno_string $android_string $lamp_string $dragon_string";
        echo "Total cost: $total_cost <br /><br />";
        echo "Credit Card Type: $card <br /><br />";
        echo "Expiration Date: $exp_date <br /><br />"
        ?>
        <input type="submit" name="submit" value="Confirm">  
        <input type="submit" name="submit" value="Cancel">
    </form>
</body>
</html>



