--TEST--
Check for get_percentage without rounding
--SKIPIF--
<?php if (!extension_loaded("u4u_functions")) print "skip"; ?>
--FILE--
<?php 
echo get_percentage(10, 33, true);
?>
--EXPECT--
3.3
