<?php
$arr = array(2, 4, 6, 8, 10 => 12);
echo 'arr count = '.count($arr) . "<br>";

echo 'arr[1] = '.$arr[1] . "<br>";
unset($arr[1]);

echo 'arr[1] = '.$arr[1] . "<br>";
$arr[9] = 11;
echo 'arr[9] = '.$arr[9] . "<br>";
echo 'arr count = '.count($arr) . "<br>";