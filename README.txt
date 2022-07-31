Various components can use this logger to print log on console, save log in a file
Various implicit requirements this project will comply are:
1. It can display timestamp 
2. Supported log categories - Error, warning, information
3. Asynchronous logging
	* New class LoggerController will have a queue of messages populated by main thread
	* LoggerController will have array of ILogger* that can contain as many different instances for different methods of logging
	* LoggerController will have instances of ConsoleLogger, FileLogger or any other logger
	* LoggerController will run a thread called as LoggerEngine that will continuously poll for any new messages in queue
	* LoggerEngine will pop the message from queue and call respective Logger implementation methods
	* LoggerSettings class is made singleton, created by LoggerController (if not already created by user) and will be consumed by all other classes
4. File logging is supported and log.txt attached to repo as sample output


Architecture

                 |-------------|                                                                                  
		 |   ILogger   | <-------------------------+----------------------------------+   
		 |-------------|                           |                                  |                  
		       ^                                   |                                  |                 
		       |                                   |                                  |
		 |------------------|              |---------------|                   |--------------|
		 | LoggerController |o-----+------>| ConsoleLogger |                   |  FileLogger  |
		 |------------------|      |       |---------------|                   |--------------|
		                           |                                                  ^
		                           |                                                  |
					   |--------------------------------------------------+
		 
		 
 Initialized Logger....
 Message 01
 WARN : Message 02 Warning
 ERROR : Message 03 Error
 Master Thread Message 0
 Master Thread Message 1
 Master Thread Message 2
 Master Thread Message 3
 Master Thread Message 4
 Master Thread Message 5
 Master Thread Message 6
 Master Thread Message 7
 Master Thread Message 8
 Master Thread Message 9
 Master Thread Message 10
 Master Thread Message 11
 Master Thread Message 12
 Master Thread Message 13
 Master Thread Message 14
 Master Thread Message 15
 Master Thread Message 16
 Master Thread Message 17
 Master Thread Message 18
 Master Thread Message 19
 Master Thread Message 20
 Master Thread Message 21
 Master Thread Message 22
 Master Thread Message 23
 Master Thread Message 24
 Master Thread Message 25
 Master Thread Message 26
 Master Thread Message 27
 Master Thread Message 28
 Master Thread Message 29
 Master Thread Message 30
 Master Thread Message 31
 Master Thread Message 32
 Master Thread Message 33
 Master Thread Message 34
 Master Thread Message 35
 Master Thread Message 36
 Master Thread Message 37
 Master Thread Message 38
 Master Thread Message 39
 Master Thread Message 40
 Master Thread Message 41
 Master Thread Message 42
 Master Thread Message 43
 Master Thread Message 44
 Master Thread Message 45
 Master Thread Message 46
 Master Thread Message 47
 Master Thread Message 48
 Master Thread Message 49
 Master Thread Message 50
 Master Thread Message 51
 Master Thread Message 52
 Master Thread Message 53
 Master Thread Message 54
 Master Thread Message 55
 Master Thread Message 56
 Master Thread Message 57
 Master Thread Message 58
 Master Thread Message 59
 Master Thread Message 60
 Master Thread Message 61
 Master Thread Message 62
 Master Thread Message 63
 Master Thread Message 64
 Master Thread Message 65
 Master Thread Message 66
 Master Thread Message 67
 Master Thread Message 68
 Master Thread Message 69
 Master Thread Message 70
 Master Thread Message 71
 Master Thread Message 72
 Master Thread Message 73
 Master Thread Message 74
 Master Thread Message 75
 Master Thread Message 76
 Master Thread Message 77
 Master Thread Message 78
 Master Thread Message 79
 Master Thread Message 80
 Master Thread Message 81
 Master Thread Message 82
 Master Thread Message 83
 Master Thread Message 84
 Master Thread Message 85
 Master Thread Message 86
 Master Thread Message 87
 Master Thread Message 88
 Master Thread Message 89
 Master Thread Message 90
 Master Thread Message 91
 Master Thread Message 92
 Master Thread Message 93
 Master Thread Message 94
 Master Thread Message 95
 Master Thread Message 96
 Master Thread Message 97
 Master Thread Message 98
 Master Thread Message 99
 Slave Thread Message 0
 Slave Thread Message 1
 Slave Thread Message 2
 Slave Thread Message 3
 Slave Thread Message 4
 Slave Thread Message 5
 Slave Thread Message 6
 Slave Thread Message 7
 Slave Thread Message 8
 Slave Thread Message 9
 Slave Thread Message 10
 Slave Thread Message 11
 Slave Thread Message 12
 Slave Thread Message 13
 Slave Thread Message 14
 Slave Thread Message 15
 Slave Thread Message 16
 Slave Thread Message 17
 Slave Thread Message 18
 Slave Thread Message 19
 Slave Thread Message 20
 Slave Thread Message 21
 Slave Thread Message 22
 Slave Thread Message 23
 Slave Thread Message 24
 Slave Thread Message 25
 Slave Thread Message 26
 Slave Thread Message 27
 Slave Thread Message 28
 Slave Thread Message 29
 Slave Thread Message 30
 Slave Thread Message 31
 Slave Thread Message 32
 Slave Thread Message 33
 Slave Thread Message 34
 Slave Thread Message 35
 Slave Thread Message 36
 Slave Thread Message 37
 Slave Thread Message 38
 Slave Thread Message 39
 Slave Thread Message 40
 Slave Thread Message 41
 Slave Thread Message 42
 Slave Thread Message 43
 Slave Thread Message 44
 Slave Thread Message 45
 Slave Thread Message 46
 Slave Thread Message 47
 Slave Thread Message 48
 Slave Thread Message 49
 Slave Thread Message 50
 Slave Thread Message 51
 Slave Thread Message 52
 Slave Thread Message 53
 Slave Thread Message 54
 Slave Thread Message 55
 Slave Thread Message 56
 Slave Thread Message 57
 Slave Thread Message 58
 Slave Thread Message 59
 Slave Thread Message 60
 Slave Thread Message 61
 Slave Thread Message 62
 Slave Thread Message 63
 Slave Thread Message 64
 Slave Thread Message 65
 Slave Thread Message 66
 Slave Thread Message 67
 Slave Thread Message 68
 Slave Thread Message 69
 Slave Thread Message 70
 Slave Thread Message 71
 Slave Thread Message 72
 Slave Thread Message 73
 Slave Thread Message 74
 Slave Thread Message 75
 Slave Thread Message 76
 Slave Thread Message 77
 Slave Thread Message 78
 Slave Thread Message 79
 Slave Thread Message 80
 Slave Thread Message 81
 Slave Thread Message 82
 Slave Thread Message 83
 Slave Thread Message 84
 Slave Thread Message 85
 Slave Thread Message 86
 Slave Thread Message 87
 Slave Thread Message 88
 Slave Thread Message 89
 Slave Thread Message 90
 Slave Thread Message 91
 Slave Thread Message 92
 Slave Thread Message 93
 Slave Thread Message 94
 Slave Thread Message 95
 Slave Thread Message 96
 Slave Thread Message 97
 Slave Thread Message 98
 Slave Thread Message 99
 Message 04
 Message 05

D:\Interviews\Logger\x64\Debug\Project2.exe (process 17220) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .
