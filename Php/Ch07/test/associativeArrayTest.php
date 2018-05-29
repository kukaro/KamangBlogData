<?php
$arr = array(2, 4, 'a'=> 6, 'b'=>8, 'c' => 12);
echo 'arr count = '.count($arr) . "<br>";

echo 'arr[\'a\'] = '.$arr['a'] . "<br>";

$arr['d'] = 16;
echo 'arr[\'d\'] = '.count($arr) . "<br>";