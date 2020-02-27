<?php
include ("Table_Plan.php");

if(isset($_POST['status'])){
$status = $_POST['status'];
$delivery = $_POST['delivery'];
$payment = $_POST['payment'];


for($i = 0; $i < $total_tables; $i++){
    $j=$i+1;
    
    $sql1 = "UPDATE `table plan` SET `status`='$status[$i]' WHERE tableid=$j";
    $sql2 = "UPDATE `table plan` SET `delivery`='$delivery[$i]' WHERE tableid=$j";
    $sql3 = "UPDATE `table plan` SET `payment`='$payment[$i]' WHERE tableid=$j";

    $connect->query($sql1);
    $connect->query($sql2);
    $connect->query($sql3);

}



$query_menu1 = "SELECT* FROM orders";
$query_menu2 = "SELECT* FROM `table plan`";
$run_query1 = mysqli_query($connect,$query_menu1);
$run_query2 = mysqli_query($connect,$query_menu2);

for($i=0; $result2 = mysqli_fetch_assoc($run_query2); $i++ ){
    if(($result2["Delivery"]==='Delivered')&($result2["status"])==='Occupied'){
    $table_status[$i]=$result2["Delivery"];
}else{
    $table_status[$i]="Process";
}}

while($result1 = mysqli_fetch_assoc($run_query1)){
    $a=$result1["tableid"]-1;
    $b=$result1["tableid"];
    $sql2 = "UPDATE `orders` SET `Status` = '$table_status[$a]' WHERE tableid = $b";

    $connect->query($sql2);
}}

else {

$query_menu1 = "SELECT* FROM orders";
$query_menu2 = "SELECT* FROM `table plan`";
$run_query1 = mysqli_query($connect,$query_menu1);
$run_query2 = mysqli_query($connect,$query_menu2);

for($i=0; $result2 = mysqli_fetch_assoc($run_query2); $i++ ){
    if(($result2["Delivery"]==='Delivered')&($result2["status"])==='Occupied'){
    $table_status[$i]=$result2["Delivery"];
}else{
    $table_status[$i]="Process";
}}

while($result1 = mysqli_fetch_assoc($run_query1)){
    $a=$result1["tableid"]-1;
    $b=$result1["tableid"];
    $sql2 = "UPDATE `orders` SET `Status` = '$table_status[$a]' WHERE tableid = $b";

    $connect->query($sql2);
}}



?>