// Fill out your copyright notice in the Description page of Project Settings.
// Fill out your copyright notice in the Description page of Project Settings.
#include "DrawDebugHelpers.h"
#include "Templates/Function.h"
#include "Engine/World.h"
#include "WheelHoverComponent.h"

// Sets default values for this component's properties
UWheelHoverComponent::UWheelHoverComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	bWheelIsGrounded = false;
	AngularDamping = 10.f;
	LinearDamping = 5.f;
	HoverStrength = 400000.f;
	TraceLength = 60.f;


	// ...
}


// Called when the game starts
void UWheelHoverComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


FHitResult UWheelHoverComponent::GroundTrace(FVector WorldLocation)
{
	FVector startLoc = WorldLocation;
	FVector endLoc = startLoc + (GetUpVector() * TraceLength * -1);
	FHitResult Hit;
	FCollisionQueryParams TraceParams;
	bool bHasHit = GetWorld()->LineTraceSingleByChannel(Hit, startLoc, endLoc, ECC_Visibility);
	
	DrawDebugLine(GetWorld(), startLoc, endLoc, FColor::Red, false, 1.f);
	
	
	if (bHasHit)
	{
		DrawDebugBox(GetWorld(), Hit.ImpactPoint, FVector(10.f, 10.f, 10.f), FColor::Green, false, 2.f);
		bWheelIsGrounded = true;
		UE_LOG(LogTemp, Warning, TEXT("this wheel is grounded"));
	}
	else
	{
		bWheelIsGrounded = false;
	}
	return Hit;
	
	
}

// Called every frame
void UWheelHoverComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	
	// ...
}

