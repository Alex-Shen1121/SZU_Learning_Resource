$('li[id!="one"]').hide().delay(500).fadeIn(1400); // semi-colon indicates end of chaining - can be writen on separate lines
$('li:first-child').addClass('next');
$('li.priority').addClass('highlight');