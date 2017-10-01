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
    <form method="post" action="search.php" target="_blank">
     <label>ID：</label>
     <input type = "test" name="ID" style="width:250px" list="idList"  required/>
     <datalist id="idList">
       <option value="A111">目前唯一可用ID</option>
     </datalist>
     <label for="startDate">开始日期：</label>
     <input id="startDate" type = "date" name = "startDate" style="width:250px" required />
     <label for="endDate">截至日期：</label>
     <input id="endDate" type="date" name="endDate" style="width:250px" required/>
     <label for="upTemper">上限温度</label>
     <input id="upTemper" type="text" name="upTemper" style="width:250px" placeholder="(选填)">
     <input type ="submit" value = "搜索" />
   </form>
 </center>
</body>
</html>
