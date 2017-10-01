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
     <label>ID：</label>
     <input type = "test" name="ID" pattern="[A-Z][0-9]{4}"/>
     <label for="startDate">开始日期：</label>
     <input id="startDate" type = "text" name = "startDate" placeholder="格式(yy-mm-dd)"/>
     <label for="endDate">截至日期：</label>
     <input id="endDate" type="text" name="endDate" placeholder="格式(yyyy-mm-dd)" />
     <input type ="submit" value = "search" />
   </form>
 </center>
</body>
</html>
