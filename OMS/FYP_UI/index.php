<!DOCTYPE html>
<html lang="en">
    <head>
        <title>Home</title>
        <meta charset="utf-8">
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.0/css/bootstrap.min.css">
        <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
        <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.0/js/bootstrap.min.js"></script>
    </head>
    <body>


        <?php include("./includes/connection.php");
        $query_menu = "SELECT* FROM food_menu";
        $cat_ = array("Burgers","Snacks","Buckets","Buriyani","Sawan","Smart Combos - Meals","Desserts and Beverages","Family Meals","Add - Ons");
        ?>


        <nav class="navbar navbar-inverse">
            <div class="container-fluid">
                <a class="navbar-brand" href="#">Order Management System</a>
                <ul class="nav navbar-nav">
                    <li class="active"><a href="#">Home</a></li>
                    <li><a href="login.php">Admin</a></li>
                    <li><a href="#">About</a></li>
                    <li><a href="#">Contact us</a></li>
                </ul>
            </div>
        </nav>

        <div class="container">

            <?php 

            for ($cat = 0; $cat < sizeof($cat_); $cat++){


                include("./includes/connection.php");
                $query_menu = "SELECT* FROM food_menu";
                $run_query = mysqli_query($connect,$query_menu);
                $result = mysqli_fetch_assoc($run_query);
                $piece="";?>

            <h2><?php echo $cat_[$cat]; ?></h2>
            <div class="row">
                <?php
                while($result = mysqli_fetch_assoc($run_query)){ 
                    if($result['catid']===$cat_[$cat]){
                ?>

                <div class="col-md-4">
                    <div class="thumbnail">
                        <a href='order.php?id1=<?php echo $result['catid']; ?>&id2=<?php echo $result['desc']; ?>&id3=<?php echo $result['pieces']; ?>'>
                            <img src="./Images/<?php echo $result['catid']?>/<?php echo $result['desc']?>.jpg" alt="" width="100">
                            <div class="caption">
                                <p><?php echo $result['desc']?></p>
                            </div>
                        </a>
                    </div>
                </div>

                <?php }} ?>
            </div>
            <br>
            <br>
            <?php    } ?>

        </div>

    </body>
</html>