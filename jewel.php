<html lang="en">
<head>
    <meta charset="UTF-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />

    <!-- Material Icons -->

    <link href="https://fonts.googleapis.com/icon?family=Material+Icons" rel="stylesheet" />
    <!-- CSS File -->
    <link rel="stylesheet" href="com.css" />
    <title>Final UI </title>
</head>
<body>
<div class="header">
    <div class="header__left">
      <img
        src="header.png"
        alt=""
      />
    </div>

    <div class="header__search">
      <form action="">
        <input type="text" placeholder="Search" />
        <button><i class="material-icons">search</i></button>
      </form>
    </div>

    <div class="header__icons">
      <i class="material-icons display-this">search</i>
      <i class="material-icons">more</i>
      <i class="material-icons">notifications</i>
      <i class="material-icons display-this">account_circle</i>
    </div>
  </div>
  <!-- Header Ends -->

  <!-- Main Body Starts -->  
  <center>
    <form action="" method="POST" enctype="multipart/form-data">
      <table style="width:100%">
        <thead>
          <tr>
            <th style="text-align:left"> PRODUCTNO </th>
            <th style="text-align:left"> PRODUCTNAME </th>
            <th  style="text-align:left"> QUANTITY </th>
            <th  style="text-align:left"> POSITION </th>
            <th  style="text-align:left"> PRICE </th>
            <th  style="text-align:left"> NETWEIGHT </th>
            <th  style="text-align:left"> IMAGE </th>

          </tr>
        </thead>
        <?php
          $connection = mysqli_connect("localhost","yoga","0987654321","caratlane");
          $query = " SELECT * FROM `jewel` ";
          $query_run = mysqli_query($connection,$query);
          
          while($row = mysqli_fetch_array($query_run))
          {
            ?>
            <tr>
              <td> <?php echo $row['prono']; ?> </td>
              <td> <?php echo $row['proname']; ?> </td>
              <td> <?php echo $row['Quantity']; ?> </td> 
              <td> <?php echo $row['position']; ?> </td>
              <td> <?php echo $row['price']; ?> </td>
              <td> <?php echo $row['netweight']; ?> </td>
              <td>
                <?php
                echo '<img src="data:image;base64,'.base64_encode($row['image']).'" alt="Image" style="width: 100px;height: 100px;" >';
                ?>
                <button class= "soldbutton" onClick="updateId(<?php echo $row['prono']; ?>)" >Sell</button>
                <style>
                  .soldbutton{
                    background-color: white;
                    border:0.1px
                    height: 50px;
                    align-items: center;
                    width: 50px;
                    border-radius: 3px;
                    cursor: pointer;
                    float: right ;
                    transition: opacity 0.15s;
                  }
                  .soldbutton:hover{
                    opacity: 0.8;
                  }
                  .soldbutton:active{
                    opacity: 0.5;
                  }
                </style>
                
              
              
              </td>
            
            </tr>

            <?php
          }

        
        ?>

        
      </table>

  <script src="	https://cdn.jsdelivr.net/npm/bootstrap@5.2.3/dist/js/bootstrap.bundle.min.js"></script>
  <script>
    function updateId(id)
{   
    var xmlhttp = new XMLHttpRequest();
    xmlhttp.onreadystatechange = function() {
        if (xmlhttp.readyState == 4 && xmlhttp.status == 200) 
        {
            console.log(xmlhttp.responseText);
        }
    };
    xmlhttp.open("GET", "del.php?id=" +id, true);
    xmlhttp.send();
}
  </script>

</body>
</html>