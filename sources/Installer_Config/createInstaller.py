import os
import shutil
import zipfile

basePath: str = "../.."
basePathInstall: str = "../Installers"
qtVersion: str = "6_7_1"
qtMySQLZIP: str = "qsqlmysql.dll_Qt_SQL_driver_6.7.1_MSVC2019_64-bit.zip"

def dataCollectorConfigure() -> None:
    pathProject: str = basePath + "/HoopTesting_DataCollector/build/Desktop_Qt_" + qtVersion + "_MSVC2019_64bit-Release"
    pathInstall: str = basePathInstall + "/DataCollector"

    shutil.rmtree(pathInstall)
    os.system("windeployqt.exe --dir " + '"' + pathInstall + '"' + " --no-translations --no-quick-import --compiler-runtime --no-virtualkeyboard  --release " + '"' + pathProject + "/DataCollector.exe" + '"')
    shutil.copyfile(pathProject + "/DataCollector.exe", pathInstall + "/DataCollector.exe")
    
    with zipfile.ZipFile(basePath + "/HoopTesting_DataCollector/" + qtMySQLZIP, 'r') as zip_ref:
        zip_ref.extractall(pathInstall)

    os.system("rm " + '"' + pathInstall + "/sqldrivers/qsqlite.dll" + '" ' + '"' + pathInstall + "/sqldrivers/qsqlmysqld.dll" + '"')

def databaseManagerConfigure() -> None:
    pathProject: str = basePath + "/HoopTesting_DatabaseManager/build/Desktop_Qt_" + qtVersion + "_MSVC2019_64bit-Release"
    pathInstall: str = basePathInstall + "/DatabaseManager"

    shutil.rmtree(pathInstall)
    os.system("windeployqt.exe --dir " + '"' + pathInstall + '"' + " --no-translations --no-quick-import --compiler-runtime --no-virtualkeyboard  --release " + '"' + pathProject + "/DatabaseManager.exe" + '"')
    shutil.copyfile(pathProject + "/DatabaseManager.exe", pathInstall + "/DatabaseManager.exe")
    
    with zipfile.ZipFile(basePath + "/HoopTesting_DatabaseManager/" + qtMySQLZIP, 'r') as zip_ref:
        zip_ref.extractall(pathInstall)

    os.system("rm " + '"' + pathInstall + "/sqldrivers/qsqlite.dll" + '" ' + '"' + pathInstall + "/sqldrivers/qsqlmysqld.dll" + '"')

def reportGeneratorConfigure() -> None:
    pathProject: str = basePath + "/HoopTesting_ReportGenerator/dist/win-unpacked"
    pathInstall: str = basePathInstall + "/ReportGenerator"

    shutil.rmtree(pathInstall)
    shutil.copytree(pathProject, pathInstall)

if __name__ == "__main__":
    # Data Collector Installer Preparation
    dataCollectorConfigure()
    os.system("clear")

    # Database Manager Installer Preparation
    databaseManagerConfigure()
    os.system("clear")

    # Report Generator Installer Preparation
    reportGeneratorConfigure()

    os.system("clear")
    print("Finished.....")