<?php
include("./includes/connection.php");
$PCs_detail = $_POST['piece_select'];
$table_no = $_POST['table_select'];

$pieces ="";


for ($i = 0; $i < sizeof($PCs_detail); $i++){
   $pieces = "$pieces"."$PCs_detail[$i]"."; ";
}


$sql = "INSERT INTO `orders` (`pieces`,`tableid`) VALUES ('$pieces','$table_no')";


if ($connect->query($sql) === TRUE){
    echo "New record created successfully";
}else{
    echo "Errors" . $sql . "<br>" . $connect->error;
}


$connect->close();


?>