<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "order_management";

//create connection
$connect = mysqli_connect($servername,$username,$password,$dbname);

//check connection
if($connect->connect_error){
    die("connection failed: " . $connect->connect_error);
}
?>