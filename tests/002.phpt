--TEST--
Check for get_percentage with rounding
--SKIPIF--
<?php if (!extension_loaded("u4u_functions")) print "skip"; ?>
--FILE--
<?php 
echo get_percentage(10, 33, false);
?>
--EXPECT--
3
