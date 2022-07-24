Various components can use this logger to print log on console, save log in a file
Various implicit requirements this project will comply are:
1. It can display timestamp 
2. Supported log categories - Error, warning, information
3. Sometimes user may not want to print on console as they log, they may choose to do so by setting verbose argument
5. Saving to file is a time or lesser time operation.
4. Logs saved in file in case of exception
5. Return the mutex for cout to client code
6. Automatic deletion of logger object in the program end and save any unlogged data

Future Scope/ideas

Threadwise settings and logging
. Current implementation prints/saves log based on the time of statement execution.
. Developers may want to see threadwise logs. This could be done by storing the logs in container threadwise.
. Similarly settings could be stored threadwise
	
Unit Tests

Output : 
Sun Jul 24 06:08:22 2022 Message 01
Sun Jul 24 06:08:22 2022 WARN : Message 02 Warning
Sun Jul 24 06:08:22 2022 ERROR : Message 03 Error
Sun Jul 24 06:08:22 2022 Master Thread Message 0
Sun Jul 24 06:08:22 2022 Master Thread Message 1
Sun Jul 24 06:08:22 2022 Master Thread Message 2
Sun Jul 24 06:08:22 2022 Master Thread Message 3
Sun Jul 24 06:08:22 2022 Master Thread Message 4
Sun Jul 24 06:08:22 2022 Master Thread Message 5
Sun Jul 24 06:08:22 2022 Master Thread Message 6
Sun Jul 24 06:08:22 2022 Master Thread Message 7
Sun Jul 24 06:08:22 2022 Master Thread Message 8
Sun Jul 24 06:08:22 2022 Master Thread Message 9
Sun Jul 24 06:08:22 2022 Master Thread Message 10
Sun Jul 24 06:08:22 2022 Master Thread Message 11
Sun Jul 24 06:08:22 2022 Master Thread Message 12
Sun Jul 24 06:08:22 2022 Master Thread Message 13
Sun Jul 24 06:08:22 2022 Master Thread Message 14
Sun Jul 24 06:08:22 2022 Master Thread Message 15
Sun Jul 24 06:08:22 2022 Master Thread Message 16
Sun Jul 24 06:08:22 2022 Master Thread Message 17
Sun Jul 24 06:08:22 2022 Master Thread Message 18
Sun Jul 24 06:08:22 2022 Master Thread Message 19
Sun Jul 24 06:08:22 2022 Slave Thread Message 0
Sun Jul 24 06:08:22 2022 Master Thread Message 20
Sun Jul 24 06:08:22 2022 Master Thread Message 21
Sun Jul 24 06:08:22 2022 Master Thread Message 22
Sun Jul 24 06:08:22 2022 Master Thread Message 23
Sun Jul 24 06:08:22 2022 Slave Thread Message 1
Sun Jul 24 06:08:22 2022 Master Thread Message 24
Sun Jul 24 06:08:22 2022 Slave Thread Message 2
Sun Jul 24 06:08:22 2022 Master Thread Message 25
Sun Jul 24 06:08:22 2022 Slave Thread Message 3
Sun Jul 24 06:08:22 2022 Master Thread Message 26
Sun Jul 24 06:08:22 2022 Master Thread Message 27
Sun Jul 24 06:08:22 2022 Slave Thread Message 4
Sun Jul 24 06:08:22 2022 Master Thread Message 28
Sun Jul 24 06:08:22 2022 Slave Thread Message 5
Sun Jul 24 06:08:22 2022 Master Thread Message 29
Sun Jul 24 06:08:22 2022 Slave Thread Message 6
Sun Jul 24 06:08:22 2022 Master Thread Message 30
Sun Jul 24 06:08:22 2022 Slave Thread Message 7
Sun Jul 24 06:08:22 2022 Master Thread Message 31
Sun Jul 24 06:08:22 2022 Master Thread Message 32
Sun Jul 24 06:08:22 2022 Slave Thread Message 8
Sun Jul 24 06:08:22 2022 Master Thread Message 33
Sun Jul 24 06:08:22 2022 Master Thread Message 34
Sun Jul 24 06:08:22 2022 Master Thread Message 35
Sun Jul 24 06:08:22 2022 Master Thread Message 36
Sun Jul 24 06:08:22 2022 Master Thread Message 37
Sun Jul 24 06:08:22 2022 Master Thread Message 38
Sun Jul 24 06:08:22 2022 Master Thread Message 39
Sun Jul 24 06:08:22 2022 Master Thread Message 40
Sun Jul 24 06:08:22 2022 Master Thread Message 41
Sun Jul 24 06:08:22 2022 Master Thread Message 42
Sun Jul 24 06:08:22 2022 Master Thread Message 43
Sun Jul 24 06:08:22 2022 Master Thread Message 44
Sun Jul 24 06:08:22 2022 Master Thread Message 45
Sun Jul 24 06:08:22 2022 Master Thread Message 46
Sun Jul 24 06:08:22 2022 Master Thread Message 47
Sun Jul 24 06:08:22 2022 Master Thread Message 48
Sun Jul 24 06:08:22 2022 Master Thread Message 49
Sun Jul 24 06:08:22 2022 Master Thread Message 50
Sun Jul 24 06:08:22 2022 Master Thread Message 51
Sun Jul 24 06:08:22 2022 Master Thread Message 52
Sun Jul 24 06:08:22 2022 Master Thread Message 53
Sun Jul 24 06:08:22 2022 Master Thread Message 54
Sun Jul 24 06:08:22 2022 Master Thread Message 55
Sun Jul 24 06:08:22 2022 Master Thread Message 56
Sun Jul 24 06:08:23 2022 Master Thread Message 57
Sun Jul 24 06:08:23 2022 Master Thread Message 58
Sun Jul 24 06:08:23 2022 Master Thread Message 59
Sun Jul 24 06:08:22 2022 Slave Thread Message 9
Sun Jul 24 06:08:23 2022 Master Thread Message 60
Sun Jul 24 06:08:23 2022 Master Thread Message 61
Sun Jul 24 06:08:23 2022 Master Thread Message 62
Sun Jul 24 06:08:23 2022 Master Thread Message 63
Sun Jul 24 06:08:23 2022 Master Thread Message 64
Sun Jul 24 06:08:23 2022 Master Thread Message 65
Sun Jul 24 06:08:23 2022 Master Thread Message 66
Sun Jul 24 06:08:23 2022 Master Thread Message 67
Sun Jul 24 06:08:23 2022 Master Thread Message 68
Sun Jul 24 06:08:23 2022 Slave Thread Message 10
Sun Jul 24 06:08:23 2022 Master Thread Message 69
Sun Jul 24 06:08:23 2022 Master Thread Message 70
Sun Jul 24 06:08:23 2022 Slave Thread Message 11
Sun Jul 24 06:08:23 2022 Slave Thread Message 12
Sun Jul 24 06:08:23 2022 Slave Thread Message 13
Sun Jul 24 06:08:23 2022 Slave Thread Message 14
Sun Jul 24 06:08:23 2022 Slave Thread Message 15
Sun Jul 24 06:08:23 2022 Slave Thread Message 16
Sun Jul 24 06:08:23 2022 Slave Thread Message 17
Sun Jul 24 06:08:23 2022 Slave Thread Message 18
Sun Jul 24 06:08:23 2022 Master Thread Message 71
Sun Jul 24 06:08:23 2022 Slave Thread Message 19
Sun Jul 24 06:08:23 2022 Slave Thread Message 20
Sun Jul 24 06:08:23 2022 Slave Thread Message 21
Sun Jul 24 06:08:23 2022 Slave Thread Message 22
Sun Jul 24 06:08:23 2022 Slave Thread Message 23
Sun Jul 24 06:08:23 2022 Slave Thread Message 24
Sun Jul 24 06:08:23 2022 Slave Thread Message 25
Sun Jul 24 06:08:23 2022 Slave Thread Message 26
Sun Jul 24 06:08:23 2022 Master Thread Message 72
Sun Jul 24 06:08:23 2022 Master Thread Message 73
Sun Jul 24 06:08:23 2022 Master Thread Message 74
Sun Jul 24 06:08:23 2022 Master Thread Message 75
Sun Jul 24 06:08:23 2022 Master Thread Message 76
Sun Jul 24 06:08:23 2022 Master Thread Message 77
Sun Jul 24 06:08:23 2022 Master Thread Message 78
Sun Jul 24 06:08:23 2022 Master Thread Message 79
Sun Jul 24 06:08:23 2022 Slave Thread Message 27
Sun Jul 24 06:08:23 2022 Slave Thread Message 28
Sun Jul 24 06:08:23 2022 Slave Thread Message 29
Sun Jul 24 06:08:23 2022 Slave Thread Message 30
Sun Jul 24 06:08:23 2022 Slave Thread Message 31
Sun Jul 24 06:08:23 2022 Slave Thread Message 32
Sun Jul 24 06:08:23 2022 Master Thread Message 80
Sun Jul 24 06:08:23 2022 Master Thread Message 81
Sun Jul 24 06:08:23 2022 Master Thread Message 82
Sun Jul 24 06:08:23 2022 Slave Thread Message 33
Sun Jul 24 06:08:23 2022 Slave Thread Message 34
Sun Jul 24 06:08:23 2022 Slave Thread Message 35
Sun Jul 24 06:08:23 2022 Master Thread Message 83
Sun Jul 24 06:08:23 2022 Master Thread Message 84
Sun Jul 24 06:08:23 2022 Master Thread Message 85
Sun Jul 24 06:08:23 2022 Master Thread Message 86
Sun Jul 24 06:08:23 2022 Slave Thread Message 36
Sun Jul 24 06:08:23 2022 Master Thread Message 87
Sun Jul 24 06:08:23 2022 Slave Thread Message 37
Sun Jul 24 06:08:23 2022 Master Thread Message 88
Sun Jul 24 06:08:23 2022 Master Thread Message 89
Sun Jul 24 06:08:23 2022 Master Thread Message 90
Sun Jul 24 06:08:23 2022 Master Thread Message 91
Sun Jul 24 06:08:23 2022 Master Thread Message 92
Sun Jul 24 06:08:23 2022 Master Thread Message 93
Sun Jul 24 06:08:23 2022 Master Thread Message 94
Sun Jul 24 06:08:23 2022 Master Thread Message 95
Sun Jul 24 06:08:23 2022 Master Thread Message 96
Sun Jul 24 06:08:23 2022 Slave Thread Message 38
Sun Jul 24 06:08:23 2022 Slave Thread Message 39
Sun Jul 24 06:08:23 2022 Slave Thread Message 40
Sun Jul 24 06:08:23 2022 Master Thread Message 97
Sun Jul 24 06:08:23 2022 Master Thread Message 98
Sun Jul 24 06:08:23 2022 Master Thread Message 99
Sun Jul 24 06:08:23 2022 Slave Thread Message 41
Sun Jul 24 06:08:23 2022 Slave Thread Message 42
Sun Jul 24 06:08:23 2022 Slave Thread Message 43
Sun Jul 24 06:08:23 2022 Slave Thread Message 44
Sun Jul 24 06:08:23 2022 Slave Thread Message 45
Sun Jul 24 06:08:23 2022 Slave Thread Message 46
Sun Jul 24 06:08:23 2022 Slave Thread Message 47
Sun Jul 24 06:08:23 2022 Slave Thread Message 48
Sun Jul 24 06:08:23 2022 Slave Thread Message 49
Sun Jul 24 06:08:23 2022 Slave Thread Message 50
Sun Jul 24 06:08:23 2022 Slave Thread Message 51
Sun Jul 24 06:08:23 2022 Slave Thread Message 52
Sun Jul 24 06:08:23 2022 Slave Thread Message 53
Sun Jul 24 06:08:23 2022 Slave Thread Message 54
Sun Jul 24 06:08:23 2022 Slave Thread Message 55
Sun Jul 24 06:08:23 2022 Slave Thread Message 56
Sun Jul 24 06:08:23 2022 Slave Thread Message 57
Sun Jul 24 06:08:23 2022 Slave Thread Message 58
Sun Jul 24 06:08:23 2022 Slave Thread Message 59
Sun Jul 24 06:08:23 2022 Slave Thread Message 60
Sun Jul 24 06:08:23 2022 Slave Thread Message 61
Sun Jul 24 06:08:23 2022 Slave Thread Message 62
Sun Jul 24 06:08:23 2022 Slave Thread Message 63
Sun Jul 24 06:08:23 2022 Slave Thread Message 64
Sun Jul 24 06:08:23 2022 Slave Thread Message 65
Sun Jul 24 06:08:23 2022 Slave Thread Message 66
Sun Jul 24 06:08:23 2022 Slave Thread Message 67
Sun Jul 24 06:08:23 2022 Slave Thread Message 68
Sun Jul 24 06:08:23 2022 Slave Thread Message 69
Sun Jul 24 06:08:23 2022 Slave Thread Message 70
Sun Jul 24 06:08:23 2022 Slave Thread Message 71
Sun Jul 24 06:08:23 2022 Slave Thread Message 72
Sun Jul 24 06:08:23 2022 Slave Thread Message 73
Sun Jul 24 06:08:23 2022 Slave Thread Message 74
Sun Jul 24 06:08:23 2022 Slave Thread Message 75
Sun Jul 24 06:08:23 2022 Slave Thread Message 76
Sun Jul 24 06:08:23 2022 Slave Thread Message 77
Sun Jul 24 06:08:23 2022 Slave Thread Message 78
Sun Jul 24 06:08:23 2022 Slave Thread Message 79
Sun Jul 24 06:08:23 2022 Slave Thread Message 80
Sun Jul 24 06:08:23 2022 Slave Thread Message 81
Sun Jul 24 06:08:23 2022 Slave Thread Message 82
Sun Jul 24 06:08:23 2022 Slave Thread Message 83
Sun Jul 24 06:08:23 2022 Slave Thread Message 84
Sun Jul 24 06:08:23 2022 Slave Thread Message 85
Sun Jul 24 06:08:23 2022 Slave Thread Message 86
Sun Jul 24 06:08:23 2022 Slave Thread Message 87
Sun Jul 24 06:08:23 2022 Slave Thread Message 88
Sun Jul 24 06:08:23 2022 Slave Thread Message 89
Sun Jul 24 06:08:23 2022 Slave Thread Message 90
Sun Jul 24 06:08:23 2022 Slave Thread Message 91
Sun Jul 24 06:08:23 2022 Slave Thread Message 92
Sun Jul 24 06:08:23 2022 Slave Thread Message 93
Sun Jul 24 06:08:23 2022 Slave Thread Message 94
Sun Jul 24 06:08:23 2022 Slave Thread Message 95
Sun Jul 24 06:08:23 2022 Slave Thread Message 96
Sun Jul 24 06:08:23 2022 Slave Thread Message 97
Sun Jul 24 06:08:23 2022 Slave Thread Message 98
Sun Jul 24 06:08:23 2022 Slave Thread Message 99

C:\Users\scot\source\repos\Project2\Debug\Project2.exe (process 12748) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .
