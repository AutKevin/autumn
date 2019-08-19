@echo off
@echo 正在关闭Oracle...
net start OracleJobSchedulerORCL
net start OracleOraDB12Home1MTSRecoveryService
net start OracleOraDB12Home1TNSListener
net start OracleRemExecServiceV2
net start OracleServiceORCL
net start OracleVssWriterORCL
@echo Oracle关闭完毕!
pause