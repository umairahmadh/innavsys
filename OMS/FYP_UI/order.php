<html>
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <link href="./css/thanksmsg.css" rel="stylesheet">
        <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.0/css/bootstrap.min.css">
        <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
        <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.0/js/bootstrap.min.js"></script>
        <title>Order</title>
    </head>
    <body>


        <nav class="navbar navbar-inverse">
            <div class="container-fluid">
                <a class="navbar-brand" href="#">Order Management System</a>
                <ul class="nav navbar-nav">
                    <li><a href="index.php">Home</a></li>
                    <li class="active"><a href="#">Order</a></li>
                </ul>
            </div>
        </nav>


        <div class="container">
            <?php 
            include("./includes/connection.php");
            $query_menu = "SELECT* FROM admin";
            $run_query = mysqli_query($connect,$query_menu);
            $result = mysqli_fetch_assoc($run_query);
            $total_tables = $result['Tables'];
            $piece="";

            if(isset($_GET['id1'])){
                $foodi=$_GET['id2']; $image="./Images/".$_GET['id1']."/".$_GET['id2'].".jpg";
                $PCs_detail="";
                $table_no=0;
                $table_status="Start";
                
                $sql = "INSERT INTO `orders` (`food_item`,`pieces`,`tableid`,`status`) VALUES ('$foodi','$PCs_detail','$table_no','$table_status')";
              $connect->query($sql);
            ?>

            <div class="col-md-4">
                <div class="thumbnail">
                    <img src="<?php echo $image?>" alt="" width="250">
                </div>
            </div>

            <form action="#" method="get">
                <br>
                <br>
                PCs:
                    <select name="piece_select" class="piece_select">
                        <option value="" disabled selected>--</option>
                        <?php for ($i = 1; $i <= $_GET['id3']; $i++){ ?>
                        <option value="<?php echo $i; ?>"><?php echo $i;?></option>   
                        <?php }?>
                    </select>
                &emsp; &emsp;
                Table Number:
                    <select name="table_select" class="piece_select">
                        <option value="" disabled selected>--</option>
                        <?php for ($i = 1; $i <= $total_tables; $i++){ ?>
                        <option value="<?php echo $i; ?>"><?php echo $i;?></option>   
                        <?php } ?>
                    </select>
                &emsp; &emsp;
                <input class="btn-primary btn-sm" type="submit" name="submit" value="OK">
            </form>
            <?php }?>

            <?php if(isset($_GET['submit'])){ ?>
            <a style="text-align:center;display:block;" class="btn-primary btn-lg" data-toggle="modal" class="login-button" href="#ignismyModal">Order Your Food</a>
            
        

            <?php

            if(isset($_GET['submit']) & isset($_GET['piece_select']) & isset($_GET['table_select'])){

                $PCs_detail = $_GET['piece_select'];
                $table_no = $_GET['table_select'];
                $pieces="";

                $result=mysqli_query($connect,"SELECT MAX(orderid) AS maximum FROM orders");
                $row=mysqli_fetch_assoc($result);
                $maximum=$row['maximum'];


                $sql1 = "UPDATE `orders` SET `pieces`='$PCs_detail' WHERE orderid=$maximum";
                $sql2 = "UPDATE `orders` SET `tableid`='$table_no' WHERE orderid=$maximum";
                $connect->query($sql1);
                $connect->query($sql2);
            }} ?>
            
            <?php if(isset($_GET['piece_select'])){ ?>
            <div class="modal fade" id="ignismyModal" role="dialog">
                <div class="modal-dialog">
                    <div class="modal-content">
                        <div class="modal-header">
                            <button type="button" class="close" data-dismiss="modal" aria-label=""><span>×</span></button>
                        </div>
                        <div class="modal-body">
                            <div class="thank-you-pop">  
                                <img src="./Images/tick.jpg" alt="">
                                <h1>Thank You!</h1>
                                <p>Your submission is received and we will contact you soon</p>
                                <h3 class="cupon-pop">Your Id: <span><?php echo $maximum;?></span></h3> 
                            </div>
                        </div>
                    </div>
                </div>
            </div>
            <?php } else {?>
            <div class="modal fade" id="ignismyModal" role="dialog">
                <div class="modal-dialog">
                    <div class="modal-content">
                        <div class="modal-header">
                            <button type="button" class="close" data-dismiss="modal" aria-label=""><span>×</span></button>
                        </div>
                        <div class="modal-body">
                            <div class="thank-you-pop">  
                                <img src="./Images/cross.jpg" alt="">
                                <h1>Sorry!</h1>
                                <p>Please enter the amount of dishes and the table number</p>
                                <h3 class="cupon-pop">Try again</h3>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
            <?php $connect->close();}?>


        </div>
    </body>
</html>



