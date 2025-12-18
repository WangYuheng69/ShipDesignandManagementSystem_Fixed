
# ShipDesignAndManagementSystem

## 项目简介

ShipDesignAndManagementSystem 是一个基于 **Qt 桌面应用程序** 与 **MySQL 数据库** 的船舶设计协同管理系统。
系统面向船舶设计流程中的设计文件管理、项目管理和审批记录管理需求，支持 **设计师、项目经理和审批者** 三类角色登录与协作，通过数据库实现数据的集中存储与统一管理。

本项目为软件综合实践课程设计项目，系统采用 C++17 语言开发，使用 Qt 进行图形界面构建，并通过 ODBC 接口实现与 MySQL 数据库的交互。


## 系统功能概述

系统主要包含以下功能模块：

- 多角色登录（设计师 / 项目经理 / 审批者）

- 设计文件信息管理（新增、修改、删除、查询）

- 项目信息管理与状态维护

- 设计文件审批记录管理

- 基于数据库的数据集中存储与查询


系统共包含四个主要界面：

1. 登录主界面

2. 设计师功能界面

3. 项目经理功能界面

4. 审批者功能界面



## 开发与运行环境

### 软件环境

- **操作系统**：Windows 11（Windows 7 及以上理论可运行）

- **Qt**：Qt 5.14.2

- **Qt Creator**：4.11.1

    > 位于 `Qt5.14.2\Tools\QtCreator\bin\qtcreator.exe`

- **开发语言**：C++（C++17 标准）、XML（1.0）

- **数据库**：MySQL Community Server 8.0.27.1

- **数据库管理工具**：

    - Navicat Premium 16

    - MySQL Workbench 8.0

- **数据库驱动**：MySQL Connector/ODBC 9.1.0（64 位）


⚠️ **注意**：
由于 Qt 项目构建为 64 位（`Desktop_Qt_5_14_2_MSVC2017_64bit`），必须使用 **64 位 ODBC 驱动**，否则无法正常连接数据库。


## 数据库配置说明

### 1. 创建数据库 Schema

在 MySQL 中创建用于本项目的数据库（Schema）：

```sql
CREATE DATABASE shipmanagement;
```

后续所有数据表均创建在该 Schema 下。


### 2. 数据表结构

系统共使用 **6 个数据表**：

- designer（设计师）

- designfile（设计文件）

- project（项目）

- manager（项目经理）

- approver（审批者）

- approvefile（审批记录）


#### 2.1 designer 表（设计师）

|字段名|说明|
|---|---|
|designerid|设计师编号（登录账号）|
|password|登录密码|
|name|姓名|
|gender|性别|
|phone|电话|
|email|邮箱|

示例数据：

|designerid|password|name|gender|phone|email|
|---|---|---|---|---|---|
|202501001|12301001|d001|male|186001|[d001@gmail.com](mailto:d001@gmail.com)|


#### 2.2 designfile 表（设计文件）

|字段名|说明|
|---|---|
|fileid|文件编号|
|filename|文件名|
|filetype|文件类型|
|uploaddate|上传日期|
|versionnumber|版本号|
|designerid|设计师编号|
|projectid|项目编号|

示例数据：

|fileid|filename|filetype|uploaddate|versionnumber|designerid|projectid|
|---|---|---|---|---|---|---|
|f001|fn001|CSV|2025.1.1|1.1|202501001|p001|

#### 2.3 project 表（项目）

|字段名|说明|
|---|---|
|projectid|项目编号|
|projectname|项目名称|
|startdate|开始日期|
|enddate|结束日期|
|status|项目状态|

示例数据：

|projectid|projectname|startdate|enddate|status|
|---|---|---|---|---|
|p001|n001|2025.9.1|2025.9.2|done|

#### 2.4 manager 表（项目经理）

|字段名|说明|
|---|---|
|managerid|项目经理编号（登录账号）|
|password|登录密码|
|name|姓名|
|gender|性别|
|phone|电话|
|email|邮箱|

示例数据：

