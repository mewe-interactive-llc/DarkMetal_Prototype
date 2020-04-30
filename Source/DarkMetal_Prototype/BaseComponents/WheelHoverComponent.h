// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Engine/World.h"
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "WheelHoverComponent.generated.h"


UCLASS( Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DARKMETAL_PROTOTYPE_API UWheelHoverComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UWheelHoverComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	FHitResult GroundTrace(FVector WorldLocation);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bWheelIsGrounded;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TraceLength;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float HoverStrength;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float LinearDamping;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float AngularDamping;
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
