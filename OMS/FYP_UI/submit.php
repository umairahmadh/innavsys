<?php

$x=$_POST['Username'];
$y=$_POST['Password'];
include ("./includes/connection.php");

$sql = "INSERT INTO `user` (`Uname`,`Upassword`) VALUES ('$x','$y')";

$connect->query($sql);
$connect->close();
?>