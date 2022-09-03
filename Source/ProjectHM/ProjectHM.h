// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "EngineMinimal.h"

DECLARE_LOG_CATEGORY_EXTERN(ProjectHM, Log, All);

#define HMLOG_CALLINFO (FString(__FUNCTION__) + TEXT("(")+FString::FromInt(__LINE__)+TEXT())
#define HMLOG_S(Verbosity) UE_LOG(ProjectHM, Verbosity, TEXT("%s"), *HMLOG_CALLINFO)
#define HMLOG(Verbosity, Format, ...) UE_LOG(ProjectHM, Verbosity, TEXT("%s %s"), *HMLOG_CALLINFO, *FString::Printf(Format, ##__VA_ARGS__))

#define COLLISION_INTERACTABLE ECC_GameTraceChannel1;