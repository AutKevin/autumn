@echo off
@echo ���ڹر�Oracle...
net stop OracleJobSchedulerORCL
net stop OracleOraDB12Home1MTSRecoveryService
net stop OracleOraDB12Home1TNSListener
net stop OracleRemExecServiceV2
net stop OracleServiceORCL
net stop OracleVssWriterORCL
@echo Oracle�ر����!
pause