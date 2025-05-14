##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Connexion_BDD
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=/home/seb/Ventilation
ProjectPath            :=/home/seb/Ventilation/Connexion_BDD
IntermediateDirectory  :=../build-$(ConfigurationName)/Connexion_BDD
OutDir                 :=../build-$(ConfigurationName)/Connexion_BDD
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=
Date                   :=05/14/25
CodeLitePath           :=/home/seb/.codelite
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
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
Libs                   := $(LibrarySwitch)PocoDataODBC $(LibrarySwitch)PocoData $(LibrarySwitch)PocoFoundation 
ArLibs                 :=  "PocoDataODBC" "PocoData" "PocoFoundation" 
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -Wall $(shell wx-config --cxxflags --unicode=yes  ) $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(shell wx-config --cxxflags --unicode=yes  ) $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=../build-$(ConfigurationName)/Connexion_BDD/MyApp.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/Connexion_BDD/.d $(Objects) 
	@mkdir -p "../build-$(ConfigurationName)/Connexion_BDD"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@mkdir -p "../build-$(ConfigurationName)/Connexion_BDD"
	@mkdir -p ""../build-$(ConfigurationName)/bin""

../build-$(ConfigurationName)/Connexion_BDD/.d:
	@mkdir -p "../build-$(ConfigurationName)/Connexion_BDD"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/Connexion_BDD/MyApp.cpp$(ObjectSuffix): MyApp.cpp ../build-$(ConfigurationName)/Connexion_BDD/MyApp.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/seb/Ventilation/Connexion_BDD/MyApp.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/MyApp.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Connexion_BDD/MyApp.cpp$(DependSuffix): MyApp.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Connexion_BDD/MyApp.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/Connexion_BDD/MyApp.cpp$(DependSuffix) -MM MyApp.cpp

../build-$(ConfigurationName)/Connexion_BDD/MyApp.cpp$(PreprocessSuffix): MyApp.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Connexion_BDD/MyApp.cpp$(PreprocessSuffix) MyApp.cpp


-include ../build-$(ConfigurationName)/Connexion_BDD//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


