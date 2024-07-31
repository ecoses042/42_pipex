this program is echol 42 pipex project.
it will mimic linux command relating file.
<file1 cmd1 | cmd2> file2

1.1 main process and 1 child process is activated to execute cmd 1 and 2
2.child will pass result of cmd1 on file1 to main process using pipe() function
3.parent process execute cmd2 and store it on outputside of pipe
