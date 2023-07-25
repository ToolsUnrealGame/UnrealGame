// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class Unreal_GameServerTarget : TargetRules //이 행은 프로젝트 이름에 맞게 변경합니다.
{
    public Unreal_GameServerTarget(TargetInfo Target) : base(Target) //이 행은 프로젝트 이름에 맞게 변경합니다.
    {
        Type = TargetType.Server;
        DefaultBuildSettings = BuildSettingsVersion.V2;
        ExtraModuleNames.Add("Unreal_Game"); //이 행은 프로젝트 이름에 맞게 변경합니다.
    }
}