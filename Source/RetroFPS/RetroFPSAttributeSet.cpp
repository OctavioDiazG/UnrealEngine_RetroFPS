// Fill out your copyright notice in the Description page of Project Settings.


#include "RetroFPSAttributeSet.h"

URetroFPSAttributeSet::URetroFPSAttributeSet()
{
	
}

void URetroFPSAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	NewValue = FMath::Clamp<float>(NewValue, 0.0f, 100.0f);
}

bool URetroFPSAttributeSet::PreGameplayEffectExecute(FGameplayEffectModCallbackData& Data)
{
	float ArmourDamage = FMath::Abs(Data.EvaluatedData.Magnitude);

	if (Data.EvaluatedData.Attribute == GetArmourAttribute() && ArmourDamage > GetArmour() && Data.EvaluatedData.Magnitude < 0.0f)
	{
		Health.SetCurrentValue(Health.GetCurrentValue() - (ArmourDamage - GetArmour()));
	}
	return true;
}
