<?php



require_once './includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

db_query("SELECT count(1) from node");

//http_response_code(200);

//var_dump(http_response_code(200));

//print 200;
//return 200;
print header('X-PHP-Response-Code: 200', true, 200);

////////////////////////////////////////////////
//the below stuff all came from Example #1 on 
//http://php.net/manual/en/function.http-response-code.php

// Get the current default response code
//var_dump(http_response_code()); // int(200)

// Set our response code
//http_response_code(200);

// Get our new response code
//var_dump(http_response_code()); // int(404)

