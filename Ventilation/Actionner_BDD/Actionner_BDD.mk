##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Actionner_BDD
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=/home/ir2/seb/Documents/Ventilation
ProjectPath            :=/home/ir2/seb/Documents/Ventilation/Actionner_BDD
IntermediateDirectory  :=../build-$(ConfigurationName)/Actionner_BDD
OutDir                 :=../build-$(ConfigurationName)/Actionner_BDD
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Sofiane EL-BOUHALI
Date                   :=05/13/25
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
Libs                   := $(LibrarySwitch)pigpio $(LibrarySwitch)PocoDataODBC $(LibrarySwitch)PocoData $(LibrarySwitch)PocoFoundation $(LibrarySwitch)PocoDataKeywords 
ArLibs                 :=  "pigpio" "PocoDataODBC" "PocoData" "PocoFoundation" "PocoDataKeywords" 
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
Objects0=../build-$(ConfigurationName)/Actionner_BDD/MyApp.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/Actionner_BDD/.d $(Objects) 
	@mkdir -p "../build-$(ConfigurationName)/Actionner_BDD"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@mkdir -p "../build-$(ConfigurationName)/Actionner_BDD"
	@mkdir -p ""../build-$(ConfigurationName)/bin""

../build-$(ConfigurationName)/Actionner_BDD/.d:
	@mkdir -p "../build-$(ConfigurationName)/Actionner_BDD"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/Actionner_BDD/MyApp.cpp$(ObjectSuffix): MyApp.cpp ../build-$(ConfigurationName)/Actionner_BDD/MyApp.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ir2/seb/Documents/Ventilation/Actionner_BDD/MyApp.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/MyApp.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Actionner_BDD/MyApp.cpp$(DependSuffix): MyApp.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Actionner_BDD/MyApp.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/Actionner_BDD/MyApp.cpp$(DependSuffix) -MM MyApp.cpp

../build-$(ConfigurationName)/Actionner_BDD/MyApp.cpp$(PreprocessSuffix): MyApp.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Actionner_BDD/MyApp.cpp$(PreprocessSuffix) MyApp.cpp


-include ../build-$(ConfigurationName)/Actionner_BDD//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


