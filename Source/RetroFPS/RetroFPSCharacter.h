// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameplayTagContainer.h"
#include <GameplayEffect.h>
#include "AbilitySystemInterface.h"
#include "RetroFPSCharacter.generated.h"

UCLASS()
class RETROFPS_API ARetroFPSCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Abilities, meta = (AllowPrivateAccess = "true"))
		class UAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY()
		class URetroFPSAttributeSet* Attributes;

public:
	// Sets default values for this character's properties
	ARetroFPSCharacter();

	//override IAbilitySystemInterface
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	//Effect that initializes our default attributes
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "RetroFPS")
		TSubclassOf<class UGameplayEffect> DefaultAttributesEffect;

	//Array of starting abilities
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "RetroFPS")
		TArray<TSubclassOf<class UGameplayAbility>> DefaultAbilities;
	

};
