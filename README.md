# ShipDesignandManagementSystem_Fixed


### 环境
- MySQL Community 8.0.27.1[MySQL :: Download MySQL Installer](https://dev.mysql.com/downloads/installer/)
- Qt 5.14.2[Index of /archive/qt/5.14/5.14.2](https://download.qt.io/archive/qt/5.14/5.14.2/)
- ODBC 9.1.0[MySQL :: Download MySQL Connector/ODBC (Archived Versions)](https://downloads.mysql.com/archives/c-odbc/)
- Qt Creator 4.11.1（在Qt5.14.2\Tools\QtCreator\bin目录下的qtcreator.exe）
- Navicat Premium 16（可在tb购买安装的exe)
- MySQL Workbench 8.0（下载mysql时一并下载）



### 数据库设置
- 打开应用软件Navicat Premium 16
- 点击 ‘新建表’，designer、designfile、project、manager、approver、approvefile，一共这6个表

designer表单：
designerid和password是在主界面，选择"设计师"登录的ID和PWD

|designerid|password|name|gender|phone|email|
|---|---|---|---|---|---|
|202501001|12301001|d001|male|186001|d001@gmail.com|
|202501002|12301002|d002|female|186002|d002@gmail.com|
|202501003|12301003|d003|female|186003|d003@gmail.com|
|202501004|12301004|d004|male|186004|d004@gmail.com|

designfile表单:

|fileid|filename|filetype|uploaddate|versionnumber|designerid|projectid|
|---|---|---|---|---|---|---|
|f001|fn001|CSV|2025.1.1|1.1|202501001|p001|
|f002|fn002|readme|2025.2.2|1.2|202401002|p002|
|f003|fn003|txt|2025.3.3|1.3|202401003|p003|
|f004|fn004|dll|2025.4.4|1.4|202401004|p004|

project表单:

|projectid|projectname|startdate|enddate|status|
|---|---|---|---|---|
|p001|n001|2025.9.1|2025.9.2|done|
|p002|n002|2025.10.2|2025.10.3|doing|
|p003|n003|2025.11.3|2025.11.4|undo|
|p004|n004|2025.12.4|2025.12.5|doing|

manager表单：
managerid和password是在主界面，选择"项目经理"登录的ID和PWD

|managerid|password|name|gender|phone|email|
|---|---|---|---|---|---|
|202502001|12302001|m001|male|188001|m001@gmail.com|
|202502002|12302002|m002|male|188002|m002@gmail.com|
|202502003|12302003|m003|female|188003|m003@gmail.com|
|202502004|12302004|m004|female|188004|m004@gmail.com|

approver表单：
approverid和password是在主界面，选择"审批者"登录的ID和PWD

|approverid|password|name|gender|phone|email|
|---|---|---|---|---|---|
|202503001|12303001|a001|female|198001|a001@gmail.com|
|202503002|12303002|a002|female|198002|a002@gmail.com|
|202503003|12303003|a003|male|198003|a003@gmail.com|
|202503004|12303004|a004|female|198004|a004@gmail.com|

approvefile表单：

|recordid|fileid|filename|changewhy|changedate|approverid|
|---|---|---|---|---|---|
|r001|f001|fn001|delete|2025.1.1|202503001|
|r002|f002|fn002|add|2025.2.2|202503002|
|r003|f003|fn003|alter|2025.3.3|202503003|
|r004|f004|fn004|add|2025.4.4|202503004|

- 打开应用软件 MySQL Workbench8.0
- 点击Local instance MySQL80（Navicat就没有这一步了）




### ODBC（64位）设置
点击"配置"
- 注意一定是得64 位 ODBC DSN/驱动，因为Qt构建是 64 位：Desktop_Qt_5_14_2_MSVC2017_64bit-Debug
- Data Source Name: ShipDesignandManagement
- Description: 为空即可
- TCP/IP Server: 127.0.0.1
- Port: 3306
- User: root
- Password:SHWYH
- Database: shipmanagement
这些设置，像Data Source Name: ShipDesignandManagement不可随便修改，是和 database.cpp中一一对应的
P.S.Database是选择我们本地的数据库，是我们在mysql中为我们这个项目新建的schema名，我的mysql这里是 shipmanagement，与 ShipDesignandManagement可不一样哦
