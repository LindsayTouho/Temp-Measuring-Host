<!DOCTYPE html>
<html lang="en">
  <head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
    <title>搜索结果</title>
    <!-- Bootstrap CSS -->
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-beta/css/bootstrap.min.css" integrity="sha384-/Y6pD6FV/Vv2HJnA6t+vslU6fwYXjCFtcEpHbNJ0lyAFsXTsjBbfaDjzALeQsN6M" crossorigin="anonymous">
    <style>
      td{width:300px;
      border: solid #000 1px;
    }
    </style>
  </head>

  <body>
	<?php
  $ID = $_POST['ID'];
  $startDate = $_POST['startDate'];
  $endDate = $_POST['endDate'];

	$db = new mysqli('47.93.191.3','public','Changli','temperature');
	if(mysqli_connect_errno()){
		echo 'ERROR : can not connect to database';
		exit;
	}
	$query = "select * from ".$ID." where time >= '".$startDate."' and  time <='".$endDate." '";
	$db -> select_db("temperature");
	$result = $db -> query($query);
  $rowNum = $result -> num_rows;
  echo "存在".$rowNum."条记录 <br/>";
  echo '<table align = "center">';
  ?>
  <tr>
    <td>时间</td>
    <td>温度一</td>
    <td>温度二</td>
    <td>温度三</td>
    <td>温度四</td>
    <td>温度五</td>
    <td>温度六</td>
    <td>温度七</td>
    <td>温度八</td>
</tr>
  <?php
    for ($line = 0 ;$line != $rowNum; $line ++) {
      $row = $result -> fetch_assoc();
      echo '<tr>';
      echo '<td>';
      echo stripslashes($row['time']);
      echo '</td>';
      echo '<td>';
      echo stripslashes($row['T1']?$row['T1']:'NULL');
      echo '</td>';
      echo '<td>';
      echo stripslashes($row['T2']?$row['T2']:'NULL');
      echo '</td>';
      echo '<td>';
      echo stripslashes($row['T3']?$row['T3']:'NULL');
      echo '</td>';
      echo '<td>';
      echo stripslashes($row['T4']?$row['T4']:'NULL');
      echo '</td>';
      echo '<td>';
      echo stripslashes($row['T5']?$row['T5']:'NULL');
      echo '</td>';
      echo '<td>';
      echo stripslashes($row['T6']?$row['T6']:'NULL');
      echo '</td>';
      echo '<td>';
      echo stripslashes($row['T7']?$row['T7']:'NULL');
      echo '</td>';
      echo '<td>';
      echo stripslashes($row['T8']?$row['T8']:'NULL');
      echo '</td>';
      echo '</tr>';
    }
  echo '</table>';
?>
<!-- Optional JavaScript -->
<!-- jQuery first, then Popper.js, then Bootstrap JS -->
<script src="https://code.jquery.com/jquery-3.2.1.slim.min.js" integrity="sha384-KJ3o2DKtIkvYIK3UENzmM7KCkRr/rE9/Qpg6aAZGJwFDMVNA/GpGFF93hXpG5KkN" crossorigin="anonymous"></script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.11.0/umd/popper.min.js" integrity="sha384-b/U6ypiBEHpOf/4+1nzFpr53nxSS+GLCkfwBdFNTxtclqqenISfwAzpKaMNFNmj4" crossorigin="anonymous"></script>
<script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-beta/js/bootstrap.min.js" integrity="sha384-h0AbiXch4ZDo7tp9hKZ4TsHbi047NrKGLO3SEJAg45jXxnGIfYzk4Si90RDIqNm1" crossorigin="anonymous"></script>
</body>
</body>
