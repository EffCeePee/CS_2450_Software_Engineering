#-------------------------------------------------------------------------------
# Program to run a command line interface program with its input redirected
# from a file and its output redirected to a file.
# Michael Kennard 2014
#-------------------------------------------------------------------------------
import os
import subprocess
import filecmp
import shutil

#-------------------------------------------------------------------------------
def runTests():
    for dname, dirs, files in os.walk("./"):
        for fname in files:
            fileName, extension = os.path.splitext(fname)
            if (extension == ".txt" and "test" in fname
                    and not "_base" in fname and not "_out" in fname):
                resetStartingFiles()
                outName = fileName + "_out.txt"
                program = '.\\..\\Debug\\Library.exe'
                command = program + ' < ' + fname + ' >' + outName
                print("Running " + fname);
                os.system(command)
#-------------------------------------------------------------------------------
def compare2Files(outName, baseName):
    nBad = 0
    nGood = 0
    if os.path.isfile(baseName):
        if not filecmp.cmp(baseName, outName):
            print(baseName + " and " + outName + " differ.")
            nBad = nBad + 1
        else:
            nGood = nGood + 1
    else:
        print(baseName + " doesn't exist.")
        nBad = nBad + 1
    return (nGood, nBad)
#-------------------------------------------------------------------------------
def compareOutputsToBaselines():
    nBad = 0
    nGood = 0
    for dname, dirs, files in os.walk("./"):
        for fname in files:
            fileName, extension = os.path.splitext(fname)
            if (extension == ".txt" and "test" in fname
                    and not "_base" in fname and not "_out" in fname):
                baseName = fileName + "_base.txt"
                outName = fileName + "_out.txt"
                mediaBase = fileName + "MediaFile_base.txt"
                mediaOut = fileName + "MediaFile_out.txt"
                patronBase = fileName + "PatronFile_base.txt"
                patronOut = fileName + "PatronFile_out.txt"

                g = 0
                b = 0

                # Compare testX_out.txt to testX_base.txt
                g, b = compare2Files(outName, baseName)
                nGood = nGood + g
                nBad = nBad + b

                # Compare testXMediaFile_out.txt to testXMediaFile_base.txt
                if os.path.isfile(mediaBase):
                    g, b = compare2Files(mediaOut, mediaBase)
                    nGood = nGood + g
                    nBad = nBad + b

                # Compare testXPatronFile_out.txt to testXPatronFile_base.txt
                if os.path.isfile(patronBase):
                    g, b = compare2Files(patronOut, patronBase)
                    nGood = nGood + g
                    nBad = nBad + b

    return (nGood, nBad)
#-------------------------------------------------------------------------------
# Get fresh copies of the media and patron files
#-------------------------------------------------------------------------------
def resetStartingFiles():
    shutil.copyfile("mediaFile_orig.txt", "mediaFile.txt")
    shutil.copyfile("patronFile_orig.txt", "patronFile.txt")
    shutil.copyfile("mediaFile2_orig.txt", "mediaFile2.txt")
    shutil.copyfile("patronFile2_orig.txt", "patronFile2.txt")
#-------------------------------------------------------------------------------

print("Running program...")

runTests()
print("Comparing outputs to baselines...")
nGood, nBad = compareOutputsToBaselines()
print("Num Successes: " + str(nGood))
print("Num failures: " + str(nBad))
print("Finished.")
exit()