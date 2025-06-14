##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Debit_BDD
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=/home/ir2/seb/Documents/Projet_Ventilation_ERP-Etudiant-2
ProjectPath            :=/home/ir2/seb/Documents/Projet_Ventilation_ERP-Etudiant-2/Debit_BDD
IntermediateDirectory  :=../build-$(ConfigurationName)/Debit_BDD
OutDir                 :=../build-$(ConfigurationName)/Debit_BDD
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Sofiane EL-BOUHALI
Date                   :=06/13/25
CodeLitePath           :=/home/ir2/seb/.codelite
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=../build-$(ConfigurationName)/bin/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
LinkOptions            :=  $(shell wx-config   --libs --unicode=yes)
IncludePath            :=  $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)PocoData $(LibrarySwitch)PocoDataODBC $(LibrarySwitch)PocoFoundation 
ArLibs                 :=  "PocoData" "PocoDataODBC" "PocoFoundation" 
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -g -O0 -Wall $(shell wx-config --cxxflags --unicode=yes  ) $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(shell wx-config --cxxflags --unicode=yes  ) $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=../build-$(ConfigurationName)/Debit_BDD/Debit_BDD.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/Debit_BDD/.d $(Objects) 
	@mkdir -p "../build-$(ConfigurationName)/Debit_BDD"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@mkdir -p "../build-$(ConfigurationName)/Debit_BDD"
	@mkdir -p ""../build-$(ConfigurationName)/bin""

../build-$(ConfigurationName)/Debit_BDD/.d:
	@mkdir -p "../build-$(ConfigurationName)/Debit_BDD"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/Debit_BDD/Debit_BDD.cpp$(ObjectSuffix): Debit_BDD.cpp ../build-$(ConfigurationName)/Debit_BDD/Debit_BDD.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ir2/seb/Documents/Projet_Ventilation_ERP-Etudiant-2/Debit_BDD/Debit_BDD.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Debit_BDD.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Debit_BDD/Debit_BDD.cpp$(DependSuffix): Debit_BDD.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Debit_BDD/Debit_BDD.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/Debit_BDD/Debit_BDD.cpp$(DependSuffix) -MM Debit_BDD.cpp

../build-$(ConfigurationName)/Debit_BDD/Debit_BDD.cpp$(PreprocessSuffix): Debit_BDD.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Debit_BDD/Debit_BDD.cpp$(PreprocessSuffix) Debit_BDD.cpp


-include ../build-$(ConfigurationName)/Debit_BDD//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


