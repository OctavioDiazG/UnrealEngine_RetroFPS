// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PooledObject.h"
//#include "CoreMinimal.h"
//#include "Components/ActorComponent.h"
#include "ObjectPooling.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RETROFPS_API UObjectPooling : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UObjectPooling();

	UFUNCTION(BlueprintCallable, Category = "Object Pooling")
	APooledObject* SpawnPooledObject();

	UPROPERTY(EditAnywhere, Category = "Object Pooling")
	TSubclassOf<class APooledObject> PooledObjectSubclass;

	UPROPERTY(EditAnywhere, Category = "Object Pooling")
	int PoolSize = 20;

	UPROPERTY(EditAnywhere, Category = "Object Pooling")
	float PooledObjectLifeSpan = 0.0f;

	UFUNCTION()
	void OnPooledObjectDespawn(APooledObject* PoolActor);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	TArray<APooledObject*> ObjectPool;
	TArray<int> SpawnedPoolIndexes;
};
