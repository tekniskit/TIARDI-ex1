Topic
-----
Wrapper Facade Classes for Socket Communication
 
References
----------
POSA2, p.47-74
 
Goal
----
Obtaining experience with design and implementation of Wrapper Façade classes and obtaining knowledge of the different implementation options.
 
Platform
--------
PC with Windows operating system
 
Assignment
----------
<ol>
<li>Study and discuss the Logging Server code presented in POSA2 page 48.</li>

<li>Design and implement Socket wrapper facades (OO classes) wrapping the Socket C-API, for the following classes:
<ul>
  <li><em>INET_Addr</em></li>
  <li><em>SOCK_Stream</em></li>
  <li><em>SOCK_Acceptor</em></li>
  <li><em>SOCK_Connector</em></li>
</ul>
(NB! the three first classes are outlined in POSA2 p.61-63)
</li>

<li>Study the code for the new Logging Server based on the wrapper classes INET_Addr, SOCK_Stream and SOCK_Acceptor in POSA2 p.68-69 and compare it with the C version.</li>

<li>Develop a simple PC Server console application and a PC Client application based on these classes.
The PC server application shall write "Hello World from client xx" for each client connection.
	<ol>
		<li>Test the wrapper facades first with a PC server application as local host.</li>
		<li>Test the PC server application on another host on the network.</li>
	</ol>
</li>
</ol>
 
Product / delivery / deadline
-----------------------------
The wrapper classes shall be finished to be used in exercise 3.
 
Evaluation
----------
Will be tested on windows in this exercise and more comprehensive in exercise 3.

Background reading/guide
------------------------
<a href="http://beej.us/guide/bgnet/">Beej's Guide to Network Programming - Using Internet Sockets</a>
<br>
Written for Unix, but the socket-API is general OS-independent. Includes a short description of windows related subjects.