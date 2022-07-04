<?php
$choice = $_GET['submit'];
$message = "";
$heading = "";
if ($choice == "Confirm") {
    $heading = "Thanks for shopping with us!";
    $message = "Your purchase has been confirmed. You're the best!";
} else { 
    $heading = "Cancellation";
    $message = "Your purchase has been cancelled. That makes me sad.";
}
?>


<!DOCTYPE HTML>
<html lang="en-us">
<head>
</head>
<body>
    <?php
    echo "<h1>$heading</h1>"; 
    echo "$message";
    ?>
</body>
</html>