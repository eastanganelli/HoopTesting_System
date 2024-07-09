import os
import shutil
import zipfile

basePath: str = "../.."
basePathInstall: str = "../Installers"
qtVersion: str = "6_7_2"
compilerVersion: str = "MSVC2019"
qtMySQLZIP: str = "qsqlmysql.dll_Qt_SQL_driver_6.7.2_MSVC2019_64-bit.zip"

def dataCollectorConfigure() -> None:
    pathProject: str = basePath + "/HoopTesting_DataCollector/build/Desktop_Qt_" + qtVersion + "_" + compilerVersion + "_64bit-Release"
    pathInstall: str = basePathInstall + "/DataCollector"

    try:
        shutil.rmtree(pathInstall)
    except:
        pass
    os.system("windeployqt.exe --dir " + '"' + pathInstall + '"' + " --no-translations --no-quick-import --compiler-runtime --no-virtualkeyboard  --release " + '"' + pathProject + "/DataCollector.exe" + '"')
    shutil.copyfile(pathProject + "/DataCollector.exe", pathInstall + "/DataCollector.exe")
    
    with zipfile.ZipFile(basePath + "/HoopTesting_DataCollector/" + qtMySQLZIP, 'r') as zip_ref:
        zip_ref.extractall(pathInstall)

    os.remove(pathInstall + "/sqldrivers/qsqlite.dll")
    os.remove(pathInstall + "/sqldrivers/qsqlmysqld.dll")

def databaseManagerConfigure() -> None:
    pathProject: str = basePath + "/HoopTesting_DatabaseManager/build/Desktop_Qt_" + qtVersion + "_" + compilerVersion + "_64bit-Release"
    pathInstall: str = basePathInstall + "/DatabaseManager"

    try:
        shutil.rmtree(pathInstall)
    except:
        pass
    os.system("windeployqt.exe --dir " + '"' + pathInstall + '"' + " --no-translations --no-quick-import --compiler-runtime --no-virtualkeyboard  --release " + '"' + pathProject + "/DatabaseManager.exe" + '"')
    shutil.copyfile(pathProject + "/DatabaseManager.exe", pathInstall + "/DatabaseManager.exe")
    
    with zipfile.ZipFile(basePath + "/HoopTesting_DatabaseManager/" + qtMySQLZIP, 'r') as zip_ref:
        zip_ref.extractall(pathInstall)

    os.remove(pathInstall + "/sqldrivers/qsqlite.dll")
    os.remove(pathInstall + "/sqldrivers/qsqlmysqld.dll")

def emulatorConfigure() -> None:
    pathProject: str = basePath + "/HoopTesting_Emulator/build/Desktop_Qt_" + qtVersion + "_" + compilerVersion + "_64bit-Release/release"
    pathInstall: str = basePathInstall + "/Emulator"

    try:
        shutil.rmtree(pathInstall)
    except:
        pass
    os.system("windeployqt.exe --dir " + '"' + pathInstall + '"' + " --no-translations --no-quick-import --compiler-runtime --no-virtualkeyboard  --release " + '"' + pathProject + "/PLC_Emulator.exe" + '"')
    shutil.copyfile(pathProject + "/PLC_Emulator.exe", pathInstall + "/PLC_Emulator.exe")

def reportGeneratorConfigure() -> None:
    pathProject: str = basePath + "/HoopTesting_ReportGenerator/dist/win-unpacked"
    pathInstall: str = basePathInstall + "/ReportGenerator"

    try:
        shutil.rmtree(pathInstall)
    except:
        pass
    shutil.copytree(pathProject, pathInstall)
    shutil.rmtree(pathInstall + "/locales")

if __name__ == "__main__":
    # Data Collector Installer Preparation
    dataCollectorConfigure()
    os.system("cls")

    # Database Manager Installer Preparation
    databaseManagerConfigure()
    os.system("cls")

    # Report Generator Installer Preparation
    reportGeneratorConfigure()
    os.system("cls")

    # Report Generator Installer Preparation
    emulatorConfigure()

    os.system("cls")
    print("Finished.....")