<?php 
if(isset($_GET['id']) && !empty($_GET['id']))
{
    $id = $_GET['id'];
    include('jewel.php');
    $connection = mysqli_connect("localhost","yoga","0987654321","caratlane");
    $query1 = " UPDATE jewel SET Quantity = Quantity-1  WHERE prono= $id";

    if (mysqli_query($connection, $query1))
    {
        echo "Record updated successfully";
    } 
    else 
    {
        echo "Error updating record: " . mysqli_error($connect);
    }
    die;
}
?>