|managerid|password|name|gender|phone|email|
|---|---|---|---|---|---|
|202502001|12302001|m001|male|188001|[m001@gmail.com](mailto:m001@gmail.com)|

#### 2.5 approver 表（审批者）

|字段名|说明|
|---|---|
|approverid|审批者编号（登录账号）|
|password|登录密码|
|name|姓名|
|gender|性别|
|phone|电话|
|email|邮箱|

示例数据：

|approverid|password|name|gender|phone|email|
|---|---|---|---|---|---|
|202503001|12303001|a001|female|198001|[a001@gmail.com](mailto:a001@gmail.com)|

#### 2.6 approvefile 表（审批记录）

|字段名|说明|
|---|---|
|recordid|记录编号|
|fileid|文件编号|
|filename|文件名|
|changewhy|变更原因|
|changedate|变更日期|
|approverid|审批者编号|

示例数据：

|recordid|fileid|filename|changewhy|changedate|approverid|
|---|---|---|---|---|---|
|r001|f001|fn001|delete|2025.1.1|202503001|

## ODBC 数据源配置（关键步骤）

### ODBC DSN 设置（64 位）

请通过 **ODBC 数据源管理器（64 位）** 进行配置：

- **Data Source Name**：`ShipDesignandManagement`

- **Description**：可为空

- **Server**：127.0.0.1

- **Port**：3306

- **User**：root

- **Password**：SHWYH

- **Database**：shipmanagement


⚠️ **重要说明**：

- `Data Source Name` 必须为 **ShipDesignandManagement**，
    该名称与项目中 `database.cpp` 文件中的配置严格对应，不可随意修改。
- `Database` 是 MySQL 中创建的 Schema 名称，与 DSN 名称可以不同。


## 系统登录说明（测试账号）
系统采用基于角色的登录方式，请在登录界面选择对应角色后输入账号和密码。

### 设计师登录
- 账号：designer 表中的 designerid
- 密码：designer 表中的 password

### 项目经理登录
- 账号：manager 表中的 managerid
- 密码：manager 表中的 password

### 审批者登录
- 账号：approver 表中的 approverid
- 密码：approver 表中的 password

示例账号：
```
（设计师）
账号：202501001
密码：12301001

（项目经理）
账号：202502001
密码：12302001

（审批者）
账号：202503001
密码：12303001
```


## 说明
本项目为软件综合实践课程设计项目，主要用于软件工程相关课程的学习与实践。当前版本重点实现了基于 Qt 桌面应用的多角色数据管理与协作功能，涵盖设计文件管理、项目管理以及审批记录管理等基础模块。

受课程周期和项目规模限制，系统暂未引入更复杂的功能，如细粒度权限控制、操作日志记录、异常处理与安全机制等内容。后续可在现有系统架构和数据库设计的基础上，进一步扩展系统功能，完善工程性和实用性。

本项目更侧重于对软件工程开发流程的实践，包括需求分析、数据库建模、系统实现与测试等环节，适合作为课程设计或 Qt 桌面应用开发的学习参考。

## 致谢
本项目在开发初期参考了 Bilibili 上的[我的朋友约塞克](https://space.bilibili.com/646100493/?spm_id_from=333.788.upinfo.detail.click)发布的Qt 教学视频
[**《超市会员管理系统第一节之文档构思及 QT 环境配置》**](https://www.bilibili.com/video/BV1C5411d71m/?spm_id_from=333.337.search-card.all.click)
作为 Qt 环境搭建和项目结构规划的入门学习资料。

在此基础上，本项目对系统功能、数据库结构、界面设计以及角色划分等内容均进行了重新设计与实现，最终形成了面向船舶设计流程的独立管理系统。
在此对原视频作者的分享表示感谢，也希望该视频能为初学 Qt 的同学提供有价值的学习指引。

## 开源协议
本项目采用 **MIT License** 开源协议。
MIT License 允许任何人自由使用、复制、修改、合并、发布、分发本软件及其副本，前提是在软件及其所有副本中包含原始版权声明和许可声明。