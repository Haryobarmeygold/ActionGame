// Fill out your copyright notice in the Description page of Project Settings.

#include "SItemChest.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ASItemChest::ASItemChest()
{

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>("Basemesh");
	BaseMesh->SetupAttachment(RootComponent);

	Lidmesh = CreateDefaultSubobject<UStaticMeshComponent>("Lidmesh");
	Lidmesh->SetupAttachment(BaseMesh);

	TargetPitch = 110;
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}
void ASItemChest::Interact_Implementation(APawn* InstigatorPawn)
{
	Lidmesh->SetRelativeRotation(FRotator(TargetPitch, 0, 0));
}

// Called when the game starts or when spawned
void ASItemChest::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASItemChest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

