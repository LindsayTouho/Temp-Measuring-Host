<?php
	$userName = $_POST['userName'];
	$passWd = $_POST['passWord'];

	$db = new mysqli('47.93.191.3','public','Changli','temperature');
	if(mysqli_connect_errno()){
		echo 'ERROR : can not connect to database';
		exit;
	}
	require('header.php');

	require('footer.php');

?>
