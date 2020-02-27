<html>
    <head>
        <link href="//netdna.bootstrapcdn.com/bootstrap/3.1.0/css/bootstrap.min.css" rel="stylesheet" id="bootstrap-css">
        <script src="//netdna.bootstrapcdn.com/bootstrap/3.1.0/js/bootstrap.min.js"></script>
        <script src="//code.jquery.com/jquery-1.11.1.min.js"></script>
        <link rel="stylesheet" href="css/table.css">
    </head>


    <body>


        <nav class="navbar navbar-inverse">
            <div class="container-fluid">
                <a class="navbar-brand" href="#">Admin Page</a>
                <ul class="nav navbar-nav">
                    <li><a href="index.php">Home</a></li>
                    <li><a href="administration.php">Admin</a></li>
                    <li class="active"><a href="#">Table plan</a></li>
                    <li><a href="order_details.php">Food Order</a></li>
                    <li><a href="logout.php">Sign Out</a></li>
                </ul>
            </div>
        </nav>

        <?php include("./includes/connection.php");
        $query_menu = "SELECT* FROM admin";
        $run_query = mysqli_query($connect,$query_menu);
        $result = mysqli_fetch_assoc($run_query);
        $total_tables = $result['Tables'];
        ?>
        <div class="container">
            <h2 style="color:white">Table Planing</h2>
            <br>

            <div class="row">
                <div class="panel panel-primary filterable">
                    <div class="panel-heading">
                        <h3 class="panel-title">Table reservation</h3>

                    </div>
                    <br>
                    <br>

                    <form action="Table_connect.php" method="post">
                        <table class="table">
                            <thead>

                                <th>Table ID</th>
                                <th>Status</th>
                                <th>Delivery</th>
                                <th>Payment</th>

                            </thead>

                            <?php 
                            for ($i = 1; $i <= $total_tables; $i++){

                            ?>
                            <tr>
                                <td><?php echo $i; ?></td>
                                <td><select name="status[]">
                                    <option value="" disabled selected>Status</option>
                                    <option value="Open">Open</option>
                                    <option value="Dirty">Dirty</option>
                                    <option value="Occupied">Occupied</option>
                                    </select></td>

                                <td><select name="delivery[]" id="">
                                    <option value="----------">----------</option>
                                    <option value="Delivered">Delivered</option>
                                    <option value="Not yet">Not yet</option>
                                    </select></td>

                                <td><select name="payment[]" id="">
                                    <option value="----------">----------</option>
                                    <option value="Paid">Paid</option>
                                    <option value="Not yet">Not yet</option>
                                    </select></td>

                            </tr>

                            <?php }?>
                        </table>

                        <input type="submit" name="submit" class="btn btn-primary">
                    </form>


                </div>
            </div>
        </div>





    </body>

</html>