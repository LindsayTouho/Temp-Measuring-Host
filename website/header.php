<!DOCTYPE html>
<html lang="en">
  <head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
    <title>Welcome</title>
    <!-- Bootstrap CSS -->
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-beta/css/bootstrap.min.css" integrity="sha384-/Y6pD6FV/Vv2HJnA6t+vslU6fwYXjCFtcEpHbNJ0lyAFsXTsjBbfaDjzALeQsN6M" crossorigin="anonymous">
  </head>
  <body>
    <center>
    <form method="post" action="search.php">
     <span>ID：</span>
     <input type = "test" name="ID"/>
     <span>	&nbsp	&nbsp	&nbsp	&nbsp</span>
     <span>开始日期：</span>
     <input type = "text" name = "startDate" placeholder="格式(yy-mm-dd)"/>
     <span>	&nbsp	&nbsp	&nbsp	&nbsp</span>
     <span>截至日期：</span>
     <input type = "text" name = "endDate" placeholder="格式(yy-mm-dd)" />
     <span>	&nbsp	&nbsp	&nbsp	&nbsp</span>
     <input type ="submit" value = "search" />
   </form>
 </center>
</body>
</html>
