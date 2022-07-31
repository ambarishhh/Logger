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
		 
Mon Aug  1 00:18:39 2022 Initialized Logger....
Mon Aug  1 00:18:39 2022 Message 01
Mon Aug  1 00:18:39 2022 WARN : Message 02 Warning
Mon Aug  1 00:18:39 2022 ERROR : Message 03 Error
Mon Aug  1 00:18:39 2022 Master Thread Message 0
Mon Aug  1 00:18:39 2022 Master Thread Message 1
Mon Aug  1 00:18:39 2022 Master Thread Message 2
Mon Aug  1 00:18:39 2022 Master Thread Message 3
Mon Aug  1 00:18:39 2022 Master Thread Message 4
Mon Aug  1 00:18:39 2022 Master Thread Message 5
Mon Aug  1 00:18:39 2022 Master Thread Message 6
Mon Aug  1 00:18:39 2022 Master Thread Message 7
Mon Aug  1 00:18:39 2022 Master Thread Message 8
Mon Aug  1 00:18:39 2022 Master Thread Message 9
Mon Aug  1 00:18:39 2022 Master Thread Message 10
Mon Aug  1 00:18:39 2022 Master Thread Message 11
Mon Aug  1 00:18:39 2022 Master Thread Message 12
Mon Aug  1 00:18:39 2022 Master Thread Message 13
Mon Aug  1 00:18:39 2022 Master Thread Message 14
Mon Aug  1 00:18:39 2022 Master Thread Message 15
Mon Aug  1 00:18:39 2022 Master Thread Message 16
Mon Aug  1 00:18:39 2022 Master Thread Message 17
Mon Aug  1 00:18:39 2022 Master Thread Message 18
Mon Aug  1 00:18:39 2022 Master Thread Message 19
Mon Aug  1 00:18:39 2022 Master Thread Message 20
Mon Aug  1 00:18:39 2022 Master Thread Message 21
Mon Aug  1 00:18:39 2022 Master Thread Message 22
Mon Aug  1 00:18:39 2022 Master Thread Message 23
Mon Aug  1 00:18:39 2022 Master Thread Message 24
Mon Aug  1 00:18:39 2022 Master Thread Message 25
Mon Aug  1 00:18:39 2022 Master Thread Message 26
Mon Aug  1 00:18:39 2022 Master Thread Message 27
Mon Aug  1 00:18:39 2022 Master Thread Message 28
Mon Aug  1 00:18:39 2022 Master Thread Message 29
Mon Aug  1 00:18:39 2022 Master Thread Message 30
Mon Aug  1 00:18:39 2022 Master Thread Message 31
Mon Aug  1 00:18:39 2022 Master Thread Message 32
Mon Aug  1 00:18:39 2022 Master Thread Message 33
Mon Aug  1 00:18:39 2022 Master Thread Message 34
Mon Aug  1 00:18:39 2022 Master Thread Message 35
Mon Aug  1 00:18:39 2022 Master Thread Message 36
Mon Aug  1 00:18:39 2022 Master Thread Message 37
Mon Aug  1 00:18:39 2022 Master Thread Message 38
Mon Aug  1 00:18:39 2022 Master Thread Message 39
Mon Aug  1 00:18:39 2022 Master Thread Message 40
Mon Aug  1 00:18:39 2022 Master Thread Message 41
Mon Aug  1 00:18:39 2022 Master Thread Message 42
Mon Aug  1 00:18:39 2022 Master Thread Message 43
Mon Aug  1 00:18:39 2022 Master Thread Message 44
Mon Aug  1 00:18:39 2022 Master Thread Message 45
Mon Aug  1 00:18:39 2022 Master Thread Message 46
Mon Aug  1 00:18:39 2022 Master Thread Message 47
Mon Aug  1 00:18:39 2022 Master Thread Message 48
Mon Aug  1 00:18:39 2022 Master Thread Message 49
Mon Aug  1 00:18:39 2022 Master Thread Message 50
Mon Aug  1 00:18:39 2022 Master Thread Message 51
Mon Aug  1 00:18:39 2022 Master Thread Message 52
Mon Aug  1 00:18:39 2022 Master Thread Message 53
Mon Aug  1 00:18:39 2022 Master Thread Message 54
Mon Aug  1 00:18:39 2022 Master Thread Message 55
Mon Aug  1 00:18:39 2022 Master Thread Message 56
Mon Aug  1 00:18:39 2022 Master Thread Message 57
Mon Aug  1 00:18:39 2022 Master Thread Message 58
Mon Aug  1 00:18:39 2022 Master Thread Message 59
Mon Aug  1 00:18:39 2022 Master Thread Message 60
Mon Aug  1 00:18:39 2022 Master Thread Message 61
Mon Aug  1 00:18:39 2022 Master Thread Message 62
Mon Aug  1 00:18:39 2022 Master Thread Message 63
Mon Aug  1 00:18:39 2022 Master Thread Message 64
Mon Aug  1 00:18:39 2022 Master Thread Message 65
Mon Aug  1 00:18:39 2022 Master Thread Message 66
Mon Aug  1 00:18:39 2022 Master Thread Message 67
Mon Aug  1 00:18:39 2022 Master Thread Message 68
Mon Aug  1 00:18:39 2022 Master Thread Message 69
Mon Aug  1 00:18:39 2022 Master Thread Message 70
Mon Aug  1 00:18:39 2022 Master Thread Message 71
Mon Aug  1 00:18:39 2022 Master Thread Message 72
Mon Aug  1 00:18:39 2022 Master Thread Message 73
Mon Aug  1 00:18:39 2022 Master Thread Message 74
Mon Aug  1 00:18:39 2022 Master Thread Message 75
Mon Aug  1 00:18:39 2022 Master Thread Message 76
Mon Aug  1 00:18:39 2022 Master Thread Message 77
Mon Aug  1 00:18:39 2022 Master Thread Message 78
Mon Aug  1 00:18:39 2022 Master Thread Message 79
Mon Aug  1 00:18:39 2022 Master Thread Message 80
Mon Aug  1 00:18:39 2022 Master Thread Message 81
Mon Aug  1 00:18:39 2022 Master Thread Message 82
Mon Aug  1 00:18:39 2022 Master Thread Message 83
Mon Aug  1 00:18:39 2022 Master Thread Message 84
Mon Aug  1 00:18:39 2022 Master Thread Message 85
Mon Aug  1 00:18:39 2022 Master Thread Message 86
Mon Aug  1 00:18:39 2022 Master Thread Message 87
Mon Aug  1 00:18:39 2022 Master Thread Message 88
Mon Aug  1 00:18:39 2022 Master Thread Message 89
Mon Aug  1 00:18:39 2022 Master Thread Message 90
Mon Aug  1 00:18:39 2022 Master Thread Message 91
Mon Aug  1 00:18:39 2022 Master Thread Message 92
Mon Aug  1 00:18:39 2022 Master Thread Message 93
Mon Aug  1 00:18:39 2022 Master Thread Message 94
Mon Aug  1 00:18:39 2022 Master Thread Message 95
Mon Aug  1 00:18:39 2022 Master Thread Message 96
Mon Aug  1 00:18:39 2022 Master Thread Message 97
Mon Aug  1 00:18:39 2022 Master Thread Message 98
Mon Aug  1 00:18:39 2022 Master Thread Message 99
Mon Aug  1 00:18:39 2022 Slave Thread Message 0
Mon Aug  1 00:18:39 2022 Slave Thread Message 1
Mon Aug  1 00:18:39 2022 Slave Thread Message 2
Mon Aug  1 00:18:39 2022 Slave Thread Message 3
Mon Aug  1 00:18:39 2022 Slave Thread Message 4
Mon Aug  1 00:18:39 2022 Slave Thread Message 5
Mon Aug  1 00:18:39 2022 Slave Thread Message 6
Mon Aug  1 00:18:39 2022 Slave Thread Message 7
Mon Aug  1 00:18:39 2022 Slave Thread Message 8
Mon Aug  1 00:18:39 2022 Slave Thread Message 9
Mon Aug  1 00:18:39 2022 Slave Thread Message 10
Mon Aug  1 00:18:39 2022 Slave Thread Message 11
Mon Aug  1 00:18:39 2022 Slave Thread Message 12
Mon Aug  1 00:18:39 2022 Slave Thread Message 13
Mon Aug  1 00:18:39 2022 Slave Thread Message 14
Mon Aug  1 00:18:39 2022 Slave Thread Message 15
Mon Aug  1 00:18:39 2022 Slave Thread Message 16
Mon Aug  1 00:18:39 2022 Slave Thread Message 17
Mon Aug  1 00:18:39 2022 Slave Thread Message 18
Mon Aug  1 00:18:39 2022 Slave Thread Message 19
Mon Aug  1 00:18:39 2022 Slave Thread Message 20
Mon Aug  1 00:18:39 2022 Slave Thread Message 21
Mon Aug  1 00:18:39 2022 Slave Thread Message 22
Mon Aug  1 00:18:39 2022 Slave Thread Message 23
Mon Aug  1 00:18:39 2022 Slave Thread Message 24
Mon Aug  1 00:18:39 2022 Slave Thread Message 25
Mon Aug  1 00:18:39 2022 Slave Thread Message 26
Mon Aug  1 00:18:39 2022 Slave Thread Message 27
Mon Aug  1 00:18:39 2022 Slave Thread Message 28
Mon Aug  1 00:18:39 2022 Slave Thread Message 29
Mon Aug  1 00:18:39 2022 Slave Thread Message 30
Mon Aug  1 00:18:39 2022 Slave Thread Message 31
Mon Aug  1 00:18:39 2022 Slave Thread Message 32
Mon Aug  1 00:18:39 2022 Slave Thread Message 33
Mon Aug  1 00:18:39 2022 Slave Thread Message 34
Mon Aug  1 00:18:39 2022 Slave Thread Message 35
Mon Aug  1 00:18:39 2022 Slave Thread Message 36
Mon Aug  1 00:18:39 2022 Slave Thread Message 37
Mon Aug  1 00:18:39 2022 Slave Thread Message 38
Mon Aug  1 00:18:39 2022 Slave Thread Message 39
Mon Aug  1 00:18:39 2022 Slave Thread Message 40
Mon Aug  1 00:18:39 2022 Slave Thread Message 41
Mon Aug  1 00:18:39 2022 Slave Thread Message 42
Mon Aug  1 00:18:39 2022 Slave Thread Message 43
Mon Aug  1 00:18:39 2022 Slave Thread Message 44
Mon Aug  1 00:18:39 2022 Slave Thread Message 45
Mon Aug  1 00:18:39 2022 Slave Thread Message 46
Mon Aug  1 00:18:39 2022 Slave Thread Message 47
Mon Aug  1 00:18:39 2022 Slave Thread Message 48
Mon Aug  1 00:18:39 2022 Slave Thread Message 49
Mon Aug  1 00:18:39 2022 Slave Thread Message 50
Mon Aug  1 00:18:39 2022 Slave Thread Message 51
Mon Aug  1 00:18:39 2022 Slave Thread Message 52
Mon Aug  1 00:18:39 2022 Slave Thread Message 53
Mon Aug  1 00:18:39 2022 Slave Thread Message 54
Mon Aug  1 00:18:39 2022 Slave Thread Message 55
Mon Aug  1 00:18:39 2022 Slave Thread Message 56
Mon Aug  1 00:18:39 2022 Slave Thread Message 57
Mon Aug  1 00:18:39 2022 Slave Thread Message 58
Mon Aug  1 00:18:39 2022 Slave Thread Message 59
Mon Aug  1 00:18:39 2022 Slave Thread Message 60
Mon Aug  1 00:18:39 2022 Slave Thread Message 61
Mon Aug  1 00:18:39 2022 Slave Thread Message 62
Mon Aug  1 00:18:39 2022 Slave Thread Message 63
Mon Aug  1 00:18:39 2022 Slave Thread Message 64
Mon Aug  1 00:18:39 2022 Slave Thread Message 65
Mon Aug  1 00:18:39 2022 Slave Thread Message 66
Mon Aug  1 00:18:39 2022 Slave Thread Message 67
Mon Aug  1 00:18:39 2022 Slave Thread Message 68
Mon Aug  1 00:18:39 2022 Slave Thread Message 69
Mon Aug  1 00:18:39 2022 Slave Thread Message 70
Mon Aug  1 00:18:39 2022 Slave Thread Message 71
Mon Aug  1 00:18:39 2022 Slave Thread Message 72
Mon Aug  1 00:18:39 2022 Slave Thread Message 73
Mon Aug  1 00:18:39 2022 Slave Thread Message 74
Mon Aug  1 00:18:39 2022 Slave Thread Message 75
Mon Aug  1 00:18:39 2022 Slave Thread Message 76
Mon Aug  1 00:18:39 2022 Slave Thread Message 77
Mon Aug  1 00:18:39 2022 Slave Thread Message 78
Mon Aug  1 00:18:39 2022 Slave Thread Message 79
Mon Aug  1 00:18:39 2022 Slave Thread Message 80
Mon Aug  1 00:18:39 2022 Slave Thread Message 81
Mon Aug  1 00:18:39 2022 Slave Thread Message 82
Mon Aug  1 00:18:39 2022 Slave Thread Message 83
Mon Aug  1 00:18:39 2022 Slave Thread Message 84
Mon Aug  1 00:18:39 2022 Slave Thread Message 85
Mon Aug  1 00:18:39 2022 Slave Thread Message 86
Mon Aug  1 00:18:39 2022 Slave Thread Message 87
Mon Aug  1 00:18:39 2022 Slave Thread Message 88
Mon Aug  1 00:18:39 2022 Slave Thread Message 89
Mon Aug  1 00:18:39 2022 Slave Thread Message 90
Mon Aug  1 00:18:39 2022 Slave Thread Message 91
Mon Aug  1 00:18:39 2022 Slave Thread Message 92
Mon Aug  1 00:18:39 2022 Slave Thread Message 93
Mon Aug  1 00:18:39 2022 Slave Thread Message 94
Mon Aug  1 00:18:39 2022 Slave Thread Message 95
Mon Aug  1 00:18:39 2022 Slave Thread Message 96
Mon Aug  1 00:18:39 2022 Slave Thread Message 97
Mon Aug  1 00:18:39 2022 Slave Thread Message 98
Mon Aug  1 00:18:39 2022 Slave Thread Message 99
Mon Aug  1 00:18:39 2022 Message 04
Mon Aug  1 00:18:39 2022 Message 05

D:\Interviews\Logger\x64\Debug\Project2.exe (process 452) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

