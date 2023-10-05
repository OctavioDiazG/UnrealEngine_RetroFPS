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
	float AbsoluteMagnitude = FMath::Abs(Data.EvaluatedData.Magnitude);

	if (Data.EvaluatedData.Magnitude > 0)
	{
		if (Data.EvaluatedData.Attribute == GetArmourAttribute() && GetArmour() + AbsoluteMagnitude >= 100.0f)
		{
			SetArmour(100);
			return false;
		}
		if (Data.EvaluatedData.Attribute == GetHealthAttribute() && GetHealth() + AbsoluteMagnitude >= 100.0f)
		{
			SetHealth(100);
			return false;
		}
	}
	else
	{
		if (Data.EvaluatedData.Attribute == GetArmourAttribute() && AbsoluteMagnitude > GetArmour())
		{
			Health.SetCurrentValue(Health.GetCurrentValue() - (AbsoluteMagnitude - GetArmour()));
		}
	}

	return true;
}
