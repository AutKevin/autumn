@echo off
@echo 正在关闭Oracle...
net stop OracleJobSchedulerORCL
net stop OracleOraDB12Home1MTSRecoveryService
net stop OracleOraDB12Home1TNSListener
net stop OracleRemExecServiceV2
net stop OracleServiceORCL
net stop OracleVssWriterORCL
@echo Oracle关闭完毕!
pause