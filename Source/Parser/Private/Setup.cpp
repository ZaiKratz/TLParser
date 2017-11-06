// Fill out your copyright notice in the Description page of Project Settings.

#include "Setup.h"
#include "FileHelper.h"
#include "Generator.h"
#include "Regex.h"
#include "PlatformFilemanager.h"
#include "Runtime/Core/Public/Misc/Paths.h"
// Sets default values
ASetup::ASetup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASetup::BeginPlay()
{
	Super::BeginPlay();

	FString GameDir = FPaths::GameDir();
	FString PluginDir = GameDir + TEXT("Plugins/Parser/");
	FString PluginContentDir = PluginDir + TEXT("TL/");
	FString FuncDir = PluginContentDir + TEXT("Functions/");
	FString TypesDir = PluginContentDir + TEXT("Types/");
	FString SñhemeFile = PluginContentDir + TEXT("scheme.tl");

	TLGenerator Gen;

	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
	if (PlatformFile.DirectoryExists(*FuncDir) || PlatformFile.DirectoryExists(*TypesDir))
		Gen.CleanTLObjects();
	Gen.GenerateTLObjects(SñhemeFile);
}

// Called every frame
void ASetup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

