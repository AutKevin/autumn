@echo off
@echo ���ڹر�Oracle...
net start OracleJobSchedulerORCL
net start OracleOraDB12Home1MTSRecoveryService
net start OracleOraDB12Home1TNSListener
net start OracleRemExecServiceV2
net start OracleServiceORCL
net start OracleVssWriterORCL
@echo Oracle�ر����!
pause