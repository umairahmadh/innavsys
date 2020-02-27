<!DOCTYPE html>
<html lang="en">
    <head>
        <link href="//netdna.bootstrapcdn.com/bootstrap/3.1.0/css/bootstrap.min.css" rel="stylesheet" id="bootstrap-css">
        <script src="//netdna.bootstrapcdn.com/bootstrap/3.1.0/js/bootstrap.min.js"></script>
        <script src="//code.jquery.com/jquery-1.11.1.min.js"></script>
        <!------ Include the above in your HEAD tag ---------->
        <script src="js/table.js"></script>
        <link rel="stylesheet" href="css/table.css">
    </head>

    <body>

        <nav class="navbar navbar-inverse">
            <div class="container-fluid">
                <a class="navbar-brand" href="#">Admin Page</a>
                <ul class="nav navbar-nav">
                    <li><a href="index.php">Home</a></li>
                    <li><a href="administration.php">Admin</a></li>
                    <li><a href="Table_Plan.php">Table plan</a></li>
                    <li  class="active"><a href="#">Food Order</a></li>
                    <li><a href="logout.php">Sign Out</a></li>  
                </ul>
            </div>
        </nav>

        <div class="container">
    <br><br>

            <div class="row">
                <div class="panel panel-primary filterable">
                    <div class="panel-heading">
                        <h3 class="panel-title">Orders</h3>
                        <div class="pull-right">
                            <button class="btn btn-default btn-xs btn-filter"><span class="glyphicon glyphicon-filter"></span> Filter</button>
                        </div>
                    </div>
                    <br>
                    <br>
                    <table class="table">
                        <thead>
                            <tr class="filters">
                                <th><input type="text" class="form-control" placeholder="Table No" disabled></th>
                                <th><input type="text" class="form-control" placeholder="Food Item" disabled></th>
                                <th><input type="text" class="form-control" placeholder="Pieces" disabled></th>
                                <th><input type="text" class="form-control" placeholder="Status" disabled></th>
                            </tr>
                        </thead>

                        <?php include("./includes/connection.php");
                        $query_menu = "SELECT* FROM orders";
                        $run_query = mysqli_query($connect,$query_menu);
                        while($result = mysqli_fetch_assoc($run_query)){ 
                        ?>
                        <tr>
                            <td><?php echo $result['tableid'];?></td>
                            <td><?php echo $result['food_item'];?></td>
                            <td><?php echo $result['pieces'];?></td>
                            <td><?php echo $result['status'];?></td>
                        </tr>

                        <?php }?>
                    </table>
                </div>
            </div>
        </div>
    </body>
</html>